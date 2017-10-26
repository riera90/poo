#include "jugador.h"



Jugador::Jugador(string codigo,
				string DNI,
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

	if(tipo_apuesta==1)//apuesta sencilla
	{

		return apuesta_sencilla(valor_apuesta);
	}
	return false;
}

bool Jugador::apuesta(int tipo_apuesta, string valor_apuesta, int cantidad_apostada)
{
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
	if (/*valor*//*operador*/b_.get_valor())//apuesta ganada
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
	if (/*valor*//*operador*/b_.get_valor())//apuesta ganada
	{
		return true;
	}
	else //apuesta peridda
	{
		return false;
	}
}