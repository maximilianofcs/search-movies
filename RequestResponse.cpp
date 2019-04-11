#include "RequestResponse.h"

RequestResponse::RequestResponse()
{

}

std::string RequestResponse::getUrl(std::string url)
{
    std::string result;

    QNetworkAccessManager NAManager;
    QUrl qurl (url.c_str());
    QNetworkRequest request(qurl);
    QNetworkReply *reply = NAManager.get(request);
    QEventLoop eventLoop;
    QObject::connect(reply, SIGNAL(finished()), &eventLoop, SLOT(quit()));
    eventLoop.exec();

    result = reply->readAll().toStdString();

    return result;
}
