#include "configuration.h"

std::string Configuration::dir() const
{
    return mDir;
}

void Configuration::setDir(const std::string &dir)
{
    mDir = dir;
}

bool Configuration::isFileDownloadingEnabled() const
{
    return mIsFileDownloadingEnabled;
}

void Configuration::setIsFileDownloadingEnabled(bool isFileDownloadingEnabled)
{
    mIsFileDownloadingEnabled = isFileDownloadingEnabled;
}

FSizeEnum Configuration::fsizeDisplayingMode() const
{
    return mFsizeDisplayingMode;
}

void Configuration::setFsizeDisplayingMode(const FSizeEnum &fsizeDisplayingMode)
{
    mFsizeDisplayingMode = fsizeDisplayingMode;
}


bool Configuration::isIconColumnVisible() const
{
    return mIsIconColumnVisible;
}

void Configuration::setIsIconColumnVisible(bool isIconColumnVisible)
{
    mIsIconColumnVisible = isIconColumnVisible;
}

bool Configuration::isFileSizeColumnVisible() const
{
    return mIsFileSizeColumnVisible;
}

void Configuration::setIsFileSizeColumnVisible(bool isFileSizeColumnVisible)
{
    mIsFileSizeColumnVisible = isFileSizeColumnVisible;
}

bool Configuration::isDetailedInfoColumnVisible() const
{
    return mIsDetailedInfoColumnVisible;
}

void Configuration::setIsDetailedInfoColumnVisible(bool isDetailedInfoColumnVisible)
{
    mIsDetailedInfoColumnVisible = isDetailedInfoColumnVisible;
}

Configuration::Configuration()
{

}

void Configuration::setPort(int port)
{
    mPort = port;
}

int Configuration::port() const
{
    return mPort;
}

