#include "Packet.h"

Packet::Packet()
{
	Length = 0;
	Offset = 0;
	Data = NULL;
}

Packet::Packet(size_t length)
{
	Length = length;
	Offset = 0;
	Data = NULL;
}

void Packet::AddByte(uint8_t byte)
{
	Data[Offset++] = byte;
}

uint8_t Packet::PopByte()
{
	return Data[Offset++];
}

uint8_t Packet::GetCurrentByte()
{
	return Data[Offset];
}
