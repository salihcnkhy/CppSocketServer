cmake_minimum_required(VERSION 3.17)
project(_MultiplayerGameServer)

set(CMAKE_CXX_STANDARD 14)

add_executable(_MultiplayerGameServer main.cpp
        Server/Server.h
        Server/Server.cpp
        Client/PlayerClient.cpp
        Client/PlayerClient.h
        Server/ErrorCode.h
        Helpers/MessageHandler.cpp
        Helpers/MessageHandler.h
        Client/GameObject.cpp
        Client/GameObject.h
        Client/Variables/Variable.h
        Client/Variables/Vectors/Vector3.cpp
        Client/Variables/Vectors/Vector3.h)