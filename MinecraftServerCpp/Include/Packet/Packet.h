#pragma once

#include <stdint.h>

struct Packet
{
	uint8_t* Data;
	size_t Length;
	size_t Offset;

	Packet();
	Packet(size_t length);

	void AllocateData();
	void DeallocateData();

	void AddByte(uint8_t byte);

	uint8_t PopByte();

	uint8_t GetCurrentByte();
};
