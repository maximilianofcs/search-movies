#ifndef IOMDBAPI_H
#define IOMDBAPI_H

#include <QString>

//
// Interface para o OMDB API
//
struct IOmdbApi
{
    virtual QString run(QString search, QString type) = 0;
};


#endif // IOMDBAPI_H
