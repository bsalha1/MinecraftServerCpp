#include "Minecraft/UUID.h"

using namespace Minecraft;

UUID::UUID(char bigEndianBytes[16])
{
	for (int i = 0; i < 16; i++)
	{
		Bytes[i] = bigEndianBytes[i];
	}

	Msb =
		(uint64_t)Bytes[15] << 56 |
		(uint64_t)Bytes[14] << 48 |
		(uint64_t)Bytes[13] << 40 |
		(uint64_t)Bytes[12] << 32 |
		(uint64_t)Bytes[11] << 24 |
		(uint64_t)Bytes[10] << 16 |
		(uint64_t)Bytes[9] << 8 |
		(uint64_t)Bytes[8] << 0;

	Lsb =
		(uint64_t)Bytes[7] << 56 |
		(uint64_t)Bytes[6] << 48 |
		(uint64_t)Bytes[5] << 40 |
		(uint64_t)Bytes[4] << 32 |
		(uint64_t)Bytes[3] << 24 |
		(uint64_t)Bytes[2] << 16 |
		(uint64_t)Bytes[1] << 8 |
		(uint64_t)Bytes[0] << 0;
}

UUID::UUID()
{
	Msb = 0;
	Lsb = 0;
}

std::string UUID::ToString()
{
	char str[37] = {};
	sprintf_s(str,
		"%02x%02x%02x%02x-%02x%02x-%02x%02x-%02x%02x-%02x%02x%02x%02x%02x%02x",
		Bytes[0], Bytes[1], Bytes[2], Bytes[3], Bytes[4], Bytes[5], Bytes[6], Bytes[7],
		Bytes[8], Bytes[9], Bytes[10], Bytes[11], Bytes[12], Bytes[13], Bytes[14], Bytes[15]
	);

	return str;
}

/*std::ostream& operator<<(std::ostream& os, UUID uuid)
{
	os << uuid.to_string();
	return os;
}*/

bool Minecraft::operator==(const UUID& lhs, const UUID& rhs)
{
	return lhs.Msb == rhs.Msb && lhs.Lsb == rhs.Lsb;
}

bool Minecraft::operator<(const UUID& uuid1, const UUID& uuid2)
{
	if (uuid1.Msb > uuid2.Msb)
	{
		return true;
	}
	else if (uuid1.Msb < uuid2.Msb)
	{
		return false;
	}
	else if (uuid1.Lsb > uuid2.Lsb)
	{
		return true;
	}

	return false;
}
