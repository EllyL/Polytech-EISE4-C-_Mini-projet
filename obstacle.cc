
/**************************************************************

	[projet-EISE4-c++] Elisabeth Levert, Alexandre Maury
Class définissant les caractéristiques de bases d'un
objet sur la carte.

**************************************************************/

#include "obstacle.hh"

#include <iostream>
using namespace std;



Obstacle::Obstacle(unsigned int x, unsigned int y)
{
	_nom = getclass()+to_string(_i);
	_posx = x;
	_posy = y;
	_image = "";

	
	_i++;
}

Obstacle::~Obstacle(){
_i--;
}



string Obstacle::affichage() const{
	return _nom + " est un "+ getclass() + " en position ("+to_string(_posx)+","+to_string(_posy)+") avec l'image : "+_image;
	//affichage  nom  class  position  image
}
