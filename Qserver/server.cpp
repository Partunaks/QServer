#include "server.h"
#include<string>

Server::Server(QObject *parent) : QObject(parent)
{
    server = new QTcpServer(this);
    connect(server,SIGNAL(newConnection()),this,SLOT(newConnection()));
    server->listen(QHostAddress::Any,1234);
    if(server->isListening())
    {

        qDebug()<<"Server started!";
    }

    else
    {
        qDebug()<<"Server cant start!";
    }
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("test.sqlite");
    if(!db.open())
    {
        qDebug()<<"Cant open database!";
    }
    else
    {
        qDebug()<<"Database opened!";
    }

}


void Server::newConnection()
{
    QTcpSocket *socket = server->nextPendingConnection();
    qDebug()<<socket->peerAddress()<<"\t"<<socket->peerPort();
    socket->write("Welcome to QT test server!\n");
    socket->flush();
    socket->waitForBytesWritten(3000);
    QSqlQuery query("SELECT PORT FROM logs");
    socket->close();
    delete socket;



}

Server::~Server()
{
    db.close();
    delete server;

}
