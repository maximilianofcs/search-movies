#ifndef OMDBAPI_H
#define OMDBAPI_H

#include <QObject>
#include "IOmdbApi.h"

class OmdbApi : public IOmdbApi
{
public:
    OmdbApi();

public:
    // Implementacao da interface IOmdbApi
    virtual QString run(QString search, QString type);
};

#endif // OMDBAPI_H
