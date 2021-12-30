#pragma once

#include <iostream>

namespace Minecraft {

	class UUID
	{
	private:
		uint8_t Bytes[16] = { 0 };
		uint64_t Msb;
		uint64_t Lsb;

	public:
		UUID(char bigEndianBytes[16]);

		UUID();

		std::string ToString();

		//friend std::ostream& operator<<(std::ostream& os, UUID uuid);

		friend bool operator<(const UUID& lhs, const UUID& rhs);
		friend bool operator==(const UUID& lhs, const UUID& rhs);
	};

}