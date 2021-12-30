#pragma once

#include <list>
#include "NBTTag.h"
#include "Enums.h"

namespace Minecraft {

	class NBTList
	{
	private:
		NBTType Type;
		std::list<NBTTag> Elements;

	public:
		NBTList(NBTType type);
		NBTList();

		void AddElement(NBTTag tag);

		NBTType GetType();
		std::list<NBTTag> GetElements();
	};
}