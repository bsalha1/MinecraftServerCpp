#pragma once

#include <iostream>

#include "Packet/Packet.h"

namespace Minecraft {

	class Serializable
	{
	public:
		virtual void Serialize(Packet& packet) const = 0;
	};
}

