#include "Packet/PacketStatusOutPong.h"
#include "Packet/PacketEncoder.h"

using namespace Minecraft;

PacketStatusOutPong::PacketStatusOutPong(long payload)
{
	Payload = payload;
}

Packet PacketStatusOutPong::BuildPacket() const
{
	uint8_t packetId = 0x01;

	struct Packet packet(PacketEncoder::GetVarIntNumBytes(packetId) + sizeof(uint64_t));
	packet.AllocateData();

	PacketEncoder::WriteVarInt(packetId, packet);
	PacketEncoder::WriteLong(Payload, packet);

	return packet;
}
