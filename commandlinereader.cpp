#include "commandlinereader.h"

#include <boost/program_options.hpp>

#include <iostream>

CommandLineReader::CommandLineReader(int argumentsCount, char **argumentList)
{
    boost::program_options::options_description optionDescriprion("Allowedoptions");
    optionDescriprion.add_options()
        ("help", "Produce help message")
        ("port", boost::program_options::value<int>(), "The TCP/IP port that the server instance should use to connect to clients. The default value is 8080")
        ("dir",boost::program_options::value<std::string>(),"Root folder that will be available on server. This parameter cannot be ommited and has no default value");

    boost::program_options::variables_map vm;
    boost::program_options::store(boost::program_options::parse_command_line(argumentsCount,
                                                                             argumentList,
                                                                             optionDescriprion),
                                  vm);
    boost::program_options::notify(vm);

    if (vm.count("help"))
    {
        std::cout << optionDescriprion << std::endl;
    }

    if (vm.count("port"))
    {
        mConfig.setPort(vm["port"].as<int>());
    }

    if (vm.count("dir"))
    {
        mConfig.setDir(vm["dir"].as<std::string>());
    }

}

Configuration CommandLineReader::configuration()
{
    return mConfig;
}
