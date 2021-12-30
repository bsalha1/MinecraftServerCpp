#pragma once

#include "Packet.h"

namespace Minecraft {

	class MCPacket {
	private:
		struct Packet Pack;

	public:
		virtual void HandlePacket(struct Packet packet) const = 0;
		
		virtual struct Packet BuildPacket() const = 0;
	};
}

