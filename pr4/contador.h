#ifndef _CONTADOR_H_
#define _CONTADOR_H_

#include <list>
#include <iostream>

class Contador{
	
private:
	int min, max, value;
	std::list <int> values;

	void set(int val){
		if (val<=min) value=min;
		else if (val>=max) value=max;
		else value=val;
	};

	void set(Contador &obj, int val){
		printf(">>>>>>>>>>>>>>>>>obj:%i val:%i\n", obj.value,val);
		if (val<=obj.min) value=obj.min;
		else if (val>=obj.max) value=obj.max;
		else obj.value=val;
	};

public:
	Contador(int val_min=0,int val_max=1000, int initial_value=0);

	int get(){return value;};
	
	Contador operator=(int val);
	int operator=(const Contador &obj);
	Contador operator++(int);
	Contador operator++(void);
	Contador operator--(int);
	Contador operator--(void);
	bool undo(int n=1);
	/*Contador operator+(const Contador &obj);
	Contador operator+(int val);
	Contador operator-(int val);*/
	friend Contador operator+(int val,Contador &obj);
	friend Contador operator+(Contador &obj,int val);
	friend Contador operator-(int val,Contador &obj);
	friend Contador operator-(Contador &obj,int val);


};
/*
int operator+(const Contador &obj1,const Contador &obj2);
int operator+(const Contador &obj,const int val);
int operator+(const int val,const Contador &obj);
*/

int operator+(const Contador &obj,const int val);

#endif