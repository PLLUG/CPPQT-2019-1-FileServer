#ifndef COMMANDLINEREADER_H
#define COMMANDLINEREADER_H

#include "configurationreader.h"

class CommandLineReader : public ConfigurationReader
{
public:
    CommandLineReader(int argumentsCount, char ** argumentList);

    // ConfigurationReader interface
public:
    virtual Configuration configuration() override;

private:
    Configuration mConfig;
};

#endif // COMMANDLINEREADER_H
