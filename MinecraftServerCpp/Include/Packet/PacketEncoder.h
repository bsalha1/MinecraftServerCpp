#pragma once

#include <iostream>

#include "Packet/Packet.h"
#include "Minecraft/Slot.h"

class PacketEncoder
{
public:

	static void IntToBigEndianBytes(uint32_t num, uint8_t bytes[sizeof(uint32_t)]);

	// VarInt //
	static void WriteVarInt(int value, uint8_t* data, size_t& offset);
	static void WriteVarInt(int value, Packet& packet);
	static int GetVarIntNumBytes(int value);
	static int GetVarIntNumBytes(std::initializer_list<int> values);


	// Arrays //
	static void WriteByteArray(uint8_t* bytes, int length, Packet& packet);
	static void WriteIntArray(uint32_t* ints, int length, Packet& packet);
	static void WriteLongArray(uint64_t* longs, int length, Packet& packet);


	// Strings //
	static void WriteString(char* string, Packet& packet);
	static void WriteString(std::string string, Packet& packet);
	static void WriteNBTString(std::string string, Packet& packet);
	static int GetStringNumBytes(std::string string);
	static int GetStringNumBytes(std::initializer_list<std::string> values);


	// Basic Types //
	static void WriteBoolean(bool value, Packet& packet);
	static void WriteByte(uint8_t num, Packet& packet);
	static void WriteShort(uint16_t num, Packet& packet);
	static void WriteInt(uint32_t num, Packet& packet);
	static void WriteLong(uint64_t num, Packet& packet);
	static void WriteDouble(double num, Packet& packet);
	static void WriteFloat(float num, Packet& packet);


	// Special Types //
	static void WritePosition(int x, int y, int z, Packet& packet);
};