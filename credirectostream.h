#ifndef CREDIRECTOSTREAM_H
#define CREDIRECTOSTREAM_H
#include <stdio.h>

class CRedirectOStream
{
    CRedirectOStream (const CRedirectOStream &) = delete;
    CRedirectOStream & operator = (const CRedirectOStream &) = delete;
public:
    explicit CRedirectOStream(FILE * stream);
    ~CRedirectOStream();
private:
    FILE * newStream;
};

#endif // CREDIRECTOSTREAM_H
