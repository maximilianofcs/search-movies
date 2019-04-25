#ifndef REQUESTRESONSE_H
#define REQUESTRESONSE_H

#include <QObject>
#include <QString>
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

public:
    QString getUrl(std::string url);
};

#endif // REQUESTRESONSE_H
