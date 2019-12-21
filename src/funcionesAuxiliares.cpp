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

#include "funcionesAuxiliares.hpp"

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
	std::cout << "[4] Mostrar el listado completo de pacientes de la clínica.";

	LUGAR(posicion++,10);
	std::cout << "[5] Dar de alta a un nuevo paciente.";

	LUGAR(posicion++,10);
	std::cout << "[6] Buscar a un paciente.";

	LUGAR(posicion++,10);
	std::cout << "[7] Modificar los datos personales de un paciente.";

	LUGAR(posicion++,10);
	std::cout << "[8] Eliminar a un paciente de la base de datos.";

	LUGAR(posicion++,10);
	std::cout << "[9] Consultar el listado completo de citas de un paciente.";

	LUGAR(posicion++,10);
	std::cout << "[10] Añadir una nueva cita para un paciente";

	LUGAR(posicion++,10);
	std::cout << "[11] Modificar una cita exitente perteneciente a un paciente.";

	LUGAR(posicion++,10);
	std::cout << "[12] Cancelar una cita existente perteneciente a un paciente.";

	LUGAR(posicion++,10);
	std::cout << "[13] Consultar el listado completo de registros de historial de un paciente.";

	LUGAR(posicion++,10);
	std::cout << "[14] Añadir registro al historial de un paciente.";

	LUGAR(posicion++,10);
	std::cout << "[15] Consultar el listado de completo de tratamientos de un paciente.";

	LUGAR(posicion++,10);
	std::cout << "[16] Añadir un nuevo tratamiento para un paciente.";

	LUGAR(posicion++,10);
	std::cout << "[17] Cancelar un tratamiento ya existente perteneciente a un paciente.";

	LUGAR(posicion++,10);
	std::cout << "[18] Mostrar las citas de un día.";

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

bool is::comprobarListaPacientesVacia(std::list<is::Paciente> &listaPacientes)
{
	LUGAR(8,10);
	
	std::cout << BIYELLOW << "La base de datos:" << std::endl;

	if (listaPacientes.empty() == true)
	{
		std::cout << "está vacía" << RESET;
		return true;
	}
	else{
		std::cout << "NO está vacía" << RESET;
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
	//Ordenamos la lista de pacientes
	listaPacientes.sort();

	f.close();
		
	return true;
}

void is::cargarListaPacientes(std::list<is::Paciente> &listaPacientes)
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

	if( !cargarFichero(nombreFichero, listaPacientes) )
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

bool is::grabarFichero(std::string const &nombreFichero, std::list<is::Paciente> &listaPacientes)
{
	std::ofstream f(nombreFichero.c_str());

	if(!f)
	{
		return false;
	}
	else
	{
		for (std::list<is::Paciente>::iterator it = listaPacientes.begin(); it != listaPacientes.end(); ++it)
		{
			f << *it;
		}
	
		f.close();
		
		return true;
	}
}

void is::grabarListaPacientes(std::list<is::Paciente> &listaPacientes)
{
  	std::string nombreFichero;

	LUGAR(8,10);

	if(comprobarListaPacientesVacia(std::list<is::Paciente> &listaPacientes)
	{
		std::cout << IRED << "No hay ninguna base de datos cargada." << RESET;
		return;
	}
	else
	{
		std::cout << BIYELLOW << "Introduce el nombre del archivo: " << RESET;	
		std::getline(std::cin,nombreFichero);

		grabarFichero(nombreFichero);

		LUGAR(15,10);
		std::cout << BIBLUE << "El archivo se guardó correctamente." << RESET;
	}
}

void is::imprimirListaPacientes(std::list<is::Paciente> &listaPacientes)
{

	if(comprobarListaPacientesVacia(std::list<is::Paciente> &listaPacientes)
	{
			std::cout << IRED << "No hay ninguna base de datos cargada." << RESET;
			return;
	}
	else
	{
		LUGAR(15,10);
		std::cout << BIYELLOW<< "-----LISTA DE PACIENTES-----" << RESET;
		
		for (std::list<is::Paciente>::iterator it = listaPacientes.begin(); it != listaPacientes.end(); ++it)
		{
			it->escribirPaciente();
			std::cout << "----------" << std::endl;
		}
		
	}
}

void is::darAltaPaciente(std::list<is::Paciente> &listaPacientes)
{
	is::Paciente p;
	p.leerPaciente();
	listaPacientes.pushback(p);
	listaPacientes.sort();
}

bool is::buscarPaciente (std::list<is::Paciente> &listaPacientes, is::Paciente p)
{

  std::list<is::Paciente>::iterator it;
  it = std::find(listaPacientes.begin(), listaPacientes.end(), p);
  if (it == p)
  {
	cout << "FUNCION BUSCAR PACIENTE -> Se ha encontrado al paciente." << std::endl;
    return true;
  }
  else
  {
	cout << "FUNCION BUSCAR PACIENTE -> No se ha encontrado al paciente." << std::endl;
    return false;
  }
}

is::Paciente is::cargarPaciente (std::list<is::Paciente> &listaPacientes, is::Paciente &p)
{

	std::list<is::Paciente>::iterator it = listaPacientes.begin();

	if(buscarPaciente(listaPacientes, p)
	{
		std::list<is::Paciente>::iterator it;
		it = std::find(listaPacientes.begin(), this->listaPacientes.end(), p);
		return *it;
	}

	else
	{
	cout << "FUNCION CARGAR PACIENTE -> No se ha podido cargar el paciente, ya que no se ha podido encontrar dicho paciente en la base de datos." << std::endl;
	return *it;
	}
}

void is::guardarPaciente (std::list<is::Paciente> &listaPacientes, is::Paciente p)
{

  listaPacientes.push_back(h);
  //Ordenar lista de pacientes
  listaPacientes.sort();
}

void is::borrarPaciente (std::list<is::Paciente> &listaPacientes, is::Paciente p);
{

  if(buscarPaciente(listaPacientes, p))
  {
    std::list<is::Paciente>::iterator it;
    it = std::find(listaPacientes.begin(), this->listaPacientes.end(), p);
    listaPacientes.erase(it);
	cout << "FUNCION BORRAR PACIENTE -> Paciente borrado con éxito." << std::endl;
  }

  else
  {
    cout << "FUNCION BORRAR PACIENTE -> No se ha podido borrar el paciente, ya que no se ha podido encontrar dicho paciente en la base de datos." << std::endl;
  }
}

void is::modificarPaciente (std::list<is::Paciente> &listaPacientes, is::Paciente p)
{

	if(buscarPaciente(listaPacientes, p)
	{
		std::list<is::Paciente>::iterator it;
		it = std::find(listaPacientes.begin(), this->listaPacientes.end(), p);
		it->leerPaciente();

		//Reordenar lista de pacientes
		listaPacientes.sort();
	}
	else
	{
   		cout << "FUNCION MODIFICAR PACIENTE -> No se ha podido modificar el paciente, ya que no se ha podido encontrar dicho paciente en la base de datos." << std::endl;
	}
}

void is::consultarCitasPaciente (std::list<is::Paciente> &listaPacientes, is::Paciente p)
{
	if(buscarPaciente(listaPacientes, p)
	{
		//Primero, buscamos y cargamos al paciente(preguntar datos antes) 
		p = cargarPaciente(listaPacientes, p);

		int i=0;
		for (std::list<is::Citas>::iterator it = p._citas.begin(); it != p._citas.end(); ++it)
		{
			i++;
			std::cout << "Cita " << i << ":" << std::endl << *it;
		}
	}
	else
	{
   		cout << "FUNCION CONSULTAR CITAS PACIENTE -> No se ha podido encontrar el paciente en la base de datos." << std::endl;
	}
}

void is::anadirCita (std::list<is::Paciente> &listaPacientes, is::Paciente p, is::Cita c)
{
	if(buscarPaciente(listaPacientes, p)
	{
	//Primero, buscamos y cargamos al paciente(preguntar datos antes) 
	p = cargarPaciente(listaPacientes, p);
	p._citas.push_back(c);
	//Ordenar lista de citas
	std::sort (listaPacientes.begin(),listaPacientes.end(), is::Paciente::operator<);
	}
	else
	{
   		cout << "FUNCION AÑADIR CITA -> No se ha podido encontrar el paciente al que añadir la cita, en la base de datos." << std::endl;
	}	
}