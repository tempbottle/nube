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

#ifndef HTTP_NUBE_MIME_TYPES_HPP
#define HTTP_NUBE_MIME_TYPES_HPP

#include <string>

namespace nube {
namespace mime_types {

/// Convert a file extension into a MIME type.
std::string extension_to_type(const std::string& extension);

} // namespace mime_types
} // namespace http

#endif // HTTP_NUBE_MIME_TYPES_HPP
