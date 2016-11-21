#pragma once 

#include "personnage.hh"
#include <string>

class Joueur: public Personnage{

public:
	Joueur(unsigned int x, unsigned int y,string image);
	~Joueur();
	string affichage() const;
	string getclass() const {return "Joueur";}

protected:
	

};