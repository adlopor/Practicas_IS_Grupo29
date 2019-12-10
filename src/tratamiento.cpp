/*!
	\file    tratamiento.cpp
	\brief   Métodos de la clase Tratamiento
	\author  Adrián López Ortiz
	\date    20/11/2019
	\version 1.0
*/


//#include <iostream>
//#include <stdio.h>

// si se desea usar atof en la sobrecarga del operador >>
//#include <stdlib.h>

#include "tratamiento.hpp"

// Se han utilizado los calificadores is:: y std:: en vez de las sentencias siguientes
//using namespace is;
//using namespace std;

/*!	
	    \name Sobrecarga de operadores.
*/

is::Tratamiento &is::Tratamiento::operator=(const is::Tratamiento &t)
{
		// Se comprueba que no sean el mismo objeto
		if (this != &t) 
		{
            this->setFechaInicio(t.getFechaInicio());
			this->setFechaFin(t.getFechaFin());
            this->setPeriodicidad(t.getPeriodicidad());
            this->getDosis(t.getDosis());
		}

    // Se devuelve el objeto actual
		return *this;
}

bool is::Tratamiento::operator==(const is::Tratamiento & t) const
{
		return (    (this->getFechaInicio() == t.getFechaInicio()) 
            and (this->getFechaFin() == t.getFechaFin())
                and (this->getPeriodicidad() == t.getPeriodicidad())
                    and (this->getDosis() == t.getDosis()));
}

bool is::Tratamiento::operator<(const is::Tratamiento & t) const
{
	if (this->getFechaInicio() < t.getFechaInicio())
      return true;
	else if (     (this->getFechaInicio() == t.getFechaInicio()) 
            and (this->getFechaFin() < t.getFechaFin())
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

std::istream &operator>>(std::istream &i, is::Tratamiento &t)
{
  std::getline(i,t._fechaInicio);

  std::getline(i,t._fechaFin);

  std::getline(i,t._periodicidad);

  std::getline(i,t._dosis);

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


std::ostream &operator<<(std::ostream &o, is::Tratamiento const &t)
{
  o << t._fechaInicio << std::endl;
  o << t._fechaFin << std::endl;
  o << t._periodicidad << std::endl;
  o << t._dosis << std::endl;

  // Se devuelve el flujo de salida
  return o;
}

} // Fin del espacio de nombres is