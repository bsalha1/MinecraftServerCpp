#pragma once

#include "SocketServer.h"
#include "Packet/Packet.h"
#include "Minecraft/Enums.h"

class PacketHandler
{
private:

	Minecraft::State State;
	SocketServer Server;
	SOCKET ClientSocket;

	void SendPacketLength(uint32_t length);

	void HandleHandshakePacket(uint32_t packetId, struct Packet packet);
	void HandleHandshakeIn(struct Packet& packet);

    void HandleStatusPacket(uint32_t packetId, struct Packet packet);
	void HandleStatusInRequest(struct Packet& packet);
	void HandleStatusInPing(struct Packet& packet);

public:
	PacketHandler() = default;
	PacketHandler(SocketServer socketServer, SOCKET clientSocket);
	void HandlePacket(struct Packet packet);

};

