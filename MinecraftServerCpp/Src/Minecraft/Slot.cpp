#include "Minecraft/Slot.h"
#include "Packet/PacketEncoder.h"

using namespace Minecraft;

Slot::Slot()
{
	Id = -1;
	Count = -1;
	Data = -1;
}

Slot::Slot(short id, int count, short data, NBTTagCompound nbt)
{
	Id = id;
	Count = count;
	Data = data;
	Nbt = nbt;
}

void Slot::Serialize(Packet& packet) const
{
	PacketEncoder::WriteShort(Id, packet);
	PacketEncoder::WriteByte(Count, packet);
	PacketEncoder::WriteShort(Data, packet);
	Nbt.Serialize(packet);
}

short Slot::GetID()
{
	return Id;
}

uint8_t Slot::GetCount()
{
	return Count;
}

short Slot::GetData()
{
	return Data;
}

NBTTagCompound Slot::GetNBT()
{
	return Nbt;
}

std::string Slot::ToString()
{
	return "[id:" + std::to_string(Id) +
		", count:" + std::to_string(Count) +
		", data:" + std::to_string(Data) + ", nbt:" + Nbt.ToString() + "]";
}