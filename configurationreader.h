#ifndef CONFIGURATIOREADER_H
#define CONFIGURATIOREADER_H

#include "configuration.h"

class ConfigurationReader
{
public:
    virtual Configuration configuration() = 0;

    virtual ~ConfigurationReader() =default;
};

#endif // CONFIGURATIOREADER_H
