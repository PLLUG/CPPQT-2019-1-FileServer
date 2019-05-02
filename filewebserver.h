#ifndef FILEWEBSERVER_H
#define FILEWEBSERVER_H

#include "configurable.h"

class FileWebServer : public Configurable
{
public:
    virtual ~FileWebServer();

    int run();

    // Configurable interface
public:
    virtual void setConfiguration(Configuration configuration) override;

private:
    std::string mServerIP = "127.0.0.1";
    unsigned mPort = 8080;
    std::string mPath = "d://";
};


#endif // FILEWEBSERVER_H
