//
// Created by Salihcan Kahya on 22.10.2020.
//

#ifndef _MULTIPLAYERGAMESERVER_SERVERROOM_H
#define _MULTIPLAYERGAMESERVER_SERVERROOM_H
#include "Server.h"
#include "../Client/PlayerClient/PlayerClient.h"

using namespace SocketClient;

class ServerRoom : protected Server {

private:

    int m_maxClientCount = 10000;
    int m_maxMessageSize = 1000;
    std::map<PlayerClient*, std::thread> m_clients;
    void addClient(PlayerClient* client);
    void sendMessageToAllClients(std::string &message, PlayerClient* sender);
    void sendMessage(std::string &message, int clientSD);
    PlayerClient* acceptClients();
    bool checkServerLimitations() override;

};


#endif //_MULTIPLAYERGAMESERVER_SERVERROOM_H
