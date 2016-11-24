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
	Fantome(unsigned int x, unsigned int y,string image);
	~Fantome();
	
	string affichage() const;
	string getclass() const {return "Fantome";}

	void set_posx(unsigned int x){_posx = x;}
	unsigned int get_posx() {return _posx;}

	void set_posy(unsigned int y){_posy = y;}
	unsigned int get_posy() {return _posy;}

	void set_vie(unsigned int vie){_vie = vie;}
	unsigned int get_vie() {return _vie;}


protected:

	bool _vie;
	

};