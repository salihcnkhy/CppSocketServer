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
#include "../Client/Client.h"
#include <map>
#include <thread>

namespace SocketServer{

    using namespace SocketClient;

    class Server{
    public:
        Server(const char* server_ip, const int server_port, sockaddr_in socket_info);
        Server(const char* server_ip, const int server_port);
        void startServer();

    private:

        const char* m_serverIP;
        const int m_serverPORT;
        int m_serverSD;
        int m_maxClientCount = 10;
        int m_maxMessageSize = 1000;
        struct sockaddr_in m_serverSADDR;

        std::map<Client*, std::thread> m_clients;

        void establishServer();
        void bindServer();
        void listenServer();
        Client* acceptClients();
        void startServerLoop();

        bool checkServerIsFull();

        void addClient(Client* client);
    };
    enum ExitCode{
        EstablishConnection = 5,
        BindServer = 6,
        ListenServer = 7,
    };
}





#endif //Server_H
