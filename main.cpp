#include "Aether.h"
#include <stdlib.h>


int main()
{
	srand(0); // always same
	double scale = 120;
	double sizeW = 16;
	double sizeH = 9;
	Aether world;
	if (world.Construct((uint32_t)(scale*sizeW), (uint32_t)(scale*sizeH), (uint32_t)std::max(1.0, 120 / scale), (uint32_t)std::max(1.0, 120 / scale)))
	{
		world.Start();
	}
	return 0;
}
