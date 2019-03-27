#include <iostream>
#include <vector>

#include "configurable.h"
#include "filewebserver.h"
#include "filesystemmodel.h"

int main()
{
    FileWebServer server;

    FileSystemModel fileSystemModel;

    std::cout << "Hello World!" << std::endl;
    return 0;
}
