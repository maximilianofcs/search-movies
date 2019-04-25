#include <QJsonDocument>
#include <QJsonObject>
#include <QVariantMap>

#include "ParseJasonResult.h"

ParseJasonResult::ParseJasonResult()
{

}


QString ParseJasonResult::parseAndFormat(QString jasonText)
{
    QString result;
    // Reserva espaço para aumentar a performance da concatenacao
    result.reserve(4096);

    // Verifica erros


    // Exibe o resultado em json
    result.append("Resultado:").append("\n");

    // Parse json result
    QJsonDocument doc = QJsonDocument::fromJson(jasonText.toUtf8());
    QJsonObject jObject = doc.object();
    QVariantMap mainMap = jObject.toVariantMap();

    // Para cada item no json mostre o nome e valor
    for(QVariantMap::iterator it = mainMap.begin(); it != mainMap.end(); it++)
    {
        result.append(it.key().toStdString().c_str());
        result.append(" - ");
        result.append(it.value().toString());
        result.append("\n");
    }

    return result;
}
