//
// Created by Salihcan Kahya on 15.10.2020.
//

#ifndef Server_H
#define Server_H
#ifdef __APPLE__
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#endif
#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#endif
#include <string>
#include <unistd.h>
#include <iostream>
#include <vector>
#include <map>
#include <thread>
#include <poll.h>

#include "ErrorCode.h"
#include "../Client/PlayerClient.h"
#include "../Client/Variables/Variable.h"

namespace SocketServer{

    using namespace SocketClient;

    class Server{
    public:
        Server(const char* server_ip, const int server_port, sockaddr_in socket_info);
        Server(const char* server_ip, const int server_port);
        void startServer();
        bool IsAlive();

    private:

        const char* m_serverIP;
        int m_serverPORT;
        int m_serverSD;
        int m_maxClientCount = 10000;
        int m_maxMessageSize = 1000;
        struct sockaddr_in m_serverSADDR;
        bool m_isAlive = false;
        std::map<PlayerClient*, std::thread> m_clients;

        void establishServer();
        void bindServer();
        void listenServer();
        PlayerClient* acceptClients();
        void startServerLoop();

        bool checkServerIsFull();

        void addClient(PlayerClient* client);
        void sendMessageToAllClients(std::string &message, PlayerClient* sender);
        void sendMessage(std::string &message, int clientSD);

        bool isClientConnected(int clientSD);
        bool is_client_closed(int clientSD);
    };
}





#endif //Server_H
