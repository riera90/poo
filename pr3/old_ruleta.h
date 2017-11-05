#ifndef RULETA_h
#define RULETA_h
#include "bola.h"
#include "jugador.h"
#include "crupier.h"
#include <iostream>


class Ruleta
{

private:
	int banca_;
	std::list <Jugador> jugadores_;
	Bola bola;


public:
	Crupier *crupier;
	Ruleta(Crupier& obj) : crupier{&obj}
	{
		banca_=1000000;
	};

	int getBanca(){return banca_;};
	int getBola (){return bola.get_valor();};

	bool setBanca(int a)
	{
		if (a>=0)
		{
			banca_=a;
			return true;
		}
		return false;
	};
	bool setBola (int a){return bola.set_valor(a);};

	Crupier getCrupier(){return *crupier;};
	void setCrupier(Crupier& obj){*crupier=obj;};

	std::list<Jugador> getJugadores(){return(jugadores_);}
	bool addJugador(Jugador& jug);

    int deleteJugador(Jugador& juga);
    int deleteJugador(std::string DNI);
    void escribeJugadores();
    void leeJugadores();
    void giraRuleta(){bola.trow();};
    void getPremios();
    
};


#endif