#include "credirectostream.h"

CRedirectOStream::CRedirectOStream(FILE * stream)
{
    errno_t err;
        err = freopen_s(&newStream, "error.txt", "a", stream);
        if (err != 0)
            fprintf(stdout, "error on freopen\n");
}

CRedirectOStream::~CRedirectOStream()
{
    fclose(newStream);
}
