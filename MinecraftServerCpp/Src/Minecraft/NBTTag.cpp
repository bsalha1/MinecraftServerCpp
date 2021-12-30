#include "Minecraft/NBTTag.h"
#include "Minecraft/NBTList.h"
#include "Packet/PacketEncoder.h"
#include "Buffer.h"

using namespace Minecraft;

NBTTag::NBTTag(NBTType type, std::string name, boost::any value)
{
	Type = type;
	Name = name;
	Value = value;
}

NBTTag::NBTTag(NBTType type, std::string name)
{
	Type = type;
	Name = name;
}

NBTTag::NBTTag()
{
	Type = NBTType::UNKNOWN;
	Name = "NONE";
}

void NBTTag::Serialize(Packet& packet) const
{
	PacketEncoder::WriteByte((uint8_t)Type, packet);
	PacketEncoder::WriteNBTString(Name, packet);

	switch (Type)
	{
	case NBTType::TAG_BYTE:
		PacketEncoder::WriteByte(boost::any_cast<int8_t>(Value), packet);
		break;
	case NBTType::TAG_SHORT:
		PacketEncoder::WriteShort(boost::any_cast<int16_t>(Value), packet);
		break;
	case NBTType::TAG_INT:
		PacketEncoder::WriteInt(boost::any_cast<int32_t>(Value), packet);
		break;
	case NBTType::TAG_LONG:
		PacketEncoder::WriteLong(boost::any_cast<int64_t>(Value), packet);
		break;
	case NBTType::TAG_FLOAT:
		PacketEncoder::WriteFloat(boost::any_cast<float>(Value), packet);
		break;
	case NBTType::TAG_DOUBLE:
		PacketEncoder::WriteDouble(boost::any_cast<double>(Value), packet);
		break;
	case NBTType::TAG_STRING:
		PacketEncoder::WriteString(boost::any_cast<std::string>(Value), packet);
		break;
	case NBTType::TAG_BYTE_ARRAY:
	{
		Buffer<int8_t> arr = boost::any_cast<Buffer<int8_t>>(Value);
		PacketEncoder::WriteInt((uint32_t)arr.GetCurrentSize(), packet);
		PacketEncoder::WriteByteArray((uint8_t*)arr.GetArray(), arr.GetCurrentSize(), packet);
		break;
	}
	case NBTType::TAG_INT_ARRAY:
	{
		Buffer<int32_t> arr = boost::any_cast<Buffer<int32_t>>(Value);
		PacketEncoder::WriteInt((uint32_t)arr.GetCurrentSize(), packet);
		PacketEncoder::WriteIntArray((uint32_t*)arr.GetArray(), arr.GetCurrentSize(), packet);
		break;
	}
	case NBTType::TAG_LONG_ARRAY:
	{
		Buffer<int64_t> arr = boost::any_cast<Buffer<int64_t>>(Value);
		PacketEncoder::WriteInt((uint32_t)arr.GetCurrentSize(), packet);
		PacketEncoder::WriteLongArray((uint64_t*)arr.GetArray(), arr.GetCurrentSize(), packet);
		break;
	}
	case NBTType::TAG_LIST:
	{
		NBTList nbt_list = boost::any_cast<NBTList>(Value);
		PacketEncoder::WriteByte((uint8_t)nbt_list.GetType(), packet);
		PacketEncoder::WriteInt((uint32_t)nbt_list.GetElements().size(), packet);
		for (NBTTag tag : nbt_list.GetElements())
		{
			tag.Serialize(packet);
		}
		break;
	}
	case NBTType::TAG_COMPOUND:
	{
		NBTTagCompound nbt_compound = boost::any_cast<NBTTagCompound>(Value);
		nbt_compound.Serialize(packet);
		break;
	}
	}
}

std::string NBTTag::GetName()
{
	return Name;
}

NBTType NBTTag::GetType()
{
	return Type;
}

boost::any NBTTag::GetValue()
{
	return Value;
}