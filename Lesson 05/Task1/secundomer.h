#ifndef QSECUNDOMER_H
#define QSECUNDOMER_H

#include <QObject>
#include <QTime>
#include <QTimer>

class Secundomer : public QObject
{
    Q_OBJECT
public:
    explicit Secundomer(QObject *parent = nullptr);
    void start();
    void stop();
    void clear();
    QTime getCircleTime();
    int getCircleNumber();

private:
    QTime curTime = QTime(0,0,0);
    QTime lastTime = QTime(0,0,0);
    QTimer* timer;
    int step = 10; // шаг секундомера в 10 мс
    int circleNumber = 0;

    void newTime();

signals:
    void sig_newTime(QTime time);
};

#endif // QSECUNDOMER_H
