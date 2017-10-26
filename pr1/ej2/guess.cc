//date: 11 sept 2017
//brief: the pragram generates a random number betwen 1 nad 10 and the user try to guess it

#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{
	std::cout<<"this program makes you guess a number between 1 and 10.\n\n";

	int tries=0;
		//user tries

	int user_guess=11;
		//11 is an imposible value for enterinng the while loop

	srand(time(NULL));
		//rng (random number generator)
		//time (NULL) return the number of
		//seconds since 00:00:00 of jaunary of 1970
	int random_number=rand()%10;
	random_number++;


	//dev line: shows the secret number.
	//std::cout<<">>>"<<random_number<<"\n";


		//gets a random number of the srand series and gets it's module of 11

	while(user_guess!=random_number)
	{
	if(user_guess!=11)
	{
		//print if the guess is lower or not
		if (user_guess<random_number)
		{
			std::cout<<"sorry the secret number is lower\ntry again\n";
		}
		else
		{
			std::cout<<"sorry the secret number is greater\ntry again\n";
		}
		
	}
	std::cout<<"if you want to quit introduce -1\n";
	std::cout<<"make a guess!\n >";
	std::cin>>user_guess;
		//user input
	tries++;
	if (user_guess==-1) break;
	std::cout<<"\n\n";
	}
	if (user_guess!=-1)	std::cout<<"correct! only "<<tries<<" tries!\n\n";

	return 0;
}