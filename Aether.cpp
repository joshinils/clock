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

double getSeconds()
{
	using namespace std;
	// current date/time based on current system
	time_t now = time(0);
	tm ltm;
	localtime_s(&ltm, &now);

	unsigned __int64 milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
	unsigned __int64 seconds = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();

	return ltm.tm_sec + (milliseconds - seconds*1000)/1000.;
}

double getMinutes()
{
	using namespace std;
	// current date/time based on current system
	time_t now = time(0);
	tm ltm;
	localtime_s(&ltm, &now);

	unsigned __int64 milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
	unsigned __int64 seconds = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();

	return ltm.tm_min + (ltm.tm_sec + (milliseconds - seconds*1000)/1000.)/60.;
}

double getHours()
{
	using namespace std;
	// current date/time based on current system
	time_t now = time(0);
	tm ltm;
	localtime_s(&ltm, &now);

	unsigned __int64 milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
	unsigned __int64 seconds = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();

	return ltm.tm_hour + (ltm.tm_min + (ltm.tm_sec + (milliseconds - seconds*1000)/1000.)/60.)/60.;
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
	this->_secondHandle.draw(*this, -getSeconds() * 6 + 180);
	this->_minuteHandle.draw(*this, -getMinutes() * 6 + 180);
	this->_hourHandle  .draw(*this, -getHours() / 12 * 360 + 180);

	return true;
}

void Aether::init()
{
	if(this->_isInited)
	{
		return;
	}
	this->_isInited = true;
	double secondLength = 0.9;
	double minuteLength = 0.8;
	double hourLength = 0.6;
	double shrinkage = 0.8;

	this->_secondHandle.init(secondLength * std::min(GetDrawTargetHeight(), GetDrawTargetWidth()) / 2, shrinkage * secondLength * std::min(GetDrawTargetHeight(), GetDrawTargetWidth()) / 2, 1.5);
	this->_minuteHandle.init(minuteLength * std::min(GetDrawTargetHeight(), GetDrawTargetWidth()) / 2, shrinkage * minuteLength * std::min(GetDrawTargetHeight(), GetDrawTargetWidth()) / 2, 2);
	this->_hourHandle.init  (hourLength   * std::min(GetDrawTargetHeight(), GetDrawTargetWidth()) / 2, shrinkage * hourLength   * std::min(GetDrawTargetHeight(), GetDrawTargetWidth()) / 2, 4);
}
