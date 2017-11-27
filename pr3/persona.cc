#include "persona.h"
#include <cstdlib>
#include <iostream>

using namespace std;


Persona::Persona(string DNI,
				string nombre,
				string apellidos,
				string direccion,
				string localidad,
				string provincia,
				string pais)

{
	//constructor
	DNI_=DNI;
	nombre_=nombre;
	apellidos_=apellidos;
	direccion_=direccion;
	localidad_=localidad;
	provincia_=provincia;
	pais_=pais;
}