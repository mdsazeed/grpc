# Sample Client-Server model of GRPC using Proto file and CMake to compile required libraries and files.

Took Reference from 
https://github.com/chungphb/grpc-cpp/blob/master/sample/

Both Client and Server were running on a Docker Container.

# Project Folder : Server

Server
|__CMakeLists.txt
|__src
   |__server.cc
   |__client.cc
|__proto
   |__hello.proto
|__build
   |__<all built files>


CMakeLists.txt - Add required dependencies for proto compilation, GRPC compilation, cpp file compilation, etc

proto - Google proto file having client, server and rpc service

server.cc - create server

client.cc - create client

Build Steps:

go to build path (server/build) and run

$ cmake ..
$ make

Open two terminals, 1 for each client and server
$ ./server  (starts server and listening)

$ ./client (client process send and receive request-response via defined rpc)


# grpc
GRPC Client &amp; Server model using CPP
