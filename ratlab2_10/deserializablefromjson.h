#ifndef DESERIALIZABLEFROMJSON_H
#define DESERIALIZABLEFROMJSON_H

#include <QJsonObject>

class DeserializableFromJSON
{
public:
    DeserializableFromJSON();

    virtual bool DeserializeFromJSON(QJsonObject) = 0;

};

#endif // DESERIALIZABLEFROMJSON_H
