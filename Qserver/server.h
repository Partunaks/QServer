#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include<QTcpServer>
#include<QTcpSocket>
#include<QDebug>
#include<QtSql>

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);
    ~Server();

signals:

public slots:
    void newConnection();
private:
    QTcpServer *server;
    QSqlDatabase db;
};

#endif // SERVER_H
