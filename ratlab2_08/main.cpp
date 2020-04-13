#include <QApplication>
#include <QQmlApplicationEngine>
#include "serialconnector.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    SerialConnector serialConnector;
    serialConnector.connect();

    QObject *rootObject = engine.rootObjects().first();
    // find the objects
    QObject *temperatureMeter = rootObject->findChild<QObject*>("TemperatureMeter");
    QObject *tiltMeter = rootObject->findChild<QObject*>("TiltMeter");
    // connect value signals
    QObject::connect(&serialConnector,SIGNAL(tempChanged(QVariant)),temperatureMeter,SLOT(valueChanged(QVariant)));
    QObject::connect(&serialConnector,SIGNAL(tiltChanged(QVariant)),tiltMeter,SLOT(valueChanged(QVariant)));
    // connect alarm signals
    QObject::connect(&serialConnector,SIGNAL(alarmChanged(QVariant)),temperatureMeter,SLOT(alarmStateChanged(QVariant)));
    QObject::connect(&serialConnector,SIGNAL(alarmChanged(QVariant)),tiltMeter,SLOT(alarmStateChanged(QVariant)));

    return app.exec();
}
