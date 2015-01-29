//
// Nube
//
// A cloud scripting server based in Google V8 and Boost libraries.
// Nube means cloud in Spanish.
//
// Based on original work by:
// Copyright (c) 2003-2008 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef HTTP_NUBE_SERVER_HPP
#define HTTP_NUBE_SERVER_HPP

#define NUBE_BIND_ADDRESS "127.0.0.1"
#define NUBE_BIND_PORT    "8181"
#define NUBE_NUM_THREADS  "4"
#define NUBE_DOC_ROOT     "/tmp/"

#include <boost/asio.hpp>
#include <string>
#include <vector>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>
#include "connection.hpp"
#include "request_handler.hpp"

namespace nube {

// The top-level class of the server.
class server
  : private boost::noncopyable
{
public:
  // Construct the server to listen on the specified TCP address and port, and
  // serve up files from the given directory.
  explicit server(const std::string& address, const std::string& port,
      const std::string& doc_root, std::size_t thread_pool_size);

  // Run the server's io_service loop.
  void run();

  // Stop the server.
  void stop();

private:
  // Handle completion of an asynchronous accept operation.
  void handle_accept(const boost::system::error_code& e);

  // The number of threads that will call io_service::run().
  std::size_t thread_pool_size_;

  // The io_service used to perform asynchronous operations.
  boost::asio::io_service io_service_;

  // Acceptor used to listen for incoming connections.
  boost::asio::ip::tcp::acceptor acceptor_;

  // The next connection to be accepted.
  connection_ptr new_connection_;

  // The handler for all incoming requests.
  request_handler request_handler_;
};

} // namespace nube

#endif // HTTP_NUBE_SERVER_HPP
