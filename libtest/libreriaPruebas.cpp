#include <sstream> 
#include <iostream> 
#include <string> 
#include <limits>  // Required to avoid "incomplete type used in nested name specifier" in ubuntu
#include "libreriaPruebas.h" 
#ifdef UTILIZA_ALEA
#include "alea.h" 
#else
#include <cstdlib>
#endif

// using namespace std;
	
void escribeNumeroAleatorio(std::ostream& os, std::string mensaje)
{
#ifdef UTILIZA_ALEA
	cAlea numAleatorio;
	numAleatorio.AleaSemilla();
	unsigned int maxUI = std::numeric_limits<unsigned int>::max();
	

	os << "ALEA: " << mensaje << " " << numAleatorio.DameAleaMargen(maxUI) << std::endl;
#else

#if defined(TIENE_COUT) && defined(TIENE_RAND)
	os << "NOALEA: " << mensaje << " " << std::rand() << endl;
#else
	os << "ESTO NO PUEDE PASAR PORQUE SIEMPRE TENDRAN COUT Y std::rand()" endl;
#endif

#endif

}

