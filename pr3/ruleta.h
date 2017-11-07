#ifndef _RULETA_H
#define _RULETA_H

#include "crupier.h"
#include "jugador.h"
#include "bola.h"
#include <string>
#include <list>

using namespace std;

class Ruleta
{
	private:
		int banca_;
		Bola bola_;
		list<Jugador> jugadores_;
		Crupier crupier_;

	public:
		Ruleta(Crupier initCrupier);
		int getBanca() {return(banca_);}
		bool setBanca(int banca);
		int getBola(){return(bola_.get_valor());}
		bool setBola(int bola);
		Crupier getCrupier(){return(crupier_);}
		void setCrupier(Crupier crupier);
		list<Jugador> getJugadores(){return(jugadores_);}
		bool addJugador(Jugador jugador);
		int deleteJugador(Jugador jugador);
		int deleteJugador(string DNI);
		void escribeJugadores();
		void leeJugadores();
		void giraRuleta(){bola_.trow();};
		void getPremios();
		
		int apuesta_ganada(int cant, int en_contra);
		int apuesta_perida(int cant, int en_contra);



//--------------------------------------------------------------------


		void test_print_list(list<Jugador> jugadores);
		void test_print_list (list<Apuesta> jugadores);
};

#endif
