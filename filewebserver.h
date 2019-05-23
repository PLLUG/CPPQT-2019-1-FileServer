#ifndef FILEWEBSERVER_H
#define FILEWEBSERVER_H

#include "configurable.h"

class Generator;

class FileSystemModel;

class FileWebServer : public Configurable
{
public:
    FileWebServer();
    virtual ~FileWebServer() override;

    int run();

    // Configurable interface
public:
    virtual void setConfiguration(Configuration configuration) override;

    void setGenerator(Generator *generator);
    void setFileSysemModel(FileSystemModel *fileSysemModel);

private:
    FileSystemModel *mFileSysemModel;
    Generator *mGenerator;
    std::string mServerIP;
    unsigned mPort;
    std::string mPath;
};

#endif // FILEWEBSERVER_H
