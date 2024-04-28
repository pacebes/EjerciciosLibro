#include <sstream> 
#include <iostream> 
#include <string> 
#include "libreriaPruebas.h" 
#ifdef UTILIZA_ALEA
#include "alea.h" 
#else
#include <cstdlib>
#endif

using namespace std;
	
void escribeNumeroAleatorio(ostream& os, string mensaje)
{
#ifdef UTILIZA_ALEA
	cAlea numAleatorio;
	numAleatorio.AleaSemilla();
	
	os << "ALEA: " << mensaje << " " << numAleatorio.DameAleaMargen(std::numeric_limits<unsigned int>::max() ) << endl;
#else

#if defined(TIENE_COUT) && defined(TIENE_RAND)
	os << "NOALEA: " << mensaje << " " << std::rand() << endl;
#else
	os << "ESTO NO PUEDE PASAR PORQUE SIEMPRE TENDRAN COUT Y std::rand()" endl;
#endif

#endif

}

