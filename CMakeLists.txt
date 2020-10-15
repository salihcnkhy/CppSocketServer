# cmake_minimum_required(VERSION <specify CMake version here>)
project(CppSocketServer)

set(CMAKE_CXX_STANDARD 14)

include_directories(.idea)
include_directories(Client)
include_directories(cmake-build-debug)
include_directories(Server)

add_executable(CppSocketServer
        .idea/.gitignore
        .idea/CppSocketServer.iml
        .idea/misc.xml
        .idea/modules.xml
        .idea/vcs.xml
        .idea/workspace.xml
        Client/Client.cpp
        Client/Client.h
        Server/Server.cpp
        Server/Server.h
        .gitignore
        CMakeLists.txt
        main.cpp)
