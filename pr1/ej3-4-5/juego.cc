#include "dados.h"
#include <iostream>

int main(int argc, char const *argv[])
{
	Dados d;
	int v[4];

	std::cout<<"dice 1: >'"<<d.getDado1()<<"'\n";
	std::cout<<"dice 2: >'"<<d.getDado2()<<"'\n\n";


	d.getUltimos1(v);
	for (int i = 0; i < 5; ++i)
	{
		std::cout<<"v["<<i<<"]="<<v[i]<<"\n";
	}
	std::cout<<"\n";
	d.getUltimos2(v);;
	for (int i = 0; i < 5; ++i)
	{
		std::cout<<"v["<<i<<"]="<<v[i]<<"\n";
	}

	std::cout<<"\ntrow\n\n";


	for (int i = 0; i < 6; ++i)
	{
		d.trow();
		std::cout<<"dice 1: >'"<<d.getDado1()<<"'\n";
		std::cout<<"dice 2: >'"<<d.getDado2()<<"'\n\n";
		d.getUltimos1(v);
		for (int i = 0; i < 5; ++i)
		{
			std::cout<<"v["<<i<<"]="<<v[i]<<"\n";
		}
		std::cout<<"\n";
		d.getUltimos2(v);
		for (int i = 0; i < 5; ++i)
		{
			std::cout<<"v["<<i<<"]="<<v[i]<<"\n";
		}
	}
	/*
	std::cout<<"trows dice 1: >'"<<d.getLanzamientos1()<<"'\n";
	std::cout<<"trows dice 2: >'"<<d.getLanzamientos2()<<"'\n\n";

	std::cout<<"sum dice 1: >'"<<d.get_sum_d1()<<"'\n";
	std::cout<<"sum dice 2: >'"<<d.get_sum_d2()<<"'\n\n";

	std::cout<<"mean dice 1: >'"<<d.getMedia1()<<"'\n";
	std::cout<<"mean dice 2: >'"<<d.getMedia2()<<"'\n\n";
	*/



	
}