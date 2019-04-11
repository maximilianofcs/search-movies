#include <iostream>

#include "RequestResponse.h"
#include <string>

#include <QJsonDocument>
#include <QJsonObject>
#include <QVariantMap>

int main(int argc, char *argv[])
{
    std::string searchStr;
    std::string searchTitleStr;
    bool hasType = false;
    std::string typeStr;

    QCoreApplication app(argc, argv);

    for(int count=0; count<argc; count++)
    {
        std::string param = argv[count];
        // Exibir help?
        if( param == std::string("--help") or (argc<=1) )
        {
            std::cout << "use:" << std::endl;
            std::cout << "-h ou --help" << std::endl;
            std::cout << "      lista as opções de uso." << std::endl;
            std::cout << "-s ou --search" << std::endl;
            std::cout << "      busca pelo título da midia." << std::endl;
            std::cout << "-t ou --type" << std::endl;
            std::cout << "      retorna o tipo da midia selecionado. (movie, series, episode)." << std::endl;
            std::cout << " Exemplo:" << std::endl;
            std::cout << "      ./search-movies --type movie --search Guardians Of The Galaxy" << std::endl << std::endl;
            return 0;
        }
        // Exibir tipo?
        else if( param == std::string("--type") )
        {
            hasType = true;
            count++;
            if(count < argc)
                typeStr = argv[count];
        }
        // Fazer a pesquisa?
        else if( param == std::string("--search") )
        {
            while(++count < argc)
            {
                // caso tipo seja solicitado reavalia os parametros
                if( std::string(argv[count]) == std::string("--type") )
                {
                    count--;
                    break;
                }

                if(searchStr.size()==0)
                    searchStr.append(argv[count]);
                else
                    searchStr.append(" ").append(argv[count]);

                if(searchTitleStr.size()==0)
                    searchTitleStr.append(argv[count]);
                else
                    searchTitleStr.append("+").append(argv[count]);
            }
            std::cout << std::endl << "Procurando no 'omdbapi' por: '" << searchStr << "'" << std::endl << std::endl;
            break;
        }
    }

    // Faz o request do search no omdbapi
    std::string url = "http://www.omdbapi.com/?apikey=3ef02985";
    url.append("&t=");
    url.append(searchTitleStr);

    // Tipo foi solicitado?
    if(hasType)
    {
        url.append("&type=");
        url.append(typeStr);
    }

    url.append("&plot=full");

    RequestResponse request;

    // Pega o resultado
    std::string result = request.getUrl(url);

    // Exibe o resultado em json
    std::cout << "Resultado:" << std::endl;

    // Parse json result
    QJsonDocument doc = QJsonDocument::fromJson(QString(result.c_str()).toUtf8());
    QJsonObject jObject = doc.object();
    QVariantMap mainMap = jObject.toVariantMap();

    // Para cada item no json mostre o nome e valor
    for(QVariantMap::iterator it = mainMap.begin(); it != mainMap.end(); it++)
    {
        std::cout << it.key().toStdString().c_str()
                  << " - " << it.value().toString().toStdString().c_str()
                  << std::endl;
    }
}
