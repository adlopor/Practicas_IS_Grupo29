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
#include <list>
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
class Paciente {
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

		int _indiceCitas;
		int _indiceTratamientos;
		int _indiceHistorial;
        std::list<is::Cita> 		_citas;				                            //!<  \brief Lista de citas del paciente. 
        std::list<is::Tratamiento>	_tratamientos;				                    //!<  \brief Lista de tratamientos del paciente.
        std::list<is::Historial>	_historial;				                        //!<  \brief Lista de los registros de historial del paciente.

	/*!
		\name  Métodos públicos de la clase Paciente.
	*/

  	public: 

		/*!
			\name Constructor.
		*/

		Paciente(std::string const &nombre ="", std::string const &apellidos ="", std::string const &telefono ="", std::string const &direccionPostal ="", std::string const &fechaNacimiento ="", bool const &tarjetaSanitaria = true)
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
		inline std::string getNombre() const{return _nombre;}

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
		inline std::list<is::Cita> getCitas() const{return this->_citas;}

		/*!
			\brief  Devuelve la lista de tratamientos del paciente
			\note   Función de tipo inline
			\return Listado de tratamientos del paciente 
  			\sa     setTratamientos
		*/
		inline std::list<is::Tratamiento> getTratamientos() const{return this->_tratamientos;}

		/*!
			\brief  Devuelve la lista de historial del paciente
			\note   Función de tipo inline
			\return Listado de historial del paciente 
  			\sa     setHistorial
		*/
		inline std::list<is::Historial> getHistorial() const{return this->_historial;}

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
		inline void setCitas( std::list<is::Cita> citas)
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
	        \name Métodos del Listado de Citas
    */

    /*!
	    \brief  Método que devuelve el tamaño del listado de citas
		\note	Función inline
	    \return Devuelve un valor entero con el tamaño de la lista de citas
    */
	inline int getTamanoListaCitas(){return this->_citas.size();}

	/*!
	    \brief  Método que indica si la lista de citas está vacía
		\note	Función inline
	    \return Devuelve un booleano de valor True en caso de que la lista esta vacía. False, en caso contrario.
		\sa		getTamanoListaCitas
    */
	inline bool estaVaciaListaCitas()
	{
		if(this->_citas.empty()){
			return true;
		}
		else{
			return false;
		}
	}
	
	/*!
	    \brief  Método que devuelve la posición en la que se encuentra el índice de la lista de citas
	    \note	Función Inline
		\return Devuelve un entero que indica la posición del índice de la lista de citas
    */
	inline int getIndiceListaCitas (){return this->_indiceCitas;}

	/*!
	    \brief  Método que ajusta la posición en la que se encuentra el índice de la lista de citas al inicio
	    \note	Función Inline
		\return void
		\sa		getIndiceListaCitas
    */
	inline void setIndiceListaCitasBegin (){this->_indiceCitas = 0;}

	/*!
	    \brief  Método que ajusta la posición en la que se encuentra el índice de la lista de citas al final
	    \note	Función Inline
		\return void
		\sa		getIndiceListaCitas
    */
	inline void setIndiceListaCitasEnd (){this->_indiceCitas = getTamanoListaCitas();}
	
	/*!
	    \brief  Método que avanza en una posición el índice de la lista de citas
	    \note	Función Inline
		\return void
		\sa		getIndiceListaCitas
    */
	inline void avanzarCitaAdelante (){this->_indiceCitas = (this->_indiceCitas + 1) % getTamanoListaCitas();}
	
	/*!
	    \brief  Método que devuelve la cita señalada por el índice del listado de citas
		\pre	La lista no puede estar vacía
	    \return Devuelve la cita del listado de citas a la que esté señalando el índice del listado de citas
		\sa		estaVaciaListaCitas
    */
	is::Cita getCurrentCita();

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
	    \name Métodos del Listado de Tratamientos
    */

    /*!
	    \brief  Método que devuelve el tamaño del listado de tratamientos
		\note	Función inline
	    \return Devuelve un valor entero con el tamaño de la lista de tratamientos
    */
	inline int getTamanoListaTratamientos(){return this->_tratamientos.size();}

	/*!
	    \brief  Método que indica si la lista de tratamientos está vacía
		\note	Función inline
	    \return Devuelve un booleano de valor True en caso de que la lista esta vacía. False, en caso contrario.
		\sa		getTamanoListaTratamientos
    */
	inline bool estaVaciaListaTratamientos()
	{
		if(this->_tratamientos.empty())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	/*!
	    \brief  Método que devuelve la posición en la que se encuentra el índice de la lista de tratamientos
	    \note	Función Inline
		\return Devuelve un entero que indica la posición del índice de la lista de tratamientos
    */
	inline int getIndiceListaTratamientos (){return this->_indiceTratamientos;}

	/*!
	    \brief  Método que ajusta la posición en la que se encuentra el índice de la lista de tratamientos al inicio
	    \note	Función Inline
		\return void
		\sa		getIndiceListaTratamientos
    */
	inline void setIndiceListaTratamientosBegin (){this->_indiceTratamientos = 0;}

	/*!
	    \brief  Método que ajusta la posición en la que se encuentra el índice de la lista de tratamientos al final
	    \note	Función Inline
		\return void
		\sa		getIndiceListaTratamientos
    */
	inline void setIndiceListaTratamientosEnd (){this->_indiceTratamientos = getTamanoListaTratamientos();}
	
	/*!
	    \brief  Método que avanza en una posición el índice de la lista de tratamientos
	    \note	Función Inline
		\return void
		\sa		getIndiceListaTratamientos
    */
	inline void avanzarTratamientoAdelante (){this->_indiceTratamientos = (this->_indiceTratamientos + 1) % getTamanoListaTratamientos();}
	
	/*!
	    \brief  Método que devuelve el tratamiento señalado por el índice del listado de tratamientos
		\pre	La lista no puede estar vacía
	    \return Devuelve el tratamiento del listado de tratamientos al que esté señalando el índice
		\sa		estaVaciaListaTratamientos
    */
	is::Tratamiento getCurrentTratamiento ();

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
  		\sa 	buscarTratamiento
	*/
	is::Tratamiento cargarTratamiento (is::Tratamiento &t);

	/*!
		\brief  Guarda el tratamiento en la lista de tratamientos del paciente y la reordena.
  		\param  t: variable de la clase Tratamiento
		\return No se devuelve ningún resultado
  		\sa 	buscarTratamiento
	*/
	void guardarTratamiento (is::Tratamiento &t);

	/*!
		\brief  Borra un tratamiento de la lista de tratamientos del paciente
  		\param  t: variable de la clase Tratamiento
		\return No se devuelve ningún resultado
		\sa		buscarTratamiento
	*/
	void borrarTratamiento (is::Tratamiento &t);


	/*!
	    \name Métodos del Listado de Historial
    */

    /*!
	    \brief  Método que devuelve el tamaño del listado de historial
		\note	Función inline
	    \return Devuelve un valor entero con el tamaño de la lista de historial
    */
	inline int getTamanoListaHistorial(){return this->_historial.size();}

	/*!
	    \brief  Método que indica si la lista de historial está vacía
		\note	Función inline
	    \return Devuelve un booleano de valor True en caso de que la lista esta vacía. False, en caso contrario.
		\sa		getTamanoListaHistorial
    */
	inline bool estaVaciaListaHistorial()
	{
		if(this->_historial.empty())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	/*!
	    \brief  Método que devuelve la posición en la que se encuentra el índice de la lista de historial
	    \note	Función Inline
		\return Devuelve un entero que indica la posición del índice de la lista de historial
    */
	inline int getIndiceListaHistorial (){return this->_indiceHistorial;}

	/*!
	    \brief  Método que ajusta la posición en la que se encuentra el índice de la lista de historial al inicio
	    \note	Función Inline
		\return void
		\sa		getIndiceListaHistorial
    */
	inline void setIndiceListaHistorialBegin (){this->_indiceHistorial = 0;}

	/*!
	    \brief  Método que ajusta la posición en la que se encuentra el índice de la lista de historial al final
	    \note	Función Inline
		\return void
		\sa		getIndiceListaHistorial
    */
	inline void setIndiceListaHistorialEnd (){this->_indiceHistorial = getTamanoListaHistorial();}
	
	/*!
	    \brief  Método que avanza en una posición el índice de la lista de historial
	    \note	Función Inline
		\return void
		\sa		getIndiceListaHistorial
    */
	inline void avanzarHistorialAdelante (){this->_indiceHistorial = (this->_indiceHistorial + 1) % getTamanoListaHistorial();}
	
	/*!
	    \brief  Método que devuelve el historial señalado por el índice del listado de historiales
		\pre	La lista no puede estar vacía
	    \return Devuelve el historial del listado de historiales al que esté señalando el índice
		\sa		estaVaciaListaHistoriales
    */
	is::Historial getCurrentHistorial();

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
	is::Historial cargarHistorial (is::Historial &h);

	/*!		
		\brief  Guarda el historial en la lista de historiales del paciente y la reordena.
  		\param  h: variable de la clase Historial
		\return No se devuelve ningún resultado
  		
	*/
	void guardarHistorial (is::Historial &h);

	/*!		
		\brief  Borra un historial de la lista de historiales del paciente
  		\param  h: variable de la clase Historial
		\return No se devuelve ningún resultado
  		
	*/
	void borrarHistorial (is::Historial &h);


	/*!	
		\name Funciones de E/S
	*/
		
	/*!		
		\brief Lee por teclado algunos datos personales (nombre y apellidos) de un paciente    
		\pre   Ninguna
		\post  Se modifican los atributos del paciente usando valores introducidos por el teclado
	*/
	void leerNombreApellidosPaciente();

	/*!		
		\brief Lee por teclado los datos personales (todos los strings) de un paciente    
		\pre   Ninguna
		\post  Se modifican los atributos del paciente usando valores introducidos por el teclado
	*/
	void leerPaciente();

	/*!		
		\brief Imprime por pantalla los datos personales (todos los strings) de un paciente
		\pre   El paciente debe tener sus datos cumplimentados
		\post  Ninguna
	*/
	void escribirPaciente();

    /*!	
        \name Operadores
    */

    /*!		
        \brief  Operador de asignacion entre objetos de tipo Paciente
        \param  p: objeto de tipo Paciente
        \post   El objeto actual es igual al objeto parámetro
        \return Devuelve una referencia al objeto actual
    */
	Paciente &operator=(const Paciente &p);

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
	friend std::ostream &operator<<(std::ostream &o, Paciente &p);


}; //Fin de la clase 

} // Fin del espacio de nombres is

#endif // _PACIENTE_HPP_