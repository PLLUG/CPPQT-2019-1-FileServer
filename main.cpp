#include <iostream>
#include <vector>

#include <boost/program_options.hpp>

#include "configurable.h"
#include "filewebserver.h"
#include "filesystemmodel.h"
#include "commandlinereader.h"
#include "configurationreader.h"
#include "htmlcontentgenerator.h"

int main(int ac, char ** av)
{
    CommandLineReader reader(ac,av);
    Configuration config = reader.configuration();

//    FileWebServer server;
//    server.setConfiguration(config);
//    server.run();

    HTMLContentGenerator temp;
    temp.setConfiguration(config);
    temp.generate("/");
    std::cout<< temp.generate("/");
//    ConfiguratioReader reader;

//    Configuration c = reader.configuration();

//    FileSystemModel fileSystemModel;

    std::cout << "Hello World!" << std::endl;
    return 0;
}
