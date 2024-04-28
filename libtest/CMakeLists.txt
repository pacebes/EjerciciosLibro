#set(CMAKE_VERBOSE_MAKEFILE ON)

#
# Inclusión del CMake de hacer tablas
#
include(HazTabla.cmake)

#
# Validación de disponibilidad de funciones en el sistema
#
include(CheckCXXSourceCompiles)

check_cxx_source_compiles("
    #include <iostream> 
    int main() {
      std::cout << \"Test\" << std::endl;
      return 0;
   }
" TIENEF_COUT)
 
check_cxx_source_compiles("
    #include <cstdlib>
    int main() {
      std::rand();
      return 0;
    }
" TIENEF_RAND)



  
#
# Indicamos que queremos utilizar la libría local de aleatorización (cambiable con 
# Se puede cambiar con el comando "cmake -DUSE_ALEA=OFF"
#
option(USE_ALEA "Utiliza la función local de aleatorización" ON)

#
# Librería que se crea de pruebas con el fichero incluido
#
add_library(libreriaPruebas libreriaPruebas.cpp)

#
# Se compila con los flags heredados del CMakeList.txt
#
target_link_libraries(libreriaPruebas PUBLIC ejerciciolibro_compiler_flags)


# 
#
#
set_property(TARGET libreriaPruebas PROPERTY VERSION "1.0.0")
set_property(TARGET libreriaPruebas PROPERTY SOVERSION "1")


# Indicamos (si utilizamos librerías dinámicas) que necesitamos PIC 
if (BUILD_SHARED_LIBS)

# Definimos el símbolo que luego se utiliza en libreriaPruebas.h con declspec (dllexport) en windows 
target_compile_definitions(libreriaPruebas PRIVATE "EXPORTAMOS_ENA")

# Establecemos el define UTILIZA_ALEA para que el programa c++ sepa qué hacer
target_compile_definitions(libreriaPruebas PRIVATE "UTILIZA_LIBRERIAS_COMPARTIDAS")

set_target_properties(libreriaPruebas PROPERTIES
                        POSITION_INDEPENDENT_CODE ${BUILD_SHARED_LIBS}
                      )
endif ()				

#
# Solo si utilizamos la librería local de aleatorización 
#
if (USE_ALEA)

# Establecemos el define UTILIZA_ALEA para que el programa c++ sepa qué hacer
target_compile_definitions(libreriaPruebas PRIVATE "UTILIZA_ALEA")

# Compilamos en este caso la libraría adicional .
add_library(libreriaAleaCrc STATIC alea.cpp crc16.cpp 
	${CMAKE_CURRENT_BINARY_DIR}/Tabla.h
	)
			  
if (BUILD_SHARED_LIBS)
set_target_properties(libreriaAleaCrc PROPERTIES
                        POSITION_INDEPENDENT_CODE ${BUILD_SHARED_LIBS}
                      )
endif ()				

					


#
# Añadimos esta línea para que sepa dónde encontrar Tabla.h
#
target_include_directories(libreriaAleaCrc PRIVATE
                             ${CMAKE_CURRENT_BINARY_DIR}
                             )


#
# Añadimos la librería compilada como dependencia de la primaria
#
target_link_libraries(libreriaPruebas PRIVATE libreriaAleaCrc ejerciciolibro_compiler_flags)


endif()



if(TIENEF_COUT AND TIENEF_RAND)
target_compile_definitions(libreriaPruebas
								   PRIVATE "TIENE_COUT" "TIENE_RAND"
								   )
endif()



#
# Indicación de dónde están los includes de las librerías
#
target_include_directories(libreriaPruebas
##                           INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
							INTERFACE
                            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
                            $<INSTALL_INTERFACE:include>						   
                           )

#
# Definición de librerías que se quieren instalar
#
set(librerias_para_instalar libreriaPruebas ejerciciolibro_compiler_flags)

#
# Si se utiliza la local
#
if(TARGET libreriaAleaCrc)
  list(APPEND librerias_para_instalar libreriaAleaCrc)
endif()

#
# Add the necessary information so that other CMake projects can use our project, be it from a build directory, a local install or when packaged.
#
install(TARGETS ${librerias_para_instalar}
        EXPORT libreriaPruebasTargets
        DESTINATION lib)

#
# Se añaden además los ficheros .h que se quieren instalar
#
install(FILES libreriaPruebas.h DESTINATION include)

# install include headers

