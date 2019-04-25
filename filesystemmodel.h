#ifndef FILESYSTEMMODEL_H
#define FILESYSTEMMODEL_H

#include "configurable.h"
#include "datamodel.h"

#include <vector>

class FileSystemModel : public DataModel, public Configurable
{
    // Configurable interface
public:

    virtual void setConfiguration(Configuration configuration) override;

    // DataModel interface
public:
    virtual int count() const override;
    virtual std::string name(int index) const override;
    virtual int size(int index) const override;
    virtual bool isDir(int index) const override;
    virtual void enter(int index) override;
    virtual void up() override;

    std::string rootDir() const;
    void setRootDir(const std::string &rootDir);

private:
    void enterDirectory(const std::string &path);

private:
    std::string mRootDir;
    std::string mCurrentDir;

    std::vector<std::string> mListFilePathes;
};

#endif // FILESYSTEMMODEL_H
