#pragma once

#include "Serializable.h"
#include "NBTTagCompound.h"

namespace Minecraft {

	class Slot : Serializable
	{
	private:
		short Id;
		uint8_t Count;
		short Data;
		NBTTagCompound Nbt;

	public:
		Slot();

		Slot(short id, int count, short data, NBTTagCompound nbt);

		void Serialize(Packet& packet) const override;

		short GetID();
		uint8_t GetCount();
		short GetData();
		NBTTagCompound GetNBT();

		std::string ToString();
	};
}