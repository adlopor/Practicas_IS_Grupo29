/*!
	\file    historial.cpp
	\brief   Métodos de la clase Historial
	\author  Adrián López Ortiz
	\date    20/11/2019
	\version 1.0
*/


//#include <iostream>
//#include <stdio.h>

// si se desea usar atof en la sobrecarga del operador >>
//#include <stdlib.h>

#include "historial.hpp"

// Se han utilizado los calificadores is:: y std:: en vez de las sentencias siguientes
//using namespace is;
//using namespace std;

/*
	Definiciones de las funciones lectura y escritura de la clase Historial
*/

void is::Historial::leerHistorial()
{
	std::cout << "Introduce el motivo de la consulta: ";
	std::getline(std::cin,this->_motivoConsulta);
	
	std::cout << "Introduce la fecha: ";
	std::getline(std::cin,this->_fecha);

	// Se elimina el salto de línea para evitar problemas en una posterior lectura de cadenas 
	std::cin.ignore(); 
}

void is::Historial::escribirHistorial()
{
	std::cout << "Motivo de consulta: " << this->getMotivoConsulta() << std::endl;
	std::cout << "Fecha: " << this->getFecha() << std::endl;
}


/*!	
	    \name Sobrecarga de operadores.
*/

is::Historial &is::Historial::operator=(const is::Historial &h)
{
		// Se comprueba que no sean el mismo objeto
		if (this != &h) 
		{
			this->setMotivoConsulta(h.getMotivoConsulta());
			this->setFecha(h.getFecha());
		}

    // Se devuelve el objeto actual
		return *this;
}

bool is::Historial::operator==(const is::Historial & h) const
{
		return (    (this->getMotivoConsulta() == h.getMotivoConsulta()) 
            and (this->getFecha() == h.getFecha()));
}


bool is::Historial::operator <(const is::Historial & h) const
{
  // 
	if (this->getFecha() < h.getFecha())
       return true;
	else
   	  return false;
}


/*!	
	\namespace is
	\brief Espacio de nombres para la asignatura Ingeniería del Software
*/
namespace is{

std::istream &operator>>(std::istream &i, is::Historial &h)
{
	std::getline(i,h._motivoConsulta);
	std::getline(i,h._fecha);

	/*Forma alternativa para la lectura de datos numéricos usando una variable auxiliar: cadena
    
	std::string cadena;

    std::getline(i,cadena);
    c._fecha= atof(cadena.c_str());
    
    std::getline(i,cadena);
    c._hora = atof(cadena.c_str());
	*/

	// Se devuelve el flujo de entrada
	return i;
}


std::ostream &operator<<(std::ostream &o, is::Historial const &h)
{
  o << h._motivoConsulta << std::endl;
  o << h._fecha << std::endl;

  // Se devuelve el flujo de salida
  return o;
}

} // Fin del espacio de nombres is