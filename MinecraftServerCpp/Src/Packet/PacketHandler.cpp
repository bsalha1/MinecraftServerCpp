#include "Packet/PacketHandler.h"
#include "Packet/PacketDecoder.h"
#include "Packet/PacketEncoder.h"
#include "Packet/PacketStatusOutResponse.h"
#include "Packet/PacketStatusOutPong.h"
#include "Packet/PacketStatusInRequest.h"
#include "Packet/PacketStatusInPing.h"
#include <iostream>


void LogDebug(std::string message) {

    std::cout << "[D] " << message << std::endl;
}

PacketHandler::PacketHandler(SocketServer socketServer, SOCKET clientSocket)
{
    Server = socketServer;
    ClientSocket = clientSocket;
    State = Minecraft::State::HANDSHAKE;
}

void PacketHandler::SendPacketLength(uint32_t length) {

    Packet packetLengthPacket(PacketEncoder::GetVarIntNumBytes(length));
    packetLengthPacket.AllocateData();
    PacketEncoder::WriteVarInt(length, packetLengthPacket);
    
    Server.SendData(ClientSocket, packetLengthPacket.Data, packetLengthPacket.Length);
    
    packetLengthPacket.DeallocateData();
}

void PacketHandler::HandlePacket(struct Packet packet) {

    uint32_t packetLength = PacketDecoder::ReadVarInt(packet);
    int32_t packetId = PacketDecoder::ReadVarInt(packet);

    LogDebug(">>> Length: " + std::to_string(packetLength));
    LogDebug(">>> ID: " + std::to_string(packetId));
    
    switch (State) {
        case Minecraft::State::HANDSHAKE:
            HandleHandshakePacket(packetId, packet);
            break;

        case Minecraft::State::STATUS:
            HandleStatusPacket(packetId, packet);
            break;
   
    }
}

void PacketHandler::HandleHandshakePacket(uint32_t packetId, struct Packet packet)
{
    switch (packetId) {
        case 0x00:
            HandleHandshakeIn(packet);
            break;
    }
}

void PacketHandler::HandleHandshakeIn(struct Packet& packet) {

    LogDebug(">>> Handling HandshakeIn");

    uint32_t protocolVersion = PacketDecoder::ReadVarInt(packet);
    std::string serverAddress = PacketDecoder::ReadString(packet);
    uint16_t serverPort = PacketDecoder::ReadShort(packet);
    Minecraft::State nextState = (Minecraft::State) PacketDecoder::ReadByte(packet);

    State = nextState;
}

void PacketHandler::HandleStatusPacket(uint32_t packetId, struct Packet packet)
{
    switch (packetId) {
        case 0x00:
            HandleStatusInRequest(packet);
            break;
        case 0x01:
            HandleStatusInPing(packet);
            break;
    }
}

void PacketHandler::HandleStatusInRequest(struct Packet& packet) {

    LogDebug(">>> Handling StatusInRequest");

    // Read Packet
    PacketStatusInRequest pack;
    pack.ReadPacket(packet);

    // Construct Packet
    std::string version = "1.8.8";
    int protocol = 47;
    int maxPlayers = 20; 
    int onlinePlayers = 0;
    std::string description = "Minecraft Server in C++!";
    std::string favicon = "";
    PacketStatusOutResponse response(version, protocol, maxPlayers, onlinePlayers, description, favicon);
    struct Packet responsePacket = response.BuildPacket();

    // Send PacketLength
    SendPacketLength(responsePacket.Length);
    
    // Send Packet
    Server.SendData(ClientSocket, responsePacket.Data, responsePacket.Length);
}

void PacketHandler::HandleStatusInPing(struct Packet& packet) {
    
    LogDebug(">>> Handling StatusInPing");

    // Read Packet
    PacketStatusInPing pack;
    pack.ReadPacket(packet);

    // Construct Packet
    PacketStatusOutPong response(pack.GetPayload());
    struct Packet responsePacket = response.BuildPacket();

    // Send PacketLength
    SendPacketLength(responsePacket.Length);

    // Send Packet
    Server.SendData(ClientSocket, responsePacket.Data, responsePacket.Length);
}
