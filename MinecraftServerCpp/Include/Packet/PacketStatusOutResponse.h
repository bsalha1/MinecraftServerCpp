#pragma once

#include "MCPacket.h"
#include <iostream>

namespace Minecraft {

	class PacketStatusOutResponse : MCPacket
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

		void HandlePacket(struct Packet packet) const override;

		struct Packet BuildPacket() const override;
	};
}

