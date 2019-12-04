/*!
	\file    cita.cpp
	\brief   Métodos de la clase Cita
	\author  Adrián López Ortiz
	\date    20/11/2019
	\version 1.0
*/


#include <iostream>
#include <stdio.h>

// si se desea usar atof en la sobrecarga del operador >>
#include <stdlib.h>

#include "cita.hpp"

// Se han utilizado los calificadores is:: y std:: en vez de las sentencias siguientes
//using namespace ed;
//using namespace std;

/*!	
	    \name Sobrecarga de operadores.
*/

is::Cita &is::Cita::operator=(const is::Cita &c)
{
		// Se comprueba que no sean el mismo objeto
		if (this != &c) 
		{
			this->getFecha(c.getFecha());
			this->setHora(e.getHora());
		}

    // Se devuelve el objeto actual
		return *this;
}

bool is::Cita::operator==(const is::Cita & c) const
{
		return (    (this->getFecha() == c.getFecha()) 
            and (this->getHora() == c.getHora()));
}


bool is::Cita::operator <(const is::Cita & c) const
{
  // 
	if (this->getFecha() < c.getFecha())
       return true;
	else if (     (this->getFecha() == c.getFecha()) 
            and (this->getHora() < c.getHora())
            )
     		   return true;
     	else
   			  return false;
}


/*!	
	\namespace is
	\brief Espacio de nombres para la asignatura Ingeniería del Software
*/
namespace is{

std::istream &operator>>(std::istream &i, is::Cita &c)
{
  std::getline(i,c._fecha);

  std::getline(i,c._hora);

/*  Forma alternativa para la lectura de datos numéricos usando una variable auxiliar: cadena
    std::string cadena;

    std::getline(i,cadena);
    c._fecha= atof(cadena.c_str());
    
    std::getline(i,cadena);
    c._hora = atof(cadena.c_str());
*/

  // Se devuelve el flujo de entrada
  return i;
}


std::ostream &operator<<(std::ostream &o, is::Cita const &c)
{
  o << c._fecha << std::endl;
  o << c._hora << std::endl;

  // Se devuelve el flujo de salida
  return o;
}

} // Fin del espacio de nombres is
