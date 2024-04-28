#pragma once
#include <sstream> 
#include <string> 

#if defined(UTILIZA_LIBRERIAS_COMPARTIDAS)
#	if defined(_WIN32)
#  		if defined(EXPORTAMOS_ENA)
#    		define DECLSPEC __declspec(dllexport)
#  		else
#    		define DECLSPEC __declspec(dllimport)
#  		endif
#	else // non windows
#  	define DECLSPEC
#	endif
#endif

#if defined(UTILIZA_LIBRERIAS_COMPARTIDAS)
	extern void DECLSPEC escribeNumeroAleatorio(std::ostream& os, std::string mensaje);
#else
	extern void escribeNumeroAleatorio(std::ostream& os, std::string mensaje);
#endif


