#include "Stopwatch.h"

Stopwatch::Stopwatch(QObject *parent)
    : QObject{parent}
{
    timer = new QTimer(this);
    timer->setInterval(step);
    connect(timer, &QTimer::timeout, this, &Stopwatch::newTime);
}

void Stopwatch::start() {
    timer->start();
}

void Stopwatch::stop() {
    timer->stop();
}

QTime Stopwatch::getCircleTime() {
    QTime circleTime(0,0,0);
    circleTime = circleTime.addMSecs(lastTime.msecsTo(curTime));
    lastTime = curTime;
    circleNumber++;
    return circleTime;
}

int Stopwatch::getCircleNumber() {
    return circleNumber;
}

void Stopwatch::clear() {
    curTime = QTime(0,0,0);
    lastTime = QTime(0,0,0);
    circleNumber = 0;
    emit sig_newTime(QTime(curTime));
}

void Stopwatch::newTime() {
    curTime = curTime.addMSecs(step);
    emit sig_newTime(QTime(curTime));
}
