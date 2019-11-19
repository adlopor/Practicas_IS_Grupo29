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