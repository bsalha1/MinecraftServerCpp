#include "Minecraft/Particle.h"

using namespace Minecraft;

Particle::Particle(int id)
{
	Id = id;
}

Particle::Particle(int id, Slot data)
{
	Id = id;
	Data = data;
}

Particle::Particle(int id, Color color)
{
	Id = id;
	Data = color;
}

Particle::Particle(int id, int block_state)
{
	Id = id;
	Data = block_state;
}
