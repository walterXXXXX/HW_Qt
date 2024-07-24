#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>

#include "secundomer.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void ReceiveSecTime(QTime time);

private slots:
    void on_pb_startstop_clicked();

    void on_pb_clear_clicked();

    void on_pb_circle_clicked();

private:
    Ui::MainWindow *ui;
    Secundomer* sec;

};
#endif // MAINWINDOW_H
