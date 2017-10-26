#include "dados.h"
#include <ctime>
#include <cstdlib>
#include <vector>


Dados::Dados()
{
	srand(time(NULL));
	values_d1_.resize(5,0);
	values_d2_.resize(5,0);	
	d1_=1;
	d2_=1;
	lanzamientos_d1_=lanzamientos_d2_=0;
	sum_d1_=sum_d2_=0;

	pushDado1(1);
	pushDado2(1);
}

Dados::~Dados()
{
	//destructor
}

void Dados::lanzamiento()
{	
	int val;
	val=((rand()%6)+1);
	d1_=val;
	sum_d1_ += val;
	lanzamientos_d1_++;
	pushDado1(val);

	val=((rand()%6)+1);
	d2_=val;
	sum_d2_ += val;
	lanzamientos_d2_++;
	pushDado2(val);

}


int Dados::getDado1()
{
	return d1_;
}

int Dados::getDado2()
{
	return d2_;
}

int Dados::getSuma()
{
	return d1_+d2_;
}

bool Dados::setDado1(int val)
{
	if ( val<1 or val>6 ) return false;
	
	d1_=val;
	lanzamientos_d1_++;
	sum_d1_ += val;
	pushDado1(val);
	return true;

}

bool Dados::setDado2(int val)
{
	if ( val<1 or val>6 ) return false;
	
	d2_=val;
	lanzamientos_d2_++;
	sum_d2_ += val;
	pushDado2(val);
	return true;
}

int Dados::getLanzamientos1()
{
	return lanzamientos_d1_;
}

int Dados::getLanzamientos2()
{
	return lanzamientos_d2_;
}

float Dados::getMedia1()
{
	if (lanzamientos_d1_==0)
	{
		return 0;
	}
	else
	{
		return float(sum_d1_)/float(lanzamientos_d1_);
	}
}

float Dados::getMedia2()
{
	if (lanzamientos_d2_==0)
	{
		return 0;
	}
	else
	{
		return float(sum_d2_)/float(lanzamientos_d2_);
	}
}

int Dados::get_sum_d1()
{
	return sum_d1_;
}

int Dados::get_sum_d2()
{
	return sum_d2_;
}

void Dados::getUltimos1(int* v)
{
	for (int i = 0; i < 5; ++i)
	{
		v[i]=values_d1_[i];
	}
}

void Dados::getUltimos2(int* v)
{
	for (int i = 0; i < 5; ++i)
	{
		v[i]=values_d2_[i];
	}
}

void Dados::pushDado1(int val)
{
	for (int i = 4; i > 0; --i)
	{
		values_d1_[i]=values_d1_[i-1];
	}
	values_d1_[0]=val;
}
void Dados::pushDado2(int val)
{
	for (int i = 4; i > 0; --i)
	{
		values_d2_[i]=values_d2_[i-1];
	}
	values_d2_[0]=val;
}

int Dados::getDiferencia()
{
	return( (d1_<d2_) ? (d2_-d1_) : (d1_-d2_));
}