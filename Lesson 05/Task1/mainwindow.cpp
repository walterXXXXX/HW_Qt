#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ReceiveSecTime(QTime(0,0,0));

    sec = new Secundomer(this);

    connect(sec, &Secundomer::sig_newTime, this, &MainWindow::ReceiveSecTime);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ReceiveSecTime(QTime time)
{
    ui->label->setText(time.toString("hh:mm:ss.zzz"));
}


void MainWindow::on_pb_startstop_clicked()
{
    if (ui->pb_startstop->isChecked())
        sec->start();
    else
        sec->stop();
}


void MainWindow::on_pb_clear_clicked()
{
    sec->clear();
}


void MainWindow::on_pb_circle_clicked()
{
    if (!ui->pb_startstop->isChecked())
        return;
    ui->textBrowser->append("Круг "
                            + QString::number(sec->getCircleNumber()) + ": "
                            + sec->getCircleTime().toString("hh:mm:ss.zzz"));
}

