#ifndef SQUAREPLATE_H
#define SQUAREPLATE_H
#pragma once
class SquarePlate
{
private:
	int nX; // Must be not even
	int nY; // How many SmallSquares are used to approximate the plate
	int nN; // Total number of SmallSquares
	double side; //length of the side in meter
	Vektor<SmallSquare> vPlate; //Plate composed of SmallSquares

public:
	SquarePlate(void);
	~SquarePlate(void);
	void SetSide(const double aSide){side = aSide;}; //Set the side length of the plate
	void CreatePlate(); //Fillup Vektor to describe the plate
};
#endif

