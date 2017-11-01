#ifndef RULETA_h
#define RULETA_h
#include "bola.h"
#include "jugador.h"
#include "crupier.h"


class Ruleta
{

private:
	int banca_;
	//std::list <Jugador> jugadores_;
	Bola bola;
	//Crupier cr;


	//

protected:

public:
	Ruleta(const Crupier& obj);
	Crupier *obj;

	int getBanca (){return banca_;};
	int getBola (){return bola.get_valor();};

	bool set_valor(int a)
	{
		if (a<=0)
		{
			banca_=a;
			return true;
		}
		return false;
	};
	bool setBola (int a){return bola.set_valor(a);};
	//Crupier getCrupier(){return *crupier;};
	//void setCrupier();
	void test()
	{
		printf("test\n");
		//Crupier obj=*crupier;
		//obj.setCodigo("123");
		//crupier->setCodigo("123");
		//printf("test2\n");
		obj->test();
	};

};


#endif