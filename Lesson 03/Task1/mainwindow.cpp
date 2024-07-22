#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dbConnectDialog = new DBConnectDialog();
    dbConnectDialog->setModal(true);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete dbConnectDialog;
}


void MainWindow::on_btDBConnect_clicked()
{
    dbConnectDialog->show();
}

