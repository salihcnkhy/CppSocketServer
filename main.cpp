#include <iostream>
#include "Server/Server.h"
int main() {

    Variables::BaseClass::Vector3<int> vector3int = Variables::BaseClass::Vector3<int>(1,2,3);

    SocketServer::Server* server = new SocketServer::Server("localhost", 3001);
    server->startServer();
    while(server->IsAlive());
    return 0;
}
