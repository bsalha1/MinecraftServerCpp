#pragma once

#include <winsock2.h>

#include "Packet/Packet.h"

#define DEFAULT_BUFLEN 1024
#define DEFAULT_PORT "25565"

typedef void (*PacketReceiveCallback)(struct Packet);

class SocketServer
{
private:
	SOCKET ListenSocket;

public:	
	SocketServer();

	void InitializeServer();

	SOCKET WaitForClient();

	void StartClientThread(SOCKET clientSocket, PacketReceiveCallback callback);
	void SendData(SOCKET clientSocket, uint8_t* buffer, int bufferLength);


};

