/**************************************************************

	[projet-EISE4-c++] Elisabeth Levert, Alexandre Maury
Class virtuel définissant les caractéristiques de bases d'un
objet sur la carte.

**************************************************************/


#include "fantome.hh"
#include <iostream>
using namespace std;



Fantome::Fantome(unsigned int x, unsigned int y)
{
	_nom = getclass()+to_string(_i);
	_posx = x;
	_posy = y;
	_image = "";

	
	_nbVie=1;
	_i++;
}

Fantome::~Fantome(){
_i--;
}



string Fantome::affichage() const{
	return _nom + " est un "+ getclass() + " en position ("+to_string(_posx)+","+to_string(_posy)+") avec l'image : "+_image;  //affichage  nom  class  position  image
}

