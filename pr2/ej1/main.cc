#include "persona.h"
#include <cstdlib>
#include <iostream>


int main(int argc, char const *argv[])
{
	std::string DNI="15101010E";
	std::string nombre="pepe";
	Persona p(DNI,nombre,"apellidos");
	p.print_all();
	std::cout<<"apellidos y nombres: "<<p.getApellidosyNombre()<<"\n";
	std::cout<<"\n\n";
	Persona q("5");
	q.print_all();
	q=p;
	std::cout<<"\n\n";
	q.print_all();

	return 0;
}