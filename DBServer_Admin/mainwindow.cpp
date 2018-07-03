#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->cb_name->addItem("ADDRESS");
    ui->cb_name->addItem("PORT");
    ui->cb_name->addItem("NAME");
    connect(ui->Add_button,SIGNAL(clicked(bool)),this,SLOT(Open_db()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

MainWindow::Open_db()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("test.sqlite");
    db.open();
    QSqlQuery query;
    query.prepare("INSERT INTO logs");





}
