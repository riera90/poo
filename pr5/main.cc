#include "persona.h"
#include "jugador.h"
#include "crupier.h"
#include "ruleta.h"
#include <cstdlib>
#include <iostream>
#include <list>


//struct Apuestas print_class(class Apuestas* a);


int main(int argc, char const *argv[])
{


	Crupier c("dni1","1");
	Crupier c2("dni2","2");

	Ruleta r(c);
	Ruleta r2(c2);

	Jugador j1("dni1","codigo1");
	Jugador j2("dni2","codigo2");

	r.addJugador(j1);
	r.addJugador(j2);

	list<Jugador> jugadores;
	jugadores=r.getJugadores();
	printf("------------------------------------\n");
	r.test_print_list(jugadores);

	r.deleteJugador("dni1");
	jugadores=r.getJugadores();

	printf("---------------------------after delete---------\n");
	r.test_print_list(jugadores);

	r.escribeJugadores();

	return 0;
}