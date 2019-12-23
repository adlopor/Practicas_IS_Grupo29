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
		std::vector<is::Cita>::iterator it;
		int i=0;

    for( it = this->_citas.begin(); it != this->_citas.end() ; ++it,++i)
		{
      if(this->getIndiceListaCitas() == i)
      {
			  return *it;
      }
    }

    return *it;
  }
}

bool is::Paciente::buscarCita (is::Cita &c)
{
  if(getTamanoListaCitas() == 0){
    std::cout << "La lista de citas está vacía." << std::endl;
    return false;
  }
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
  /*
  std::vector<is::Cita>::iterator it;
  std::cout<< "Imprimimos la lista de citas: " << std::endl;
  int i = 1;
  for( it = this->_citas.begin(); it != this->_citas.end() ; ++it, ++i)
  {
    std::cout << "Cita [" << i << "]:" << std::endl << *it << std::endl;
  }
  */

  std::cout << "FUNCION GUARDAR CITA-> Cita guardada con éxito." <<std::endl;
  //std::sort(this->_citas.begin(), this->_citas.end());
}

void is::Paciente::borrarCita (is::Cita &c)
{

  if(buscarCita(c))
  {
    std::vector<is::Cita>::iterator it = (this->_citas.begin() + this->getIndiceListaCitas());
    std::cout << "FUNCION BORRAR CITA -> Se ha encontrado la cita y nos disponemos a borrarla." << std::endl;
    this->_citas.erase(it);
    std::cout << "FUNCION BORRAR CITA -> Cita borrada con éxito." << std::endl;
    //std::sort(this->_citas.begin(), this->_citas.end());
    this->setIndiceListaCitasBegin();
    return;
    
  }
  else
  {
    std::cout << "FUNCION BORRAR CITA -> No se ha podido borrar la cita, ya que no se ha podido encontrar dicha cita en la base de datos del paciente." << std::endl;
  }
  this->setIndiceListaCitasBegin();
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
		std::vector<is::Tratamiento>::iterator it;
		int i=0;

    for( it = this->_tratamientos.begin(); it != this->_tratamientos.end() ; ++it,++i)
		{
      if(this->getIndiceListaTratamientos() == i)
      {
			  return *it;
      }
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
  std::cout << "FUNCION GUARDAR TRATAMIENTO -> Tratamiento guardado con éxito." <<std::endl;
  std::sort(this->_tratamientos.begin(), this->_tratamientos.end());
}

void is::Paciente::borrarTratamiento (is::Tratamiento &t)
{
  if(buscarTratamiento(t))
  {
    std::vector<is::Tratamiento>::iterator it = this->_tratamientos.begin();
    this->setIndiceListaTratamientosBegin();
    std::cout << "FUNCION BORRAR TRATAMIENTO -> Se ha encontrado el tratamiento y nos disponemos a borrarlo." << std::endl;
  
    for(it = this->_tratamientos.begin(); it < this->_tratamientos.end(); it++)
    {
      if (*it == t)
      {
        this->_tratamientos.erase(it);
        std::sort(this->_tratamientos.begin(), this->_tratamientos.end());
        std::cout << "FUNCION BORRAR TRATAMIENTO -> Tratamiento borrado con éxito." << std::endl;
        this->setIndiceListaTratamientosBegin();
        return;
      }
    }
  std::cout << "FUNCION BORRAR TRATAMIENTO -> Error al borrar." << std::endl;
  }
  else
  {
    std::cout << "FUNCION BORRAR TRATAMIENTO -> No se ha podido borrar el tratamiento, ya que no se ha podido encontrar dicho tratamiento en la base de datos del paciente." << std::endl;
  }
  this->setIndiceListaTratamientosBegin();
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
		std::vector<is::Historial>::iterator it;
		int i=0;

    for( it = this->_historial.begin(); it != this->_historial.end() ; ++it,++i)
		{
      if(this->getIndiceListaHistorial() == i)
      {
			  return *it;
      }
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
      std::cout << "FUNCION BUSCAR HISTORIAL -> Se ha encontrado el historial." << std::endl;
      return true;
    }
  }
  
  std::cout << "FUNCION BUSCAR HISTORIAL -> No se ha encontrado el historial." << std::endl;
  return false;
}

is::Historial is::Paciente::cargarHistorial (is::Historial &h)
{
  if(buscarHistorial(h))
  {
    std::cout << "FUNCION CARGAR HISTORIAL -> Se ha encontrado el historial y nos disponemos a cargarlo." << std::endl;
    return getCurrentHistorial();
  }
  else
  {
    std::cout << "FUNCION CARGAR HISTORIAL -> No se ha podido cargar el historial, ya que no se ha podido encontrar dicho historial en la base de datos del paciente. Se devuelve el primero de la lista." << std::endl;
    setIndiceListaHistorialBegin();
    return getCurrentHistorial();
  }
}

void is::Paciente::guardarHistorial (is::Historial &h)
{
  this->_historial.push_back(h);
  std::cout << "FUNCION GUARDAR HISTORIAL-> Historial guardado con éxito." <<std::endl;
  std::sort(this->_historial.begin(), this->_historial.end());
}

void is::Paciente::borrarHistorial (is::Historial &h)
{
  if(buscarHistorial(h))
  {
    std::vector<is::Historial>::iterator it = this->_historial.begin();
    this->setIndiceListaHistorialBegin();
    std::cout << "FUNCION BORRAR HISTORIAL -> Se ha encontrado el historial y nos disponemos a borrarlo." << std::endl;
  
    for(it = this->_historial.begin(); it < this->_historial.end(); it++)
    {
      if (*it == h)
      {
        this->_historial.erase(it);
        std::cout << "FUNCION BORRAR HISTORIAL -> Historial borrado con éxito." << std::endl;
        std::sort(this->_historial.begin(), this->_historial.end());
        this->setIndiceListaHistorialBegin();
        return;
      }
    }
  std::cout << "FUNCION BORRAR HISTORIAL -> Error al borrar." << std::endl;
  }
  else
  {
    std::cout << "FUNCION BORRAR HISTORIAL -> No se ha podido borrar el historial, ya que no se ha podido encontrar dicho historial en la base de datos del paciente." << std::endl;
  }
  this->setIndiceListaHistorialBegin();
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
  std::cout << "---Datos personales del paciente: ---" << std::endl;
  std::cout << "Nombre: " << this->getNombre() << std::endl;
  std::cout << "Apellidos: " << this->getApellidos() << std::endl;
  std::cout << "Teléfono: " << this->getTelefono() << std::endl;
  std::cout << "Dirección Postal: " << this->getDireccionPostal() << std::endl;
  std::cout << "Fecha de Nacimiento: " << this->getFechaNacimiento() << std::endl;
  std::cout << "TarjetaSanitaria: ";
  if (this->getTarjetaSanitaria())
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
  std::string aux;

  //Leemos el inicio de Paciente "*"
  std::getline(i,aux);
  //std::cout << "Principio paciente: "<< aux << std::endl;

  //Luego leemos los atributos de la clase Paciente (datos personales).
  std::getline(i,p._nombre);
  //std::cout << "Nombre: " << p.getNombre() << std::endl;
  std::getline(i,p._apellidos);
  //std::cout << "Apellidos: " << p.getApellidos() << std::endl;
  std::getline(i,p._telefono);
  //std::cout << "Telefono: " << p.getTelefono() << std::endl;
  std::getline(i,p._direccionPostal);
  //std::cout << "Direccion Postal: " << p.getDireccionPostal() << std::endl;
  std::getline(i,p._fechaNacimiento);
  //std::cout << "Fecha de nacimiento: " << p.getFechaNacimiento() << std::endl;
  std::getline(i,s);
  //std::cout << "Tarjeta sanitaria: " << s << std::endl;
  //std::cout << std::endl;
  if(s == "true")
  {
    p.setTarjetaSanitaria(true);
  }
  else
  {
    p.setTarjetaSanitaria(false);
  }
  /*
  std::cout << "-+-+-+-+" << std::endl;
  p.escribirPaciente();
  std::cout << "-+-+-+-+" << std::endl;
  */
  //Leemos el final de los datos personales "+-+-"
  std::getline(i,aux);
  //std::cout << "Final datos personales: " << aux << std::endl;
  
  while (std::getline(i,aux)){
  //std::cout << "aux:[" << aux << "]";
  //Citas
  if(aux == "Citas:"){
    is::Cita c;
    i>>c;
    //std::cout << "cita:" << std::endl << c;
    p._citas.push_back(c);
    //std::cout << "Tamano citas: [" << p._citas.size() << "]" << std::endl;
    do{
    std::getline(i,aux);
      if (aux == "#")
      {
        break;
      }
      else if(aux == "----------")
      {
        i>>c;
        p._citas.push_back(c);
      }
    }while (aux == "----------");
  }

  //Tratamientos
  if(aux == "Tratamientos:"){
    is::Tratamiento t;
    i>>t;
    //std::cout << "tratamiento:" << std::endl << t;
    p._tratamientos.push_back(t);
    do{
      std::getline(i,aux);
      if (aux == "#")
      {
        break;
      }
      else if(aux == "----------")
      {
        i>>t;
        p._tratamientos.push_back(t);
      }
    }while (aux == "----------");
  }

  //Historiales
  if(aux == "Historial:"){
    is::Historial h;
    i>>h;
    //std::cout << "historial:" << std::endl << h;
    p._historial.push_back(h);
    do{
      std::getline(i,aux);
      if (aux == "#")
      {
        break;
      }
      else if(aux == "----------")
      {
        i>>h;
        p._historial.push_back(h);
      }
    }while (aux == "----------");
  }
std::cout<<"aux: "<<aux<<std::endl;
}//endwhile
  //std::cout << "Final de operator>>\n";
  // Se devuelve el flujo de entrada
  return i;
}


std::ostream &operator<<(std::ostream &o, is::Paciente &p)
{
  o << "*" << std::endl;
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
  o << "+-+-" << std::endl;

  //Citas
  if(!p.estaVaciaListaCitas())
  {
    o << "Citas:" << std::endl;

    for (std::vector<is::Cita>::iterator it = p._citas.begin(); it != p._citas.end(); ++it)
    {
      o << *it;
    
      if (it +1 == p._citas.end())
      {
        o << "#" << std::endl;
      }
      else
      {
        o << "----------" << std::endl;
      }
    }  
  }

  //Tratamientos
  if(!p.estaVaciaListaTratamientos())
  {
    o << "Tratamientos:" << std::endl;
    
    for (std::vector<is::Tratamiento>::iterator it = p._tratamientos.begin(); it != p._tratamientos.end(); ++it)
    {
      o << *it;

      if (it + 1 == p._tratamientos.end())
      {
        o << "#" << std::endl;
      }
      else
      {
        o << "----------" << std::endl;
      }  
    }
  }
  
  //Historiales
  if(!p.estaVaciaListaHistorial())
  {
    o << "Historial:" << std::endl;
    for (std::vector<is::Historial>::iterator it = p._historial.begin(); it != p._historial.end(); ++it)
    {
      o << *it;
      
      if (it + 1 == p._historial.end())
      {
        o << "#" << std::endl;
      }
      else
      {
        o << "----------" << std::endl;
      }
    }
  }

  // Se devuelve el flujo de salida
  return o;
}

} // Fin del espacio de nombres is