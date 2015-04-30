// ConsoleApplication.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

#ifndef CMPLX_H
#include "cmplx.h"
#endif

#ifndef RVEKTOR_H
#include "RVektor.h"
#endif

#ifndef RMATRIX_H
#include "RMatrix.h"
#endif

int _tmain(int argc, _TCHAR* argv[])
{
	int a;
	printf("\n\nMy super program\n\n");
	Cmplx z(1,2);
	cout<<"z = " << z << "\n";

	RVektor aVec(1,2,3);
	RVektor bVec(4,5,6);
	RVektor cVec(7,8,9);
	cout<<"aVec = " << aVec << "\n";

	RMatrix aMa(3,3);
	aMa[0] = aVec;
	aMa[1] = bVec;
	aMa[2] = cVec;

	cout<<"aMa = \n" << aMa << "\n";

	// define the matrix
	int indexN = 5; // N=5
	RMatrix matrixLmn(indexN, indexN); // define matrix 5x5
	cout<<"myMatrix0 = \n" << matrixLmn << "\n";
	int i;
	int k;
	for(i = 0; i<indexN; i++)
	{
		
		for(k=0; k<indexN; k++)
		{
			if( i == k)
			{
			     matrixLmn[i][k] = 2*(indexN + 1);
			}
		   if(abs(i - k) == 1)
		   {
			matrixLmn[i][k] = -(indexN + 1);
		   }
	    }// end inner for

	}// end outer for
	
	cout<<"myMatrixNew = \n" << matrixLmn << "\n";

	// define the vector
	RVektor v(indexN); // define vector 5
	for(int m = 1; m < indexN + 1; m++)
	{
		double ad = (((4*m*m + 1.0/3)/((indexN+1)*(indexN+1))) + 1.0)*(1.0/(indexN + 1));
		v[m - 1] = ad; 
	}

	cout<<"Vector v = \n" << v << "\n";

	RVektor aRes;
	aRes = RealGaussElimination(matrixLmn, v);

	cout<<"Solution = \n" << aRes << "\n";


	cin>> a;
}

