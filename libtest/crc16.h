#ifndef CRC16_H
#define CRC16_H

// Clase que proporciona las facilidades para generar un crc de 16 bits
class cCrc16
{
private:
  // Crc calculado
  unsigned short CrcCalculado;

private:

  // Comentarios en el correspondiente fichero .cpp
  void Inicializa();

  // Comentarios en el correspondiente fichero .cpp
  void Anade(const unsigned char caracter);

  // Comentarios en el correspondiente fichero .cpp
  unsigned short Devuelve();

public:

/*
------------------------------------------------------------------------------
* -- cCrc16::cCrc16 --
*
*  DESCRIPCION:
*	Constructor de la clase Crc16. Inicializa el Crc
*
*  PARAMETROS
*	Ninguno.
*
*  RETORNO
*	Objeto creado.
*
------------------------------------------------------------------------------
*/
  cCrc16();

/*
------------------------------------------------------------------------------
* -- cCrc16::~cCrc16 --
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
  ~cCrc16();


/*
------------------------------------------------------------------------------
* -- cCrc16::CalculaCrc --
*
*  DESCRIPCION:
*       Calcula el Crc de 16 bytes de la cadena que se le pasa como
*       par metro
*
*  PARAMETROS
*	const unsigned char* cadena (IN) : cadena de la que hay que
*			calcular el crc.
*	const unsigned short tamano (IN) : tamano de la cadena anterior
*
*  RETORNO
*       Crc de la cadena
*
------------------------------------------------------------------------------
*/
  unsigned short CalculaCrc(const unsigned char* cadena,
			    const unsigned short tamano);
};

#endif

