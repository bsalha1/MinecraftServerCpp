#include "Minecraft/NBTList.h"

using namespace Minecraft;

NBTList::NBTList(NBTType type)
{
    Type = type;
}

NBTList::NBTList()
{
    Type = NBTType::UNKNOWN;
}

void NBTList::AddElement(NBTTag tag)
{
    Elements.push_back(tag);
}

NBTType NBTList::GetType()
{
    return Type;
}

std::list<NBTTag> NBTList::GetElements()
{
    return Elements;
}
