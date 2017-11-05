#include <unistd.h>
#include <fstream>


#include "ruleta.h"
#include "crupier.h"



bool Ruleta::addJugador(Jugador& jug)
{

	if (FILE *f = fopen(((jug.getDNI()+".txt").c_str()), "r")) 
	{
        printf("test true\n");
		fclose(f);
    	return false; //the file exists

    }else
    {
        printf("test false %s\n",jug.getDNI().c_str() );
    	ofstream file;
    	file.open(jug.getDNI()+".txt");
        file.close();

    	jugadores_.push_back(jug);
        return true; //the file does not exists
    }
}



int Ruleta::deleteJugador(Jugador& jugad)
{	
	Jugador temp=jugad;
	if (jugadores_.empty()) return -1; //list is empty
	else if (FILE *file = fopen((jugad.getDNI()+".txt").c_str(), "r")) 
	{
        fclose(file);
        std::list<Jugador>::iterator it;
        it= jugadores_.begin();

        for (; it != jugadores_.end(); ++it)
        {


        	if (it->getDNI()==jugad.getDNI())
        	{
        		jugadores_.erase(it);
        		execl("rm",jugad.getDNI().c_str());
        	}
        }

        return 1; //dni.txt found

    }
    else
    {

    	return -2; //dnbi.txt not found
   	}
}

int Ruleta::deleteJugador(std::string DNI)
{	
	if (jugadores_.empty()) return -1; //list is empty
	else if (FILE *file = fopen((DNI+".txt").c_str(), "r")) 
	{
        fclose(file);
        std::list<Jugador>::iterator it;
        it= jugadores_.begin();

        for (; it != jugadores_.end(); ++it)
        {


        	if (it->getDNI()==DNI)
        	{
        		jugadores_.erase(it);
        		execl("rm",(DNI+".txt").c_str());
        	}
        }

        return 1; //dni.txt found

    }
    else
    {

    	return -2; //dni.txt not found
   	}
}


void Ruleta::escribeJugadores()
{
    std::list<Jugador>::iterator it;
	ofstream file;
    file.open("jugadores.txt");
    
    for (it=jugadores_.begin(); it != jugadores_.end(); ++it)
    {
       	

    	file<<it->getDNI();
    	file<<",";
    	file<<it->getCodigo().c_str();
    	file<<",";
		file<<it->getNombre().c_str();
    	file<<",";
		file<<it->getApellidos().c_str();
    	file<<",";
    	file<<it->getDireccion().c_str();
    	file<<",";
		file<<it->getLocalidad().c_str();
    	file<<",";
		file<<it->getProvincia().c_str();
    	file<<",";
    	file<<it->getPais().c_str();
    	file<<",";
		file<<it->getDinero();
		file<<"\n";

    }
	file.close();

}


void Ruleta::leeJugadores()
{
	std::string temp;
	ifstream file;
    Jugador jug_temp("dni","codigo");
    file.open("jugadores.txt");
    
    while (!0)
    {
       	
	if (!std::getline(file,temp,',')) break;
    jug_temp.setDNI(temp);
	std::getline(file,temp,',');
    jug_temp.setCodigo(temp);
    std::getline(file,temp,',');
    jug_temp.setNombre(temp);
    std::getline(file,temp,',');
    jug_temp.setApellidos(temp);
    std::getline(file,temp,',');
    jug_temp.setDireccion(temp);
    std::getline(file,temp,',');
    jug_temp.setLocalidad(temp);
    std::getline(file,temp,',');
    jug_temp.setProvincia(temp);
    std::getline(file,temp,',');
    jug_temp.setPais(temp);
    std::getline(file,temp,'\n');
    jug_temp.setDinero(atoi(temp.c_str()));


    }
	file.close();
}
