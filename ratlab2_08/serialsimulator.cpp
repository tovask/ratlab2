#include "serialsimulator.h"
//#include <QRandomGenerator>
#include <QDebug>

//#include <random>
//#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>

SerialSimulator::SerialSimulator(QObject *parent) : QObject(parent),alert(0)
{
    connect(&timer,SIGNAL(timeout()),this,SLOT(timerTimeout()));
}

quint32 SerialSimulator::random_gen()
{
    static bool dummy = (srand( (unsigned)time(NULL) ) , true);
    return rand();
}

QByteArray SerialSimulator::fetchBuffer(int index)
{
    QByteArray retArray = buffer.left(index);
    buffer.remove(0,index);
    return retArray;
}

QByteArray SerialSimulator::readAll()
{
    quint32 value = random_gen();//QRandomGenerator::global()->generate();

    int index = 0;

    if(value % 3){
        index = buffer.size()-3;
    }
    else if(value % 5){
        index = buffer.size()-4;
    }
    else{
        index = buffer.size();
    }
    return fetchBuffer(index);
}

bool SerialSimulator::open(QIODevice::OpenMode mode)
{
    if(mode == QIODevice::ReadOnly)
    {
        timer.start(500);
        elapsedTimer.start();
        return true;
    }
    else{
        return false;
    }
}

void SerialSimulator::close()
{
    timer.stop();
    buffer.clear();
}

void SerialSimulator::timerTimeout()
{
    quint32 value = random_gen();//QRandomGenerator::global()->generate();

    if(value % 3)
    {
        this->temp = quint32(10.0*sin(double(elapsedTimer.elapsed())) + 30.0);
        buffer.append("#Temp:" + QString::number(this->temp) + "\n\r");
        emit readyRead();
    }

    if(value % 5)
    {
        this->tilt = quint32(10.0*cos(double(elapsedTimer.elapsed())) + 40.0);
        buffer.append("#Tilt:" + QString::number(this->tilt) + "\n\r");
        emit readyRead();
    }

    this->alert++;

    if(this->alert == 10)
    {
        buffer.append("#Alarm:1\n\r");
        emit readyRead();
    }
    if(this->alert == 20)
    {
        buffer.append("#Alert:0\n\r");
        emit readyRead();
        alert = 0;
    }
}
