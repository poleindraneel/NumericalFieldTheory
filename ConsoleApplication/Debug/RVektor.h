#ifndef RVEKTOR_H
#define RVEKTOR_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef  CMPLX_H
#include "cmplx.h"
#endif

typedef REAL Type;

#ifndef VEKTOR_H
#include "Vector.h"
#endif

class RVektor : public Vektor<REAL>
{

public:
	 RVektor();
     RVektor(int n);
     RVektor(const RVektor &aVec):Vektor<REAL>(aVec){};
     RVektor(REAL a, REAL b):Vektor<REAL>(a,b){};
     RVektor(REAL a, REAL b, REAL c):Vektor<REAL>(a,b,c){};

	 void SetZero();//Vektor auf Null setzen
	 REAL Norm();   //Betrag des Vektors

#ifndef MY_KONSOL_APP
	 void Serialize(CArchive& a);
#endif

	 RVektor& operator/=(const double aDouble);
	 RVektor& operator-=(const RVektor& aVec);

	 //Operatoren die nicht verändern
	 RVektor operator-(const RVektor& aVec);

     //RVektor  operator=(const Vektor<REAL>& aVec);
     //RVektor  operator=(const RVektor& aVec);
};
//-----------------------------------------------------
// Stream Ausgabe

std::ostream& operator<<(std::ostream& os, const RVektor& m);

// Stream Eingabe

std::istream& operator>>(std::istream& is, RVektor& m);

#endif