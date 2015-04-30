// Vector.h
// Vector Klassendefinition

#ifndef VEKTOR_H
#define VEKTOR_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000





//extern Type Zero;
template <class Type> class Vektor
{
  protected:
    Type *a;
    int Size;

      // Statische (Klassen-) Variablen
      // ------------------------------

      // Zeiger auf Funktion zur Fehlerbehandlung
    static void (*ErrHdlr)(char*);

      // Default-Fehlerbehandlung
    static void DefaultErrHdlr(char* Msg)
	{
       std::cout << "Vektor Fehler: " << Msg << "\n";
    };

      // Fehler Flag: 1 = letzte Operation fehlerhaft
    static char ErrFlag;

  public:
      // Erzeugen eines Vektors mit 'n' Elementen
//    friend class CVektor;
	friend class RVektor;
	friend class RMatrix;
//	friend class CMatrix;
//	friend class RealSignal;
//	friend class CmplxSignal;
    Vektor();
    Vektor( int n );

      // Konstruktor kopieren
    Vektor(const Vektor&);

      // Erzeugen eines Vektors mit 2 Elementen
    Vektor( Type x1, Type x2  )
    {
      Size = 2;
      a = new Type[ Size ];
      a[0] = x1; a[1] = x2;
    }
      // Erzeugen eines Vektors mit 3 Elementen
    Vektor( Type x1, Type x2, Type x3 )
    {
      Size = 3;
      a = new Type[ Size ];
      a[0] = x1; a[1] = x2; a[2] = x3;
    }
      // Destruktor
    ~Vektor()
    {
      delete [Size]a;
    }
      // Zuweisungs-Operator
    Vektor& operator=(const Vektor&);

	void SetDim(int nDim);//Löschen und neue Dimension
      // Index Operator
    Type& operator[]( int n ) const
    {
      if ( n>=0 && n<Size )
        return *(a+n);
      else
      {
        Error( "ungültiger Index" );
        return *(a);
      }
    }
      // Nur-Lese Index Operator, fr konstante Objekte (const)
    const Type& Elem( int n ) const
    {
      if ( n>=0 && n<Size )
        return a[n];
      else
      {
        Error( "ungültiger Index" );
        return a[0];
      }
    }

      // Operatoren, die das Objekt modifizieren
      // ---------------------------------------
      // Multiplikation mit Skalar: v *= r
    Vektor& operator*=(const float&);
    Vektor& operator*=(const Type&);

      // Division durch Skalar: v /= r
    Vektor& operator/=(const float&);
    Vektor& operator/=(const Type&);

      // Addition eines Vektors: v += w
    Vektor& operator+=(const Vektor&);

      // Subtraktion eines Vektors: v -= w
    Vektor& operator-=(const Vektor&);

	  // Neue Dimension setzen
	 void SetDimension(int nDim);

      // Konstante Operatoren
      // --------------------

      // Un„res Minus: -v
    Vektor  operator-() const;

      // Vektor*Skalar: v * r
    Vektor  operator*(const float&) const;
    Vektor  operator*(const Type&) const;

      // Vektor/Skalar: v / r
    Vektor  operator/(const float&) const;
    Vektor  operator/(const Type&) const;

      // Vektor*Vektor: v*w
    Vektor   operator*(const Vektor& w) const;

      // Vektor+Vektor: v+w
    Vektor  operator+(const Vektor& w) const;

      // Vektor-Vektor: v-w
    Vektor  operator-(const Vektor& w) const;

      // Vergleich zweiter Vektoren: v==w
    int operator==(const Vektor& w) const;
    int operator!=(const Vektor& w) const
      { return ! (*this==w); }

      // Prüfen ob die letzte Operation zu einem Fehler führte
    static int Error()
    {
      int Result = ErrFlag;
      ErrFlag = 0;
      return Result;
    }
      // Fehlermeldung ausgeben
    static void Error( char *Msg )
    {
      ErrFlag = 1;
      if ( ErrHdlr && Msg )
                  ErrHdlr( Msg );
    };
      // Routine zur Fehlerbehandlung setzen
    static void SetErrHdlr( void (*Hdlr)(char*) = 0 ) //const
    {
      ErrHdlr = Hdlr;
    };


/*      // Rückgabe des Minimums aller Elemente
    Type Min() const;

      // Rückgabe des Maximus aller Elemente
    Type Max() const;

      // Rückgabe des Mittelwertes aller Elemente
    float Mean() const;  */

      // Rückgabe der Anzahl der Elemente
    int nElems() const { return Size; }

};

//typedef Vektor<Type> *VektorPtr;
// Ausgabe zu einem ostream
std::ostream& operator<<(std::ostream& os,  const Vektor<Type>& v);

// Eingabe von einem istream
std::istream& operator>>(std::istream& is,  Vektor<Type>& v );

//template<class Type>
//Vektor<Type> operator*(const Type& t,const Vektor<Type>& v);

  // ErrHdlr ist eine statische Elementfunktion
  // zu einer void Funktion mit char* Argument
//template<class Type>
//void (*Vektor<Type>::ErrHdlr)(char*) = Vektor<Type>::DefaultErrHdlr;
//template<class Type>
//char Vektor<Type>::ErrFlag = 0;
//----------------------------------------------------------------
//-------------------------------------------------------------------
/*
template<class Type>
Vektor<Type> Vektor<Type>::operator*(const Type& t,const Vektor<Type>& v)
{ return v * t; }
*/
//-------------------------------------------------------------------
#endif
// eof Vektor.h
