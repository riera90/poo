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



void Persona::print_all()
{
	cout<<"DNI: <"<<DNI_<<">\n";
	cout<<"nombre: <"<<nombre_<<">\n";
	cout<<"apellidos: <"<<apellidos_<<">\n";
	cout<<"direccion: <"<<direccion_<<">\n";
	cout<<"localidad: <"<<localidad_<<">\n";
	cout<<"provincia: <"<<provincia_<<">\n";
	cout<<"pais: <"<<pais_<<">\n";
}