#include "jugador.h"
#include <fstream>
#include <cstdio>
#include <cstring>
#include <iostream>


Jugador::Jugador(string DNI,
				string codigo,	
				string nombre,
				string apellidos,
				string direccion,
				string localidad,
				string provincia,
				string pais):
					Persona (DNI,
							nombre,
							apellidos,
							direccion,
							localidad,
							provincia,
							pais)
{
	dinero_=1000;
	codigo_=codigo;
}

void Jugador::apuesta(int tipo_apuesta, int valor_apuesta, int cantidad_apostada)
{
	//the values are assinned ot the priovate variables for lather use of them
	//in "pushApuesta"
	apuesta(tipo_apuesta,to_string(valor_apuesta),cantidad_apostada);
}

void Jugador::apuesta(int tipo_apuesta, string valor_apuesta, int cantidad_apostada)
{
	//the values are assinned ot the priovate variables for lather use of them
	//in "pushApuesta"
	temp_apuesta_.tipo=tipo_apuesta;
	temp_apuesta_.valor=valor_apuesta;
	temp_apuesta_.cantidad=cantidad_apostada;
	pushApuesta();

	
}



void Jugador::pushApuesta()
{
	apuestas_.push_back(temp_apuesta_);
}



void Jugador::recordApuestas()
{
	//saves the bets onto a file named with the player's dni
	std::ofstream f;
	f.open(getDNI()+".txt");
	int i=apuestas_.size();
	while (i>0)
	{
		i--;
		temp_apuesta_ = apuestas_.front();
		f<<temp_apuesta_.tipo;
		f<<",";
		f<<temp_apuesta_.valor;
		f<<",";
		f<<temp_apuesta_.cantidad;
		f<<"\n";
		apuestas_.pop_front();
	}


	f.close();
	
}

void Jugador::setApuestas()
{
	//read the file of the player's bets 
	//(named with the player's dni)
	//and charges it into the class mem

	std::string temp;
	std::ifstream f;
	f.open(getDNI()+".txt");

		//read the file og the player's bets 
		//(named with the player's dni)
	while (1)
	{

		//read form the file
		if(!std::getline(f,temp,',')) break;
		temp_apuesta_.tipo=atoi(temp.c_str());
		std::getline(f,temp,',');
		temp_apuesta_.valor=temp;
		std::getline(f,temp,'\n');
		temp_apuesta_.cantidad=atoi(temp.c_str());

		//pushes the struct onto the future retun list
		apuestas_.push_back(temp_apuesta_);


	}
	f.close();
}


void Jugador::clear(){
	apuestas_.clear();
}



//dev
void Jugador::print_last_apuesta()
{
	temp_apuesta_ = apuestas_.back();
	printf("tipo de apuesta: <%i>\n",temp_apuesta_.tipo);
	cout<<"valor de la apuesta; <"<<temp_apuesta_.valor<<">\n";
	printf("cantidad apostada: <%i>\n",temp_apuesta_.cantidad);
	printf("\n");
}
