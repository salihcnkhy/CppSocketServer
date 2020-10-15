//
// Created by Salihcan Kahya on 15.10.2020.
//

#include "Client.h"

namespace SocketClient{
    Client::Client() {
        this->m_socklen = sizeof(this->m_clientSADDR);
    }

    int Client::establishClient(int serverSD, sockaddr* serverSADDR) {
        this->m_clientSD = accept(serverSD, serverSADDR, &this->m_socklen);
        return m_clientSD;
    }

    int Client::getClientSD() const {
        return m_clientSD;
    }

    const sockaddr_in &Client::getClientSADDR() const {
        return m_clientSADDR;
    }
}