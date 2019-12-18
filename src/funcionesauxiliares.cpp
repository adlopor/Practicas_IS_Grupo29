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

int is::menu()
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
	std::cout << "[1] Comprobar si la base de datos está vacía.";

	LUGAR(posicion++,10);
	std::cout << "[2] Cargar la base de datos de un fichero.";

	LUGAR(posicion++,10);
	std::cout << "[3] Guardar la base de datos actual en un fichero.";

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

void is::comprobarListaPacientesVacia(std::list<is::Paciente> &listaPacientes)
{
	LUGAR(8,10);
	
	std::cout << BIYELLOW << "La base de datos:" << std::endl;

	if (listaPacientes.empty() == true)
	{
		std::cout << "está vacía" << RESET;
		return true;
	}
	else{
		std::cout << "no está vacía" << RESET;
		return false;
	}
}

bool is::cargarFichero(std::string const &nombreFichero, std::list<is::Paciente> &listaPacientes)
{
	std::ifstream f(nombreFichero.c_str());

	is::Paciente aux;

	if(!f)
	{
		return false;
	}

	while(f >> aux)
	{		
		listaPacientes.push_back(aux);
	}

	std::sort (listaPacientes.begin(),this->listaPacientes.end(), is::Paciente::operator<);

	f.close();
		
	return true;
}

void ed::cargarListaPaciente(std::list<is::Paciente> &listaPacientes)
{
  	std::string nombreFichero;

	LUGAR(8,10);
	std::cout << BIYELLOW << "Introduce el nombre del archivo que contiene la BBDD: " << RESET;	
	std::cin >> nombreFichero;

	//Si el programa está cargado con otra BBDD, se borra y se carga la nueva BBDD.
	if( !comprobarListaPacientesVacia(std::list<is::Paciente> &listaPacientes))
	{
		listaPacientes.clear();
	}

	//Si el programa está vacío y no está cargado con otra BBDD, se carga el fichero introducido por pantalla.
	else
	{
		
	}
	if( !cargarFichero(nombreFichero) )
	{	
		LUGAR(15,10);
		std::cout << IRED << "No se pudo abrir el archivo." << RESET;
	}
	else
	{
		LUGAR(15,10);
		std::cout << BIBLUE << "El archivo cargó correctamente." << RESET;	
	}
}