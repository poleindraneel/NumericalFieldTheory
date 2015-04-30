#ifndef SMALLSQUARE_H
#define SMALLSQUARE_H
#pragma once
class SmallSquare
{
private:
	RVektor rCenter; //Center of the square in meter
	double  side;    //Lenght of a side in meter

public:
	SmallSquare(void);
	~SmallSquare(void);

	void MoveTo(const RVektor& aVec){rCenter = aVec;}; // Moves Center to aVec
	void MoveTo(const double aX, const double aY);     // Moves in the x-y-plane
	void SetSide(const double aSide){side = aSide;};   // Set the side
};
#endif

