#pragma once

#include "Slot.h"
#include "Color.h"
#include <boost/any.hpp>

namespace Minecraft {

	class Particle
	{
	private:
		int Id;
		boost::any Data;

	public:
		Particle(int id);
		Particle(int id, Slot slot);
		Particle(int id, Color color);
		Particle(int id, int block_state);
	};
}