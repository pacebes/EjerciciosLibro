cmake_minimum_required(VERSION 3.16)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(PREBUILT_MODULE_PATH ${CMAKE_BINARY_DIR}/modules)

cmake_policy(SET CMP0076 NEW)

set(CMAKE_CXX_FLAGS "-fcoroutines -pthread -fmodules-ts" )

#set(CMAKE_CXX_FLAGS "-fcoroutines -pthread -fmodules-ts -fmodule-mapper=|@g++-mapper-server -r${CMAKE_CURRENT_BINARY_DIR}" )


project(ejercicioslibro)

set(SOURCE_FILES
    Vector.ixx
    Complejo.ixx
    EjerciciosLibro.cpp
    ficheroPrueba.cpp
	)

include_directories(.)

##add_executable(ejercicioslibro ${SOURCE_FILES})

add_executable(ejercicioslibro)

target_sources(ejercicioslibro
    PUBLIC
   ${SOURCE_FILES}
)

if (WIN32)
    # do something
endif (WIN32)

if (UNIX)
set(SYSTEM_HEADERS_TO_PRECOMPILE
"filesystem cmath vector string map complex list \
stdexcept regex fstream iostream chrono thread string_view \
syncstream bitset functional numeric random coroutine"
)


execute_process(
    COMMAND bash "-c" "${CMAKE_CURRENT_SOURCE_DIR}/compilaCabeceraSistema.sh ${SYSTEM_HEADERS_TO_PRECOMPILE}" 
    OUTPUT_VARIABLE salidaEstandar
    ERROR_VARIABLE salidaError
    RESULT_VARIABLE codigoSalida
    #OUTPUT_QUIET
    #ERROR_QUIET
)

message("${salidaEstandar}")

endif (UNIX)

if (MSVC)
    # do something
endif (MSVC)


target_precompile_headers(ejercicioslibro PRIVATE ${HEADER_FILES})

set_source_files_properties(Vector.ixx PROPERTIES COMPILE_FLAGS "-x c++")
set_source_files_properties(Complejo.ixx PROPERTIES COMPILE_FLAGS "-x c++")
#set(CMAKE_CXX_FLAGS "-fcoroutines -pthread -std=c++20 -fmodules-ts -x c++-system-header iostream" )
#set(CMAKE_CXX_FLAGS "-fcoroutines -pthread -std=c++20 -fmodules-ts" )

