#ifndef TRATAMIENTO_H
#define TRATAMIENTO_H
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


class Historial
{
	private:

		string nombre_;
		string fecha_inicio_;
		string fecha_fin_;
		string periodicidad_;
		string dosis_;


	public:


		Historial()
		{

		}

		Historial(string nombre, string fecha_inicio, string fecha_fin, string periodicidad, string dosis)
		{
			nombre_=nombre;
			fecha_inicio_=fecha_inicio;
			fecha_fin_=fecha_fin;
			periodicidad_= periodicidad;
			dosis_= dosis;
		}

		string getNombre()
		{
			return nombre_;
		}

		string getFechaInicio()
		{
			return fecha_inicio_;
		}

		string getFechaFin()
		{
			return fecha_fin_;
		}

		string getPeriodicidad()
		{
			return periodicidad_;
		}

		string getDosis()
		{
			return dosis_;
		}



		void setNombre(string h)
		{
			nombre_=h;
		}

		void setFechaInicio(string h)
		{
			fecha_inicio_=h;
		}

		void setFechaFin(string h)
		{
			fecha_fin_=h;
		}

		void setPeriodicidad(string h)
		{
			periodicidad_=h;
		}

		void setDosis(string h)
		{
			dosis_=h;
		}
};

#endif