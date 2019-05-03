#ifndef FILEWEBSERVER_H
#define FILEWEBSERVER_H

#include "configurable.h"

class FileWebServer : public Configurable
{
public:
    FileWebServer();
    virtual ~FileWebServer() override;

    int run();

    // Configurable interface
public:
    virtual void setConfiguration(Configuration configuration) override;

private:
    std::string mServerIP;
    unsigned mPort;
    std::string mPath;
};

#endif // FILEWEBSERVER_H
