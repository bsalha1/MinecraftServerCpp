#pragma once

#include "Packet.h"

namespace Minecraft {

	class OutPacket {

	public:
		virtual struct Packet BuildPacket() const = 0;
	};
}

