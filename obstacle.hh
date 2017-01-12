
/**************************************************************

	[projet-EISE4-c++] Elisabeth Levert, Alexandre Maury
Class virtuel définissant les caractéristiques de bases d'un
objet sur la carte.

**************************************************************/

#pragma once

#include "composantM.hh"

using namespace std;

class Obstacle: public ComposantM{

public:

	Obstacle(unsigned int x, unsigned int y);
	~Obstacle();


	 string affichage() const;									//fonction d'affichage de l'objet 
	 string getclass() const{return "Obstacle";}				//fonction renvoyant le nom de l'objet
	

	 //Accesseur des attributs

	void set_posx(unsigned int x){_posx = x;}
	unsigned int get_posx() {return _posx;}

	void set_posy(unsigned int y){_posy = y;}
	unsigned int get_posy() {return _posy;}

};