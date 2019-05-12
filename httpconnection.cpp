#include "httpconnection.h"

static std::string mustasheTemplate{R"(<!DOCTYPE html>
                             <html>

                             <head>
                             <title>FileServer</title>
                             <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
                             </head>

                             <body>
                             <p>&nbsp;</p>
                             <h1>File Server</h1>
                             <p>&nbsp;</p>
                             <p>&nbsp;</p>

                             <table style="width:100%">
                             <tbody>
                             <tr>
                             {{#showIcons}}
                             <td>&nbsp;</td>
                             {{/showIcons}}
                             <td><strong>Name</strong></td>
                             {{#showSize}}
                             <td><strong>Size</strong></td>
                             {{/showSize}}
                             {{#showDetails}}
                             <td><strong>Information</strong></td>
                             {{/showDetails}}
                             </tr>

                             {{#dirEntryList}}
                             <tr>
                             {{#showIcons}}
                             <td>{{{fileIcon}}}</td>
                             {{/showIcons}}
                             <td>{{fileName}}</td>
                             {{#showSize}}
                             <td>{{fileSize}}</td>
                             {{/showSize}}
                             {{#showDetails}}
                             <td>{{fileDetails}}</td>
                             {{/showDetails}}
                             </tr>
                             {{/dirEntryList}}
                             </tbody>
                             </table>

                             <p>&nbsp;</p>
                             </body>
                             </html>
                             )"};


http_connection::http_connection(boost::asio::ip::tcp::socket socket,
                                 const std::string &response_html)
    : response(response_html)
    ,socket_(std::move(socket))
    ,buffer_{8192}
    ,deadline_{socket_.get_executor(), std::chrono::seconds(60)}
{
}

void http_connection::start()
{
    read_request();
    check_deadline();
}

void http_connection::set_response(const std::string &_response)
{
    if (!_response.empty() && response != _response)
    {
        response = _response;
    }
}

void http_connection::read_request()
{
    auto self = shared_from_this();

    boost::beast::http::async_read(socket_, buffer_, request_, [self](boost::beast::error_code ec,
                                   std::size_t bytes_transferred)
    {
        boost::ignore_unused(bytes_transferred);
        if (!ec)
        {
            self->process_request();
        }
    });
}

void http_connection::process_request()
{
    response_.version(request_.version());
    response_.keep_alive(false);

    switch (request_.method())
    {
    case boost::beast::http::verb::get:
        response_.result(boost::beast::http::status::ok);
        response_.set(boost::beast::http::field::server, "Beast");
        create_response();
        break;

    default:
        // We return responses indicating an error if
        // we do not recognize the request method.
        response_.result(boost::beast::http::status::bad_request);
        response_.set(boost::beast::http::field::content_type, "text/plain");
        boost::beast::ostream(response_.body())
                << "Invalid request-method '"
                << request_.method_string().to_string()
                << "'";
        break;
    }

    write_response();
}

void http_connection::create_response()
{
    if(request_.target() == "/count")
    {
        response_.set(boost::beast::http::field::content_type, "text/html");
        boost::beast::ostream(response_.body())
                << "<html>\n"
                <<  "<head><title>Request count</title></head>\n"
                 <<  "<body>\n"
                  <<  "<h1>Request count</h1>\n"
                   <<  "<p>There have been "
                    <<  ""
                     <<  " requests so far.</p>\n"
                      <<  "</body>\n"
                       <<  "</html>\n";
    }
    else if(request_.target() == "/time")
    {
        response_.set(boost::beast::http::field::content_type, "text/html");
        boost::beast::ostream(response_.body())
                <<  "<html>\n"
                 <<  "<head><title>Current time</title></head>\n"
                  <<  "<body>\n"
                   <<  "<h1>Current time</h1>\n"
                    <<  "<p>The current time is "
                     <<  "18 00"
                      <<  " seconds since the epoch.</p>\n"
                       <<  "</body>\n"
                        <<  "</html>\n";
    }
    else
    {
        response_.result(boost::beast::http::status::not_found);
        response_.set(boost::beast::http::field::content_type, "text/html");
        boost::beast::ostream(response_.body()) << response.c_str(); //"File not found\r\n";
    }
}

void http_connection::write_response()
{
    auto self = shared_from_this();

    response_.set(boost::beast::http::field::content_length, response_.body().size());

    boost::beast::http::async_write(socket_, response_, [self](boost::beast::error_code ec, std::size_t)
    {
        self->socket_.shutdown(boost::asio::ip::tcp::socket::shutdown_send, ec);
        self->deadline_.cancel();
    });
}

void http_connection::check_deadline()
{
    auto self = shared_from_this();

    deadline_.async_wait([self](boost::beast::error_code ec)
    {
        if (!ec)
        {
            // Close socket to cancel any outstanding operation.
            self->socket_.close(ec);
        }
    });
}
