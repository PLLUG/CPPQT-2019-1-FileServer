#ifndef COMMANDLINEREADER_H
#define COMMANDLINEREADER_H

#include "configurationreader.h"

class CommandLineReader : public ConfigurationReader
{
public:
    CommandLineReader();

    // ConfigurationReader interface
public:
    virtual Configuration configuration() override;

};

#endif // COMMANDLINEREADER_H
