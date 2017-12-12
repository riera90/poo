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
		int apuesta_ganada(int cant, int en_contra);
		int apuesta_perida(int cant);

	public:
		Ruleta(Crupier initCrupier);
			//constructor of the class
		int getBanca() {return(banca_);}
		bool setBanca(int banca);
		int getBola(){return(bola_.get_valor());}
		bool setBola(int bola);
		Crupier getCrupier(){return(crupier_);}
		void setCrupier(Crupier crupier);
		list<Jugador> getJugadores(){return(jugadores_);}
		bool addJugador(Jugador jugador);
			//adds a player to the table
		int deleteJugador(Jugador jugador);
		int deleteJugador(string DNI);
			//remove the player from the table
		void escribeJugadores();
			//writes the players bets on a file named after his DNI
		void leeJugadores();
			//reads the players bets of a file named after his DNI
		void giraRuleta(){bola_.trow();};
		void getPremios();
			//aplies the bets gains or losses to the players credits




//--------------------------------------------------------------------


		void print_list(list<Jugador> jugadores);
		void print_list (list<Apuesta> jugadores);
			//prints the lsit of players or bets
};

#endif
