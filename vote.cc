
/**************************************************************

	[projet-EISE4-c++] Elisabeth Levert, Alexandre Maury
Class définissant les caractéristiques de bases d'un
objet sur la carte.

**************************************************************/

#include "vote.hh"

#include <iostream>
using namespace std;



Vote::Vote(unsigned int x, unsigned int y)
{
	_nom = getclass()+to_string(_i);
	_posx = x;
	_posy = y;
	_image = "";
	_point = 10;
	_effet = "vous gagnez 10 points";
	_i++;
}

Vote::~Vote(){
_i--;
}



string Vote::affichage() const{
	return _nom + " est un élément "+ getclass() + " en position ("+to_string(_posx)+","+to_string(_posy)+") avec l'image : "+_image
			 +"\n effet :"+_effet;
	//affichage  nom  class  position  image
}
