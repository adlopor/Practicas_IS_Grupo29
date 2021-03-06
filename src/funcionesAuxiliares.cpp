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

bool is::comprobarListaPacientesVacia(std::vector<is::Paciente> &listaPacientes)
{
	LUGAR(8,10);
	
	std::cout << BIYELLOW << "La base de datos: ";

	if (listaPacientes.empty() == true)
	{
		std::cout << "está vacía" << RESET <<std::endl;
		return true;
	}
	else{
		std::cout << "NO está vacía" << RESET << std::endl;
		return false;
	}
}

bool is::cargarFichero(std::string const &nombreFichero, std::vector<is::Paciente> &listaPacientes)
{
	std::ifstream f(nombreFichero.c_str());

	is::Paciente p;
	
	if(!f.is_open())
	{
		std::cout <<"Error cargarfichero" << std::endl;
		return false;
	}
	else{
	
		int i= 1;
		f >> p;
		listaPacientes.push_back(p);
	
		while(f >> p)
		{	
	
			i++;
			listaPacientes.push_back(p);
		}
		//Ordenamos la lista de pacientes
		//std::sort (listaPacientes.begin(), listaPacientes.end());
		f.close();
		return true;
	}
}

void is::cargarListaPacientes(std::vector<is::Paciente> &listaPacientes)
{
  	std::string nombreFichero;

	LUGAR(12,10);
	std::cout << BIYELLOW << "Introduce el nombre del archivo que contiene la BBDD: " << RESET;	
	std::cin >> nombreFichero;
	std::cout << std::endl;

	//Si el programa está cargado con otra BBDD, se borra y se carga la nueva BBDD.
	if(!comprobarListaPacientesVacia(listaPacientes))
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

bool is::grabarFichero(std::string const &nombreFichero, std::vector<is::Paciente> &listaPacientes)
{
	std::ofstream f(nombreFichero.c_str());

	if(!f)
	{
		return false;
	}
	else
	{
		for (std::vector<is::Paciente>::iterator it = listaPacientes.begin(); it != listaPacientes.end(); ++it)
		{
			f << *it;
		}
	
		f.close();
		
		return true;
	}
}

void is::grabarListaPacientes(std::vector<is::Paciente> &listaPacientes)
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

void is::escribirListaPacientes(std::vector<is::Paciente> &listaPacientes)
{

	if(comprobarListaPacientesVacia(listaPacientes))
	{
			std::cout << IRED << "No hay ninguna base de datos cargada." << RESET;
			return;
	}
	else
	{
		LUGAR(20,10);
		std::cout << BIYELLOW<< "-----LISTA DE PACIENTES-----" << RESET;
		
		for (std::vector<is::Paciente>::iterator it = listaPacientes.begin(); it != listaPacientes.end(); ++it)
		{
			it->escribirPaciente();
			std::cout << "----------" << std::endl;
		}
		
	}
}

void is::darAltaPaciente(std::vector<is::Paciente> &listaPacientes)
{
	is::Paciente p;
	LUGAR(30,10);
	std::cout <<"En primer lugar tendrás que introducir el nombre y apellidos del paciente que quieres dar de alta. En caso de que este no pertenezca a la base de datos, podrás rellenar su ficha de forma satisfactoria." <<std::endl;

	if(buscarPaciente(listaPacientes, p))
	{
		std::cout << "FUNCION DAR ALTA PACIENTE -> Error. Dicho paciente ya existe en la Base de datos." << std::endl;
		return;
	}
	else
	{
		p.leerPaciente();
		guardarPaciente(listaPacientes,p);
		//std::sort(listaPacientes.begin(), listaPacientes.end());
		
	}
}

bool is::buscarPaciente (std::vector<is::Paciente> &listaPacientes, is::Paciente &p)
{

	if(!comprobarListaPacientesVacia(listaPacientes))
	{
		p.leerNombreApellidosPaciente();
		for (std::vector<is::Paciente>::iterator it = listaPacientes.begin(); it != listaPacientes.end(); ++it)
		{
			if (*it == p)
			{
				std::cout << "FUNCION BUSCAR PACIENTE -> Se ha encontrado al paciente." << std::endl;
				p = *it;
				//std::cout << p;
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

void is::cargarPaciente (std::vector<is::Paciente> &listaPacientes, is::Paciente &p)
{
	if(buscarPaciente(listaPacientes, p)){
		std::cout << "FUNCION CARGAR PACIENTE -> Paciente cargado con éxito." << std::endl;
	}
	else
	{
		std::cout << "FUNCION CARGAR PACIENTE -> La función buscarPaciente no ha encontrado al paciente, por lo que no se encuentra en la base de datos." << std::endl;
	}
}

void is::guardarPaciente (std::vector<is::Paciente> &listaPacientes, is::Paciente &p)
{
	listaPacientes.push_back(p);
	LUGAR(32,10);
		std::cout << BIBLUE << "El paciente se guardó correctamente." << RESET;
	//std::sort(listaPacientes.begin(),listaPacientes.end());
}

void is::borrarPaciente (std::vector<is::Paciente> &listaPacientes, is::Paciente &p)
{
	if(buscarPaciente(listaPacientes, p))
	{
		for (std::vector<is::Paciente>::iterator it = listaPacientes.begin(); it != listaPacientes.end(); ++it)
		{
			if (p == *it)
			{
				listaPacientes.erase(it);
				std::cout << "FUNCION BORRAR PACIENTE -> El paciente se ha borrado con éxito." << std::endl;
				//std::sort(listaPacientes.begin(), listaPacientes.end());
				return;
			}
		}
	}
	else
	{
		std::cout << "FUNCION BORRAR PACIENTE -> No se ha podido borrar el paciente, ya que no se ha podido encontrar dicho paciente en la base de datos." << std::endl;
	}
}

void is::modificarPaciente (std::vector<is::Paciente> &listaPacientes, is::Paciente &p)
{

	if(buscarPaciente(listaPacientes, p))
	{
		for (std::vector<is::Paciente>::iterator it = listaPacientes.begin(); it != listaPacientes.end(); ++it)
		{
			if(p == *it)
			{
				it->leerPaciente();
				//Reordenar lista de pacientes
				//std::sort(listaPacientes.begin(), listaPacientes.end());
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

void is::consultarCitasPaciente (std::vector<is::Paciente> &listaPacientes, is::Paciente &p)
{
	if(buscarPaciente(listaPacientes, p))
	{
		if(p.estaVaciaListaCitas())
		{
			std::cout << "El listado de citas de este paciente, está vacía." << std::endl;
		}
		else
		{
			for(p.setIndiceListaCitasBegin(); p.getIndiceListaCitas() < p.getTamanoListaCitas(); p.avanzarCitaAdelante())
			{
				
				std::cout << "\tCita [" << p.getIndiceListaCitas()+1 << "]:"<< std::endl;
				p.getCurrentCita().escribirCita();
			}
		}
	
	}
	else
	{
   		std::cout << "FUNCION CONSULTAR CITAS PACIENTE -> No se ha podido encontrar el paciente en la base de datos." << std::endl;
	}
}

void is::anadirCita (std::vector<is::Paciente> &listaPacientes, is::Paciente &p, is::Cita &c)
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
			std::cout << "Cita a guardar:" << c << std::endl;
			for(unsigned int i=0; i<listaPacientes.size(); i++)
			{
				if (listaPacientes[i] == p){
					listaPacientes[i].guardarCita(c);
					std::cout << "FUNCION AÑADIR CITA -> Cita añadida con éxito." << std::endl;
					return;
				}	
			}			
		}
	}
	else
	{
   		std::cout << "FUNCION AÑADIR CITA -> No se ha podido encontrar el paciente al que añadir la cita, en la base de datos." << std::endl;
	}
}

void is::modificarCita (std::vector<is::Paciente> &listaPacientes, is::Paciente &p, is::Cita &c)
{
	if(buscarPaciente(listaPacientes, p))
		{
			std::cout << "Introduzca la cita a modificar: " << std::endl;
			c.leerCita();
	
			if(p.buscarCita(c))
			{
				for(unsigned int i=0; i<listaPacientes.size(); i++)
				{
					if (listaPacientes[i] == p)
					{
						listaPacientes[i].borrarCita(c);
						std::cout <<"Introduzca los nuevos datos de la cita: " << std::endl;
						c.leerCita();
						listaPacientes[i].guardarCita(c);
						std::cout << "FUNCION MODIFICAR CITA -> Cita añadida con éxito." << std::endl;
						return;
					}
				}	
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

void is::cancelarCita (std::vector<is::Paciente> &listaPacientes, is::Paciente &p, is::Cita &c)
{
	if(buscarPaciente(listaPacientes, p))
		{
			std::cout << "Introduzca la cita a cancelar: " << std::endl;
			c.leerCita();
	
			if(p.buscarCita(c))
			{
				for(unsigned int i=0; i<listaPacientes.size(); i++)
				{
					if (listaPacientes[i] == p)
					{
						listaPacientes[i].borrarCita(c);
						return;
					}
				}
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

void is::consultarHistorialPaciente (std::vector<is::Paciente> &listaPacientes, is::Paciente &p)
{
	if(buscarPaciente(listaPacientes, p))
	{
		if(p.estaVaciaListaHistorial())
		{
			std::cout << "El listado de historiales de este paciente, está vacía." << std::endl;
		}
		else
		{
			for(p.setIndiceListaHistorialBegin(); p.getIndiceListaHistorial() < p.getTamanoListaHistorial(); p.avanzarHistorialAdelante())
			{
				std::cout << "\tHistorial [" << p.getIndiceListaHistorial()+1 << "]:"<< std::endl;
				p.getCurrentHistorial().escribirHistorial();
			}
		}
	
	}
	else
	{
   		std::cout << "FUNCION CONSULTAR CITAS PACIENTE -> No se ha podido encontrar el paciente en la base de datos." << std::endl;
	}
}

void is::anadirHistorial (std::vector<is::Paciente> &listaPacientes, is::Paciente &p, is::Historial &h)
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
			for(unsigned int i=0; i<listaPacientes.size(); i++)
			{
				if (listaPacientes[i] == p)
				{
					listaPacientes[i].guardarHistorial(h);
					std::cout << "FUNCION AÑADIR HISTORIAL -> Registro de historial añadido con éxito." << std::endl;
					return;
				}
			}
			
		}
	}
	else
	{
   		std::cout << "FUNCION AÑADIR HISTORIAL -> No se ha podido encontrar el paciente al que añadir el registro de historial, en la base de datos." << std::endl;
	}
}

void is::consultarTratamientosPaciente (std::vector<is::Paciente> &listaPacientes, is::Paciente &p)
{
	if(buscarPaciente(listaPacientes, p))
	{
		if(p.estaVaciaListaTratamientos())
		{
			std::cout << "El listado de tratamientos de este paciente, está vacío." << std::endl;
		}
		else
		{
			for(p.setIndiceListaTratamientosBegin(); p.getIndiceListaTratamientos() < p.getTamanoListaTratamientos(); p.avanzarTratamientoAdelante())
			{
				//std::cout << "indice tratamiento: " << p.getIndiceListaTratamientos() << "tamaño lista tratamiento: " << p.getTamanoListaTratamientos()<< std::endl;
				std::cout << "\tTratamiento: " << std::endl;
				p.getCurrentTratamiento().escribirTratamiento();
			}
		}
	
	}
	else
	{
   		std::cout << "FUNCION CONSULTAR TRATAMIENTOS PACIENTE -> No se ha podido encontrar el paciente en la base de datos." << std::endl;
	}
}

void is::anadirTratamiento (std::vector<is::Paciente> &listaPacientes, is::Paciente &p, is::Tratamiento &t)
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
			for(unsigned int i=0; i<listaPacientes.size(); i++)
			{
				if (listaPacientes[i] == p)
				{
					listaPacientes[i].guardarTratamiento(t);
					std::cout << "FUNCION AÑADIR TRATAMIENTO -> Tratamiento añadido con éxito." << std::endl;
					return;
				}
			}	
		}
	}
	else
	{
   		std::cout << "FUNCION AÑADIR TRATAMIENTO -> No se ha podido encontrar el paciente al que añadir el tratamiento, en la base de datos." << std::endl;
	}
}

void is::cancelarTratamiento (std::vector<is::Paciente> &listaPacientes, is::Paciente &p, is::Tratamiento &t)
{
	if(buscarPaciente(listaPacientes, p))
		{
			std::cout << "Introduzca el tratamiento a cancelar: " << std::endl;
			t.leerTratamiento();
	
			if(p.buscarTratamiento(t))
			{
				for(unsigned int i=0; i<listaPacientes.size(); i++)
				{
					if (listaPacientes[i] == p)
					{
						listaPacientes[i].borrarTratamiento(t);
						return;
					}
				}	
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

void is::consultarCitasDiaPacientes (std::vector<is::Paciente> &listaPacientes)
{
	if(!comprobarListaPacientesVacia(listaPacientes))
	{	
		int i = 1;

		std::string fecha;
		std::cout << "Introduce la fecha de la que quieras consultar las citas (yyyy/mm/dd): ";
		std::getline(std::cin,fecha);

		for (std::vector<is::Paciente>::iterator it = listaPacientes.begin(); it != listaPacientes.end(); ++it, i++)
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
						if (it->getTamanoListaCitas() != it->getIndiceListaCitas())
						{
							it->avanzarCitaAdelante();
						}
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