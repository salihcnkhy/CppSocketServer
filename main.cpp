#include <iostream>
#include "Server/Server.h"

int main() {

    SocketServer::Server* server = new SocketServer::Server("localhost/game_1", 3001);
    server->startServer();
    while(server->IsAlive());
    return 0;
}
