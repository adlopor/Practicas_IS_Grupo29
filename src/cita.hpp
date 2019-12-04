/*!
	\file    cita.hpp
	\brief   Clase de una cita de un paciente de la clínica.
	\author  Adrián López Ortiz
	\date    20/11/19
	\version 1.0

*/

#ifndef __CITA_HPP__
#define __CITA_HPP__
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <ctime>
#include <cassert>

#include "macros.hpp" 

/*!	
	\namespace is
	\brief Espacio de nombres para la asignatura Ingeniería del Software

*/ 
namespace is {
 
/*!	
  	\class Cita 
  	\brief Especificaciones de la clase Cita:
  	\par   Cita perteneciente a un paciente.
*/
class Cita {

	/*!		
		\name  Atributos y métodos privados 
	*/
	private:
            //Fecha y hora
			
		 	std::string _fecha;		//!< \brief Cadena de caracteres en la que se almacena la fecha de la cita, estructura: aaaa/mm/dd.
			std::string _hora;		//!< \brief Cadena de caracteres en la que se almacena la hora, estructura: hh/mm.
	

	/*!		
		\name  Métodos públicos de la clase Paciente.
	*/
 	public:
	
	/*!	
			\name Constructor.
	*/
	Cita(std::string const &fecha ="", std::string const &hora ="")
	{
			this->setFecha(fecha);
            this->setHora(hora);
            
  	}


	/*!	
			\name Observadores.
	*/

	/*!		
			\brief  Devuelve la fecha de la cita
			\note   Función de tipo inline
			\return Cadena que representa la fecha de la cita  
  			\sa     setFecha
	*/
	inline std::string getFecha() const{return _fecha;}

	/*!		
			\brief  Devuelve la hora de la cita
			\note   Función de tipo inline
			\return Cadena que representa la hora de la cita.  
  			\sa     setHora
	*/
	inline std::string getHora() const{return _hora;}


	/*!	
			\name Modificadores.
	*/

    /*!		
			\brief  Modifica la fecha de la cita
  			\param  fecha: cadena que será la nueva fecha de la cita
  			\post   La fecha de la cita deberá ser la fecha pasada por argumento
			\return No se devuelve ningún resultado
  			\sa     getFecha
	*/
	void setFecha(std::string fecha)

    /*!		
			\brief  Modifica la hora de la cita
  			\param  hora: cadena que será la nueva hora de la cita
  			\post   La hora de la cita deberá ser la hora pasada por argumento
			\return No se devuelve ningún resultado
  			\sa     getHora
	*/
	void setHora(std::string hora)

    /*!	
	        \name Operadores
    */
	
    /*!		
	        \brief  Operador de asignacion entre objetos de tipo Cita
	        \param  c: objeto de tipo Cita
	        \post   El objeto actual es igual al objeto parámetro
	        \return Devuelve una referencia al objeto actual
    */
	Cita &operator=(const Cita &c);
		
    /*!		
	        \brief  Operador que compara la igualdad lexicográfica por la fecha y hora de dos citas
	        \param  c: objeto de tipo Cita
	        \pre    Ambas citas deben tener valores en la fecha y la hora
	        \post   Ninguna
    	    \return Devuelve true si las fechas y horas de las citas son iguales. False, en caso contrario
    */
	bool operator==(const Cita & c) const;

		
    /*!		
	        \brief  Operador que compara la desigualdad lexicográfica por fecha y hora de dos citas
	        \param  c: objeto de tipo Cita
	        \pre    Ambos cita deben tener valores en la fecha y la hora
	        \post   Ninguna
	        \return Devuelve true si la cita actual precede cronológicamente a la cita pasada como argumento. False, en caso contrario.
    */
	bool operator <(const Cita & c) const;


    /*!
            \name Funciones amigas para poder acceder a la parte privada de la clase cita.
    */

    /*!
	        \brief  Operador de inserción
	        \param  i: flujo de entrada
	        \param  c: objeto de tipo Cita
	        \pre    La Cita del parametro debe existir
	        \post   Se modifican los atributos de la Cita usando los valores insertados por el flujo de entrada
	        \return Devuelve el stream de entrada
    */
	friend std::istream &operator>>(std::istream &i, Cita &c);


    /*!		
	    	\brief  Operador de extracción
	        \param  o: flujo de salida
	        \param  c: objeto de tipo Cita
    	    \pre    La cita del parametro debe existir
	        \post   Se escriben los valores de los atributos de la Cita en flujo de salida
	        \return Devuelve el stream de salida
	*/
	friend std::ostream &operator<<(std::ostream &o, Cita const &c);


// Fin de la clase Cita
};

// Fin del espacio de nombres is
}

// Fin de _CITA_HPP_
#endif

