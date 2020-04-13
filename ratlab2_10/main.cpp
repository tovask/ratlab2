#include <QApplication>
#include <QQmlApplicationEngine>
#include "communicationmanager.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;

    // need to init with an empty recipeModel, because the download will finish a bit later (if we don't want ReferenceError, but anyway it works without this)
    engine.rootContext()->setContextProperty("recipeModel", QVariant::fromValue(QList<QObject*>()));

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    CommunicationManager comManager;
    comManager.setContext(engine.rootContext());
    comManager.DownloadRecipe();

    // find the QML objects
    QObject *rootObject = engine.rootObjects().first();
    QObject *mouseArea = rootObject->findChild<QObject*>("mouseArea");
    // connect signal to slot
    QObject::connect(mouseArea,SIGNAL(download(QVariant)),&comManager,SLOT(newSearch(QVariant)));

    return app.exec();
}
