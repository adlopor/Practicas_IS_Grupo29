/*!

  \file   funcionesAuxiliares.hpp
  \brief  Prototipos de las funciones auxiliares del programa principal
  \author Adrián López Ortiz
  \date   20/11/19

*/

#ifndef _FUNCIONESAUXILIARES_HPP_
#define _FUNCIONESAUXILIARES_HPP_

#include "paciente.hpp"
#include "cita.hpp"
#include "tratamiento.hpp"
#include "historial.hpp"

#include "macros.hpp"

namespace is
{
	/*! 
		\brief   Muestra el menú del programa principal 
		\return  Devuelve el número de opción elegido
	*/
  	int menu();

	/*! 
		\brief  Comprueba que la lista de pacientes actual del programa estén vacíos
		\param	listaPacientes: la lista de pacientes del programa
		\return Booleano que devuelve True si la lista de pacientes del programa está vacía. False, en caso contrario
		\sa		menu
	*/
	bool comprobarListaPacientesVacia(std::list<is::Paciente> &listaPacientes);

	/*! 
		\brief  Función auxiliar que ayuda a la carga de la lista de pacientes desde un fichero de texto
		\param  listaPacientes: lista de Pacientes de la clínica
		\param	nombreFichero: cadena que almacena el nombre del fichero de texto que contiene la base de datos con la lista de pacientes
		\return Booleano que devuelve True si carga con éxito el fichero que contiene la lista de pacientes. False, en caso contrario
    	\sa     comprobarListaPacientesVacia
	*/
	bool cargarFichero(std::string const &nombreFichero, std::list<is::Paciente> &listaPacientes);

	/*! 
		\brief  Carga la lista de paciente desde un fichero
		\param  listaPacientes: lista de Pacientes de la clínica
		\return void
    	\sa     comprobarListaPacientesVacia cargarFichero
	*/
	void cargarListaPacientes(std::list<is::Paciente> &listaPacientes);

	/*! 
		\brief  Función auxiliar que ayuda a la grabación de la lista de pacientes en un fichero de texto
		\param  listaPacientes: lista de Pacientes de la clínica
		\param	nombreFichero: cadena que almacena el nombre del fichero de texto que contendrá la base de datos con la lista de pacientes
		\return Booleano que devuelve True si graba con éxito en el fichero que contendrá la lista de pacientes. False, en caso contrario
    	\sa     comprobarListaPacientesVacia
	*/
	bool grabarFichero(std::string const &nombreFichero, std::list<is::Paciente> &listaPacientes);

	/*! 
		\brief  Carga la lista de pacientes desde un fichero
		\param  listaPacientes: lista de Pacientes de la clínica
		\return void
    	\sa     comprobarListaPacientesVacia grabarFichero
	*/
	void grabarListaPacientes(std::list<is::Paciente> &listaPacientes);

	/*! 
		\brief  Añade a la lista de pacientes un nuevo paciente con sus datos personales (las citas, tratamiento e historial estará vacío, ya que es un paciente nuevo)
		\param  listaPacientes: lista de Pacientes de la clínica
		\return void
		\sa buscarPaciente
	*/
	void darAltaPaciente(std::list<is::Paciente> &listaPacientes);

	/*!		
		\brief  Busca a un paciente en la lista de pacientes
  		\param  listaPacientes: lista de Pacientes de la clínica
		\param	p: variable de clase Paciente en la que se almacenará el paciente encontrado
		\return Si encuentra el paciente devuelve true. En caso contrario, devuelve false.
	*/
	bool buscarPaciente (std::list<is::Paciente> &listaPacientes, is::Paciente &p);

	/*!		
		\brief  Carga el paciente de la lista de pacientes en una clase de tipo Paciente
		\param  listaPacientes: lista de Pacientes de la clínica
		\param	p: variable de clase Paciente
		\return void
		\sa buscarPaciente
  		
	*/
	void cargarPaciente (std::list<is::Paciente> &listaPacientes, is::Paciente &p);

	/*!		
		\brief  Guarda el paciente en la lista de pacientes y la reordena.
  		\param  listaPacientes: lista de Pacientes de la clínica
		\param	p: variable de clase Paciente
		\return No se devuelve ningún resultado
  		
	*/
	void guardarPaciente (std::list<is::Paciente> &listaPacientes, is::Paciente &p);

	/*!		
		\brief  Borra un paciente de la lista de pacientes
  		\param  listaPacientes: lista de Pacientes de la clínica
		\param	p: variable de clase Paciente
		\return No se devuelve ningún resultado
  		
	*/
	void borrarPaciente (std::list<is::Paciente> &listaPacientes, is::Paciente &p);

	/*!		
		\brief  Muestra por pantalla el listado de pacientes de la clínica, (sus datos personales)
  		\param  listaPacientes: lista de Pacientes de la clínica
		\return void
  		\sa 	buscarPaciente
	*/
	void escribirListaPacientes (std::list<is::Paciente> &listaPacientes);

	/*!		
		\brief  Modifica los datos personales de un paciente de la lista de pacientes
  		\param  listaPacientes: lista de Pacientes de la clínica
		\param	p: variable de clase Paciente
		\return No se devuelve ningún resultado
	*/
	void modificarPaciente (std::list<is::Paciente> &listaPacientes, is::Paciente &p);

	/*!		
		\brief  Muestra el listado de citas de un paciente
  		\param  listaPacientes: lista de Pacientes de la clínica
		\param	p: variable de clase Paciente
		\return No se devuelve ningún resultado
	*/
	void consultarCitasPaciente (std::list<is::Paciente> &listaPacientes, is::Paciente &p);

	/*!
		\brief	Busca a un paciente en el sistema y le añade una cita en caso de que este disponible para ese momento
  		\param	listaPacientes: lista de Pacientes de la clínica
		\param	p: variable de la clase Paciente
		\param	c: variable de la clase Cita
		\return	No se devuelve ningún resultado
	*/
	void anadirCita (std::list<is::Paciente> &listaPacientes, is::Paciente &p, is::Cita &c);

	/*!
		\brief	Busca a un paciente en el sistema y le modifica una cita ya existente
  		\param	listaPacientes: lista de Pacientes de la clínica
		\param	p: variable de la clase Paciente
		\param	c: variable de la clase Cita
		\return	No se devuelve ningún resultado
	*/
	void modificarCita (std::list<is::Paciente> &listaPacientes, is::Paciente &p, is::Cita &c);

	/*!
		\brief	Busca a un paciente en el sistema y le borra/cancela una cita ya existente
  		\param	listaPacientes: lista de Pacientes de la clínica
		\param	p: variable de la clase Paciente
		\param	c: variable de la clase Cita
		\return	No se devuelve ningún resultado
	*/
	void cancelarCita (std::list<is::Paciente> &listaPacientes, is::Paciente &p, is::Cita &c);

	/*!		
		\brief  Muestra el listado de historiales de un paciente
  		\param  listaPacientes: lista de Pacientes de la clínica
		\param	p: variable de clase Paciente
		\return No se devuelve ningún resultado
	*/
	void consultarHistorialPaciente (std::list<is::Paciente> &listaPacientes, is::Paciente &p);

	/*!
		\brief	Busca a un paciente en el sistema y le añade un registro de historial en caso de que no exista ya
  		\param	listaPacientes: lista de Pacientes de la clínica
		\param	p: variable de la clase Paciente
		\param	h: variable de la clase Historial
		\return	No se devuelve ningún resultado	
	*/
	void anadirHistorial (std::list<is::Paciente> &listaPacientes, is::Paciente &p, is::Historial &h);

	/*!		
		\brief  Muestra el listado de tratamientos de un paciente
  		\param  listaPacientes: lista de Pacientes de la clínica
		\param	p: variable de clase Paciente
		\return No se devuelve ningún resultado
	*/
	void consultarTratamientosPaciente (std::list<is::Paciente> &listaPacientes, is::Paciente &p);

	/*!
		\brief	Busca a un paciente en el sistema y le añade un tratamiento en caso de que no exista ya
  		\param	listaPacientes: lista de Pacientes de la clínica
		\param	p: variable de la clase Paciente
		\param	t: variable de la clase Tratamiento
		\return	No se devuelve ningún resultado
	*/
	void anadirTratamiento (std::list<is::Paciente> &listaPacientes, is::Paciente &p, is::Tratamiento &t);
	
	/*!
		\brief	Busca a un paciente en el sistema y le borra/cancela un tratamiento ya existente
  		\param	listaPacientes: lista de Pacientes de la clínica
		\param	p: variable de la clase Paciente
		\param	t: variable de la clase Tratamiento
		\return	No se devuelve ningún resultado
	*/
	void cancelarTratamiento (std::list<is::Paciente> &listaPacientes, is::Paciente &p, is::Tratamiento &t);
	
	/*!
		\brief	Muestra todas las citas de cada uno de los pacientes que pertenecen a la base de datos del sistema, que coincidan con la fecha introducida por teclado
  		\param	listaPacientes: lista de Pacientes de la clínica
		\return	No se devuelve ningún resultado
	*/
	void consultarCitasDiaPacientes (std::list<is::Paciente> &listaPacientes);

} // Fin del espacio de nombres is

#endif // _PACIENTE_HPP_