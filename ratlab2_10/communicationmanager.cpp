#include "communicationmanager.h"
#include <QtNetwork>
#include "recipe.h"

const QString CommunicationManager::host = "www.recipepuppy.com";
const int CommunicationManager::port = 80;

CommunicationManager::CommunicationManager(QObject *parent) :
    QObject(parent)
{
}

QQmlContext *CommunicationManager::getContext() const
{
    return context;
}

void CommunicationManager::setContext(QQmlContext *value)
{
    context = value;
}


void CommunicationManager::DownloadRecipe(QString searchQuery)
{
    // build the url
    QUrl url;
    url.setScheme("http");
    url.setHost(host);
    url.setPort(port);
    url.setPath("/api/");

    // build the query part
    QUrlQuery query;
    query.addQueryItem("q",searchQuery);
    query.addQueryItem("p","1");
    url.setQuery(query);

    // make the request
    QNetworkRequest request(url);
    reply = manager.get(request);

    // wait for the response event
    connect(reply, SIGNAL(finished()),SLOT(finishedDownload()));
}

void CommunicationManager::finishedDownload()
{
    if (reply->error()) {
        qDebug("Download failed:");
        qDebug(qPrintable(reply->errorString()));
    } else {
        //qDebug("Download successful!");
        response.clear();
        response.append(reply->readAll());
        //qDebug(response);

        QJsonArray jsonArray = QJsonDocument::fromJson(response).object()["results"].toArray(); // pretty dirty one-liner
        QList<QObject*> recipeList;
        foreach (const QJsonValue & value, jsonArray) {
            recipeList.append(new Recipe(value.toObject()));
            //qDebug(qPrintable(value.toObject()["title"].toString()));
        }

        context->setContextProperty("recipeModel", QVariant::fromValue(recipeList));
    }
    reply->deleteLater();
}

void CommunicationManager::newSearch(QVariant q)
{
    DownloadRecipe(q.toString());
}
