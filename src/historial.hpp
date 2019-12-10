/*!
	\file    historial.hpp
	\brief   Clase del historial de un paciente de la clínica.
	\author  Adrián López Ortiz
	\date    20/11/19
	\version 1.0

*/

#ifndef __HISTORIAL_HPP__
#define __HISTORIAL_HPP__

#include <iostream>
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
  	\class Historial 
  	\brief Especificaciones de la clase Historial.
  	\par   Historial perteneciente a un paciente.
*/
class Historial {

	/*!		
		\name  Atributos y métodos privados 
	*/
	private:
            //Fecha y hora
			
		 	std::string _motivoConsulta;		//!< \brief Cadena de caracteres en la que se almacena el motivo de la consulta.
            std::string _fecha;		            //!< \brief Cadena de caracteres en la que se almacena la fecha de la cita, estructura: aaaa/mm/dd.
	
	/*!		
		\name  Métodos públicos de la clase Historial.
	*/
 	public:
	
	/*!	
			\name Constructor.
	*/
	Cita(std::string motivoConsulta ="", std::string const &fecha ="")
	{
			this->setMotivoConsulta(motivoConsulta);
            this->setFecha(fecha);
  	}


	/*!	
			\name Observadores.
	*/

    
	/*!		
			\brief  Devuelve el motivo de la consulta 
			\note   Función de tipo inline
			\return Cadena que el motivo de consulta de la cita  
  			\sa     setMotivoConsulta
	*/
	inline std::string getMotivoConsulta() const{return _motivoConsulta;}

	/*!		
			\brief  Devuelve la fecha de la cita
			\note   Función de tipo inline
			\return Cadena que representa la fecha de la cita  
  			\sa     setFecha
	*/
	inline std::string getFecha() const{return _fecha;}

	/*!	
			\name Modificadores.
	*/
    //Me quedo por aquí
    /*!		
			\brief  Modifica la hora de la cita
  			\note   Función de tipo inline
			\param  motivoConsulta: cadena que será el nuevo motivo de consulta
            \post   La hora de la cita deberá ser la hora pasada por argumento
			\return No se devuelve ningún resultado
  			\sa     getMotivoConsulta
	*/
	inline void setMotivoConsulta(std::string motivoConsulta){

		this->_motivoConsulta = motivoConsulta;

	}


    /*!		
			\brief  Modifica la fecha de la cita
  			\note   Función de tipo inline
			\param  fecha: cadena que será la nueva fecha de la cita
  			\post   La fecha de la cita deberá ser la fecha pasada por argumento
			\return No se devuelve ningún resultado
  			\sa     getFecha
	*/
	inline void setFecha(std::string fecha){

		this->_fecha = fecha;

	}

    
    /*!	
	        \name Operadores
    */
	
    /*!		
	        \brief  Operador de asignacion entre objetos de tipo Historial
	        \param  h: objeto de tipo Historial
	        \post   El objeto actual es igual al objeto parámetro
	        \return Devuelve una referencia al objeto actual
    */
	Historial &operator=(const Historial &h);
		
    /*!		
	        \brief  Operador que compara la igualdad lexicográfica por el motivo de consulta y la fecha dos historiales
	        \param  h: objeto de tipo Historial
	        \pre    Ambos historiales deben tener valores en el motivo de consulta y la fecha
	        \post   Ninguna
    	    \return Devuelve true si los motivo de consulta y las fechas del historial del paciente son iguales. False, en caso contrario
    */
	bool operator==(const Historial & h) const;

		
    /*!		
	        \brief  Operador que compara la desigualdad lexicográfica por el motibo de consulta y la fecha de dos historiales
	        \param  h: objeto de tipo Historial
	        \pre    Ambos historiales deben tener valores en el motivo de consulta y la fecha
	        \post   Ninguna
	        \return Devuelve true si el historial actual precede cronológicamente al historial pasado como argumento. False, en caso contrario.
    */
	bool operator <(const Historial & h) const;


    /*!
            \name Funciones amigas para poder acceder a la parte privada de la clase Historial.
    */

    /*!
	        \brief  Operador de inserción
	        \param  i: flujo de entrada
	        \param  h: objeto de tipo Historial
	        \pre    El historial del parametro debe existir
	        \post   Se modifican los atributos del Historial usando los valores insertados por el flujo de entrada
	        \return Devuelve el stream de entrada
    */
	friend std::istream &operator>>(std::istream &i, Historial &h);


    /*!		
	    	\brief  Operador de extracción
	        \param  o: flujo de salida
	        \param  h: objeto de tipo Historial
    	    \pre    El historial del parametro debe existir
	        \post   Se escriben los valores de los atributos del Historial en flujo de salida
	        \return Devuelve el stream de salida
	*/
	friend std::ostream &operator<<(std::ostream &o, Historial const &h);


// Fin de la clase Historial
};

// Fin del espacio de nombres is
}

// Fin de _CITA_HPP_
#endif