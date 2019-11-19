/*!	

	\file     asignatura.hpp
	\brief    Definición de la clase Paciente
	\author   Adrián López Ortiz
	\date     20/11/19
	\version  1.0

*/

#ifndef _PACIENTE_HPP_
#define _PACIENTE_HPP_

#include <cassert>
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <fstream>

/*!	
	\namespace is
	\brief Espacio de nombres para la asignatura Ingeniería del Software
*/
namespace is{
/*!	

  \class Paciente
  \brief Representa la clase Paciente

*/
class Paciente: 
{

	/*!		
		\name Métodos públicos de la clase Paciente
	*/

	private:

	  	std::string _nombre;     									//!<  \brief Nombre del paciente.
        std::string _apellidos;     								//!<  \brief Apellidos del paciente.
        std::string _telefono;                                      //!<  \brief Teléfono del paciente.
        std::string _direccionPostal;                               //!<  \brief Dirección Postal del paciente.
        std::string _fechaNacimiento;                               //!<  \brief Fecha de nacimiento del paciente.
        bool        _tarjetaSanitaria;                              //!<  \brief Tarjeta sanitaria del paciente.
        std::list<is::Cita> _citas;                                 //!<  \brief Vector de citas del paciente. 
        std::list<is::Tratamiento> _tratamientos;                   //!<  \brief Vector de tratamientos del paciente.
        std::list<is::Historial> _historial;                        //!<  \brief Vector de Historial del paciente.

	/*!		
		\name  Métodos públicos de la clase Paciente.
	*/
  	public: 

		/*!	
			\name Constructor.
		*/
		Paciente(std::string const &nombre ="", std::string const &apellidos ="", std::string const &telefono ="", std::string const &direccionPostal ="", std::string const &fechaNacimiento ="", std::string const &tarjetaSanitaria ="")
		{
			this->setNombre(nombre);
            this->setApellidos(apellidos);
            this->setTelefono(telefono);
            this->setDireccionPostal(direccionPostal);
            this->setFechaNacimiento(fechaNacimiento);
            this->setTarjetaSanitaria(tarjetaSanitaria);
			
  		}


		/*!	
			\name Observadores
		*/

		/*!		
			\brief  Devuelve el nombre del paciente
			\note   Función de tipo inline
			\return cadena que representa el nombre del paciente  
  			\sa     setNombre
		*/
		inline int getNombre() const{return _nombre;}


		/*!		
			\brief  Devuelve los apellidos del paciente
			\note   Función de tipo inline
			\return cadena que representa los apellidos del paciente 
  			\sa     setApellidos
		*/
		inline std::string getApellidos() const{return _nombre;}


        /*!		
			\brief  Devuelve el número de teléfono del paciente
			\note   Función de tipo inline
			\return cadena que representa el número de teléfono del paciente 
  			\sa     setTelefono
		*/
		inline std::string getTelefono() const{return _telefono;}


        /*!		
			\brief  Devuelve la dirección postal del paciente
			\note   Función de tipo inline
			\return cadena que representa la dirección Postal del paciente 
  			\sa     setDireccionPostal
		*/
		inline std::string getDireccionPostal() const{return _direccionPostal;}


        /*!		
			\brief  Devuelve la fecha de nacimiento del paciente
			\note   Función de tipo inline
			\return cadena que representa la fecha de nacimiento del paciente 
  			\sa     setFechaNacimiento
		*/
		inline std::string getFechaNacimiento() const{return _nombre;}

        /*!		
			\brief  Devuelve si el paciente tiene tarjeta sanitaria
			\note   Función de tipo inline
			\return Booleano que representa con "True" si el paciente paciente tiene tarjeta sanitaria. En caso de no tener devuelve "False". 
  			\sa     setTarjetaSanitaria
		*/
		inline bool getTarjetaSanitaria() const
        {
            if (this->_tarjetaSanitaria)
                return true;
            else
                return false;       
        }


        /*!	
			\name Modificadores
		*/

		/*!		
			\brief  Modifica el nombre del paciente
  			\note   Función inline
			\param  nombre: cadena que será el nuevo nombre del paciente
  			\post   El nombre del paciente deberá ser el nombre asignado
			\return No se devuelve ningún resultado
  			\sa     getNombre
		*/
		inline void setNombre(std::string nombre)
		{
   			_nombre = nombre;

			#ifndef NDEBUG
				assert( getNombre() == nombre );
			#endif
		} 


        /*!		
			\brief  Modifica los apellidos del paciente
  			\note   Función inline
			\param  apellidos: cadena que será los nuevos apellidos del paciente
  			\post   los apellidos del paciente deberán ser los apellidos asignados
			\return No se devuelve ningún resultado
  			\sa     getApellidos
		*/
		inline void setApellidos(std::string apellidos)
		{
   			_apellidos = apellidos;

			#ifndef NDEBUG
				assert( getApellidos() == apellidos );
			#endif
		}


        /*!		
			\brief  Modifica el teléfono del paciente
  			\note   Función inline
			\param  telefono: cadena que será el nuevo teléfono del paciente
  			\post   El teléfono del paciente deberá ser el teléfono asignado
			\return No se devuelve ningún resultado
  			\sa     getTelefono
		*/
		inline void setTelefono(std::string telefono)
		{
   			_telefono = telefono;

			#ifndef NDEBUG
				assert( getTelefono() == telefono );
			#endif
		}


        /*!		
			\brief  Modifica la dirección postal del paciente
  			\note   Función inline
			\param  direccionPostal: cadena que será la nueva dirección postal del paciente
  			\post   La dirección postal del paciente deberá ser la dirección postal asignada
			\return No se devuelve ningún resultado
  			\sa     getDireccionPostal
		*/
		inline void setDireccionPostal(std::string direccionPostal)
		{
   			_direccionPostal = direccionPostal;

			#ifndef NDEBUG
				assert( getDireccionPostal() == direccionPostal );
			#endif
		}


        /*!		
			\brief  Modifica la fecha de nacimiento del paciente
  			\note   Función inline
			\param  fechaNacimiento: cadena que será la nueva fecha de nacimiento del paciente
  			\post   La fecha de nacimiento del paciente deberá ser la fecha de nacimiento asignada
			\return No se devuelve ningún resultado
  			\sa     getFechaNacimiento
		*/
		inline void setFechaNacimiento(std::string fechaNacimiento)
		{
   			_fechaNacimiento = fechaNacimiento;

			#ifndef NDEBUG
				assert( getFechaNacimiento() == fechaNacimiento );
			#endif
		}


        /*!		
			\brief  Modifica si el paciente tiene tarjeta Sanitaria pública
  			\note   Función inline
			\param  tarjetaSanitaria: booleano que indicará si el paciente tiene tarjeta Sanitaria pública
  			\post   Deberá indicar si el paciente tiene tarjeta sanitaria y deberá de tener lo mismo a lo asignado
			\return No se devuelve ningún resultado
  			\sa     getTarjetaSanitaria
		*/
		inline void setNombre(bool tarjetaSanitaria)
		{
   			_tarjetaSanitaria = tarjetaSanitaria;

			#ifndef NDEBUG
				assert( getTarjetaSanitaria() == tarjetaSanitaria );
			#endif
		}

}; //Fin de la clase 

} // Fin del espacio de nombres is

#endif // _PACIENTE_HPP_
