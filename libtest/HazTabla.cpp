#include <fstream>
#include <iostream>

using std::cout;
using std::endl;
using std::fstream;
using std::ofstream;
using std::string; 

int main() {

    string nombreFichero("Tabla.h");
    fstream ficherosalida;

    ficherosalida.open(nombreFichero, std::ios_base::out);
    if (!ficherosalida.is_open()) {
        cout << "No puedo abrir el fichero para escribir: " << nombreFichero << '\n';
    }
    else {
        ficherosalida << "enum class TipoOperciones { ignorar, reintentar, abortar }; " << "\n";
        ficherosalida << "enum class TipoResultados { exito, fracaso, nifunifa }; " << std::endl;

        ficherosalida.close();

        cout << "Fichero " << nombreFichero << " generado." << endl;
    }

    return EXIT_SUCCESS;

}

