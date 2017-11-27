#include "ruleta.h"
#include <list>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <string>
#include <unistd.h>
#include <fstream>


using namespace std;

Ruleta::Ruleta(Crupier initCrupier) : crupier_(initCrupier){
	setBanca(1000000);
	bola_.set_valor(-1);
	srand(time(NULL));
}

bool Ruleta::setBanca(int banca){
	if(banca>=0){
		banca_ = banca;
		return(true);
	}
	else{
		return(false);
	}
}

bool Ruleta::setBola(int bola){
	return(bola_.set_valor(bola));
}

void Ruleta::setCrupier(Crupier crupier){
	crupier_ = crupier;
}

bool Ruleta::addJugador(Jugador jugador){
	ifstream ifile;
	jugadores_.push_back(jugador);
	ifile.open((jugador.getDNI()+".txt").c_str());
	if(!ifile.is_open()){
		ofstream ofile((jugador.getDNI()+".txt").c_str());
		ofile.close();
		ifile.close();
		return false;
	}else{
		ifile.close();
		return true;
	}
}

int Ruleta::deleteJugador(Jugador jugador){
	list<Jugador>::iterator i;
	if(jugadores_.empty()) return(-1);

	for(i=jugadores_.begin(); i!=jugadores_.end(); i++){
		if(i->getDNI() == jugador.getDNI()){
			jugadores_.erase(i);
			return(1);
		}
	}
	return(-2);
}

int Ruleta::deleteJugador(string DNI){
	list<Jugador>::iterator i;

	if(jugadores_.empty()) return(-1);

	for(i=jugadores_.begin(); i!=jugadores_.end(); i++){
		if(i->getDNI() == DNI){
			jugadores_.erase(i);
			remove((i->getDNI()+".txt").c_str());

			return(1);
		}
	}
	return(-2);
}

void Ruleta::escribeJugadores(){
	ofstream ofile;
	ofile.open("jugadores.txt");
	if(!ofile.is_open()){
		printf("error el fichero no se pudo crear\n");
		exit;
	}
	list<Jugador>::iterator it;
	for(it=jugadores_.begin(); it!=jugadores_.end(); it++){
		ofile<<it->getDNI()<<",";
		ofile<<it->getCodigo()<<",";
		ofile<<it->getNombre()<<",";
		ofile<<it->getApellidos()<<",";
		ofile<<it->getDireccion()<<",";
		ofile<<it->getLocalidad()<<",";
		ofile<<it->getProvincia()<<",";
		ofile<<it->getPais()<<",";
		ofile<<it->getDinero()<<"\n";

	}
}

void Ruleta::leeJugadores(){
	string temp;
	ifstream file;
    Jugador jug_temp("","");
    file.open("jugadores.txt");
    
    while (!0){
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
	    jugadores_.push_back(jug_temp);
    }
	file.close();
}

void Ruleta::getPremios(){
	int dif;//diference in the win or lose

	Jugador jug_temp("","");
	
	list <Apuesta> list_apuestas_temp;
	list <Apuesta>::iterator apuestas_it;
	jugadores_.clear();
	leeJugadores();//load the jugadores.txt

	//run trought the players
	list<Jugador>::iterator it;
	for(it=jugadores_.begin(); it!=jugadores_.end(); it++){
		
		//clear the memory form the previous itetarion
		jug_temp.clear();
		list_apuestas_temp.clear();


		jug_temp.setDNI(it->getDNI().c_str());//load the dni into the player obj
		jug_temp.setApuestas();//load the dni.txt into memory
		list_apuestas_temp=jug_temp.getApuestas();//load the list of bets into the temp list


		for(apuestas_it=list_apuestas_temp.begin(); apuestas_it!=list_apuestas_temp.end(); apuestas_it++){

			switch ((int)apuestas_it->tipo){

				case 1:
				if (bola_.get_valor()==0){
					dif=apuesta_perida(apuestas_it->cantidad);
					it->setDinero(it->getDinero()+dif);
					break;
				}
					if (atoi(apuestas_it->valor.c_str())==bola_.get_valor()){
						dif=apuesta_ganada(apuestas_it->cantidad,36);
						it->setDinero(it->getDinero()+dif);
					}else{
						dif=apuesta_perida(apuestas_it->cantidad);
						it->setDinero(it->getDinero()+dif);
					}
					break;

				case 2:
				if (bola_.get_valor()==0){
					dif=apuesta_perida(apuestas_it->cantidad);
					it->setDinero(it->getDinero()+dif);
					break;
				}
					if (apuestas_it->valor=="rojo"){
						if (bola_.is_red()){
							dif=apuesta_ganada(apuestas_it->cantidad,2);
							it->setDinero(it->getDinero()+dif);
							break;
						}
					}else if (apuestas_it->valor=="negro"){
						if (bola_.is_black()){
							dif=apuesta_ganada(apuestas_it->cantidad,2);
							it->setDinero(it->getDinero()+dif);
							break;
						}
					}
					dif=apuesta_perida(apuestas_it->cantidad);
					it->setDinero(it->getDinero()+dif);
					break;

				case 3:
				if (bola_.get_valor()==0){
					dif=apuesta_perida(apuestas_it->cantidad);
					it->setDinero(it->getDinero()+dif);
					break;
				}
					if (apuestas_it->valor=="par"){
						if (bola_.get_valor()%2==0){
							dif=apuesta_ganada(apuestas_it->cantidad,2);
							it->setDinero(it->getDinero()+dif);
							break;
						}
					}else if (apuestas_it->valor=="impar"){
						if (bola_.get_valor()%2!=0){
							dif=apuesta_ganada(apuestas_it->cantidad,2);
							it->setDinero(it->getDinero()+dif);
							break;
						}
					}
					dif=apuesta_perida(apuestas_it->cantidad);
					it->setDinero(it->getDinero()+dif);
					break;



				case 4:
				if (bola_.get_valor()==0){
					dif=apuesta_perida(apuestas_it->cantidad);
					it->setDinero(it->getDinero()+dif);
					break;
				}
					if (apuestas_it->valor=="alto"){
						if (bola_.get_valor()>18){
							dif=apuesta_ganada(apuestas_it->cantidad,2);
							it->setDinero(it->getDinero()+dif);
							break;
						}
					}else if (apuestas_it->valor=="bajo"){
						if (bola_.get_valor()<=18){
							dif=apuesta_ganada(apuestas_it->cantidad,2);
							it->setDinero(it->getDinero()+dif);
							break;
						}
					}
					dif=apuesta_perida(apuestas_it->cantidad);
					it->setDinero(it->getDinero()+dif);
					break;
			}
		}
	}
}

int Ruleta::apuesta_ganada(int cant, int en_contra){
	int dif=cant*(en_contra-1);
	setBanca(getBanca()-dif);
	return +dif;
}

int Ruleta::apuesta_perida(int cant){
	int dif=cant;
	setBanca(getBanca()+dif);
	return -dif;
}



//--------------------------------------------------------------------



void Ruleta::print_list (list<Jugador> jugadores){
	list<Jugador>::iterator it_test;
	for (it_test=jugadores.begin(); it_test!=jugadores.end(); ++it_test){
		cout<<"\tdni: <"<<it_test->getDNI()<<">\n";
	}
	cout<<"\tsize: <"<<jugadores.size()<<">\n";
}
void Ruleta::print_list (list<Apuesta> lista){
	list<Apuesta>::iterator it_test;
	for (it_test=lista.begin(); it_test!=lista.end(); ++it_test){
		cout<<"\ttipo: <"<<it_test->tipo<<">\n";
	}
	cout<<"\tsize: <"<<lista.size()<<">\n";
}