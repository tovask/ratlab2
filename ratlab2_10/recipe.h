#ifndef RECIPE_H
#define RECIPE_H

#include <QObject>
#include "deserializablefromjson.h"

class Recipe : public QObject, public DeserializableFromJSON
{
    Q_OBJECT

    Q_PROPERTY(QString title MEMBER m_title READ getTitle WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(QString ingredients MEMBER m_ingredients READ getIngredients WRITE setIngredients NOTIFY ingredientsChanged)
    Q_PROPERTY(QString href MEMBER m_href READ getHref WRITE setHref NOTIFY hrefChanged)
    Q_PROPERTY(QString thumbnail MEMBER m_thumbnail READ getThumbnail WRITE setThumbnail NOTIFY thumbnailChanged)

private:

    QString m_title;
    QString m_ingredients;
    QString m_href;
    QString m_thumbnail;

public:
    explicit Recipe(QObject *parent = 0);
    Recipe(QJsonObject, QObject *parent = 0);

    QString getTitle() const;
    QString getIngredients() const;
    QString getHref() const;
    QString getThumbnail() const;

    virtual bool DeserializeFromJSON(QJsonObject) override;

signals:

    void titleChanged(QString arg);
    void ingredientsChanged(QString arg);
    void hrefChanged(QString arg);
    void thumbnailChanged(QString arg);

public slots:

    void setTitle(QString arg);
    void setIngredients(QString arg);
    void setHref(QString arg);
    void setThumbnail(QString arg);
};

#endif // RECIPE_H
