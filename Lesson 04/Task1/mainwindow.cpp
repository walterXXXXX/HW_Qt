#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->rb_button1->setText("Кнопка 1");
    ui->rb_button2->setText("Кнопка 2");
    for (int i = 0; i < 10; i++) {
        if (i < 2)
            ui->cb_combo->addItem(QString::number(1));
        else
            ui->cb_combo->addItem(QString::number(
                                      (ui->cb_combo->itemText(i-1)).toInt()+
                                      (ui->cb_combo->itemText(i-2)).toInt()));
    }
    ui->pb_button->setText("Кнопка 3");
    ui->pb_button->setCheckable(true);
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(100);
    ui->progressBar->setValue(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_button_clicked()
{
    if (ui->progressBar->value() >= 100)
        ui->progressBar->setValue(0);
    else
        ui->progressBar->setValue(ui->progressBar->value()+10);
}

