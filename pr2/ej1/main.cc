#include "persona.h"
#include <cstdlib>
#include <iostream>
#include <list>


int main(int argc, char const *argv[])
{
	std::string DNI="15101010E";
	std::string nombre="pepe";
	Persona p(DNI);

	p.print_all();

	std::cout<<"apellidos y nombres: <"<<p.getApellidosyNombre()<<">\n";
	std::cout<<"\n\n";


	std::list <int>a;
	a.push_back(3);
	printf("%i\n",a.back() );

	return 0;
}