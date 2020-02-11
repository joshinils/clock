#ifndef AETHER_H
#define AETHER_H

#include "olcPixelGameEngine/olcPixelGameEngine.h"
#include "ClockHandle.h"

class Aether
	: public olc::PixelGameEngine
{
private:
	ClockHandle _secondHandle;
	ClockHandle _minuteHandle;
	ClockHandle _hourHandle;

public:
	Aether();
	~Aether();

	virtual bool OnUserCreate();
	virtual bool OnUserUpdate(float fElapsedTime);

private:
	bool _isInited = false;
	void init();
};

#endif // AETHER_H
