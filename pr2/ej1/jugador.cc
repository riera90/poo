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

bool Jugador::apuesta(int tipo_apuesta, int valor_apuesta, int cantidad_apostada)
{
	//the values are assinned ot the priovate variables for lather use of them
	//in "pushApuesta"
	
	temp_apuesta_.tipo=tipo_apuesta;
	temp_apuesta_.valor=to_string(valor_apuesta);
	temp_apuesta_.cantidad=cantidad_apostada;

	pushApuesta();
	//print_last_apuesta();


	if(tipo_apuesta==1)//apuesta sencilla
	{

		return apuesta_sencilla(valor_apuesta);
	}
	return false;
}

bool Jugador::apuesta(int tipo_apuesta, string valor_apuesta, int cantidad_apostada)
{
	//the values are assinned ot the priovate variables for lather use of them
	//in "pushApuesta"
	temp_apuesta_.tipo=tipo_apuesta;
	temp_apuesta_.valor=valor_apuesta;
	temp_apuesta_.cantidad=cantidad_apostada;
	pushApuesta();

	//detects the type of betting
	if (tipo_apuesta==2) //apuesta tipo color
	{
		if (valor_apuesta=="rojo") return apuesta_color_rojo();
		else if (valor_apuesta=="negro") return apuesta_color_negro();
		else
		{
			printf("ERROR, EL VALOR DE LA APUESTA NO CORRESPONDE A NINGUN TIPO\n");
			exit(-1);
		}
	}

	if (tipo_apuesta==3) //apuesta tipo paridad
	{
		if (valor_apuesta=="par") return apuesta_par();
		else if (valor_apuesta=="impar") return apuesta_impar();
		else
		{
			printf("ERROR, EL VALOR DE LA APUESTA NO CORRESPONDE A NINGUN TIPO\n");
			exit(-1);
		}
	}

	if (tipo_apuesta==4) //apuesta tipo alto o bajo
	{
		if (valor_apuesta=="alto") return apuesta_alto();
		else if (valor_apuesta=="bajo") return apuesta_bajo();
		else
		{
			printf("ERROR, EL VALOR DE LA APUESTA NO CORRESPONDE A NINGUN TIPO\n");
			exit(-1);
		}
	}
	return false;
}

bool Jugador::apuesta_sencilla(int val)
{
	b_.trow();
	if (val==b_.get_valor())//apuesta ganada
	{
		return true;
	}
	else //apuesta peridda
	{
		return false;
	}
}

bool Jugador::apuesta_color_rojo() 
{
	b_.trow();
	if (b_.is_red())//apuesta ganada
	{
		return true;
	}
	else //apuesta peridda
	{
		return false;
	}
}

bool Jugador::apuesta_color_negro()
{
	b_.trow();
	if (b_.is_black())//apuesta ganada
	{
		return true;
	}
	else //apuesta peridda
	{
		return false;
	}
}

bool Jugador::apuesta_par()
{
	b_.trow();
	if (b_.get_valor()%2==0)//apuesta ganada
	{
		return true;
	}
	else //apuesta peridda
	{
		return false;
	}
}

bool Jugador::apuesta_impar()
{
	b_.trow();
	if (b_.get_valor()%2==1)//apuesta ganada
	{
		return true;
	}
	else //apuesta peridda
	{
		return false;
	}
}

bool Jugador::apuesta_bajo()
{
	b_.trow();
	if (b_.get_valor()<=18)//apuesta ganada
	{
		return true;
	}
	else //apuesta peridda
	{
		return false;
	}
}
bool Jugador::apuesta_alto()
{
	b_.trow();
	if (b_.get_valor()>18)//apuesta ganada
	{
		return true;
	}
	else //apuesta peridda
	{
		return false;
	}
}

void Jugador::pushApuesta()
{
	apuestas_.push_back(temp_apuesta_);
}


void Jugador::print_last_apuesta()
{
	//temp_apuesta_=apuestas_.back();
	temp_apuesta_ = apuestas_.back();
	//b.tipo_apuesta = 1;
	printf("tipo de apuesta: <%i>\n",temp_apuesta_.tipo);
	cout<<"valor de la apuesta; <"<<temp_apuesta_.valor<<">\n";
	printf("cantidad apostada: <%i>\n",temp_apuesta_.cantidad);
	printf("\n");
}

void Jugador::recordApuestas()
{
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

	std::string temp;
	std::ifstream f;
	f.open(getDNI()+".txt");

		//read the file
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
		//print_last_apuesta();


	}
	f.close();
}