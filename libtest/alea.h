/*-------------------------------------------------------*/
/*                                                       */
/*   Alea.h: Cabecera del fichero Alea.cpp               */
/*-------------------------------------------------------*/

#ifndef ALEA_H
#define ALEA_H

// Clase que proporciona las facilidades para generar un crc de 16 bits
class cAlea
{
private:

  // Semilla utilizada para generar claves aleatorias
  long semilla;

public:
/*
------------------------------------------------------------------------------
* -- cAlea::cAlea --
*
*  DESCRIPCION:
*	Constructor de la clase Alea. Inicializa la semilla
*
*  PARAMETROS
*	const long valor (IN): valor inicial de la semilla
*
*  RETORNO
*	Objeto creado.
*
------------------------------------------------------------------------------
*/
  cAlea(const long valor=2345678901);

/*
------------------------------------------------------------------------------
* -- cAlea::~cAlea --
*
*  DESCRIPCION:
*	Destructor de la clase
*
*  PARAMETROS
*	Ninguno.
*
*  RETORNO
*	Nada.                                                          z
*
------------------------------------------------------------------------------
*/
  ~cAlea();

/*
------------------------------------------------------------------------------
* -- cAlea::IniSemilla --
*
*  DESCRIPCION:
*       Inicializa la semilla utilizada en la generaci¢n de claves
*
*  PARAMETROS
*	const long valor (IN) : valor con el que se inicializa la semilla
*
*  RETORNO
*       Nada
*
------------------------------------------------------------------------------
*/
  void IniSemilla(const long valor);


/*
------------------------------------------------------------------------------
* -- cAlea::AleaSemilla --
*
*  DESCRIPCION:
*       Inicializa la semilla aleatoriamente en funci¢n de la fecha
*
*  PARAMETROS
*	Ninguno
*
*  RETORNO
*       Nada
*
------------------------------------------------------------------------------
*/
  void AleaSemilla();


/*
------------------------------------------------------------------------------
* -- cAlea::DameSemilla --
*
*  DESCRIPCION:
*       Devuelve el valor actual de la semilla
*
*  PARAMETROS
*	Ninguno
*
*  RETORNO
*       Valor actual de la semilla (long)
*
------------------------------------------------------------------------------
*/
  long DameSemilla();


/*
------------------------------------------------------------------------------
* -- cAlea::DameAleatorio --
*
*  DESCRIPCION:
*       Devuelve un valor aletorio.
*
*  PARAMETROS
*	Ninguno
*
*  RETORNO
*       Devuelve un valor aleatorio
*
------------------------------------------------------------------------------
*/
  double DameAleatorio();


/*
------------------------------------------------------------------------------
* -- cAlea::DameAleaMargen --
*
*  DESCRIPCION:
*       Devuelve un valor aleatorio entre (0 y (par metro - 1))
*
*  PARAMETROS
*	const unsigned int MaxVal (IN) : Valor m ximo hasta el que quiero
*				el valor aleatorio
*
*  RETORNO
*       Valor aleatorio entre 0 y (MaxVal -1)
*
------------------------------------------------------------------------------
*/
  unsigned int DameAleaMargen (const unsigned int MaxVal);

};

#endif

