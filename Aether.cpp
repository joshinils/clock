#include "Aether.h"
#include <iostream>
#include <chrono>
#include <ctime>


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
	this->init();
	Clear(olc::BLACK);
	double t = 0;
	{
		using namespace std;
		// current date/time based on current system
		time_t now = time(0);
		tm ltm;
		localtime_s(&ltm, &now);

		unsigned __int64 milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
		unsigned __int64 seconds = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();

		cout << " Time: "<< ltm.tm_hour << ":";
		cout << ltm.tm_min << ":";
		cout << (t = ltm.tm_sec + (milliseconds - seconds*1000)/1000. )<< endl;
	}
	this->_secondhandle.draw(*this, -t * 6 +180);

	return true;
}

void Aether::init()
{
	if(this->_isInited)
	{
		return;
	}
	this->_isInited = true;
	this->_secondhandle.init(0.9 * std::min(GetDrawTargetHeight(), GetDrawTargetWidth()) / 2, 0.6 * std::min(GetDrawTargetHeight(), GetDrawTargetWidth()) / 2, 5);
}
