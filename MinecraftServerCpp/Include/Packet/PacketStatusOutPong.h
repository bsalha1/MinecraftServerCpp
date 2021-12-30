#pragma once

#include "Packet/OutPacket.h"

namespace Minecraft {

	class PacketStatusOutPong : OutPacket
	{
	private:
		long Payload;

	public:
		PacketStatusOutPong(long payload);

		struct Packet BuildPacket() const override;
	};
}

