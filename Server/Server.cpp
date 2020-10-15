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
            exit(ExitCode::EstablishConnection);
        }
    }

    void Server::bindServer() {
        int bindStatus = bind(this->m_serverSD,
                              (struct sockaddr *) &this->m_serverSADDR,
                              sizeof(this->m_serverSADDR));
        if (bindStatus < 0) {
            perror("Error Occurred at BIND SERVER ");
            exit(ExitCode::BindServer);
        }
    }

    void Server::listenServer() {
        int listenStatus = listen(this->m_serverSD, this->m_maxClientCount);
        if (listenStatus < 0) {
            perror("Error Occurred at LISTEN SERVER ");
            exit(ExitCode::ListenServer);
        }


    }

    void Server::startServerLoop() {
        while (1) {
            if (!this->checkServerIsFull()) {
                Client *client = acceptClients();
                if (client != nullptr) {
                    this->addClient(client);
                }
            }
        }
    }

    Client *Server::acceptClients() {
        Client *client = new Client();
        if (client->establishClient(this->m_serverSD, (struct sockaddr *) &this->m_serverSADDR) < 0) {
            return nullptr;
        }
        return client;
    }

    bool Server::checkServerIsFull() {
        return (this->m_clients.size() + 1) > this->m_maxClientCount;
    }

    void Server::addClient(Client* client) {

        this->m_clients[client] = std::thread([=]{
            std::string client_ip(inet_ntoa(client->getClientSADDR().sin_addr));
            std::string client_port(std::to_string(ntohs(client->getClientSADDR().sin_port)));
            int len;
            char message_buffer[this->m_maxMessageSize];
            while((len = recv(client->getClientSD(),message_buffer,this->m_maxMessageSize,0)) > 0){
                message_buffer[len] = '\0';
                std::string message(client_ip + ":" + client_port + " > " + message_buffer);
                std::cout<< message<< std::endl;
                std::memset(message_buffer, '\0', sizeof (message_buffer));
            }
        });
        this->m_clients[client].detach();

    }

}