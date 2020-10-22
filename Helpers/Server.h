//
// Created by Salihcan Kahya on 22.10.2020.
//

#ifndef _MULTIPLAYERGAMESERVER_SERVER_H
#define _MULTIPLAYERGAMESERVER_SERVER_H
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

class Server {
    public:
        Server(const char* server_ip, const int server_port, sockaddr_in socket_info);
        Server(const char* server_ip, const int server_port);
        void startServer();
        bool IsAlive();

protected:
    bool m_isAlive = false;
    const char* m_serverIP;
    int m_serverPORT;
    int m_serverSD;
    struct sockaddr_in m_serverSADDR;

    void establishServer();
    void bindServer();
    void listenServer();
    void startServerLoop();
    virtual bool checkServerLimitations();
    private:
        int m_maxServerRoom = 1000;
        //Server room list
        //Add new room
        //close room


};


#endif //_MULTIPLAYERGAMESERVER_SERVER_H
