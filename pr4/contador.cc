#include "contador.h"
#include <iostream>
Contador::Contador(int val_min,int val_max, int initial_value){
	if(val_min<val_max){
		min=val_min;
		max=val_max;
		if(val_min<=initial_value && initial_value<=val_max) value=initial_value;
		else value=0;
	}
	else{
		value=0;
		min=0;
		max=1000;
	}
}

	Contador Contador::operator=(int val){
		values.push_back(this->value);
		set(val);
		return *this;
	}

	int Contador::operator=(const Contador &obj){
		values.push_back(this->value);
		*this=obj.value;
		return obj.value;
	}

	Contador Contador::operator++(int){
		values.push_back(this->value);
		Contador aux=*this;
		set(value+1);
		return aux;
	}

	Contador Contador::operator++(void){//--a
		values.push_back(this->value);
		set(value+1);
		return *this;
	}


	Contador Contador::operator--(int){//a--
		values.push_back(this->value);
		Contador aux=*this;
		set(value-1);
		return aux;
	}

	Contador Contador::operator--(void){
		values.push_back(this->value);
		set(value-1);
		return *this;
	}

	bool Contador::undo(int n){
		if (n>values.size())return false;
		for (int i = 0; i < n; ++i){
			values.pop_back();
		}
		this->value=values.back();
		return true;
	}

	Contador operator+(Contador &obj1,const Contador &obj2){
		Contador aux;
		aux.set(obj1,obj1.value+obj2.value);
		return obj1;
	}

	Contador operator+(Contador &obj,int val){
		Contador aux;
		aux.set(obj,obj.value+val);
		return obj;
	}

	Contador operator+(int val,const Contador &obj){
		val+=obj.value;
		return val;
	}

