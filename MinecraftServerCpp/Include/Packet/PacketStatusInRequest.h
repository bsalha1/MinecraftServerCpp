#pragma once

#include "Packet/InPacket.h"

namespace Minecraft {
	
	class PacketStatusInRequest : InPacket
	{
	public:
		void ReadPacket(struct Packet packet) override;
	};
}

