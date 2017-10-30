#include "persona.h"
#include "jugador.h"
#include <cstdlib>
#include <iostream>
#include <list>


//struct Apuestas print_class(class Apuestas* a);


int main(int argc, char const *argv[])
{
	

	Jugador a("dni","codigo");
	a.apuesta(1,2,3);
	a.apuesta(1,22,33);
	a.apuesta(1,222,333);

	//a.print_last_apuesta();
	a.setApuestas();
	Jugador b("dni","codigo2");

	b.getApuestas();
	b.setDNI("dni2");
	b.setApuestas();



	

	return 0;
}

/*
struct Apuestas print_class(class Apuestas* a)
{
	a->a=0;
	a->b=1;
	//return a;
}*/