#include <iostream>
#include "Server/Server.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    SocketServer::Server* server = new SocketServer::Server("localhost", 3001);
    server->startServer();
    return 0;
}
