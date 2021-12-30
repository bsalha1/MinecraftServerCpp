#pragma once

#include "Packet.h"

namespace Minecraft {

	class InPacket {
	public:
		virtual void ReadPacket(struct Packet packet) = 0;
	};
}

