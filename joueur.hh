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
	Joueur(unsigned int x, unsigned int y);
	~Joueur();
	string affichage() const;
	string getclass() const {return "Joueur";}


	//Accesseur des attributs

	void set_posx(unsigned int x){_posx = x;}
	unsigned int get_posx() {return _posx;}

	void set_posy(unsigned int y){_posy = y;}
	unsigned int get_posy() {return _posy;}

	void set_score(unsigned int score){_score = score;}
	unsigned int get_score() {return _score;}

	void set_nbVie(unsigned int nbVie){_nbVie = nbVie;}
	unsigned int get_nbVie() {return _nbVie;}
	
	void set_bonus(unsigned int bonus){_bonus = bonus;}
	unsigned int get_bonus() {return _bonus;}


protected:
	unsigned int _score;
	bool _bonus;
	

};