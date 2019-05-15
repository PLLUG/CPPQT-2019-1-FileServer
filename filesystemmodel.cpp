#include "filesystemmodel.h"
#include <iostream>
#include <filesystem>
#include <chrono>
#include <ctime>


void FileSystemModel::setConfiguration(Configuration configuration)
{
    setRootDir(configuration.dir());
    mFSizeDisplayMode=configuration.fsizeDisplayingMode();
}

int FileSystemModel::count() const
{
    return mListFilePathes.size();
}

std::string FileSystemModel::name(int index) const
{
    return mListFilePathes.at(index);
}

std::string FileSystemModel::sizeString (int index) const
{
    std::filesystem::path fsPath = mListFilePathes.at(index);
    int fileSize=std::filesystem::file_size(fsPath);
    std::string sizeFileString;
    if (FSizeEnum::BYTES==mFSizeDisplayMode || FSizeEnum::AUTOMATICALLY==mFSizeDisplayMode)
    {
        sizeFileString = std::to_string(fileSize)+" b";
    }
    else
        if (FSizeEnum::KILOBYTES==mFSizeDisplayMode)
        {
            if((fileSize/1024)>0)
            {
                sizeFileString= std::to_string(fileSize/1024)+" Kb";

            }
            else
            {
                sizeFileString= std::to_string(fileSize)+" b";
            }
        }
    if (FSizeEnum::MEGABYTES==mFSizeDisplayMode)
    {
        if((fileSize/1048576)>0)
        {
            sizeFileString= std::to_string(fileSize/1048576)+" Mb";
        }
        else
        {
            if((fileSize/1024)>0)
            {
                sizeFileString= std::to_string(fileSize/1024)+" Kb";
            }
            else
            {
                sizeFileString= std::to_string(fileSize)+" b";
            }
        }
    }
    return sizeFileString;
}

std::string FileSystemModel::fileLastWriteTime(int index) const
{
    std::filesystem::path fsPath = mListFilePathes.at(index);
    std::filesystem::file_time_type ftime = std::filesystem::last_write_time(fsPath);
    std::time_t cftime = decltype(ftime)::clock::to_time_t(ftime);
    std::string ft=std::asctime(std::localtime(&cftime));
    ft.erase(ft.size()-1);
    return ft;
 }

int FileSystemModel::size(int index) const
{
    std::filesystem::path fsPath = mListFilePathes.at(index);        
    return std::filesystem::file_size(fsPath);
}

bool FileSystemModel::isDir(int index) const
{
    std::filesystem::path fsPath = mListFilePathes.at(index);
    return std::filesystem::is_directory(fsPath);
}

void FileSystemModel::enter(int index)
{
    enterDirectory(mListFilePathes.at(index));
}

void FileSystemModel::up()
{
    if (mCurrentDir != mRootDir)
    {
        std::filesystem::path fsPath{mCurrentDir};
        std::filesystem::path parentPath = fsPath.parent_path().string();
        if (parentPath.string() != mRootDir)
        {
            enterDirectory(parentPath.string());
        }
    }
}

std::string FileSystemModel::rootDir() const
{
    return mRootDir;
}

void FileSystemModel::setRootDir(const std::string &rootDir)
{
    mRootDir = rootDir;
    mCurrentDir = rootDir;
    enterDirectory(mRootDir);
}

void FileSystemModel::enterDirectory(const std::string &path)
{
    std::filesystem::path fsPath{path};
    if (std::filesystem::is_directory(fsPath))
    {
        mListFilePathes.clear();

        std::filesystem::path fsPath = path;
        for(auto& entry: std::filesystem::directory_iterator(fsPath))
        {
            mListFilePathes.push_back(entry.path().string());
        }

        mCurrentDir = path;
    }
}
