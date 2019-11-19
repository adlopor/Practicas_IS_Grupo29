/*!

  \file   funcionesAuxiliares.cpp
  \brief  Código de las funciones auxiliares del programa principal
  \author Adrián López Ortiz
  \date   20/11/19

*/

#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <fstream>

#include "funcionesauxiliares.hpp"

int ed::menu()
{
 	int opcion, posicion;

	// Se muestran las opciones del menú
	posicion=8;

	// Se borra la pantalla
	std::cout << CLEAR_SCREEN;

	LUGAR(5,10);
   	std::cout << BIYELLOW;
	std::cout << "Programa principal | Opciones del menú   ";
	std::cout << RESET;

	std::cout << IWHITE;

	LUGAR(posicion++,10);
	std::cout << "[1]";

	LUGAR(posicion++,10);
	std::cout << "[2]";

	LUGAR(posicion++,10);
	std::cout << "";

	LUGAR(posicion++,10);
	std::cout << "";

	LUGAR(posicion++,10);
	std::cout << "";

	LUGAR(posicion++,10);
	std::cout << "";

	LUGAR(posicion++,10);
	std::cout << "";

	LUGAR(posicion++,10);
	std::cout << "";

	LUGAR(posicion++,10);
	std::cout << "";

	LUGAR(posicion++,10);
	std::cout << "";

	std::cout << RESET;

	LUGAR(posicion++,10);
	std::cout << IRED << "[0] Salir";

	LUGAR(posicion++,20);
	std::cout << IYELLOW;
	std::cout << "Opción: ";
	std::cout << RESET;
	std::cin >> opcion;
    // Se elimina el salto de línea del flujo de entrada
    std::cin.ignore();

	return opcion;
}