#include <iostream>
#include "SocketServer.h"
#include "Packet/PacketHandler.h"
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>

#pragma comment (lib, "Ws2_32.lib")

PacketHandler PackHandler;

void PacketRecvCallback(Packet packet) {

    PackHandler.HandlePacket(packet);
}

int main() {
    
    std::cout << "Starting Minecraft Server...\n";
    
    SocketServer socketServer;
    socketServer.InitializeServer();
    
    while (true) {
        SOCKET clientSocket = socketServer.WaitForClient();
        PackHandler = PacketHandler(socketServer, clientSocket);
        socketServer.StartClientThread(clientSocket, PacketRecvCallback);

        if (shutdown(clientSocket, SD_SEND) == SOCKET_ERROR) {
            printf("shutdown failed with error: %d\n", WSAGetLastError());
            closesocket(clientSocket);
            WSACleanup();
            return -1;
        }
        closesocket(clientSocket);
    }

    return 0;
}
