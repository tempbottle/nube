#!/bin/bash - 
g++ connection.cpp  -I /usr/local/include/ mime_types.cpp  posix_main.cpp  reply.cpp  request_handler.cpp  request_parser.cpp  server.cpp  -pthread -lboost_system-mt -lboost_thread-mt -lglog -o nube
