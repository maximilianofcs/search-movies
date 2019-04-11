#ifndef REQUESTRESONSE_H
#define REQUESTRESONSE_H

#include <QObject>
#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QEventLoop>

class RequestResponse
{
public:
    RequestResponse();
    std::string getUrl(std::string url);

};

#endif // REQUESTRESONSE_H
