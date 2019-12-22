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
    \name Métodos del Listado de citas
  */

is::Cita is::Paciente::getCurrentCita()
{
	is::Cita c;

	if(estaVaciaListaCitas()){
		std::cout << "FUNCION GET CURRENT CITA: Error la lista está vacía." << std::endl;
		return c;
	}
	else
	{
		std::list<is::Cita>::iterator it = this->_citas.begin();
		for(int i=0; i < (this->_indiceCitas + 1); i++)
		{
			it++;
		}
		return *it;
	}
}

bool is::Paciente::buscarCita (is::Cita &c)
{
  //Ponemos el índice de la lista al principio y la recorremos hacia delante de 1 en 1.
  setIndiceListaCitasBegin();
  
  for (getIndiceListaCitas(); getIndiceListaCitas() < getTamanoListaCitas(); avanzarCitaAdelante())
  {
    if(getCurrentCita() == c)
    {
      std::cout << "FUNCION BUSCAR CITA -> Se ha encontrado la cita." << std::endl;
      return true;
    }
  }
  
  std::cout << "FUNCION BUSCAR CITA -> No se ha encontrado la cita." << std::endl;
  return false;
}

is::Cita is::Paciente::cargarCita (is::Cita &c)
{

  if(buscarCita(c))
  {
    std::cout << "FUNCION CARGAR CITA -> Se ha encontrado la cita y nos disponemos a cargarla." << std::endl;
    return getCurrentCita();
  }
  else
  {
    std::cout << "FUNCION CARGAR CITA -> No se ha podido cargar la cita, ya que no se ha podido encontrar dicha cita en la base de datos del paciente. Se devuelve la primera de la lista." << std::endl;
    setIndiceListaCitasBegin();
    return getCurrentCita();
  }
}

void is::Paciente::guardarCita (is::Cita &c)
{
  this->_citas.push_back(c);
  //Ordenar lista de citas
  //std::sort (this->_citas.begin(),this->_citas.end(), is::Cita::operator<);
  this->_citas.sort();
}

void is::Paciente::borrarCita (is::Cita &c)
{

  if(buscarCita(c))
  {
    std::list<is::Cita>::iterator it = this->_citas.begin();
    int i = 0;
    std::cout << "FUNCION BORRAR CITA -> Se ha encontrado la cita y nos disponemos a borrarla." << std::endl;
    for(it = this->_citas.begin(), i=0; i < getIndiceListaCitas(); it++)
    {i++;}
    
    if(*it == getCurrentCita()){
      this->_citas.erase(it);
      std::cout << "FUNCION BORRAR CITA -> Cita borrada con éxito." << std::endl;
    }
    else
    {
      std::cout << "FUNCION BORRAR CITA -> Error al borrar." << std::endl;
    }
  }

  else
  {
    std::cout << "FUNCION BORRAR CITA -> No se ha podido borrar la cita, ya que no se ha podido encontrar dicha cita en la base de datos del paciente." << std::endl;
  }
  setIndiceListaCitasBegin();
}

  /*!
    \name Métodos del Listado de Tratamientos
  */

is::Tratamiento is::Paciente::getCurrentTratamiento()
{
	is::Tratamiento t;

	if(estaVaciaListaTratamientos()){
		std::cout << "FUNCION GET CURRENT TRATAMIENTO: Error la lista está vacía." << std::endl;
		return t;
	}
	else
	{
		std::list<is::Tratamiento>::iterator it = this->_tratamientos.begin();
		for(int i=0; i < (this->_indiceTratamientos + 1); i++)
		{
			it++;
		}
		return *it;
	}
}

bool is::Paciente::buscarTratamiento (is::Tratamiento &t)
{
  //Ponemos el índice de la lista al principio y la recorremos hacia delante de 1 en 1.
  setIndiceListaTratamientosBegin();
  
  for (getIndiceListaTratamientos(); getIndiceListaTratamientos() < getTamanoListaTratamientos(); avanzarTratamientoAdelante())
  {
    if(getCurrentTratamiento() == t)
    {
      std::cout << "FUNCION BUSCAR TRATAMIENTO -> Se ha encontrado el tratamiento." << std::endl;
      return true;
    }
  }
  
  std::cout << "FUNCION BUSCAR TRATAMIENTO -> No se ha encontrado el tratamiento." << std::endl;
  return false;
}

is::Tratamiento is::Paciente::cargarTratamiento (is::Tratamiento &t)
{

  if(buscarTratamiento(t))
  {
    std::cout << "FUNCION CARGAR TRATAMIENTO -> Se ha encontrado el tratamiento y nos disponemos a cargarlo." << std::endl;
    return getCurrentTratamiento();
  }
  else
  {
    std::cout << "FUNCION CARGAR TRATAMIENTO -> No se ha podido cargar el tratamiento, ya que no se ha podido encontrar dicho tratamiento en la base de datos del paciente. Se devuelve el primero de la lista." << std::endl;
    setIndiceListaTratamientosBegin();
    return getCurrentTratamiento();
  }
}

void is::Paciente::guardarTratamiento (is::Tratamiento &t)
{
  this->_tratamientos.push_back(t);
  //Ordenar lista de tratamientos
  //std::sort (this->_tratamientos.begin(),this->_tratamientos.end(), is::Tratamiento::operator<);
  this->_tratamientos.sort();
}

void is::Paciente::borrarTratamiento (is::Tratamiento &t)
{

  if(buscarTratamiento(t))
  {

    std::cout << "FUNCION BORRAR TRATAMIENTO -> Se ha encontrado el tratamiento y nos disponemos a borrarlo." << std::endl;
    int i = 0;
    std::list<is::Tratamiento>::iterator it = this->_tratamientos.begin();
    for(it = this->_tratamientos.begin(), i=0; i < getIndiceListaTratamientos(); it++)
    {i++;}
    
    if(*it == getCurrentTratamiento()){
      this->_tratamientos.erase(it);
      std::cout << "FUNCION BORRAR TRATAMIENTO -> Tratamiento borrado con éxito." << std::endl;
    }
    else
    {
      std::cout << "FUNCION BORRAR TRATAMIENTO -> Error al borrar." << std::endl;
    }
  }

  else
  {
    std::cout << "FUNCION BORRAR TRATAMIENTO -> No se ha podido borrar el tratamiento, ya que no se ha podido encontrar dicho tratamiento en la base de datos del paciente." << std::endl;
  }
  setIndiceListaTratamientosBegin();
}


		/*!	
			\name Otros métodos de la clase Historial
		*/

is::Historial is::Paciente::getCurrentHistorial()
{
	is::Historial h;

	if(estaVaciaListaHistorial()){
		std::cout << "FUNCION GET CURRENT HISTORIAL: Error la lista está vacía." << std::endl;
		return h;
	}
	else
	{
		std::list<is::Historial>::iterator it = this->_historial.begin();
		for(int i=0; i < (this->_indiceHistorial + 1); i++)
		{
			it++;
		}
		return *it;
	}
}

bool is::Paciente::buscarHistorial (is::Historial &h)
{
  //Ponemos el índice de la lista al principio y la recorremos hacia delante de 1 en 1.
  setIndiceListaHistorialBegin();
  
  for (getIndiceListaHistorial(); getIndiceListaHistorial() < getTamanoListaHistorial(); avanzarHistorialAdelante())
  {
    if(getCurrentHistorial() == h)
    {
      std::cout << "FUNCION BUSCAR HISTORIAL -> Se ha encontrado el registro de historial." << std::endl;
      return true;
    }
  }
  
  std::cout << "FUNCION BUSCAR HISTORIAL -> No se ha encontrado el registro de historial." << std::endl;
  return false;
}

is::Historial is::Paciente::cargarHistorial (is::Historial &h)
{

  if(buscarHistorial(h))
  {
    std::cout << "FUNCION CARGAR HISTORIAL -> Se ha encontrado el registro de historial y nos disponemos a cargarlo." << std::endl;
    return getCurrentHistorial();
  }
  else
  {
    std::cout << "FUNCION CARGAR HISTORIAL -> No se ha podido cargar el historial, ya que no se ha podido encontrar dicho registro de historial en la base de datos del paciente. Se devuelve el primero de la lista." << std::endl;
    setIndiceListaHistorialBegin();
    return getCurrentHistorial();
  }
}

void is::Paciente::guardarHistorial (is::Historial &h)
{
  this->_historial.push_back(h);
  //Ordenar lista de historial
  //std::sort (this->_historial.begin(),this->_historial.end(), is::Historial::operator<);
  this->_historial.sort();
}

void is::Paciente::borrarHistorial (is::Historial &h)
{

  if(buscarHistorial(h))
  {
    std::cout << "FUNCION BORRAR HISTORIAL -> Se ha encontrado el historial y nos disponemos a borrarlo." << std::endl;
    std::list<is::Historial>::iterator it = this->_historial.begin();
    int i = 0;
    for(it = this->_historial.begin(), i=0; i < getIndiceListaHistorial(); it++)
    {i++;}
    
    if(*it == getCurrentHistorial()){
      this->_historial.erase(it);
      std::cout << "FUNCION BORRAR HISTORIAL -> Registro de historial borrado con éxito." << std::endl;
    }
    else
    {
      std::cout << "FUNCION BORRAR HISTORIAL -> Error al borrar." << std::endl;
    }
  }

  else
  {
    std::cout << "FUNCION BORRAR HISTORIAL -> No se ha podido borrar el registro de historial, ya que no se ha podido encontrar dicho registro de historial en la base de datos del paciente. Movemos el cursor al principio de la lista." << std::endl;
  }
  setIndiceListaHistorialBegin();
}

/*
 Definiciones de las funciones lectura y escritura de la clase Cita
*/

void is::Paciente::leerNombreApellidosPaciente()
{
	std::cout << "Introduce el nombre del paciente: ";
	std::getline(std::cin,this->_nombre);
	std::cout << "Ahora, introduce los apellidos: ";
	std::getline(std::cin,this->_apellidos);
	
	// Se elimina el salto de línea para evitar problemas en una posterior lectura de cadenas 
	std::cin.ignore(); 
}

void is::Paciente::leerPaciente()
{
  std::string s;

  std::cout << "Introduce el nombre del paciente: ";
	std::getline(std::cin,this->_nombre);
	
  std::cout << "Introduce los apellidos: ";
	std::getline(std::cin,this->_apellidos);
  
  std::cout << "Introduce el teléfono: ";
	std::getline(std::cin,this->_telefono);
  
  std::cout << "Introduce la dirección postal: ";
	std::getline(std::cin,this->_direccionPostal);
  
  std::cout << "Introduce la fecha de nacimiento, (yyyy/mm/dd): ";
	std::getline(std::cin,this->_fechaNacimiento);
	
  std::cout << "Introduce si tiene tarjeta sanitaria, (true/false): ";
	std::getline(std::cin,s);
  if(s == "true")
  {
    this->setTarjetaSanitaria(true);
  }
	else
  {
    this->setTarjetaSanitaria(false);
  }
  
	// Se elimina el salto de línea para evitar problemas en una posterior lectura de cadenas 
	std::cin.ignore(); 
}

void is::Paciente::escribirPaciente()
{
  std::cout << "\t Datos personales del paciente: " << std::endl;
  std::cout << "Nombre: " << this->getNombre() << std::endl;
  std::cout << "Apellidos: " << this->getApellidos() << std::endl;
  std::cout << "Teléfono: " << this->getTelefono() << std::endl;
  std::cout << "Dirección Postal: " << this->getDireccionPostal() << std::endl;
  std::cout << "Fecha de Nacimiento: " << this->getFechaNacimiento() << std::endl;
  std::cout << "TarjetaSanitaria: ";
  if (getTarjetaSanitaria())
  {
    std::cout << "true" << std::endl;
  }
  else
  {
    std::cout << "false" << std::endl;
  }
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
    this->setFechaNacimiento(p.getFechaNacimiento());
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
            and (this->getApellidos() == p.getApellidos()));
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
  std::string s;

  std::getline(i,p._nombre);

  std::getline(i,p._apellidos);

  std::getline(i,p._telefono);

  std::getline(i,p._direccionPostal);

  std::getline(i,p._fechaNacimiento);

  std::getline(i,s);
  
  if(s == "true")
  {
    p.setTarjetaSanitaria(true);
  }
  else
  {
    p.setTarjetaSanitaria(false);
  }

  std::string aux;

  //Citas
  if(p.getTamanoListaCitas() != 0)
  {
    is::Cita c;
    i>>c;
    p._citas.push_back(c);
    do{
      std::getline(i,aux);
      if (aux == "#")
        break;
      else
      {
        i>>c;
        p._citas.push_back(c);
      }
    }while (aux == "----------");
  }
  else
  {
    //Se lee el "#" que se pone al final de la lista, ya que no hay Citas
    std::getline(i,aux);
  }

  //Tratamientos
  if(p.getTamanoListaTratamientos() != 0)
  {
    is::Tratamiento t;
    i>>t;
    p._tratamientos.push_back(t);
    do{
      std::getline(i,aux);
      if (aux == "#")
        break;
      else
      {
        i>>t;
        p._tratamientos.push_back(t);
      }
    
    }while (aux == "----------");
  }
  else
  {
    //Se lee el "#" que se pone al final de la lista, ya que no hay Tratamientos
    std::getline(i,aux);
  }

  //Historiales
  if(p.getTamanoListaHistorial() != 0)
  {
    is::Historial h;
    i>>h;
    p._historial.push_back(h);
    do{
      std::getline(i,aux);
      if (aux == "#")
        break;
      else
      {
        i>>h;
        p._historial.push_back(h);
      } 
    }while (aux == "----------");
  }
  else
  {
    //Se lee el "#" que se pone al final de la lista, ya que no hay registro de historial
    std::getline(i,aux);
  }

  // Se devuelve el flujo de entrada
  return i;
}


std::ostream &operator<<(std::ostream &o, is::Paciente &p)
{
  o << p._nombre << std::endl;
  o << p._apellidos << std::endl;
  o << p._telefono << std::endl;
  o << p._direccionPostal << std::endl;
  o << p._fechaNacimiento << std::endl;

  if(p.getTarjetaSanitaria())
  {
    o << "true" << std::endl;
  }
  else
  {
    o << "false" << std::endl;
  }

  //Citas
  if(!p.estaVaciaListaCitas())
  {
    for (std::list<is::Cita>::iterator it = p._citas.begin(); it != p._citas.end(); ++it)
    {
      o << *it;
    
      if (it == p._citas.end())
      {
        o << "#" << std::endl;
      }
      else
      {
        o << "----------" << std::endl;
      }
    }  
  }
  else
  {
    o << "#" << std::endl;
  }
  //Tratamientos
  if(!p.estaVaciaListaTratamientos())
  {
    for (std::list<is::Tratamiento>::iterator it = p._tratamientos.begin(); it != p._tratamientos.end(); ++it)
    {
      o << *it;

      if (it == p._tratamientos.end())
      {
        o << "#" << std::endl;
      }
      else
      {
        o << "----------" << std::endl;
      }  
    }
  }
  else
  {
    o << "#" << std::endl;
  }

  //Historiales
  if(!p.estaVaciaListaHistorial())
  {
    for (std::list<is::Historial>::iterator it = p._historial.begin(); it != p._historial.end(); ++it)
    {
      o << *it;
      
      if (it == p._historial.end())
      {
        o << "#" << std::endl;
      }
      else
      {
        o << "----------" << std::endl;
      }
    }
  }
  else
  {
    o << "#" << std::endl;
  }

  // Se devuelve el flujo de salida
  return o;
}

} // Fin del espacio de nombres is