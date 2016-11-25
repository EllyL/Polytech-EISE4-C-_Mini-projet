
/**************************************************************

	[projet-EISE4-c++] Elisabeth Levert, Alexandre Maury
Class  définissant les caractéristiques de bases d'un
objet sur la carte.

**************************************************************/

#pragma once

#include "objet.hh"

using namespace std;

class Vote: public Objet{

public:

	Vote(unsigned int x, unsigned int y);
	~Vote();


	 string affichage() const;			//fonction d'affichage de l'objet 
	 string getclass() const{return "Vote";}				//fonction renvoyant le nom de l'objet
	

	 //Accesseur des attributs

	void set_posx(unsigned int x){_posx = x;}
	unsigned int get_posx() {return _posx;}

	void set_posy(unsigned int y){_posy = y;}
	unsigned int get_posy() {return _posy;}


	void set_effet(string effet){_effet = effet;}
	string get_effet() {return _effet;}

	void set_point(unsigned int point){_point = point;}
	unsigned int get_point() {return _point;}

protected:
	unsigned int _point;



};