#ifndef SERIALCONNECTOR_H
#define SERIALCONNECTOR_H

#include <QObject>
#include <QVariant>
#include "serialsimulator.h"

class SerialConnector : public QObject
{
    Q_OBJECT

private:
    SerialSimulator serialSimulator;
    QByteArray buffer;
    void getMessage();
    void decodeMessage(QString msg);

public:
    explicit SerialConnector(QObject *parent = 0);

    bool connect();
    void disconnect();

signals:
    void tempChanged(QVariant);
    void tiltChanged(QVariant);
    void alarmChanged(QVariant);

public slots:

private slots:
    void newData();
};

#endif // SERIALCONNECTOR_H
