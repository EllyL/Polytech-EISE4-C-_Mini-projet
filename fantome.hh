/**************************************************************

	[projet-EISE4-c++] Elisabeth Levert, Alexandre Maury
Class virtuel définissant les caractéristiques de bases d'un
objet sur la carte.

**************************************************************/


#pragma once 

#include "personnage.hh"
#include <string>

class Fantome: public Personnage{

public:
	Fantome(unsigned int x, unsigned int y);
	~Fantome();
	
	string affichage() const;
	string getclass() const {return "Fantome";}



	//Accesseur des attributs
	void set_posx(unsigned int x){_posx = x;}
	unsigned int get_posx() {return _posx;}

	void set_posy(unsigned int y){_posy = y;}
	unsigned int get_posy() {return _posy;}

	void set_nbVie(unsigned int nbvie){_nbVie = nbvie;}
	unsigned int get_nbVie() {return _nbVie;}


protected:

};