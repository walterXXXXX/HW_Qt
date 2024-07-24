#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ReceiveSecTime(QTime(0,0,0));

    sec = new Stopwatch(this);

    connect(sec, &Stopwatch::sig_newTime, this, &MainWindow::ReceiveSecTime);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ReceiveSecTime(QTime time)
{
    ui->label->setText("Время: " + time.toString("hh:mm:ss.z"));
}


void MainWindow::on_pb_startstop_clicked()
{
    if (ui->pb_startstop->text() == "Старт") {
        ui->pb_startstop->setText("Стоп");
        ui->pb_circle->setEnabled(true);
        sec->start();
    }
    else {
        ui->pb_startstop->setText("Старт");
        ui->pb_circle->setEnabled(false);
        sec->stop();
    }
}


void MainWindow::on_pb_clear_clicked()
{
    sec->clear();
}


void MainWindow::on_pb_circle_clicked()
{
    ui->textBrowser->append("Круг "
                            + QString::number(sec->getCircleNumber()) + ", время: "
                            + sec->getCircleTime().toString("hh:mm:ss.z") + " сек");
}

