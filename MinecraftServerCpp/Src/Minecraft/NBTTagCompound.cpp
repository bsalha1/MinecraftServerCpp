#include "Minecraft/NBTTagCompound.h"
#include "Minecraft/Enums.h"
//#include "StringUtils.h"

#include <typeinfo>

using namespace Minecraft;

NBTTagCompound::NBTTagCompound()
{
}

void NBTTagCompound::AddTag(NBTTag tag)
{
	Tags.push_back(tag);
}

void NBTTagCompound::Serialize(Packet& packet) const
{
	for (auto tag : Tags)
	{
		tag.Serialize(packet);
	}
}

std::string InsertSpaces(int numSpaces)
{
	std::string str = "";

	for (int i = 0; i < numSpaces; i++)
	{
		str += " ";
	}

	return str;
}

std::string NBTTagCompound::ToString()
{
	std::string str = "";

	//std::string spaces = insert_spaces(pretty_pointer);
	//for (auto tag : Tags)
	//{
	//	str += spaces + StringUtils::to_string(tag.get_type()) + "\n";
	//}

	return str;
}

