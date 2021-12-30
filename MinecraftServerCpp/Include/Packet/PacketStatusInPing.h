#pragma once

#include "InPacket.h"

namespace Minecraft {

	class PacketStatusInPing : InPacket
	{
	private:
		long Payload;

	public:
		void ReadPacket(struct Packet packet) override;

		long GetPayload();
	};
}

