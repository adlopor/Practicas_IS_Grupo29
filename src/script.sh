#!/bin/bash
echo "Borrando los archivos objeto y ejecutables..."
sleep 5
make clean
echo "Compilando el programa..."
echo ""
sleep 5
make
echo "Generando documentacion..."
sleep 5
doxygen Doxyfile
sleep 3
reset
echo "Ejecutando programa..."
sleep 5
./main.exe
