cmake_minimum_required(VERSION 3.17)
project(_MultiplayerGameServer)

set(CMAKE_CXX_STANDARD 14)

add_executable(_MultiplayerGameServer main.cpp
        Server/Server.h
        Server/Server.cpp
        Client/PlayerClient/PlayerClient.cpp
        Client/PlayerClient/PlayerClient.h
        Helpers/ErrorCode.h
        Helpers/MessageHandler.cpp
        Helpers/MessageHandler.h
        Client/GameObject/GameObject.cpp
        Client/GameObject/GameObject.h
        Helpers/Variables/Variable.h
        Helpers/Variables/Vector/Vector3.cpp
        Helpers/Variables/Vector/Vector3.h Helpers/Server.cpp Helpers/Server.h Helpers/ServerRoom.cpp Helpers/ServerRoom.h)