#ifndef DATAMODEL_H
#define DATAMODEL_H

#include <string>

class DataModel
{
public:
    virtual ~DataModel() =default;

    virtual int count() const = 0;

    virtual std::string name(int index) const = 0;
    virtual int size(int index) const = 0;
    virtual std::string sizeString(int index) const = 0;
    virtual bool isDir(int index) const = 0;
    virtual void enter(int index) = 0;
    virtual std::string fileLastWriteTime (int index) const=0;

    virtual void up() = 0;
};

#endif // DATAMODEL_H
