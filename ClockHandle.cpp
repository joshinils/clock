#define _USE_MATH_DEFINES
#include <cmath>

#include "ClockHandle.h"
#include <iostream>


ClockHandle::ClockHandle()
{ }

void ClockHandle::init(double r, double tR, double w)
{
	this->_radius = r;
	this->_thickRadius = tR;
	this->_widthDeg = w;
	this->_widthRad = M_PI * w / 180.;
	std::cout << "_radius" << this->_radius <<  " _thickRadius" << this->_thickRadius << " _widthRad" << this->_widthRad << std::endl;
}

void ClockHandle::draw(olc::PixelGameEngine & pge, double angleDeg)
{
	olc::vi2d center{pge.GetDrawTargetWidth() / 2, pge.GetDrawTargetHeight() / 2};

	double angleRad = M_PI * angleDeg / 180.;

	olc::vd2d direction1 = (olc::vd2d{sin(angleRad + this->_widthRad), cos(angleRad + this->_widthRad)}).norm() * this->_thickRadius;
	olc::vd2d direction2 = (olc::vd2d{sin(angleRad - this->_widthRad), cos(angleRad - this->_widthRad)}).norm() * this->_thickRadius;
	olc::vd2d directionR = (olc::vd2d{sin(angleRad), cos(angleRad)}).norm() * this->_radius;

	pge.FillTriangle(center, center + direction1, center + direction2);
	pge.FillTriangle(center + directionR, center + direction1, center + direction2);
}
