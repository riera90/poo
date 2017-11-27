#ifndef CRUPIER_H
#define CRUPIER_H

#include <iostream>
#include "persona.h"

using namespace std;


/*
the class crupier simulates a crupier of a table
the class cruìer is a persona
*/
class Crupier : public Persona
{
	private:
		string codigo_;
		
	public:
		Crupier(string DNI,
				string codigo,
				string nombre="",
				string apellidos="",
				string direccion="",
				string localidad="",
				string provincia="",
				string pais="");
		
		string getCodigo() const {return codigo_;};
		
		void setCodigo(string codigo){codigo_=codigo;};
		
};

#endif