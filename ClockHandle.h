#include "olcPixelGameEngine/olcPixelGameEngine.h"

#pragma once
class ClockHandle
{
private:
	double _radius;
	double _thickRadius;
	double _widthRad;
	double _widthDeg;

public:
	ClockHandle();
	void init(double r, double tR, double w);

public:
	void draw(olc::PixelGameEngine& pge, double angleDeg);
};

