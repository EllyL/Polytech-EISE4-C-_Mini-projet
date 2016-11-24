/**************************************************************

	[projet-EISE4-c++] Elisabeth Levert, Alexandre Maury
Class virtuel définissant les caractéristiques de bases d'un
objet sur la carte.

**************************************************************/


//// A FINIR

#include "joueur.hh"
#include <iostream>
using namespace std;



Joueur::Joueur(unsigned int x, unsigned int y,string image)
{
	_nom = getclass()+to_string(_i);
	_posx = x;
	_posy = y;
	_image = image;

	_bonus=false;
	_score =0;
	_nbVie=3;
	_i++;
}

Joueur::~Joueur(){
_i--;
}



string Joueur::affichage() const{
	return _nom + " est un "+ getclass() + " en position ("+to_string(_posx)+","+to_string(_posy)+") avec l'image : "+_image;  //affichage  nom  class  position  image
}

