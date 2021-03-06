//
// Created by Salihcan Kahya on 15.10.2020.
//

#ifndef Client_H
#define Client_H
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
#include "../GameObject/GameObject.h"

namespace SocketClient{

    class PlayerClient{

    private:
        GameObject gameObject;
        //socket descriptor
        int m_clientSD;
        //socket address
        struct sockaddr_in m_clientSADDR;
        socklen_t m_socklen;

    public:
        PlayerClient(GameObject gameObject): gameObject(gameObject){
            this->m_socklen = sizeof(this->m_clientSADDR);
        }
        int establishClient(int serverSD, sockaddr* serverSADDR);
        int getClientSD() const;
        const sockaddr_in &getClientSADDR() const;
    };
}


#endif //Client_H
