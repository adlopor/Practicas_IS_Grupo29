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
	    \name Otros métodos de la clase Cita.
*/

bool is::Paciente::buscarCita (is::Cita &c)
{

  std::list<is::Cita>::iterator it;
  it = std::find(this->_citas.begin(), this->_citas.end(), c);
  if (it == c)
  {
     cout << "FUNCION BUSCAR CITA -> Se ha encontrado la cita" << std::endl;
    return true;
  }
  else
  {
    cout << "FUNCION BUSCAR CITA -> No se ha encontrado la cita" << std::endl;
    return false;
  }
}

is::Cita is::Paciente::cargarCita (is::Cita &c)
{

  std::list<is::Cita>::iterator it = this->_citas.begin();

  if(buscarCita(c))
  {
    std::list<is::Cita>::iterator it;
    it = std::find(this->_citas.begin(), this->_citas.end(), c);
    return *it;
  }
  else
  {
    cout << "FUNCION CARGAR CITA -> No se ha podido cargar la cita, ya que no se ha podido encontrar dicha cita en la base de datos del paciente" << std::endl;
    return *it;
  }
}

void is::Paciente::guardarCita (is::Cita &c)
{

  this->_citas.push_back(c);
  //Ordenar lista de citas
  std::sort (this->_citas.begin(),this->_citas.end(), is::Cita::operator<);
}

void is::Paciente::borrarCita (is::Cita &c)
{

  if(buscarCita(c))
  {
    std::list<is::Cita>::iterator it;
    it = std::find(this->_citas.begin(), this->_citas.end(), c);
    this->_citas.erase(it);
  }

  else
  {
    cout << "FUNCION BORRAR CITA -> No se ha podido borrar la cita, ya que no se ha podido encontrar dicha cita en la base de datos del paciente." << std::endl;
  }
}


 		/*!	
			\name Otros métodos de la clase Tratamiento
		*/

bool is::Paciente::buscarTratamiento (is::Tratamiento &t)
{

  std::list<is::Tratamiento>::iterator it;
  it = std::find(this->_tratamientos.begin(), this->_tratamientos.end(), t);

  if (it == t)
  {
     cout << "FUNCION BUSCAR TRATAMIENTO -> Se ha encontrado el tratamiento" << std::endl;
    return true;
  }
  else
  {
    cout << "FUNCION BUSCAR TRATAMIENTO -> No se ha encontrado el tratamiento" << std::endl;
    return false;
  }
}

is::Tratamiento is::Paciente::cargarTratamiento (is::Tratamiento &t)
{

  std::list<is::Tratamiento>::iterator it = this->_tratamientos.begin();

  if(buscarTratamiento(t))
  {
    std::list<is::Tratamiento>::iterator it;
    it = std::find(this->_tratamientos.begin(), this->_tratamientos.end(), t);
    return *it;
  }

  else
  {
    cout << "FUNCION CARGAR TRATAMIENTO -> No se ha podido cargar el tratamiento, ya que no se ha podido encontrar dicho tratamiento en la base de datos del paciente" << std::endl;
    return *it;
  }
}

void is::Paciente::guardarTratamiento (is::Tratamiento &t)
{

  this->_tratamiento.push_back(t);
  //Ordenar lista de citas
  std::sort (this->_tratamientos.begin(),this->_tratamientos.end(), is::Tratamiento::operator<);
}

void is::Paciente::borrarTratamiento (is::Tratamiento &t)
{

  if(buscarTratamiento(t))
  {
    std::list<is::Tratamiento>::iterator it;
    it = std::find(this->_tratamientos.begin(), this->_tratamientos.end(), t);
    this->_tratamientos.erase(it);
  }

  else
  {
    cout << "FUNCION BORRAR TRATAMIENTO -> No se ha podido borrar el tratamiento, ya que no se ha podido encontrar dicho tratamiento en la base de datos del paciente." << std::endl;
  }
}

		/*!	
			\name Otros métodos de la clase Historial
		*/

bool is::Paciente::buscarHistorial (is::Historial &h)
{

  std::list<is::Historial>::iterator it;
  it = std::find(this->_historial.begin(), this->_historial.end(), h);
  if (it == h)
  {
     cout << "FUNCION BUSCAR HISTORIAL -> Se ha encontrado el historial" << std::endl;
    return true;
  }
  else
  {
    cout << "FUNCION BUSCAR HISTORIAL -> No se ha encontrado el historial" << std::endl;
    return false;
  }
}

is::Historial is::Paciente::cargarHistorial (is::Historial &h)
{

  std::list<is::Historial>::iterator it = this->_historial.begin();

  if(buscarHistorial(h))
  {
    std::list<is::Historial>::iterator it;
    it = std::find(this->_historial.begin(), this->_historial.end(), h);
    return *it;
  }

  else
  {
    cout << "FUNCION CARGAR HISTORIAL -> No se ha podido cargar el historial, ya que no se ha podido encontrar dicho historial en la base de datos del paciente" << std::endl;
    return *it;
  }
}

void is::Paciente::guardarHistorial (is::Historial &h)
{

  this->_historial.push_back(h);
  //Ordenar lista de citas
  std::sort (this->_historial.begin(),this->_historial.end(), is::Historial::operator<);
}

void is::Paciente::borrarHistorial (is::Historial &h)
{

  if(buscarHistorial(h))
  {
    std::list<is::Historial>::iterator it;
    it = std::find(this->_historial.begin(), this->_historial.end(), h);
    this->_historial.erase(it);
  }

  else
  {
    cout << "FUNCION BORRAR HISTORIAL -> No se ha podido borrar el historial, ya que no se ha podido encontrar dicho historial en la base de datos del paciente." << std::endl;
  }
}

		/*!	
			\name Otros métodos de la clase Paciente
		*/

void is::Paciente::leerPaciente()
{
  std::cout << "Introduce el nombre: ";
  // Uso de getline para leer nombres compuestos separados por espacios
  std::getline(std::cin,this->_nombre);

  // Esta sentencia no permite leer nombres compuestos con espacios en blanco
  // std::cin >> this->_nombre;

  std::cout << "Introduce los apellidos: ";
  // Uso de getline para leer los apellidos separados por espacios
  std::getline(std::cin,this->_apellidos);


  std::cout << "Introduce el telefono: ";
  std::getline(std::cin,this->_telefono);

  std::cout << "Introduce la direccion postal: ";
  std::getline(std::cin,this->_direccionPostal);
  
  std::cout << "Introduce la fecha de nacimiento (yyyy/mm/dd): ";
  std::getline(std::cin,this->_fechaNacimiento);
   
  std::cout << "Introduce la tarjeta sanitaria: ";
  std::getline(std::cin,this->_tarjetaSanitaria);
   
  // Se elimina el salto de línea para evitar problemas en una posterior lectura de cadenas 
  std::cin.ignore(); 
}


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

    this->setCitas(p.getCitas());
    this->setTratamientos(p.getTratamientos());
    this->setHistorial(p.getHistorial());

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