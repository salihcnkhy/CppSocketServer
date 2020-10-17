//
// Created by Salihcan Kahya on 15.10.2020.
//

#include "PlayerClient.h"

namespace SocketClient{
    PlayerClient::PlayerClient() {
        this->m_socklen = sizeof(this->m_clientSADDR);
    }

    int PlayerClient::establishClient(int serverSD, sockaddr* serverSADDR) {
        this->m_clientSD = accept(serverSD, serverSADDR, &this->m_socklen);
        return m_clientSD;
    }

    int PlayerClient::getClientSD() const {
        return m_clientSD;
    }

    const sockaddr_in &PlayerClient::getClientSADDR() const {
        return m_clientSADDR;
    }
}