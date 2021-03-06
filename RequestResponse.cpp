#include "RequestResponse.h"

RequestResponse::RequestResponse()
{

}

//
// Faz o HTTP Get na URL fornecida, retorna o response em uma string
//
QString RequestResponse::getUrl(QString url)
{
    QString result;

    QNetworkAccessManager NAManager;
    QUrl qurl(url);
    QNetworkRequest request(qurl);
    QNetworkReply *reply = NAManager.get(request);
    QEventLoop eventLoop;
    QObject::connect(reply, SIGNAL(finished()), &eventLoop, SLOT(quit()));
    eventLoop.exec();

    result = reply->readAll().toStdString().c_str();

    return result;
}





