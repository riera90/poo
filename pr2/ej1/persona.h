#ifndef PERSONA_H
#define PERSONA_H

#include <string>

using namespace std;

class Persona
{

	private:
		string DNI_;
		string nombre_;
		string apellidos_;
		string direccion_;
		string localidad_;
		string provincia_;
		string pais_;

	public:
		Persona(string DNI,
				string nombre="",
				string apellidos="",
				string direccion="",
				string localidad="",
				string provincia="",
				string pais="");
		//~Persona();

		string getDNI() const {return DNI_;};
		string getNombre() const {return nombre_;};
		string getApellidos() const {return apellidos_;};
		string getDireccion() const {return direccion_;};
		string getLocalidad() const {return localidad_;};
		string getProvincia() const {return provincia_;};
		string getPais() const {return pais_;};
		string getApellidosyNombre() const {return apellidos_+", "+nombre_;};
	
		void setDNI(string data){DNI_=data;};
		void setNombre(string data){nombre_=data;};
		void setApellidos(string data){apellidos_=data;};
		void setDireccion(string data){direccion_=data;};
		void setLocalidad(string data){localidad_=data;};
		void setProvincia(string data){provincia_=data;};
		void setPais(string data){pais_=data;};

		void print_all();
			//debug function
};

#endif