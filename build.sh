#!/bin/bash - 
g++ connection.cpp  mime_types.cpp  posix_main.cpp  reply.cpp  request_handler.cpp  request_parser.cpp  server.cpp  win_main.cpp -pthread -lboost_system-mt -lboost_thread-mt -o server
