#include <iostream>
#include <vector>

#include "configurable.h"
#include "filewebserver.h"
#include "filesystemmodel.h"
#include "configurationreader.h"

int main()
{
    FileWebServer server;

    //ConfiguratioReader reader;

    //Configuration c = reader.configuration();

    FileSystemModel fileSystemModel;

    std::cout << "Hello World!" << std::endl;
    return 0;
}
