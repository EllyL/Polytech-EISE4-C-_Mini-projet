/**************************************************************

	[projet-EISE4-c++] Elisabeth Levert, Alexandre Maury
Class virtuel définissant les caractéristiques de bases d'un
objet sur la carte.

**************************************************************/


//// A FINIR

#pragma once 

#include "personnage.hh"
#include <string>

class Joueur: public Personnage{

public:
	Joueur(unsigned int x, unsigned int y,string image);
	~Joueur();
	string affichage() const;
	string getclass() const {return "Joueur";}

	void set_posx(unsigned int x){_posx = x;}
	unsigned int get_posx() {return _posx;}

	void set_posy(unsigned int y){_posy = y;}
	unsigned int get_posy() {return _posy;}

protected:
	

};