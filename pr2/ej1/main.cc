#include "persona.h"
#include "jugador.h"
#include <cstdlib>
#include <iostream>
#include <list>

void print_class(*class a);
class a
{
	public:
		int a;
};


int main(int argc, char const *argv[])
{
	std::string DNI="15101010E";
	std::string nombre="pepe";
	Persona p(DNI);

	p.print_all();

	std::cout<<"apellidos y nombres: <"<<p.getApellidosyNombre()<<">\n";
	std::cout<<"\n\n";







	std::list <class a> l_a;
//	c_a.push_back('a');
	

	return 0;
}

void print_class(*class a)
{


}