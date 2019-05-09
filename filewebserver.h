#ifndef FILEWEBSERVER_H
#define FILEWEBSERVER_H

#include "configurable.h"

class Generator;

class FileWebServer : public Configurable
{
public:
    virtual ~FileWebServer();

    int run();

    // Configurable interface
public:
    virtual void setConfiguration(Configuration configuration) override;

    void setGenerator(Generator *generator);
private:
    std::string mServerIP = "127.0.0.1";
    unsigned mPort = 8080;
    std::string mPath = "d://";
    Generator *mGenerator = nullptr;
};


#endif // FILEWEBSERVER_H
