#ifndef DADOS_H
#define DADOS_H

#include <vector>

class Dados
	/*the class dado from spanish dice,
	simulates a pair of dices*/
{
	private:
		int d1_;
		int d2_;
			//the values of the dices
		int lanzamientos_d1_;
		int lanzamientos_d2_;
			/*number of dices trows on the current
			object, used for the mean*/
		int sum_d1_;
		int sum_d2_;
			/*this represet the sumatorium of 
			all the values the dices have taken,
			is used for calculate the mean*/
		std::vector <int> values_d1_;
		std::vector <int> values_d2_;
			//last 5 values of the dices

		void pushDado1(int val);
		void pushDado2(int val);
			//push the value 'val' on the vector 'values'

	public:
		Dados();
		~Dados();
		void lanzamiento();
		int getDado1();
		int getDado2();
			//just returns the value of the dice
		int getSuma();
			//returns d1_ + d2_
		bool setDado1(int val);
		bool setDado2(int val);
			//set the values of the dices to to the user's desires
			//restriction: the value must be from 1 to 6
		int getLanzamientos1();
		int getLanzamientos2();
			//returns the number of trows
		float getMedia1();
		float getMedia2();
			//returns the mean of each dice's trows or sets
		int get_sum_d1();
		int get_sum_d2();

		void getUltimos1(int* v);
		void getUltimos2(int* v);
			//returns a vector of int of the lasts
			//5 values of the dice v[0]=last value
		int getDiferencia();
			//returns the diference (positive) betwen the dices

};

#endif