#include "OmdbApi.h"
#include "RequestResponse.h"

OmdbApi::OmdbApi()
{

}


QString OmdbApi::run(QString search, QString type)
{
    QString url = "http://www.omdbapi.com/?apikey=3ef02985";
    url.append("&t=");
    url.append(search);

    // Tipo foi solicitado?
    if(!type.isEmpty())
    {
        url.append("&type=");
        url.append(type);
    }

    url.append("&plot=full");

    // Prepara para o HTTP GET
    RequestResponse request;

    // Pega o resultado do GET na URL
    QString result = request.getUrl(url);
    return result;
}
