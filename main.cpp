#include <iostream>
#include <string>

#include "RequestResponse.h"
#include "ParseJasonResult.h"
#include "OmdbApi.h"

int main(int argc, char *argv[])
{
    // Usado para exibir a consulta
    std::string searchStr;
    // Usado para fazer a consulta
    QString searchTitleStr;
    // Indica se filtramos por type
    bool hasType = false;
    // Tipo filtrado
    QString typeStr;

    // Usado para o loop de mensagens
    QCoreApplication app(argc, argv);

    // Parse dos parametros usados
    for(int count=0; count<argc; count++)
    {
        std::string param = argv[count];
        // Exibir help?
        if( (param == std::string("--help")) || (param == std::string("-h")) || (argc<=1) )
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
        else if( (param == std::string("--type")) || (param == std::string("-t"))  )
        {
            hasType = true;
            count++;
            if(count < argc)
                typeStr = argv[count];
        }
        // Fazer a pesquisa?
        else if( (param == std::string("--search")) || (param == std::string("-s")) )
        {
            while(++count < argc)
            {
                // caso tipo seja solicitado reavalia os parametros
                if( (std::string(argv[count]) == std::string("--type")) || (std::string(argv[count]) == std::string("-t")) )
                {
                    count--;
                    break;
                }

                // Para exibir com espacos
                if(searchStr.size()==0)
                    searchStr.append(argv[count]);
                else
                    searchStr.append(" ").append(argv[count]);

                // Para usar em OMDBAPI com +
                if(searchTitleStr.size()==0)
                    searchTitleStr.append(argv[count]);
                else
                    searchTitleStr.append("+").append(argv[count]);
            }
            std::cout << std::endl << "Procurando no 'omdbapi' por: '" << searchStr << "'" << std::endl << std::endl;
            break;
        }
    }

    // String de resultado da pesquisa
    QString result;

    // Acesso o OMDB API para fazer o search e/ou type
    OmdbApi omdbapi;
    if(hasType)
        result = omdbapi.run(searchTitleStr, typeStr);
    else
        result = omdbapi.run(searchTitleStr, "");

    // Faz o parse do Jason resultante
    ParseJasonResult parse;
    QString output = parse.parseAndFormat(result);

    // Exibe o resultado
    std::cout << output.toStdString() << std::endl;

    // Terminamos
    return 0;
}


