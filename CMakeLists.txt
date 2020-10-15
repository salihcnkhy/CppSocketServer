cmake_minimum_required(VERSION 3.17)
project(_MultiplayerGameServer)

set(CMAKE_CXX_STANDARD 14)

add_executable(_MultiplayerGameServer main.cpp Server/Server.h Server/Server.cpp Client/Client.cpp Client/Client.h)