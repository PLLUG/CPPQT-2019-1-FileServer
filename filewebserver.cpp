#include "filewebserver.h"

#include "boost/program_options.hpp"
#include "boost/beast/version.hpp"
#include "boost/beast/core.hpp"
#include "boost/beast/http.hpp"
#include "boost/asio.hpp"

#include "httpconnection.h"

#include <iostream>

namespace
{
    const size_t SUCCESS = 0;
    const size_t ERROR_UNHANDLED_EXCEPTION = 2;
}

FileWebServer::~FileWebServer()
{
    ///
}

void http_server(boost::asio::ip::tcp::acceptor &acceptor, boost::asio::ip::tcp::socket &socket, const std::string &response_html)
{
    acceptor.async_accept(socket, [&](boost::beast::error_code ec)
    {
        if (!ec)
        {
            std::make_shared<http_connection>(std::move(socket), response_html)->start();
        }
        //        std::cout << "IP address: " << socket.remote_endpoint().address().to_string() << std::endl;
        http_server(acceptor, socket, response_html);
    });
}

int FileWebServer::run()
{
    try
    {
        try
        {
            auto const address = boost::asio::ip::make_address(defaultIP);

            boost::asio::io_context ioc{1};

            boost::asio::ip::tcp::acceptor acceptor{ioc, {address,
                                                          static_cast<unsigned short>(defaultPort)}};
            boost::asio::ip::tcp::socket socket{ioc};

            std::cout << "Server started on " << defaultIP << ":" << defaultPort <<std::endl;
            std::cout << "Working directory is a " << defaultPath <<std::endl;
            http_server(acceptor, socket, defaultPath);
            ioc.run();
        }
        catch (std::exception& e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
            return EXIT_FAILURE;
        }
    }
    catch(std::exception& e)
    {
        std::cerr << "Unhandled Exception reached the top of main: "
                  << e.what() << ", application will now exit" << std::endl;
        return ERROR_UNHANDLED_EXCEPTION;
    }

    return SUCCESS;
}

void FileWebServer::setConfiguration(Configuration /*configuration*/)
{
    ///
}

