/*!
	\file 	 main.cpp
	\brief   Programa principal de la práctica final de la asignatura, Ingeniería del Software 
	\author  Adrián López Ortiz
	\date 	 20/11/19
	\version 1.0
*/

/*!
 \mainpage Implementación de un programa para gestionar la base de datos de una clínica médica.
 \author   Adrián López Ortiz
 \date     20/11/19
 \version  1.0
*/

#include <iostream>
#include <stdio.h>

#include <string>

#include "funcionesAuxiliares.hpp"
#include "paciente.hpp"

#include "macros.hpp"

/*!	
  	\brief Programa principal de la práctica 2 de ED
*/
int main()
{
	std::list<is::Paciente> listaPacientes;
    is::Paciente p;
    is::Cita c;
    is::Tratamiento t;
    is::Historial h;
    
	int opcion;

	do{
		// Se elige la opción del menún
		opcion = is::menu();		

		std::cout << CLEAR_SCREEN;
		LUGAR(5,1);

		// Se ejecuta la opción del menú elegida
		switch(opcion)
		{
			case 0: 
					std::cout << INVERSE;
					std::cout << "Fin del programa" << std::endl;
					std::cout << RESET;
					break;

			case 1: 
					std::cout << "[1] Comprobar si la base de datos está vacía." << std::endl;
					is::comprobarListaPacientesVacia(listaPacientes);
					break;

			case 2: 
				  	std::cout << "[2] Cargar la base de datos de un fichero." << std::endl;
					is::cargarListaPacientes(listaPacientes);
					break;

			case 3: 
				  	std::cout << "[3] Guardar la base de datos actual en un fichero." << std::endl;
					is::grabarListaPacientes(listaPacientes);
					break;

			case 4: 
			  		std::cout << "[4] Mostrar el listado completo de pacientes de la clínica." << std::endl; 
					is::escribirListaPacientes(listaPacientes);
					break;

			case 5: 
					std::cout << "[5] Dar de alta a un nuevo paciente." << std::endl;
				  	is::darAltaPaciente(listaPacientes);
					break;

			case 6: 
					std::cout << "[6] Buscar a un paciente." << std::endl;
				  	is::buscarPaciente(listaPacientes,p);
					break;


			case 7: 
					std::cout << "[7] Modificar los datos personales de un paciente." << std::endl;
			    	is::modificarPaciente(listaPacientes, p);
					break;

			case 8: 
					std::cout << "[8] Eliminar a un paciente de la base de datos." << std::endl;
				  	is::borrarPaciente(listaPacientes, p);
					break;

			case 9: 
					std::cout << "[9] Consultar el listado completo de citas de un paciente." << std::endl;
				  	is::consultarCitasPaciente(listaPacientes,p);
					break;

			case 10: 
					std::cout << "[10] Añadir una nueva cita para un paciente" << std::endl;
					is::anadirCita (listaPacientes,p,c);
					break;

            case 11: 
					std::cout << "[11] Modificar una cita existente perteneciente a un paciente." << std::endl;
					is::modificarCita(listaPacientes,p,c);
					break;
			
            case 12: 
					std::cout << "[12] Cancelar una cita existente perteneciente a un paciente." << std::endl;
					is::cancelarCita(listaPacientes,p,c);
					break;
			
            case 13: 
					std::cout << "[13] Consultar el listado completo de registros de historial de un paciente." << std::endl;
					is::consultarHistorialPaciente(listaPacientes,p);
					break;
			
            case 14: 
					std::cout << "[14] Añadir registro al historial de un paciente." << std::endl;
					is::anadirHistorial(listaPacientes,p,h);
					break;
			
            case 15: 
					std::cout << "[15] Consultar el listado de completo de tratamientos de un paciente." << std::endl;
					is::consultarTratamientosPaciente(listaPacientes,p);
					break;
			
            case 16: 
					std::cout << "[16] Añadir un nuevo tratamiento para un paciente." << std::endl;
					is::anadirTratamiento(listaPacientes,p,t);
					break;
			
            case 17: 
					std::cout << "[17] Cancelar un tratamiento ya existente perteneciente a un paciente." << std::endl;
					is::cancelarTratamiento(listaPacientes,p,t);
					break;
			
            case 18: 
					std::cout << "[18] Mostrar las citas de un día." << std::endl;
					is::consultarCitasDiaPacientes(listaPacientes);
					break;
			
            default:
			    	LUGAR(25,25);
					std::cout << INVERSE;
					std::cout << "Opción incorrecta ";
					std::cout << RESET;
			  		std::cout << RED;
					std::cout << " --> " << opcion << std::endl;
					std::cout << RESET;
     }
  
    if (opcion !=0)
    {
		 LUGAR(60,10);
		 std::cout << "pulse ";
		 std::cout << UNDERLINE;
		 std::cout << IYELLOW;
		 std::cout << "ENTER";
		 std::cout << RESET;
		 std::cout << " para ";
		 std::cout << INVERSE;
		 std::cout << "continuar"; 
		 std::cout << RESET;
		 getchar();
		 std::cout << CLEAR_SCREEN;
    }
	  }while(opcion!=0);

	return 0;
}


