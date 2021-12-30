#include "Packet/PacketStatusInPing.h"
#include "Packet/PacketDecoder.h"

using namespace Minecraft;

void PacketStatusInPing::ReadPacket(struct Packet packet) {

	Payload = PacketDecoder::ReadLong(packet);
}

long PacketStatusInPing::GetPayload()
{
	return Payload;
}
