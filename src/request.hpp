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

#ifndef HTTP_NUBE_REQUEST_HPP
#define HTTP_NUBE_REQUEST_HPP

#include <string>
#include <vector>
#include "header.hpp"

namespace http {
namespace nube {

/// A request received from a client.
struct request
{
  std::string method;
  std::string uri;
  int http_version_major;
  int http_version_minor;
  std::vector<header> headers;
};

} // namespace nube
} // namespace http

#endif // HTTP_NUBE_REQUEST_HPP