#ifndef BOLA_H
#define BOLA_H

class Bola
{
private:
	int valor_;
public:
	bool set_valor(int a)
	{
		if (a<=0 and a>=36)
		{
			valor_=a;
			return true;
		}
		return false;
	};
	Bola(){valor_=0;};
	void trow(){valor_=5;};
	int get_valor(){return valor_;};
	bool is_red()
	{
		if (   get_valor()==5
			or get_valor()==7
			or get_valor()==9
			or get_valor()==12
			or get_valor()==14
			or get_valor()==16
			or get_valor()==18
			or get_valor()==19
			or get_valor()==21
			or get_valor()==23
			or get_valor()==25
			or get_valor()==27
			or get_valor()==30
			or get_valor()==32 
			or get_valor()==34
			or get_valor()==36)
		{
			return true;
		}
		else return false;
	};

	bool is_black()
	{
		if(is_red())return false;
		else return true;
	};
	//~Bola();

};


#endif