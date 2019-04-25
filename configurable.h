#ifndef CONFIGURABLE_H
#define CONFIGURABLE_H

#include "configuration.h"

class Configurable
{
public:
    virtual void setConfiguration(Configuration configuration) = 0;
    virtual ~Configurable() =default;
};
#endif // CONFIGURABLE_H
