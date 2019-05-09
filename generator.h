#ifndef GENERATOR_H
#define GENERATOR_H

#include "dataview.h"
#include <string>

class Generator : public DataView
{
public:
    virtual ~Generator() = default;
    virtual std::string generate(const std::string &path) = 0;
};

#endif // GENERATOR_H
