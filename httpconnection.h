#ifndef HTTPCONNECTION_H
#define HTTPCONNECTION_H

#include "boost/program_options.hpp"
#include "boost/beast/version.hpp"
#include "boost/beast/core.hpp"
#include "boost/beast/http.hpp"
#include "boost/asio.hpp"

class http_connection : public std::enable_shared_from_this<http_connection>
{
public:
    http_connection(boost::asio::ip::tcp::socket socket,
                    const std::string &response_html = std::string{});

    // Initiate the asynchronous operations associated with the connection.
    void start();

private:
    // Response
    std::string response;

    // The socket for the currently connected client.
    boost::asio::ip::tcp::socket socket_;

    // The buffer for performing reads.
    boost::beast::flat_buffer buffer_{8192};

    // The request message.
    boost::beast::http::request<boost::beast::http::dynamic_body> request_;

    // The response message.
    boost::beast::http::response<boost::beast::http::dynamic_body> response_;

    // The timer for putting a deadline on connection processing.
    boost::asio::basic_waitable_timer<std::chrono::steady_clock> deadline_{
        socket_.get_executor().context(), std::chrono::seconds(60)};

private:
    void set_response(const std::string &_response);

    // Asynchronously receive a complete request message.
    void read_request();

    // Determine what needs to be done with the request message.
    void process_request();

    // Construct a response message based on the program state.
    void create_response();

    // Asynchronously transmit the response message.
    void write_response();

    // Check whether we have spent enough time on this connection.
    void check_deadline();
};


#endif // HTTPCONNECTION_H
