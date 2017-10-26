#ifndef BOLA_H
#define BOLA_H

class Bola
{
private:
	int valor_;
public:
	Bola(){valor_=0;};
	void trow(){valor_=6;};
	int get_valor(){return valor_;};
	bool is_red();
	bool is_black();
	//~Bola();
	
};


#endif