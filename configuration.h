#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <string>
#include "fsizeenum.h"

class Configuration
{
private:
    int mPort = 8080;
    std::string mDir;
    bool mIsFileDownloadingEnabled = false;
    FSizeEnum mFsizeDisplayingMode = FSizeEnum::BYTES;
    bool mIsIconColumnVisible = false;
    bool mIsFileSizeColumnVisible = false;
    bool mIsDetailedInfoColumnVisible = false;

public:
    Configuration();

    int port() const;
    void setPort(int port);

    std::string dir() const;
    void setDir(const std::string &dir);

    bool isFileDownloadingEnabled() const;
    void setIsFileDownloadingEnabled(bool isFileDownloadingEnabled);

    FSizeEnum fsizeDisplayingMode() const;
    void setFsizeDisplayingMode(const FSizeEnum &fsizeDisplayingMode);

    bool isIconColumnVisibility() const;
    void setIsIconColumnVisibility(bool isIconColumnVisibility);

    bool isIconColumnVisible() const;
    void setIsIconColumnVisible(bool isIconColumnVisible);

    bool isFileSizeColumnVisible() const;
    void setIsFileSizeColumnVisible(bool isFileSizeColumnVisible);

    bool isDetailedInfoColumnVisible() const;
    void setIsDetailedInfoColumnVisible(bool isDetailedInfoColumnVisible);
};

#endif // CONFIGURATION_H


