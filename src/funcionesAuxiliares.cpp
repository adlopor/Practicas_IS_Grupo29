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
	std::cout << "[11] Modificar una cita existente perteneciente a un paciente.";

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
	
	//std::cout << BIYELLOW << "La base de datos: ";

	if (listaPacientes.empty() == true)
	{
		//std::cout << "está vacía" << RESET <<std::endl;
		return true;
	}
	else{
		//std::cout << "NO está vacía" << RESET << std::endl;
		return false;
	}
}

bool is::cargarFichero(std::string const &nombreFichero, std::list<is::Paciente> &listaPacientes)
{
	std::ifstream f(nombreFichero.c_str());

	is::Paciente p;
	std::cout << "12";
	if(!f.is_open())
	{
		std::cout <<"Error cargarfichero" << std::endl;
		return false;
	}
	else{
		std::cout << " 34";
		int i= 1;
		while(f >> p)
		{	
			std::cout << "i= " << i << std::endl;
			i++;
			listaPacientes.push_back(p);
		}
		//Ordenamos la lista de pacientes
		//listaPacientes.sort();

		f.close();
		
		return true;
	}
}

void is::cargarListaPacientes(std::list<is::Paciente> &listaPacientes)
{
  	std::string nombreFichero;

	//LUGAR(12,10);
	//std::cout << BIYELLOW << "Introduce el nombre del archivo que contiene la BBDD: " << RESET;	
	std::cin >> nombreFichero;
	std::cout << std::endl;

	//Si el programa está cargado con otra BBDD, se borra y se carga la nueva BBDD.
	if(!comprobarListaPacientesVacia(listaPacientes))
	{
		listaPacientes.clear();
	}

	if( !cargarFichero(nombreFichero, listaPacientes) )
	{	
		//LUGAR(15,10);
		//std::cout << IRED << "No se pudo abrir el archivo." << RESET;
	}
	else
	{
		//LUGAR(15,10);
		//std::cout << BIBLUE << "El archivo cargó correctamente." << RESET;	
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

	if(comprobarListaPacientesVacia(listaPacientes))
	{
		std::cout << IRED << "No hay ninguna base de datos cargada." << RESET;
		return;
	}
	else
	{
		std::cout << BIYELLOW << "Introduce el nombre del archivo: " << RESET;	
		std::getline(std::cin,nombreFichero);

		grabarFichero(nombreFichero, listaPacientes);

		LUGAR(15,10);
		std::cout << BIBLUE << "El archivo se guardó correctamente." << RESET;
	}
}

void is::escribirListaPacientes(std::list<is::Paciente> &listaPacientes)
{

	if(comprobarListaPacientesVacia(listaPacientes))
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
	
	std::cout <<"En primer lugar tendrás que introducir el nombre y apellidos del paciente que quieres dar de alta. En caso de que este no pertenezca a la base de datos, podrás rellenar su ficha de forma satisfactoria." <<std::endl;

	if(buscarPaciente(listaPacientes, p))
	{
		std::cout << "FUNCION DAR ALTA PACIENTE -> Error. Dicho paciente ya existe en la Base de datos." << std::endl;
		return;
	}
	else
	{
		p.leerPaciente();
		listaPacientes.push_back(p);
		listaPacientes.sort();
		std::cout << "FUNCION DAR ALTA PACIENTE -> Paciente dado de alta en el sistema con éxito." << std::endl; 
	}
}

bool is::buscarPaciente (std::list<is::Paciente> &listaPacientes, is::Paciente &p)
{

	if(!comprobarListaPacientesVacia(listaPacientes))
	{
		p.leerNombreApellidosPaciente();

		for (std::list<is::Paciente>::iterator it = listaPacientes.begin(); it != listaPacientes.end(); ++it)
		{
			if (*it == p)
			{
				std::cout << "FUNCION BUSCAR PACIENTE -> Se ha encontrado al paciente." << std::endl;
				p = *it;
				return true;
			}
			else
			{
				std::cout << "FUNCION BUSCAR PACIENTE -> No se ha encontrado al paciente." << std::endl;
				return false;
			}
		}
		return false;//Para los avisos
	}
	else{
		std::cout << "La lista de pacientes se encuentra vacía, por lo tanto, el paciente no se ha encontrado." << std::endl;
		return false;
	}
	return false;//Para los avisos
}

void is::cargarPaciente (std::list<is::Paciente> &listaPacientes, is::Paciente &p)
{
	if(buscarPaciente(listaPacientes, p)){
		std::cout << "FUNCION CARGAR PACIENTE -> Paciente cargado con éxito." << std::endl;
	}
	else
	{
		std::cout << "FUNCION CARGAR PACIENTE -> La función buscarPaciente no ha encontrado al paciente, por lo que no se encuentra en la base de datos." << std::endl;
	}
}

void is::guardarPaciente (std::list<is::Paciente> &listaPacientes, is::Paciente &p)
{
  listaPacientes.push_back(p);
  //Ordenar lista de pacientes
  listaPacientes.sort();
}

void is::borrarPaciente (std::list<is::Paciente> &listaPacientes, is::Paciente &p)
{
	if(buscarPaciente(listaPacientes, p))
	{
		for (std::list<is::Paciente>::iterator it = listaPacientes.begin(); it != listaPacientes.end(); ++it)
		{
			if (p == *it)
			{
				listaPacientes.erase(it);
				std::cout << "FUNCION BORRAR PACIENTE -> El paciente se ha borrado con éxito." << std::endl;
			}
		}
	}
	else
	{
		std::cout << "FUNCION BORRAR PACIENTE -> No se ha podido borrar el paciente, ya que no se ha podido encontrar dicho paciente en la base de datos." << std::endl;
	}
}

void is::modificarPaciente (std::list<is::Paciente> &listaPacientes, is::Paciente &p)
{

	if(buscarPaciente(listaPacientes, p))
	{
		for (std::list<is::Paciente>::iterator it = listaPacientes.begin(); it != listaPacientes.end(); ++it)
		{
			if(p == *it)
			{
				it->leerPaciente();
				//Reordenar lista de pacientes
				listaPacientes.sort();
				
				std::cout << "FUNCION MODIFICAR PACIENTE -> Paciente modificado con éxito." << std::endl;

				return;
			}
		}
	}
	else
	{
		std::cout << "FUNCION MODIFICAR PACIENTE -> No se ha podido modificar el paciente, ya que no se ha podido encontrar dicho paciente en la base de datos." << std::endl;
	}
}

void is::consultarCitasPaciente (std::list<is::Paciente> &listaPacientes, is::Paciente &p)
{
	if(buscarPaciente(listaPacientes, p))
	{
		if(p.estaVaciaListaCitas())
		{
			std::cout << "El listado de citas de este paciente, está vacía." << std::endl;
		}
		else
		{
			p.setIndiceListaCitasBegin();

			for(int i = 0; i < p.getTamanoListaCitas(); ++i)
			{
				std::cout << "\tCita [" << i+1 << "]: " << std::endl;
				p.getCurrentCita().escribirCita();
				p.avanzarCitaAdelante();
			}
		}
	
	}
	else
	{
   		std::cout << "FUNCION CONSULTAR CITAS PACIENTE -> No se ha podido encontrar el paciente en la base de datos." << std::endl;
	}
}

void is::anadirCita (std::list<is::Paciente> &listaPacientes, is::Paciente &p, is::Cita &c)
{
	if(buscarPaciente(listaPacientes, p))
	{
		c.leerCita();
	
		if(p.buscarCita(c))
		{
			std::cout << "FUNCION AÑADIR CITA -> No se le puede asignar esta nueva cita a dicho paciente ya que este ya tiene una cita asignada para este momento." << std::endl;
		}
		else
		{
			p.guardarCita(c);
			std::cout << "FUNCION AÑADIR CITA -> Cita añadida con éxito." << std::endl;
		}
	}
	else
	{
   		std::cout << "FUNCION AÑADIR CITA -> No se ha podido encontrar el paciente al que añadir la cita, en la base de datos." << std::endl;
	}
}

void is::modificarCita (std::list<is::Paciente> &listaPacientes, is::Paciente &p, is::Cita &c)
{
	if(buscarPaciente(listaPacientes, p))
		{
			std::cout << "Introduzca la cita a modificar: " << std::endl;
			c.leerCita();
	
			if(p.buscarCita(c))
			{
				p.borrarCita(c);

				std::cout <<"Introduzca los nuevos datos de la cita: " << std::endl;
				c.leerCita();
				p.guardarCita(c);
			}
			else
			{
				std::cout << "FUNCION MODIFICAR CITA -> No se ha encontrado la cita en el paciente." << std::endl;
			}
		}
		else
		{
   			std::cout << "FUNCION MODIFICAR CITA -> No se ha podido encontrar el paciente al que añadir la cita, en la base de datos." << std::endl;
		}
}

void is::cancelarCita (std::list<is::Paciente> &listaPacientes, is::Paciente &p, is::Cita &c)
{
	if(buscarPaciente(listaPacientes, p))
		{
			std::cout << "Introduzca la cita a cancelar: " << std::endl;
			c.leerCita();
	
			if(p.buscarCita(c))
			{
				p.borrarCita(c);
			}
			else
			{
				std::cout << "FUNCION CANCELAR CITA -> No se ha encontrado la cita en el paciente." << std::endl;
			}
		}
		else
		{
   			std::cout << "FUNCION CANCELAR CITA -> No se ha podido encontrar el paciente al que añadir la cita, en la base de datos." << std::endl;
		}
}

void is::consultarHistorialPaciente (std::list<is::Paciente> &listaPacientes, is::Paciente &p)
{
	if(buscarPaciente(listaPacientes, p))
	{
		if(p.estaVaciaListaHistorial())
		{
			std::cout << "El listado de registros de historial de este paciente, está vacío." << std::endl;
		}
		else
		{
			p.setIndiceListaHistorialBegin();

			for(int i = 0; i < p.getTamanoListaHistorial(); ++i)
			{
				std::cout << "\tRegistro de historial [" << i+1 << "]: " << std::endl;
				p.getCurrentHistorial().escribirHistorial();
				p.avanzarHistorialAdelante();
			}
		}
	
	}
	else
	{
   		std::cout << "FUNCION CONSULTAR HISTORIAL PACIENTE -> No se ha podido encontrar el paciente en la base de datos." << std::endl;
	}
}

void is::anadirHistorial (std::list<is::Paciente> &listaPacientes, is::Paciente &p, is::Historial &h)
{
	if(buscarPaciente(listaPacientes, p))
	{
		h.leerHistorial();
	
		if(p.buscarHistorial(h))
		{
			std::cout << "FUNCION AÑADIR HISTORIAL -> No se le puede asignar este nuevo registro al historial de dicho paciente ya que este ya tiene dicho registro del historial." << std::endl;
		}
		else
		{
			p.guardarHistorial(h);
			std::cout << "FUNCION AÑADIR HISTORIAL -> Registro de historial añadido con éxito." << std::endl;
		}
	}
	else
	{
   		std::cout << "FUNCION AÑADIR HISTORIAL -> No se ha podido encontrar el paciente al que añadir el registro de historial, en la base de datos." << std::endl;
	}
}

void is::consultarTratamientosPaciente (std::list<is::Paciente> &listaPacientes, is::Paciente &p)
{
	if(buscarPaciente(listaPacientes, p))
	{
		if(p.estaVaciaListaTratamientos())
		{
			std::cout << "El listado de tratamientos de este paciente, está vacío." << std::endl;
		}
		else
		{
			p.setIndiceListaTratamientosBegin();

			for(int i = 0; i < p.getTamanoListaTratamientos(); ++i)
			{
				std::cout << "\tTratamiento [" << i+1 << "]: " << std::endl;
				p.getCurrentTratamiento().escribirTratamiento();
				p.avanzarTratamientoAdelante();
			}
		}
	
	}
	else
	{
   		std::cout << "FUNCION CONSULTAR TRATAMIENTOS PACIENTE -> No se ha podido encontrar el paciente en la base de datos." << std::endl;
	}
}

void is::anadirTratamiento (std::list<is::Paciente> &listaPacientes, is::Paciente &p, is::Tratamiento &t)
{
	if(buscarPaciente(listaPacientes, p))
	{
		t.leerTratamiento();
	
		if(p.buscarTratamiento(t))
		{
			std::cout << "FUNCION AÑADIR TRATAMIENTO -> No se le puede asignar este nuevo tratamiento a dicho paciente ya que este ya tiene dicho tratamiento." << std::endl;
		}
		else
		{
			p.guardarTratamiento(t);
			std::cout << "FUNCION AÑADIR TRATAMIENTO -> Tratamiento añadido con éxito." << std::endl;
		}
	}
	else
	{
   		std::cout << "FUNCION AÑADIR TRATAMIENTO -> No se ha podido encontrar el paciente al que añadir el tratamiento, en la base de datos." << std::endl;
	}
}

void is::cancelarTratamiento (std::list<is::Paciente> &listaPacientes, is::Paciente &p, is::Tratamiento &t)
{
	if(buscarPaciente(listaPacientes, p))
		{
			std::cout << "Introduzca el tratamiento a cancelar: " << std::endl;
			t.leerTratamiento();
	
			if(p.buscarTratamiento(t))
			{
				p.borrarTratamiento(t);
			}
			else
			{
				std::cout << "FUNCION CANCELAR TRATAMIENTO -> No se ha encontrado el tratamiento en el paciente." << std::endl;
			}
		}
		else
		{
   			std::cout << "FUNCION CANCELAR TRATAMIENTO -> No se ha podido encontrar el paciente al que añadir el tratamiento, en la base de datos." << std::endl;
		}
}

void is::consultarCitasDiaPacientes (std::list<is::Paciente> &listaPacientes)
{
	if(!comprobarListaPacientesVacia(listaPacientes))
	{	
		int i = 1;

		std::string fecha;
		std::cout << "Introduce la fecha de la que quieras consultar las citas (yyyy/mm/dd): ";
		std::getline(std::cin,fecha);

		for (std::list<is::Paciente>::iterator it = listaPacientes.begin(); it != listaPacientes.end(); ++it, i++)
		{
			if(!it->estaVaciaListaCitas())
			{
				it->setIndiceListaCitasBegin();

				for(int j = 0; j < it->getTamanoListaCitas(); ++j)
				{
					if(it->getCurrentCita().getFecha() == fecha)
					{
						std::cout << "\t\tPaciente [" << i << "]: " << std::endl;
						it->escribirPaciente();
						std::cout << "\tCita [" << j+1 << "]: " << std::endl;
						it->getCurrentCita().escribirCita();
						it->avanzarCitaAdelante();
					}
				}
			}
		}
	}
	else
	{
		std::cout << "FUNCION CONSULTAR CITAS DIA PACIENTE -> El sistema no tiene cargado ninguna base de datos." << std::endl;
	}
}