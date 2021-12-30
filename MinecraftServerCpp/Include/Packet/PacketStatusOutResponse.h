#pragma once

#include "Packet/OutPacket.h"
#include <iostream>

namespace Minecraft {

	class PacketStatusOutResponse : OutPacket
	{
	private:
		std::string Version;
		int Protocol;
		int MaxPlayers;
		int OnlinePlayers;
		std::string Description;
		std::string Favicon;

	public:
		PacketStatusOutResponse(std::string version, int protocol, int maxPlayers, int onlinePlayers, std::string description, std::string favicon);

		struct Packet BuildPacket() const override;
	};
}

