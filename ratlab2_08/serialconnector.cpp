#include "serialconnector.h"
#include <QDebug>

SerialConnector::SerialConnector(QObject *parent) :
    QObject(parent), serialSimulator()
{
    QObject::connect(&serialSimulator,SIGNAL(readyRead()),this,SLOT(newData()));
}

bool SerialConnector::connect()
{
    buffer.clear();
    return serialSimulator.open(QIODevice::ReadOnly);
}

void SerialConnector::disconnect()
{
    serialSimulator.close();
}

void SerialConnector::newData()
{
    QByteArray data = serialSimulator.readAll();
    //qDebug() << data;
    buffer.append(data);
    getMessage();
}

void SerialConnector::getMessage()
{
    QStringList messages = QString(buffer).split("\n\r");
    int processed = 0;
    for(int i=0; i<messages.length()-1; i++)
    {
        decodeMessage(messages[i]);
        processed += messages[i].toUtf8().size() + 2;
    }
    buffer.remove(0,processed);
}

void SerialConnector::decodeMessage(QString msg)
{
    qDebug() << "decoding" << msg;
    QStringList parts = msg.split(":");
    if(parts.length() < 2)
    {
        qDebug() << "unexpected message (no delimiter found): " << msg;
        return;
    }

    if(parts[0] == "#Temp")
        emit tempChanged(parts[1]);
    else if (parts[0] == "#Tilt")
        emit tiltChanged(parts[1]);
    else if (parts[0] == "#Alert")
        emit alarmChanged(parts[1]);
    else
        qDebug() << "unexpected message (unknown type): " << msg;
}

