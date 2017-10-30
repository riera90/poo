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



class Jugador : public Persona
{
private:
	int tipo_apuesta_, valor_apuesta_, cantidad_apostada_;
	std::string valor_apuesta_string_;
	bool estado_apuesta_;


	int dinero_;
	string codigo_;
	

	std::list <struct Apuesta> apuestas_;

	Apuesta temp_apuesta_;

	
	Bola b_;

	bool apuesta_sencilla(int val);
		//apuesta a un valor especifico
	bool apuesta_color_rojo();
	bool apuesta_color_negro();
		//apuestas a un color, el color es una cualidad del objeto "Bola"
	bool apuesta_par();
	bool apuesta_impar();
		//apuesta a la paridad eel valor
	bool apuesta_bajo();
		//apuesta a que el número es menor o igual que 18
	bool apuesta_alto();
		//apuesta a que el número es mayor que 18
	void pushApuesta();
		//hace push a una estrunctura de apuesta en la lista de apuestas

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

	bool apuesta(int tipo_apuesta, int valor_apuesta, int cantidad_apostada);
	bool apuesta(int tipo_apuesta, string valor_apuesta, int cantidad_apostada);

	

	void setDinero(int val){dinero_=val;};
	void setCodigo(string val){codigo_=val;};
	int getDinero() const {return dinero_;};
	string getCodigo() const {return codigo_;};
	void setApuestas();
	std::list <struct Apuesta> getApuestas() const {return apuestas_;};


	//dev
	void print_last_apuesta();
	std::list <struct Apuesta> list_apuestas;

};

#endif