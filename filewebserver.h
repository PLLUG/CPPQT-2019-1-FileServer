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
    const std::string defaultIP = "127.0.0.1";
    const unsigned defaultPort = 8080;
    std::string defaultPath = "d://";
};


#endif // FILEWEBSERVER_H
