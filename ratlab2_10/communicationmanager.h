#ifndef COMMUNICATIONMANAGER_H
#define COMMUNICATIONMANAGER_H

#include <QObject>
#include <QtNetwork>
#include <QQmlContext>

class CommunicationManager : public QObject
{
    Q_OBJECT

private:
    static const QString host;
    static const int port;
    QNetworkAccessManager manager;
    QNetworkReply* reply;
    QByteArray response;

    QQmlContext* context;

public:
    explicit CommunicationManager(QObject *parent = 0);
    void DownloadRecipe(QString searchQuery = "paprika");

    QQmlContext *getContext() const;
    void setContext(QQmlContext *value);

signals:

public slots:
    void finishedDownload();
    void newSearch(QVariant);

};

#endif // COMMUNICATIONMANAGER_H
