#include "mainwindow.h"

#include <QApplication>
#include <QtWidgets>
#include <QMessageBox>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QMessageBox msg;                        // Создаем объекта класса QMessageBox,
                                            // который является информативным окном
    msg.setText("Hello Graphic World!");    // Устанавливаем текст сообщения
    msg.setWindowTitle("I'm Life!");        // Устанавливаем текст заголовка окна
    msg.setStyleSheet("color: green");      // Пускай будет зеленый цвет
    msg.setIcon(QMessageBox::Information);  // Устанавливаем красивую иконку

    msg.show();                             // отображаем окно

 //   MainWindow w;
 //   w.show();
    return a.exec();
}
