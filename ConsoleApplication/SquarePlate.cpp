#include "stdafx.h"
#include <iostream>


#ifndef RVEKTOR_H
#include "RVektor.h"
#endif

#ifndef SMALLSQUARE_H
#include "SmallSquare.h"
#endif

#ifndef VEKTOR_H
#include "Vector.h"
#endif

#ifndef SQUAREPLATE_H
#include "SquarePlate.h"
#endif

void (*Vektor<SmallSquare>::ErrHdlr)(char*) = Vektor<SmallSquare>::DefaultErrHdlr;
char Vektor<SmallSquare>::ErrFlag = 0;

//-----------------------------------
SquarePlate::SquarePlate(void)
{
	nX   = 5;
	nY   = nX;
	nN   = nX*nY;
	side = 1;
}
//-----------------------------------
SquarePlate::~SquarePlate(void)
{
}
//---------------------------------------
void SquarePlate::CreatePlate()
{
	vPlate.SetDim(nN);
	double delX = side/nX;
	double delY = delX; 
	int iN      = 0;
	for (int iX = -nX/2; iX <= nX/2; iX++)
	{
		for(int iY = -nY/2; iY <= nY/2; iY++)
		{
			double x = delX*iX;
			double y = delY*iY;
			vPlate[iN].MoveTo(x,y);
			vPlate[iN].SetSide(delX);

			iN++;
		}
	}

}