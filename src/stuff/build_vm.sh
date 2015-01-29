#!/bin/bash - 
g++ -I/usr/local/src/v8/include/ vm.cpp -o vm -Wl,--start-group /usr/local/src/v8/out/native/obj.target/{tools/gyp/libv8_{base,libbase,snapshot,libplatform},third_party/icu/libicu{uc,i18n,data}}.a -Wl,--end-group -lrt -pthread
