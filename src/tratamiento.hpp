#ifndef TRATAMIENTO_H
#define TRATAMIENTO_H
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


class Historial
{
	private:

		string _nombre;
		string _fecha_inicio;
		string _fecha_fin;
		string _periodicidad;
		string _dosis;


	public:


		Historial()
		{

		}

		Historial(string nombre="", string fecha_inicio="", string fecha_fin="", string periodicidad="", string dosis="")
		{
			_nombre=nombre;
			_fecha_inicio=fecha_inicio;
			_fecha_fin=fecha_fin;
			_periodicidad= periodicidad;
			_dosis= dosis;
		}

		string getNombre()
		{
			return _nombre;
		}

		string getFechaInicio()
		{
			return _fecha_inicio;
		}

		string getFechaFin()
		{
			return _fecha_fin;
		}

		string getPeriodicidad()
		{
			return _periodicidad;
		}

		string getDosis()
		{
			return _dosis;
		}



		void setNombre(string h)
		{
			_nombre=h;
		}

		void setFechaInicio(string h)
		{
			_fecha_inicio=h;
		}

		void setFechaFin(string h)
		{
			_fecha_fin=h;
		}

		void setPeriodicidad(string h)
		{
			_periodicidad=h;
		}

		void setDosis(string h)
		{
			_dosis=h;
		}
};

#endif