#include "commandlinereader.h"
#include <boost/program_options.hpp>

#include <iostream>
#include "fsizeenum.h"
#include <fstream>

CommandLineReader::CommandLineReader(int argumentsCount, char **argumentList)
{

    boost::program_options::options_description optionDescription("Allowedoptions");
    optionDescription.add_options()
        ("help", "Produce help message")
        ("about", "output README information")
        ("port", boost::program_options::value<int>(), "The TCP/IP port that the server instance should use to connect to clients. The default value is 8080")
        ("dir", boost::program_options::value<std::string>(), "Root folder that will be available on server. This parameter cannot be ommited and has no default value")
        ("dpermission", boost::program_options::value<bool>(), "Enable\\disable ability to download files The default value is \"enable\"")
        ("fsize", boost::program_options::value<std::string>(), "Specify the file size displaying mode The default value is \"bytes\" \
                                                                  May take value:  BYTES, KILOBYTES, MEGABYTES, AUTOMATICALLY ")
        ("vicon", boost::program_options::value<bool>(), "Visibility of displaying icon column The default value is \"false\"")
        ("vsize", boost::program_options::value<bool>(),"Visibility of file size column  The default value is \"false\"")
        ("vinfo", boost::program_options::value<bool>(),"Visibility of detailed information column The default value is \"false\"")
        ("config", boost::program_options::value<std::string>(), "Read options from config file config.cfg")
        ;


    boost::program_options::variables_map vm, vm1;

    try {

    boost::program_options::store(boost::program_options::parse_command_line(argumentsCount,
                                                                             argumentList,
                                                                             optionDescription),
                                  vm);
    boost::program_options::notify(vm);

    if (vm.count("help"))
    {
        std::cout << optionDescription << std::endl;
    }

    if (vm.count("about"))
    {
        std::string const ReadMePath = "./readme.md";

        std::ifstream readMeFile;
        readMeFile.open(ReadMePath);
        if(!readMeFile.is_open())
        {
            std::cout<<"file \"readme.md\" not found"<<std::endl;
        }
        else
        {
            std::string stringReadMe;
            while (!readMeFile.eof())
            {
                //readMeFile>>stringReadMe;
                std::getline(readMeFile, stringReadMe);
                std::cout<<stringReadMe<<std::endl;
            }

        }
        readMeFile.close();
    }

    if(vm.count("config"))
    {
        std::string path=vm["config"].as<std::string>();
        boost::program_options::store(boost::program_options::parse_config_file(path.c_str(),optionDescription),vm);
    }

    if (vm.count("port"))
    {
        std::cout<<"Port: "<<vm["port"].as<int>()<<std::endl;
        mConfig.setPort(vm["port"].as<int>());
    }

    if(vm.count("fsize"))
    {
        std::cout<<"fsize kurva: "<<vm["fsize"].as<std::string>()<<std::endl;
        if("BYTES"==vm["fsize"].as<std::string>())
        {
            mConfig.setFsizeDisplayingMode(FSizeEnum::BYTES);
        }
        else
            if ("MEGABYTES"==vm["fsize"].as<std::string>())
            {
                mConfig.setFsizeDisplayingMode(FSizeEnum::MEGABYTES);
            }
            else
            if ("AUTOMATICALLY"==vm["fsize"].as<std::string>())
            {
                mConfig.setFsizeDisplayingMode(FSizeEnum::AUTOMATICALLY);
            }
            else {
                mConfig.setFsizeDisplayingMode(FSizeEnum::KILOBYTES);
            }
    }

    if (vm.count("dir"))
    {
        std::cout<<"Dir: "<<vm["dir"].as<std::string>()<<std::endl;
        mConfig.setDir(vm["dir"].as<std::string>());
    }

    if(vm.count("dpermission"))
    {
        std::cout<<"dpermission "<<vm["dpermission"].as<bool>()<<std::endl;
        mConfig.setIsFileDownloadingEnabled(vm["dpermission"].as<bool>());
    }

    if(vm.count("vicon"))
    {
        std::cout<<"vicon "<<vm["vicon"].as<bool>()<<std::endl;
        mConfig.setIsIconColumnVisible(vm["vicon"].as<bool>());
    }

    if(vm.count("vsize"))
    {
        std::cout<<"vsize "<<vm["vsize"].as<bool>()<<std::endl;
        mConfig.setIsFileSizeColumnVisible(vm["vsize"].as<bool>());
    }

    if(vm.count("vinfo"))
    {
        std::cout<<"vinfo "<<vm["vinfo"].as<bool>()<<std::endl;
        mConfig.setIsDetailedInfoColumnVisible(vm["vinfo"].as<bool>());
    }


   }
   catch(std::exception& ex)
   {
        std::cout << optionDescription << std::endl;
   }

}

Configuration CommandLineReader::configuration()
{
    return mConfig;
}
