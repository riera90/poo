#include "bola.h"
#include <iostream>

int main(int argc, char const *argv[])
{
	Bola b;
	b.trow();
	std::cout<<b.get_valor()<<"\n";
	if (b.is_red())
	{
		printf("rojo\n");
	}
	else printf("negro\n");

	return 0;
}