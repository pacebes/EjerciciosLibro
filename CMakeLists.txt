#
# Versión mínima de Cmake
#
cmake_minimum_required(VERSION 3.16)

#
# We want to ensure that the debug and release builds use different names for the libraries that will be installed. Let's use d as the postfix for the debug libraries.
# 
set(CMAKE_DEBUG_POSTFIX d)


set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")

option(BUILD_SHARED_LIBS "Build using shared libraries" OFF)



## set(CMAKE_CXX_STANDARD 20)
## set(CMAKE_CXX_STANDARD_REQUIRED ON)
## set(CMAKE_CXX_EXTENSIONS OFF)

#
# Indicamos los flags de compilación 
#
add_library(ejerciciolibro_compiler_flags INTERFACE)
target_compile_features(ejerciciolibro_compiler_flags INTERFACE cxx_std_20)

cmake_policy(SET CMP0076 NEW)

#
# En Unix (con GCC se requieren estos parámetros)
#
if (UNIX)
set(CMAKE_CXX_FLAGS "-fcoroutines -pthread -fmodules-ts" )
endif (UNIX)

#
# Proyecto y versión 
#
project(ejercicioslibro VERSION 1.0)

#
# Se incluye la versión en el fichero "EjerciciosLibro.h" a partir del ".h.in" en el eque se rellena el valor de los defines
#
configure_file(EjerciciosLibro.h.in EjerciciosLibro.h)
						   
#
# En Unix con GCC no se entiende de módulos
#
if (UNIX)
set(SOURCE_FILES
    Vector.cpp
    EjerciciosLibro.cpp
    ficheroPrueba.cpp
	)
endif (UNIX)


#
# En Windows con VCC sí  se entiende de módulos
#
if (WIN32)
set(SOURCE_FILES
    Vector.ixx
	Complejo.ixx
    EjerciciosLibro.cpp
    ficheroPrueba.cpp
	)
endif (WIN32)

#
# Ejecutable
#
add_executable(ejercicioslibro)

#
# El sufijo para Debug
#
set_target_properties(ejercicioslibro PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})

#
# Lista de ficheros fuente
#
target_sources(ejercicioslibro
    PUBLIC
   ${SOURCE_FILES}
)

#
# Lista de ficheros fuente
#
target_link_libraries(ejercicioslibro PUBLIC libreriaPruebas ejerciciolibro_compiler_flags)

#
# Dependencia del subdirectorio con las librerías
#
add_subdirectory(libtest)

#
# Ficheros include del ejecutable
#
target_include_directories(ejercicioslibro PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )


#
# Dónde se instala el ejecutable...
#
install(TARGETS ejercicioslibro DESTINATION bin)

#
# Dónde se instala el fichero de configuración del ejecutable
#
install(FILES "${PROJECT_BINARY_DIR}/EjerciciosLibro.h"
  DESTINATION include
  )
  
#
# Habilitamos pruebsa
#
enable_testing()
## include(CTest)


# Test sin parámetro
add_test(NAME ejecuta COMMAND ejercicioslibro)

# Test con dos valores para que indique forma de usarlo
add_test(NAME indicaUso COMMAND ejercicioslibro 4 "tramposo" )
set_tests_properties(indicaUso
  PROPERTIES PASS_REGULAR_EXPRESSION "Uso:.*numero"
  )
  
## \u00f1 y \u00d1 son el equivalente para "ñ" y "Ñ", respectivamente en ejemplo lo explicado
## los acentos son \u00E0-\u00FC 
## https://www.fileformat.info/info/charset/UTF-16/list.htm
  
  
# Test para validar resultado
add_test(NAME usoHabitual COMMAND ejercicioslibro 4)
set_tests_properties(usoHabitual
  PROPERTIES PASS_REGULAR_EXPRESSION "4 es 2"
  )

# Funcion de test compleja usable con varios parámetros
function(haz_test target arg result)
  add_test(NAME Comp${arg} COMMAND ${target} ${arg})
  set_tests_properties(Comp${arg}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result}
    )
endfunction()

# lista de tests
haz_test(ejercicioslibro 4 "4 es 2")
haz_test(ejercicioslibro 9 "9 es 3")
haz_test(ejercicioslibro 5 "5 es 2.236")

#
# Adicional para instalar en diferentes sistemas
#
include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
set(CPACK_PACKAGE_VERSION_MAJOR "${ejercicioslibro_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${ejercicioslibro_VERSION_MINOR}")
set(CPACK_SOURCE_GENERATOR "TGZ")
include(CPack)

#
# we also need to explicitly install the generated libreriaPruebasTargets.cmake file. 
#
install(EXPORT libreriaPruebasTargets
  FILE libreriaPruebasTargets.cmake
  DESTINATION lib/cmake/libreriaPruebas
)
#
#  properly configure and install libreriaPruebasTargets.cmake, add the following to the bottom of the top-level CMakeLists.txt:
#
include(CMakePackageConfigHelpers)


# generate the config file that includes the exports
configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
  "${CMAKE_CURRENT_BINARY_DIR}/libreriaPruebasConfig.cmake"
  INSTALL_DESTINATION "lib/cmake/libreriaPruebas"
  NO_SET_AND_CHECK_MACRO
  NO_CHECK_REQUIRED_COMPONENTS_MACRO
  )
  
#
# this command writes a file which is used by find_package(), documenting the version and compatibility of the desired package
#
write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/libreriaPruebasConfig.cmake"
  VERSION "${ejercicioslibro_VERSION_MAJOR}.${ejercicioslibro_VERSION_MINOR}"
  COMPATIBILITY AnyNewerVersion
)
 
#
# if we want our project to also be used from a build directory
# With this export call we now generate a MathFunctionsTargets.cmake, allowing the configured MathFunctionsConfig.cmake in the build directory to be used by other projects, 
# without needing it to be installed.
# 
export(EXPORT libreriaPruebasTargets
  FILE "${CMAKE_CURRENT_BINARY_DIR}/libreriaPruebasTargets.cmake"
)

##
## Not required because we have added target_include_directories to the library CMakeLists.txt file
##list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/libtest")

						  
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

