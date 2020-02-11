#include "Aether.h"

//#include <stdlib.h>
//#include <fstream>
//#include <string>
//#include <sstream>


Aether::Aether()
{

}

Aether::~Aether()
{

}

bool Aether::OnUserCreate()
{
	olc::PixelGameEngine::SetPixelMode(olc::Pixel::ALPHA);
	std::cout << __FUNCTION__ << std::endl;

	return true;
}

bool Aether::OnUserUpdate(float fElapsedTime)
{
	Clear(olc::BLACK);

	int s = 90;
	for (int x = -s; x < s; x++)
	{
		for (int y = -s; y < s; y++)
		{
			Draw(x, y, olc::YELLOW);
		}
	}

	return true;
}
