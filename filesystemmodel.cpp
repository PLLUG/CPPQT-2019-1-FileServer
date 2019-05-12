#include "filesystemmodel.h"

#include <filesystem>

void FileSystemModel::setConfiguration(Configuration configuration)
{
    setRootDir(configuration.dir());
}

int FileSystemModel::count() const
{
    return mListFilePathes.size();
}

std::string FileSystemModel::name(int index) const
{
    return mListFilePathes.at(index);
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
