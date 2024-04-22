cmake_minimum_required(VERSION 3.16)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

cmake_policy(SET CMP0076 NEW)

set(CMAKE_CXX_FLAGS "-fcoroutines -pthread -fmodules-ts" )

project(ejercicioslibro)

set(SOURCE_FILES
    Vector.cpp
    EjerciciosLibro.cpp
    ficheroPrueba.cpp
	)


add_executable(ejercicioslibro)

target_sources(ejercicioslibro
    PUBLIC
   ${SOURCE_FILES}
)

## 
## Playing with Modules in Ubuntu
## 
## 
## XX_if (UNIX)
## set(SYSTEM_HEADERS_TO_PRECOMPILE
## "filesystem cmath vector string map complex list \
## stdexcept regex fstream iostream chrono thread string_view \
## syncstream bitset functional numeric random coroutine"
## )
## 
## 
## execute_process(
##     COMMAND bash "-c" "${CMAKE_CURRENT_SOURCE_DIR}/compilaCabeceraSistema.sh ${SYSTEM_HEADERS_TO_PRECOMPILE}" 
##     OUTPUT_VARIABLE salidaEstandar
##     ERROR_VARIABLE salidaError
##     RESULT_VARIABLE codigoSalida
##     #OUTPUT_QUIET
##     #ERROR_QUIET
## )
##
## message("${salidaEstandar}")
##
## XX_endif (UNIX)
##
## XX_if (MSVC)
##    # do something
##XX_endif (MSVC)
## 
## 
## 
## set_source_files_properties(Vector.ixx PROPERTIES COMPILE_FLAGS "-x c++")
## set_source_files_properties(Complejo.ixx PROPERTIES COMPILE_FLAGS "-x c++")
## XX_if (WIN32)
##     # do something
## XX_endif (WIN32)
## 

