#!/bin/bash - 
g++ -I/usr/local/src/v8/include/ -I /usr/local/include/ connection.cpp mime_types.cpp main.cpp reply.cpp request_handler.cpp request_parser.cpp server.cpp \
    -pthread -lboost_system -lboost_thread \
    -Wl,--start-group /usr/local/src/v8/out/native/obj.target/{tools/gyp/libv8_{base,libbase,snapshot,libplatform},third_party/icu/libicu{uc,i18n,data}}.a \
    -Wl,--end-group -lrt \
    -o nube
