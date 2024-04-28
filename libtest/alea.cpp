/*
*=============================================================================
* ---- ALEA.CPP ----
* -------------------
*
*  DESCRIPCION:
*       Este m¢dulo implementa la clase Alea, que genera n£meros aleatorios
*
*  CLASES IMPLEMENTADAS:
*	Alea
*
*=============================================================================
*/
// Para la funcion de aleatorizar la semilla
#include <time.h>

// Includes locales
#include "alea.h"

// Par metros utilizados
const long ParametroA = 48271;
const long ParametroM = 2147483647;  // Es el valor m ximo de un long
const long ParametroQ = ParametroM / ParametroA;
const long ParametroR = ParametroM % ParametroA;
const double ParametroTemp = 1.0 / (double) ParametroM;


// Comentarios en el fichero .h
cAlea::cAlea(const long valor)
{
  semilla = valor;
}

// Comentarios en el fichero .h
cAlea::~cAlea()
{
  // No hay nada que hacer

}

// Comentarios en el fichero .h
void cAlea::IniSemilla(const long valor)
{
  semilla = valor;
}


// Comentarios en el fichero .h
void cAlea::AleaSemilla()
{
  // time_t es un long
  IniSemilla ( (long) time(0));
}

// Comentarios en el fichero .h
long cAlea::DameSemilla()
{
  return (semilla);
}

// Comentarios en el fichero .h
double cAlea::DameAleatorio()
{
  long lo, hi, test;

  hi = semilla / ParametroQ;
  lo = semilla % ParametroQ;
  test = ParametroA * lo - ParametroR * hi;
  semilla = (test > 0) ? (test) : (test + ParametroM);
  return ( (double) semilla * ParametroTemp);
}

unsigned int cAlea::DameAleaMargen (const unsigned int MaxVal)
{
  return ( (unsigned int) ( (double) DameAleatorio() * MaxVal) );
};


