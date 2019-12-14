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
      this->setFechaNacimiento(p.getFechaNacimiento())
      this->setTarjetaSanitaria(p.getTarjetaSanitaria());
    }

    // Se devuelve el objeto actual
		return *this;
}

bool is::Paciente::operator==(const is::Paciente & p) const
{
		return ((this->getNombre() == p.getNombre()) 
              and (this->getApellidos() == p.getApellidos())
                and (this->getTelefono()) == p.getTelefono()
                  and (this->getDireccionPostal() == p.getDireccionPostal())
                    and (this->getFechaNacimiento() == p.getFechaNacimiento())
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

  std::getline(i,p._fechaNacimiento);

  std::getline(i,p._tarjetaSanitaria);

  std::string aux;

  //Citas
  is::Cita c;
  i>>c;

  do{
    std::getline(i,aux)
    if (aux == "#")
      break;
    else{i>>c;}
    
  }while (aux == "----------")
  
  //Tratamientos
  is::Tratamiento t;
  i>>t;
  
  do{
    std::getline(i,aux)
    if (aux == "#")
      break;
    else{i>>t;}
    
  }while (aux == "----------")
  
  //Historiales
  is::Historial h;
  i>>h;
  
  do{
    std::getline(i,aux)
    if (aux == "#")
      break;
    else{i>>h;}
    
  }while (aux == "----------")

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


std::ostream &operator<<(std::ostream &o, is::Paciente const &p)
{
  o << p._nombre << std::endl;
  o << p._apellidos << std::endl;
  o << p._telefono << std::endl;
  o << p._direccionPostal << std::endl;
  o << p._fechaNacimiento << std::endl;
  o << p._tarjetaSanitaria << std::endl;

  //Citas
  for (std::list<is::Cita>::iterator it = p._citas.begin(); it != p._citas.end(); ++it)
  {
    o << *it 
    
    if (it == p._citas.end())
    {
      o << "#"<<std::endl;
    }
    else
    {
      o << "----------" < std::endl;
    }
    
  }

  //Tratamientos
  for (std::list<is::Cita>::iterator it = p._tratamientos.begin(); it != p._tratamientos.end(); ++it)
  {
    o << *it 
    
    if (it == p._tratamientos.end())
    {
      o << "#"<<std::endl;
    }
    else
    {
      o << "----------" << std::endl;
    }
    
  }

  //Historiales
  for (std::list<is::Cita>::iterator it = p._historial.begin(); it != p._historial.end(); ++it)
  
    o << *it 
    
    if (it == p._historial.end())
    {
      o << "#"<<std::endl;
    }
    else
    {
      o << "----------" << std::endl;
    }
    
  }

  // Se devuelve el flujo de salida
  return o;
}

} // Fin del espacio de nombres is