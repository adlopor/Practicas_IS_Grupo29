/*!	
	\file     paciente.hpp
	\brief    Definición de la clase Paciente
	\author   Adrián López Ortiz
	\date     20/11/19
	\version  1.0

*/

#ifndef _PACIENTE_HPP_
#define _PACIENTE_HPP_

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <fstream>
#include <cassert>

#include "macros.hpp"
#include "cita.hpp"
#include "tratamiento.hpp"
#include "historial.hpp"

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

	  	std::string 				_nombre;     									//!<  \brief Nombre del paciente.
        std::string 				_apellidos;     								//!<  \brief Apellidos del paciente.
        std::string 				_telefono;                                      //!<  \brief Teléfono del paciente.
        std::string 				_direccionPostal;                               //!<  \brief Dirección Postal del paciente.
        std::string 				_fechaNacimiento;                               //!<  \brief Fecha de nacimiento del paciente.
        bool        				_tarjetaSanitaria;                              //!<  \brief Tarjeta sanitaria del paciente.

        std::list<is::Cita> 		_citas;				                            //!<  \brief Lista de citas del paciente. 
        std::list<is::Tratamiento> 	_tratamientos;				                    //!<  \brief Lista de tratamientos del paciente.
        std::list<is::Historial> 	_historial;				                        //!<  \brief Lista de los registros de historial del paciente.

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

			this->		
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
		inline std::string getApellidos() const{return _apellidos;}

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
		inline std::string getFechaNacimiento() const{return _fechaNacimiento;}

        /*!		
			\brief  Devuelve si el paciente tiene tarjeta sanitaria
			\note   Función de tipo inline
			\return Booleano que representa con "True" si el paciente paciente tiene tarjeta sanitaria. En caso de no tener devuelve "False". 
  			\sa     setTarjetaSanitaria
		*/
		inline bool getTarjetaSanitaria() const
        {
            if (_tarjetaSanitaria)
                return true;
            else
                return false;
        }

		/*!		
			\brief  Devuelve la lista de citas del paciente
			\note   Función de tipo inline
			\return Listado de citas del paciente 
  			\sa     setCitas
		*/
		inline std::list<is::Cita> getCitas() const{this->_citas;}

		/*!		
			\brief  Devuelve la lista de tratamientos del paciente
			\note   Función de tipo inline
			\return Listado de tratamientos del paciente 
  			\sa     setTratamientos
		*/
		inline std::list<is::Tratamiento> getTratamientos() const{this->_tratamientos;}

		/*!		
			\brief  Devuelve la lista de historial del paciente
			\note   Función de tipo inline
			\return Listado de historial del paciente 
  			\sa     setHistorial
		*/
		inline std::list<is::Historial> getHistorial() const{this->_historial;}

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
		inline void setTarjetaSanitaria(bool tarjetaSanitaria)
		{
   			_tarjetaSanitaria = tarjetaSanitaria;

			#ifndef NDEBUG
				assert( getTarjetaSanitaria() == tarjetaSanitaria );
			#endif
		}

		/*!		
			\brief  Modifica la lista de citas del paciente
  			\note   Función inline
			\param  citas: lista de citas
  			\post   Deberá indicar si el paciente tiene un listado de citas y deberá de tener lo mismo a lo asignado
			\return No se devuelve ningún resultado
  			\sa     getCitas
		*/
		inline void setCitas( std::list<is::Citas> citas)
		{
   			this->_citas = citas;

			#ifndef NDEBUG
				assert( getCitas() == citas );
			#endif
		}

		/*!		
			\brief  Modifica la lista de tratamientos del paciente
  			\note   Función inline
			\param  tratamientos: lista de tratamientos
  			\post   Deberá indicar si el paciente tiene un listado de tratamientos y deberá de tener lo mismo a lo asignado
			\return No se devuelve ningún resultado
  			\sa     getTratamientos
		*/
		inline void setTratamientos( std::list<is::Tratamiento> tratamientos)
		{
   			this->_tratamientos = tratamientos;

			#ifndef NDEBUG
				assert( getTratamientos() == tratamientos );
			#endif
		}

				/*!		
			\brief  Modifica el historial del paciente
  			\note   Función inline
			\param  historial: historial del paciente
  			\post   Deberá indicar si el paciente tiene un historial y deberá de tener lo mismo a lo asignado
			\return No se devuelve ningún resultado
  			\sa     getHistorial
		*/
		inline void setHistorial( std::list<is::Historial> historial)
		{
   			this->_historial = historial;

			#ifndef NDEBUG
				assert( getHistorial() == historial );
			#endif
		}


    /*!	
	        \name Operadores
    */

    /*!		
	        \brief  Operador de asignacion entre objetos de tipo Paciente
	        \param  p: objeto de tipo Paciente
	        \post   El objeto actual es igual al objeto parámetro
	        \return Devuelve una referencia al objeto actual
    */
	Tratamiento &operator=(const Paciente &p);

    /*!		
	        \brief  Operador que compara la igualdad lexicográfica por el nombre, los apellidos, teléfono, dirección postal, fecha de nacimiento y tarjeta sanitaria
	        \param  p: objeto de tipo Paciente
	        \pre    Ambas citas deben tener valores en los parámetros; el nombre, los apellidos, teléfono, dirección postal, fecha de nacimiento y tarjeta sanitaria
			\post   Ninguna
    	    \return Devuelve true si el nombre, los apellidos, teléfono, dirección postal , fecha de nacimiento y tarjeta sanitaria de los pacientes son iguales. False, en caso contrario
    */
	bool operator==(const Paciente &p) const;

    /*!
	        \brief  Operador que compara la desigualdad lexicográfica por nombre y apellidos de dos pacientes.
	        \param  p: objeto de tipo Paciente
	        \pre    Ambos pacientes deben tener valores en los parámetros nombre y apellido.
	        \post   Ninguna
	        \return Devuelve true si el paciente actual precede cronológicamente al paciente pasado como argumento. False, en caso contrario
    */
	bool operator<(const Paciente &p) const;


    /*!
            \name Funciones amigas para poder acceder a la parte privada de la clase Paciente.
    */

    /*!
	        \brief  Operador de inserción
	        \param  i: flujo de entrada
	        \param  p: objeto de tipo Paciente
	        \pre    El paciente del parámetro debe existir
	        \post   Se modifican los atributos del paciente usando los valores insertados por el flujo de entrada
	        \return Devuelve el stream de entrada
    */
	friend std::istream &operator>>(std::istream &i, Paciente &p);

    /*!		
	    	\brief  Operador de extracción
	        \param  o: flujo de salida
	        \param  p: objeto de tipo Paciente
    	    \pre    El paciente del parámetro debe existir
	        \post   Se escriben los valores de los atributos del paciente en flujo de salida
	        \return Devuelve el stream de salida
	*/
	friend std::ostream &operator<<(std::ostream &o, Paciente const &p);

 		/*!	
			\name Otros métodos de la clase Cita
		*/

	/*!		
		\brief  Buscar cita en la lista de citas del paciente
  		\param  c: variable de la clase Cita
		\return Si encuentra la cita devuelve true. En caso contrario, devuelve false.
  		
	*/
	bool buscarCita (is::Cita &c);

	/*!		
		\brief  Carga la cita de la lista de citas en una clase de tipo Cita
		\param  c: variable de la clase Cita
		\return Devuelve la cita que se quiere cargar. Si no existe, la última cita de la lista, junto con un mensaje de error.
  		
	*/
	is::Cita cargarCita (is::Cita &c);

	/*!		
		\brief  Guarda la cita en la lista de citas del paciente y la reordena.
  		\param  c: variable de la clase Cita
		\return No se devuelve ningún resultado
  		
	*/
	void guardarCita (is::Cita &c);

	/*!		
		\brief  Borra una cita de la lista de citas del paciente
  		\param  c: variable de la clase Cita
		\return No se devuelve ningún resultado
  		
	*/
	void borrarCita (is::Cita &c);


 		/*!	
			\name Otros métodos de la clase Tratamiento
		*/

	/*!		
		\brief  Buscar tratamiento en la lista de tratamientos del paciente
  		\param  t: variable de la clase Tratamiento.
		\return Si encuentra el tratamiento devuelve true. En caso contrario, devuelve false.
  		
	*/
	bool buscarTratamiento (is::Tratamiento &t);

	/*!		
		\brief  Carga el tratamiento de la lista de tratamientos en una clase de tipo Tratamiento
		\param  t: variable de la clase Tratamiento
		\return Devuelve el tratamiento que se quiere cargar. Si no existe, devuelve el último tratamiento de la lista, junto con un mensaje de error.
  		
	*/
	is::Cita cargarTratamiento (is::Tratamiento &t);

	/*!		
		\brief  Guarda el tratamiento en la lista de tratamientos del paciente y la reordena.
  		\param  t: variable de la clase Tratamiento
		\return No se devuelve ningún resultado
  		
	*/
	void guardarTratamiento (is::Tratamiento &t);

	/*!		
		\brief  Borra un tratamiento de la lista de tratamientos del paciente
  		\param  t: variable de la clase Tratamiento
		\return No se devuelve ningún resultado
  		
	*/
	void borrarTratamiento (is::Tratamiento &t);


 		/*!	
			\name Otros métodos de la clase Historial
		*/

	/*!		
		\brief  Buscar historial en la lista de historiales del paciente
  		\param  h: variable de la clase Historial.
		\return Si encuentra el historial devuelve true. En caso contrario, devuelve false.
  		
	*/
	bool buscarHistorial (is::Historial &h);

	/*!		
		\brief  Carga el historial de la lista de historiales en una clase de tipo Historial
		\param  h: variable de la clase Historial
		\return Devuelve el historial que se quiere cargar. Si no existe, devuelve el último historial de la lista, junto con un mensaje de error.
  		
	*/
	is::Cita cargarHistorial (is::Historial &h);

	/*!		
		\brief  Guarda el historial en la lista de historiales del paciente y la reordena.
  		\param  h: variable de la clase Historial
		\return No se devuelve ningún resultado
  		
	*/
	void guardarHistorial (is::Historial &h);

	/*!		
		\brief  Borra un historial de la lista de hsitoriales del paciente
  		\param  h: variable de la clase Historial
		\return No se devuelve ningún resultado
  		
	*/
	void borrarHistorial (is::Historial &h);


		/*!	
			\name Otros métodos de la clase Paciente
		*/

	/*!		
	\brief Lee por teclado los datos de un paciente    
	\pre   Ninguna
	\post  Se modifican los atributos del paciente usando valores introducidos por el teclado
	*/
	void leerPaciente();

}; //Fin de la clase 

} // Fin del espacio de nombres is

#endif // _PACIENTE_HPP_