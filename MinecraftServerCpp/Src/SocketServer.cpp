#define WIN32_LEAN_AND_MEAN

#include "SocketServer.h"

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>


SocketServer::SocketServer() {
    ListenSocket = INVALID_SOCKET;
}

void SocketServer::InitializeServer() {

    WSADATA wsaData;
    struct addrinfo* result = NULL;
    struct addrinfo hints;
    int ret;

    // Initialize Winsock
    ret = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (ret != 0) {
        std::cout << "WSAStartup failed with error: " << ret << std::endl;
        return;
    }

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;

    // Resolve the server address and port
    ret = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
    if (ret != 0) {
        std::cout << "getaddrinfo failed with error: " << ret << std::endl;
        WSACleanup();
        return;
    }

    // Create a SOCKET for connecting to server
    ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (ListenSocket == INVALID_SOCKET) {
        std::cout << "socket failed with error: " << WSAGetLastError() << std::endl;
        freeaddrinfo(result);
        WSACleanup();
        return;
    }

    // Setup the TCP listening socket
    if (bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen) == SOCKET_ERROR) {
        std::cout << "bind failed with error: " << WSAGetLastError() << std::endl;
        freeaddrinfo(result);
        closesocket(ListenSocket);
        WSACleanup();
        return;
    }

    freeaddrinfo(result);

    if (listen(ListenSocket, SOMAXCONN) == SOCKET_ERROR) {
        std::cout << "listen failed with error: \n" << WSAGetLastError() << std::endl;
        closesocket(ListenSocket);
        WSACleanup();
        return;
    }
}

SOCKET SocketServer::WaitForClient() {

    SOCKET clientSocket = accept(ListenSocket, NULL, NULL);
    if (clientSocket == INVALID_SOCKET)
    {
        printf("accept failed with error: %d\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return INVALID_SOCKET;
    }
    return clientSocket;
}

void SocketServer::StartClientThread(SOCKET clientSocket, PacketReceiveCallback callback) {

    int bytesRead;
    uint8_t recvBuffer[DEFAULT_BUFLEN];
    int recvBufferLength = DEFAULT_BUFLEN;

    do {

        bytesRead = recv(clientSocket, (char*) recvBuffer, recvBufferLength, 0);

        if (bytesRead > 0) {
            
            std::cout << "Bytes received: " << bytesRead << std::endl;
            
            struct Packet packet(bytesRead);
            packet.Data = new uint8_t[bytesRead];
            memcpy(packet.Data, recvBuffer, bytesRead);

            callback(packet);
            
            delete[] packet.Data;
        }
        else if (bytesRead == 0) {
            
            std::cout << "Connection closing..." << std::endl;
        }
        else {

            std::cout << "recv failed with error: " << WSAGetLastError() << std::endl;
            closesocket(clientSocket);
            WSACleanup();
            return;
        }

    } while (bytesRead > 0);
}

void SocketServer::SendData(SOCKET clientSocket, uint8_t* buffer, int bufferLength) {

    int bytesSent = send(clientSocket, (char*) buffer, bufferLength, 0);
    if (bytesSent == SOCKET_ERROR) {
        std::cout << "send failed with error: " << WSAGetLastError() << std::endl;
        closesocket(clientSocket);
        WSACleanup();
        return;
    }
}