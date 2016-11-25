
/**************************************************************

	[projet-EISE4-c++] Elisabeth Levert, Alexandre Maury
Class définissant les caractéristiques de bases d'un
objet sur la carte.

**************************************************************/

#include "prison.hh"

#include <iostream>
using namespace std;



Prison::Prison(unsigned int x, unsigned int y)
{
	_nom = getclass()+to_string(_i);
	_posx = x;
	_posy = y;
	_image = "";
	_effet = "vous avez été arreter ! ";
	_i++;
}

Prison::~Prison(){
_i--;
}


//affichage  nom  class  position  image
string Prison::affichage() const{
	return _nom + " est un élément "+ getclass() + " en position ("+to_string(_posx)+","+to_string(_posy)+") avec l'image : "+_image
			+ "\n effet :"+_effet;
	
}
