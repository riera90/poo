#ifndef CRUPIER_H
#define CRUPIER_H

#include <iostream>
#include "persona.h"

using namespace std;

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
		//~Crupier();
		string getCodigo() const {return codigo_;};
		
		void setCodigo(string codigo)
		{
			//printf("test1\n");
			codigo_=codigo;
			//printf("test2\n");
			//cout<<"codigo: <"<<codigo_<<">\n";
		};

		void test(){printf("test crupier\n");};
		
};

#endif