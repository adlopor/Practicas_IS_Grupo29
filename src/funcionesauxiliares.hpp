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
		\return bool
		\sa		menu
	*/
	void comprobarListaPacientesVacia(std::list<is::Paciente> listaPacientes);

	/*! 
		\brief   Carga la lista de paciente desde un fichero
		\param   listaPacientes: lista de Pacientes de la clínica
		\return  void
    	\sa      comprobarListaPacientesVacia
	*/
	void cargarBBDD(std::list<is::Paciente> listaPacientes);

