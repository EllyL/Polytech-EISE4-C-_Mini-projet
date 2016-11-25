
/**************************************************************

	[projet-EISE4-c++] Elisabeth Levert, Alexandre Maury
Class définissant les caractéristiques de bases d'un
objet sur la carte.

**************************************************************/

#include "chemin.hh"

#include <iostream>
using namespace std;



Chemin::Chemin(unsigned int x, unsigned int y)
{
	_nom = getclass()+to_string(_i);
	_posx = x;
	_posy = y;
	_image = "";


	_i++;
}

Chemin::Chemin(const Chemin &a){
   _nom = getclass()+to_string(_i);
	_posx = a._posx;
	_posy = a._posy;
	_image = " ";


	_i++;
}

Chemin::~Chemin(){
_i--;
}

string Chemin::affichage() const{
	return _nom + " est un "+ getclass() + " en position ("+to_string(_posx)+","+to_string(_posy)+") avec l'image : "+_image;
	//affichage  nom  class  position  image
}

void Chemin::operator= (const Chemin &a){
   _nom = getclass()+to_string(_i);
	_posx = a._posx;
	_posy = a._posy;
	_image = " ";


	_i++;
}
