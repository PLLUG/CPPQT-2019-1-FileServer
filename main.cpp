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
