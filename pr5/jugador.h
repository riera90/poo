#ifndef JUGADOR_H
#define JUGADOR_H

#include "persona.h"
#include "bola.h"
#include <list>


//using namespace std;
struct Apuesta
{
	int tipo = -1;
	string valor ="";
	int cantidad = -1;	
};



class Jugador : public Persona, private Bola
{
private:
	int tipo_apuesta_, valor_apuesta_, cantidad_apostada_;
	std::string valor_apuesta_string_;



	int dinero_;
	string codigo_;
	

	std::list <Apuesta> apuestas_;

	Apuesta temp_apuesta_;

	
	Bola b_;


public:
	Jugador(string codigo,
			string DNI,
			string nombre="",
			string apellidos="",
			string direccion="",
			string localidad="",
			string provincia="",
			string pais="");

	void recordApuestas();
		//saves the bets onto a file named with the player's dni

	void apuesta(int tipo_apuesta, int valor_apuesta, int cantidad_apostada);
	void apuesta(int tipo_apuesta, string valor_apuesta, int cantidad_apostada);
		//the values are assinned ot the private variables for later use of them
		//in "pushApuesta"
	

	void setDinero(int val){dinero_=val;};
	void setCodigo(string val){codigo_=val;};//codigo de la apuesta
	int getDinero() const {return dinero_;};
	string getCodigo() const {return codigo_;};
	void setApuestas();
		//read the file of the player's bets 
		//(named with the player's dni)
		//and charges it into the class mem
	
	std::list <struct Apuesta> getApuestas() const {return apuestas_;};


	void pushApuesta();
		//make push of a bet into the list

	void clear();
		//clear the players bets

	
	void print_last_apuesta();
		//prints the last bet

};

#endif