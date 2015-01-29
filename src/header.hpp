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

#ifndef HTTP_NUBE_HEADER_HPP
#define HTTP_NUBE_HEADER_HPP

#include <string>

namespace nube {

struct header
{
  std::string name;
  std::string value;
};

} // namespace nube

#endif // HTTP_NUBE_HEADER_HPP
