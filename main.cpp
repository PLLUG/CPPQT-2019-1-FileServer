#include <iostream>
#include <vector>

#include "configurable.h"
#include "filewebserver.h"
#include "filesystemmodel.h"
#include "configurationreader.h"
#include "commandlinereader.h"
#include "boost/program_options.hpp"

using namespace std;
int main(int ac, char ** av)
{
    CommandLineReader reader(ac,av);
    Configuration config = reader.configuration();
    FileWebServer server;
    server.setConfiguration(config);
    server.run();
    //ConfiguratioReader reader;

    //Configuration c = reader.configuration();

//    FileSystemModel fileSystemModel;

    std::cout << "Hello World!" << std::endl;
    return 0;


}
