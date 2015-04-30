#include "stdafx.h"
#include <iostream>

#ifndef RVEKTOR_H
#include "RVektor.h"
#endif

#ifndef SMALLSQUARE_H
#include "SmallSquare.h"
#endif

//---------------------------------------
SmallSquare::SmallSquare(void)
{
	rCenter = RVektor(0.,0.,0.);
	side    = 0.;
}
//---------------------------------------
SmallSquare::~SmallSquare(void)
{
}
//--------------------------------------------
void SmallSquare::MoveTo(const double aX, const double aY)
{
	rCenter.SetX(aX);
	rCenter.SetY(aY);
}
//--------------------------------------------