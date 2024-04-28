# Generador de la tabla 
add_executable(HazTabla HazTabla.cpp)

#
# Cómo generamos el fichero Tabla.h
#
add_custom_command(
  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/Tabla.h
  COMMAND HazTabla ${CMAKE_CURRENT_BINARY_DIR}/Tabla.h
  DEPENDS HazTabla
  )
  
