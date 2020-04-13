#include "recipe.h"

Recipe::Recipe(QObject *parent) :
    QObject(parent)
{
}

Recipe::Recipe(QJsonObject data, QObject *parent) :
    QObject(parent)
{
    bool r = DeserializeFromJSON(data);
    /*qDebug(r?"true":"false");
    qDebug(qPrintable("\t"+getTitle()));
    qDebug(qPrintable("\t"+getIngredients()));
    qDebug(qPrintable("\t"+getHref()));
    qDebug(qPrintable("\t"+getThumbnail()));*/
}

QString Recipe::getTitle() const
{
    return m_title;
}

QString Recipe::getIngredients() const
{
    return m_ingredients;
}

QString Recipe::getHref() const
{
    return m_href;
}

QString Recipe::getThumbnail() const
{
    return m_thumbnail;
}

bool Recipe::DeserializeFromJSON(QJsonObject data)
{
    this->m_title = data["title"].toString();
    this->m_ingredients = data["ingredients"].toString();
    this->m_href = data["href"].toString();
    this->m_thumbnail = data["thumbnail"].toString();
    return true;
}

void Recipe::setTitle(QString arg)
{
    if (m_title == arg)
        return;

    m_title = arg;
    emit titleChanged(arg);
}

void Recipe::setIngredients(QString arg)
{
    if (m_ingredients == arg)
        return;

    m_ingredients = arg;
    emit ingredientsChanged(arg);
}

void Recipe::setHref(QString arg)
{
    if (m_href == arg)
        return;

    m_href = arg;
    emit hrefChanged(arg);
}

void Recipe::setThumbnail(QString arg)
{
    if (m_thumbnail == arg)
        return;

    m_thumbnail = arg;
    emit thumbnailChanged(arg);
}
