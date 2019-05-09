#include <iostream>
#include <vector>

#include "configurable.h"
#include "filewebserver.h"
#include "filesystemmodel.h"
#include "configurationreader.h"
#include "commandlinereader.h"
#include "boost/program_options.hpp"
#include "htmlcontentgenerator.h"

using namespace std;
int main(int ac, char ** av)
{
    CommandLineReader reader(ac,av);
    Configuration config = reader.configuration();

    FileSystemModel fileSystemModel;
    fileSystemModel.setConfiguration(config);
    std::cout << fileSystemModel.rootDir() << std::endl;

    HTMLContentGenerator htmlGenerator;
    htmlGenerator.setConfiguration(config);
    htmlGenerator.setModel(&fileSystemModel);
    //std::cout<<htmlGenerator.generate("/");

    FileWebServer server;
    server.setConfiguration(config);
    server.setGenerator(&htmlGenerator);
    server.run();

    std::cout << "Hello World!" << std::endl;
    return 0;


}
