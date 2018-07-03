#include <QCoreApplication>
#include<server.h>
#include<QtSql>
int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);
    Server mServer;
    return a.exec();
}
