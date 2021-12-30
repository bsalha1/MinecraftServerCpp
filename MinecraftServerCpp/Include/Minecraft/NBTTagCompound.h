#pragma once

#include <iostream>
#include <map>
#include <list>
#include <boost/any.hpp>

#include "Serializable.h"
#include "NBTTag.h"

namespace Minecraft {

	class NBTTagCompound : Serializable
	{
	private:
		int PrettyPointer = 0;
		std::list<NBTTag> Tags;

	public:
		NBTTagCompound();

		void AddTag(NBTTag tag);

		void Serialize(Packet& packet) const override;

		std::string ToString();

	};
}
