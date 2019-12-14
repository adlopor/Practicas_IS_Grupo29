/*!
	\file    tratamiento.hpp
	\brief   Clase de un tratamiento de un paciente de la clínica.
	\author  Adrián López Ortiz
	\date    20/11/19
	\version 1.0

*/

#ifndef __TRATAMIENTO_HPP__
#define __TRATAMIENTO_HPP__

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
  	\class Tratamiento
  	\brief Especificaciones de la clase Tratamiento.
  	\par   Tratamiento perteneciente a un paciente.
*/
class Tratamiento {

	/*!		
		\name  Atributos y métodos privados 
	*/
	private:
            			
		 	std::string _fechaInicio;		//!< \brief Cadena de caracteres en la que se almacena la fecha de inicio del tratamiento, estructura: aaaa/mm/dd.
			std::string _fechaFin;			//!< \brief Cadena de caracteres en la que se almacena la fecha de fin del tratamiento, estructura: aaaa/mm/dd.
			std::string _periodicidad;		//!< \brief Cadena de caracteres en la que se almacena periodicidad del tratamiento.
			std::string _dosis;				//!< \brief Cadena de caracteres en la que se almacena la dosis del tratamiento.
	

	/*!		
		\name  Métodos públicos de la clase Tratamiento.
	*/
 	public:
	
	/*!	
			\name Constructor.
	*/
	Cita(std::string const &fechaInicio ="", std::string const &fechaFin ="", std::string const &periodicidad ="", std::string const &dosis ="")
	{
		this->setFechaInicio(fechaInicio);
        this->setFechaFin(fechaFin);
		this->setPeriodicidad(periodicidad);
		this->setDosis(dosis);
            
  	}

	/*!	
			\name Observadores.
	*/

	/*!		
			\brief  Devuelve la fecha de inicio del tratamiento
			\note   Función de tipo inline
			\return Cadena que representa la fecha de inicio del tratamiento  
  			\sa     setFechaInicio
	*/
	inline std::string getFechaInicio() const{return _fechaInicio;}

	/*!		
			\brief  Devuelve la fecha de fin del tratamiento
			\note   Función de tipo inline
			\return Cadena que representa la fecha de fin del tratamiento.  
  			\sa     setFechaFin
	*/
	inline std::string getFechaFin() const{return _fechaFin;}

	/*!		
			\brief  Devuelve la periodicidad del tratamiento
			\note   Función de tipo inline
			\return Cadena que representa a la periodicidad del tratamiento  
  			\sa     setPeriodicidad
	*/
	inline std::string getPeriodicidad() const{return _periodicidad;}

	/*!		
			\brief  Devuelve la dosis del tratamiento
			\note   Función de tipo inline
			\return Cadena que representa la dosis del tratamiento  
  			\sa     setDosis
	*/
	inline std::string getDosis() const{return _dosis;}

	/*!	
			\name Modificadores.
	*/

    /*!		
			\brief  Modifica la fecha de inicio del tratamiento
  			\note   Función de tipo inline
			\param  fechainicio: cadena que será la nueva fecha de inicio del tratamiento
  			\post   La fecha de inicio del tratamiento deberá ser la fecha pasada por argumento
			\return No se devuelve ningún resultado
  			\sa     getFechaInicio
	*/
	inline void setFechaInicio (std::string fechaInicio){

		this->_fechaInicio = fechaInicio;

		#ifndef NDEBUG
			assert( getFechaInicio() == fechaInicio );
		#endif
	}

    /*!		
			\brief  Modifica la fecha de fin del tratamiento
  			\param  fechaFin: cadena que será la fecha de fin del tratamiento
  			\post   La fecha de fin del tratamiento deberá ser la fecha pasada por argumento
			\return No se devuelve ningún resultado
  			\sa     getFechaFin
	*/
	void setFechaFin(std::string fechaFin){

		this->_fechaFin = fechaFin;
	
		#ifndef NDEBUG
			assert( getFechaFin() == fechaFin );
		#endif
	}

    /*!		
			\brief  Modifica la periodicidad del tratamiento
  			\param  periodicidad: cadena que será la periodicidad del tratamiento
  			\post   La periodicidad del tratamiento deberá ser la periodicidad pasada por argumento
			\return No se devuelve ningún resultado
  			\sa     getPeriodicidad
	*/
	void setPeriodicidad(std::string periodicidad){

		this->_periodicidad = periodicidad;
	
		#ifndef NDEBUG
			assert( getPeriodicidad() == periodicidad );
		#endif
	}

    /*!		
			\brief  Modifica la dosis del tratamiento
  			\param  dosis: cadena que será la dosis del tratamiento
  			\post   La dosis del tratamiento deberá ser la dosis pasada por argumento
			\return No se devuelve ningún resultado
  			\sa     getDosis
	*/
	void setDosis(std::string dosis){

		this->_dosis = dosis;
	
		#ifndef NDEBUG
				assert( getDosis() == dosis );
		#endif
	}


    /*!	
	        \name Operadores
    */

    /*!		
	        \brief  Operador de asignacion entre objetos de tipo Tratamiento
	        \param  t: objeto de tipo Tratamiento
	        \post   El objeto actual es igual al objeto parámetro
	        \return Devuelve una referencia al objeto actual
    */
	Tratamiento &operator=(const Tratamiento &t);

    /*!		
	        \brief  Operador que compara la igualdad lexicográfica por la fecha de inicio, de fin, la periodicidad y la dosis del tratamiento
	        \param  t: objeto de tipo Tratamiento
	        \pre    Ambas citas deben tener valores en la fecha de inicio, de fin, la periodicidad y la dosis
	        \post   Ninguna
    	    \return Devuelve true si la fecha de inicio, de fin, periodicidad y la dosis del tratamiento son iguales. False, en caso contrario
    */
	bool operator==(const Tratamiento & t) const;

    /*!
	        \brief  Operador que compara la desigualdad lexicográfica por fecha de inicio y de fin de dos tratamientos
	        \param  t: objeto de tipo Tratamiento
	        \pre    Ambos tratamientos deben tener valores en las fechas de inicio y de fin
	        \post   Ninguna
	        \return Devuelve true si el tratamiento actual precede cronológicamente al tratamiento pasado como argumento. False, en caso contrario
    */
	bool operator<(const Tratamiento & t) const;


    /*!
            \name Funciones amigas para poder acceder a la parte privada de la clase Tratamiento.
    */

    /*!
	        \brief  Operador de inserción
	        \param  i: flujo de entrada
	        \param  t: objeto de tipo Tratamiento
	        \pre    El Tratamiento del parametro debe existir
	        \post   Se modifican los atributos del Tratamiento usando los valores insertados por el flujo de entrada
	        \return Devuelve el stream de entrada
    */
	friend std::istream &operator>>(std::istream &i, Tratamiento &t);

    /*!		
	    	\brief  Operador de extracción
	        \param  o: flujo de salida
	        \param  t: objeto de tipo Tratamiento
    	    \pre    El Tratamiento del parametro debe existir
	        \post   Se escriben los valores de los atributos del Tratamiento en flujo de salida
	        \return Devuelve el stream de salida
	*/
	friend std::ostream &operator<<(std::ostream &o, Tratamiento const &t);


// Fin de la clase Tratamiento
};

// Fin del espacio de nombres is
}

// Fin de _TRATAMIENTO_HPP_
#endif