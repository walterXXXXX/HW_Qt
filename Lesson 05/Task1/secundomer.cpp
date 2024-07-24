#include "secundomer.h"

Secundomer::Secundomer(QObject *parent)
    : QObject{parent}
{
    timer = new QTimer(this);
    timer->setInterval(step);
    connect(timer, &QTimer::timeout, this, &Secundomer::newTime);
}

void Secundomer::start() {
    timer->start();
}

void Secundomer::stop() {
    timer->stop();
}

QTime Secundomer::getCircleTime() {
    QTime circleTime(0,0,0);
    circleTime = circleTime.addMSecs(lastTime.msecsTo(curTime));
    lastTime = curTime;
    circleNumber++;
    return circleTime;
}

int Secundomer::getCircleNumber() {
    return circleNumber;
}

void Secundomer::clear() {
    curTime = QTime(0,0,0);
    lastTime = QTime(0,0,0);
    circleNumber = 0;
    emit sig_newTime(QTime(curTime));
}

void Secundomer::newTime() {
    curTime = curTime.addMSecs(step);
    emit sig_newTime(QTime(curTime));
}
