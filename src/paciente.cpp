/*!
	\file    paciente.cpp
	\brief   Métodos de la clase Paciente
	\author  Adrián López Ortiz
	\date    20/11/2019
	\version 1.0
*/


//#include <iostream>
//#include <stdio.h>

// si se desea usar atof en la sobrecarga del operador >>
//#include <stdlib.h>

#include "paciente.hpp"

// Se han utilizado los calificadores is:: y std:: en vez de las sentencias siguientes
//using namespace is;
//using namespace std;

/*!	
	    \name Sobrecarga de operadores.
*/

is::Paciente &is::Paciente::operator=(const is::Paciente &p)
{
		// Se comprueba que no sean el mismo objeto
		if (this != &p) 
		{
      this->setNombre(p.getNombre());
      this->setApellidos(p.getApellidos());
      this->setTelefono(p.getTelefono());
      this->setDireccionPostal(p.getDireccionPostal());
      this->setTarjetaSanitaria(p.getTarjetaSanitaria());
    }

    // Se devuelve el objeto actual
		return *this;
}

bool is::Paciente::operator==(const is::Paciente & p) const
{
		return ((this->getNombre() == p.getNombre()) 
              and (this->getApellidos() == t.getApellidos())
                and (this->getTelefono()) == t.getTelefono()
                  and (this->getDireccionPostal() == t.getDireccionPostal())
                    and (this->getTarjetaSanitaria() == p.tarjetaSanitaria()));
}

bool is::Paciente::operator<(const is::Paciente & p) const
{
	if (this->getNombre() < p.getNombre())
      return true;
	else if (     (this->getNombre() == p.getNombre()) 
            and (this->getApellidos() < p.getApellidos())
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
//Cómo hago para saber cuántas citas, tatamientos, historiales, leo por paciente?
std::istream &operator>>(std::istream &i, is::Paciente &p)
{
  std::getline(i,p._nombre);

  std::getline(i,p._apellidos);

  std::getline(i,p._telefono);

  std::getline(i,p._direccionPostal);

  std::getline(i,p._tarjetaSanitaria);

  //Citas
  for (int i = 0; i < ; i++)
  {
    /* code */
  }
  
  //Tratamientos
  
  //Historiales

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