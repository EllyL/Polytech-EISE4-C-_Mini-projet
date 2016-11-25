
/**************************************************************

	[projet-EISE4-c++] Elisabeth Levert, Alexandre Maury
Class  définissant les caractéristiques de bases d'un
objet sur la carte.

**************************************************************/

#pragma once

#include "objet.hh"

using namespace std;

class Bonus: public Objet{

public:

	Bonus(unsigned int x, unsigned int y);
	~Bonus();


	 string affichage() const;			//fonction d'affichage de l'objet 
	 string getclass() const{return "Bonus";}				//fonction renvoyant le nom de l'objet
	

	 //Accesseur des attributs

	void set_posx(unsigned int x){_posx = x;}
	unsigned int get_posx() {return _posx;}

	void set_posy(unsigned int y){_posy = y;}
	unsigned int get_posy() {return _posy;}


	void set_effet(string effet){_effet = effet;}
	string get_effet() {return _effet;}

	void set_duree(unsigned int duree){_duree = duree;}
	unsigned int get_duree() {return _duree;}

protected:
	unsigned int _duree;



};