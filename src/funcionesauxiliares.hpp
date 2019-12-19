/*!

  \file   funcionesAuxiliares.hpp
  \brief  Prototipos de las funciones auxiliares del programa principal
  \author Adrián López Ortiz
  \date   20/11/19

*/

#ifndef _FUNCIONESAUXILIARES_HPP_
#define _FUNCIONESAUXILIARES_HPP_

#include "paciente.hpp"
#include "cita.hpp"
#include "tratamiento.hpp"
#include "historial.hpp"

#include "macros.hpp"

namespace is
{
	/*! 
		\brief   Muestra el menú del programa principal 
		\return  Devuelve el número de opción elegido
	*/
  	int menu();

	/*! 
		\brief  Comprueba que la lista de pacientes actual del programa estén vacíos
		\param	listaPacientes: la lista de pacientes del programa
		\return Booleano que devuelve True si la lista de pacientes del programa está vacía. False, en caso contrario
		\sa		menu
	*/
	void comprobarListaPacientesVacia(std::list<is::Paciente> listaPacientes);

	/*! 
		\brief  Función auxiliar que ayuda a la carga de la lista de pacientes desde un fichero de texto
		\param  listaPacientes: lista de Pacientes de la clínica
		\param	nombreFichero: cadena que almacena el nombre del fichero de texto que contiene la base de datos con la lista de pacientes
		\return Booleano que devuelve True si carga con éxito el fichero que contiene la lista de pacientes. False, en caso contrario
    	\sa     comprobarListaPacientesVacia
	*/
	bool cargarFichero(std::string const &nombreFichero, std::list<is::Paciente> &listaPacientes);

	/*! 
		\brief  Carga la lista de paciente desde un fichero
		\param  listaPacientes: lista de Pacientes de la clínica
		\return void
    	\sa     comprobarListaPacientesVacia cargarFichero
	*/
	void cargarListaPacientes(std::list<is::Paciente> &listaPacientes);

	/*! 
		\brief  Función auxiliar que ayuda a la grabación de la lista de pacientes en un fichero de texto
		\param  listaPacientes: lista de Pacientes de la clínica
		\param	nombreFichero: cadena que almacena el nombre del fichero de texto que contendrá la base de datos con la lista de pacientes
		\return Booleano que devuelve True si graba con éxito en el fichero que contendrá la lista de pacientes. False, en caso contrario
    	\sa     comprobarListaPacientesVacia
	*/
	bool grabarFichero(std::string const &nombreFichero, std::list<is::Paciente> &listaPacientes);

	/*! 
		\brief  Carga la lista de pacientes desde un fichero
		\param  listaPacientes: lista de Pacientes de la clínica
		\return void
    	\sa     comprobarListaPacientesVacia grabarFichero
	*/
	void grabarListaPacientes(std::list<is::Paciente> &listaPacientes)

	/*! 
		\brief  Mete a un paciente nuevo en la lista de pacientes
		\param  listaPacientes: lista de Pacientes de la clínica
		\return void
	*/
	void darAltaPaciente(std::list<is::Paciente> &listaPacientes);

	/*!		
		\brief  Buscar paciente en la lista de pacientes del paciente
  		\param  listaPacientes: lista de Pacientes de la clínica
		\param	p: variable de clase Paciente
		\return Si encuentra el paciente devuelve true. En caso contrario, devuelve false.
	*/
	bool buscarPaciente (std::list<is::Paciente> &listaPacientes, is::Paciente p);

	/*!		
		\brief  Carga el paciente de la lista de pacientes en una clase de tipo Paciente
		\param  listaPacientes: lista de Pacientes de la clínica
		\param	p: variable de clase Paciente
		\return Devuelve el paciente que se quiere cargar. Si no existe, devuelve el último historial de la lista, junto con un mensaje de error.
  		
	*/
	is::Paciente cargarPaciente (std::list<is::Paciente> &listaPacientes, is::Paciente p);

	/*!		
		\brief  Guarda el paciente en la lista de pacientes y la reordena.
  		\param  listaPacientes: lista de Pacientes de la clínica
		\param	p: variable de clase Paciente
		\return No se devuelve ningún resultado
  		
	*/
	void guardarPaciente (std::list<is::Paciente> &listaPacientes, is::Paciente p);

	/*!		
		\brief  Borra un paciente de la lista de pacientes
  		\param  listaPacientes: lista de Pacientes de la clínica
		\param	p: variable de clase Paciente
		\return No se devuelve ningún resultado
  		
	*/
	void borrarPaciente (std::list<is::Paciente> &listaPacientes, is::Paciente p);

	/*!		
		\brief  Modifica los datos personales de un paciente de la lista de pacientes
  		\param  listaPacientes: lista de Pacientes de la clínica
		\param	p: variable de clase Paciente
		\return No se devuelve ningún resultado
  		
	*/
	void modificarPaciente (std::list<is::Paciente> &listaPacientes, is::Paciente p);

	/*!		
		\brief  Modifica los datos personales de un paciente de la lista de pacientes
  		\param  listaPacientes: lista de Pacientes de la clínica
		\param	p: variable de clase Paciente
		\return No se devuelve ningún resultado
  		
	*/
	void consultarCitasPaciente (std::list<is::Paciente> &listaPacientes);