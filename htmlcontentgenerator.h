#ifndef HTMLCONTENTGENERATOR_H
#define HTMLCONTENTGENERATOR_H

#include "configurable.h"
#include "generator.h"
#include "fsizeenum.h"

class HTMLContentGenerator : public Generator, public Configurable
{
private:
    bool mShowIconsColumn;
    bool mShowSizeColumn;
    bool mShowDetailsConst;
    FSizeEnum mFSizeDisplayMode;

public:
    ~HTMLContentGenerator() override;
    std::string generate(const std::string &path) override;

    // Configurable interface
public:
    virtual void setConfiguration(Configuration configuration) override;

};

#endif // HTMLCONTENTGENERATOR_H
