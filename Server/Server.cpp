//
// Created by Salihcan Kahya on 15.10.2020.
//
#include "Server.h"

namespace SocketServer {

    Server::Server(const char *server_ip, const int server_port, sockaddr_in socket_info) :
            m_serverIP(server_ip),
            m_serverPORT(server_port),
            m_serverSADDR(socket_info) {}

    Server::Server(const char *server_ip, const int server_port) :
            m_serverIP(server_ip),
            m_serverPORT(server_port) {
        memset(&this->m_serverSADDR, 0, sizeof(this->m_serverSADDR));
        this->m_serverSADDR.sin_family = AF_INET;
        this->m_serverSADDR.sin_addr.s_addr = htonl(INADDR_ANY);
        this->m_serverSADDR.sin_port = htons(this->m_serverPORT);
    }

    bool Server::IsAlive() {
        return this->m_isAlive;
    }

    void Server::startServer() {
        this->establishServer();
        this->bindServer();
        this->listenServer();
        this->startServerLoop();
    }

    void Server::establishServer() {
        this->m_serverSD = socket(AF_INET, SOCK_STREAM, 0);
        if (this->m_serverSD < 0) {
            perror("Error Occurred at ESTABLISH SERVER");
            throw Error::EstablishConnection;
        }
    }

    void Server::bindServer() {
        int bindStatus = bind(this->m_serverSD,
                              (struct sockaddr *) &this->m_serverSADDR,
                              sizeof(this->m_serverSADDR));

        while (bindStatus < 0) {
            this->m_serverPORT += 1;
            this->m_serverSADDR.sin_port = htons(this->m_serverPORT);

            if (bindStatus < 0) {
                int i = 0;
                perror("Error Occurred at BIND SERVER ");

            }
            bindStatus = bind(this->m_serverSD,
                              (struct sockaddr *) &this->m_serverSADDR,
                              sizeof(this->m_serverSADDR));
        }
    }

    void Server::listenServer() {
        int listenStatus = listen(this->m_serverSD, this->m_maxClientCount);
        if (listenStatus < 0) {
            throw Error::ListenServer;
        }


    }

    void Server::startServerLoop() {
        std::cout << "SERVER IS RUNNING ON-> " << this->m_serverIP << ":" << this->m_serverPORT << std::endl;
        this->m_isAlive = true;
        std::thread([&] {
            while (1) {
                if (!this->checkServerIsFull()) {
                    PlayerClient *client = acceptClients();
                    if (client != nullptr) {
                        this->addClient(client);
                    }
                } else {
                    perror("Server Is Full");
                    throw Error::ServerIsFull;
                }
            }
        }).detach();
    }

    PlayerClient *Server::acceptClients() {

        GameObject gameObject;

        PlayerClient *client = new PlayerClient(gameObject);
        if (client->establishClient(this->m_serverSD, (struct sockaddr *) &this->m_serverSADDR) < 0) {
            return nullptr;
        }
        return client;
    }

    bool Server::checkServerIsFull() {
        return (this->m_clients.size() + 1) > this->m_maxClientCount;
    }

    void Server::addClient(PlayerClient *client) {
        std::cout << "New PlayerClient Connected" << std::endl;
        this->m_clients[client] = std::thread([=] {
            std::string client_ip(inet_ntoa(client->getClientSADDR().sin_addr));
            std::string client_port(std::to_string(ntohs(client->getClientSADDR().sin_port)));
            int len;
            char message_buffer[this->m_maxMessageSize];
            while ((len = recv(client->getClientSD(), message_buffer, this->m_maxMessageSize, 0)) > 0) {
                message_buffer[len] = '\0';
                //// MESSAGETYPE : {actionType: 'movement', action: { position: {x:2,y:3,z:4}} }

                //// TODO: Parse message here with message handler
                std::string message(client_ip + ":" + client_port + " > " + message_buffer);
                std::cout << message << std::endl;
                std::memset(message_buffer, '\0', sizeof(message_buffer));
                sendMessageToAllClients(message,client);
            }
            std::cout << "PlayerClient Disconnected" << std::endl;
            this->m_clients.erase(this->m_clients.find(client));
        });
        this->m_clients[client].detach();
    }

    void Server::sendMessageToAllClients(std::string &message, PlayerClient* sender) {
        for (auto &client : this->m_clients) {
            if(sender != client.first){
                //// MESSAGETYPE : {id: playerSD, actionType: 'movement', action: { position: {x:2,y:3,z:4}} }
                std::string playerID = std::to_string(sender->getClientSD());
                playerID.insert(0,"{playerID:");
                playerID.append("}");

                message.insert(1,playerID);
                this->sendMessage(message, client.first->getClientSD());
            }
        }
    }
    void Server::sendMessage(std::string &message, int clientSD){
            if(send(clientSD,(char*) &message, sizeof(message),0) < 0) {
                perror("Error Occurred while send message");
            }
    }
}