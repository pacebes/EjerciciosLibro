cd C:\Users\pacebes\Desarrollo\C++\Pruebas\Libro\EjerciciosLibro
rmdir /s build
mkdir build && cd build
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build  . --config Debug


