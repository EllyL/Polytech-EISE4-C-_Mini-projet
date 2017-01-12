/**************************************************************

	[projet-EISE4-c++] Elisabeth Levert, Alexandre Maury
Class virtuel définissant les caractéristiques de bases d'un
objet sur la carte.

**************************************************************/


#include "joueur.hh"
#include <iostream>
using namespace std;



Joueur::Joueur(unsigned int x, unsigned int y)
{
	_nom = getclass()+to_string(_i);
	_posx = x;
	_posy = y;
	_image = "";
	_perdu =false;
	_tpBonus=0;
	_score =0;
	_nbVie=3;
	_i++;
}
/*Joueur::Joueur(Joueur& J){
	_nom = J._nom;
	_posx = J._posx;
	_posy = J._posy;
	_image = J._image;
	_perdu =false;
	_bonus=J._bonus;
	_score =J._score;
	_nbVie=J._nbVie;
	_i++;
}*/

Joueur::~Joueur(){
_i--;
}



string Joueur::affichage() const{
	return _nom + " est un "+ getclass() + " en position ("+to_string(_posx)+","+to_string(_posy)+") avec l'image : "+_image;  //affichage  nom  class  position  image
}

