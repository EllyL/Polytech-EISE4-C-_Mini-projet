#include "joueur.hh"

using namespace std;



Joueur::Joueur(unsigned int x, unsigned int y,string image)
{
	_nom = getclass()+to_string(_i);
	_posx = x;
	_posy = y;
	_image = image;

	_i++;
}

Joueur::~Joueur(){
_i--;
}



string Joueur::affichage() const{
	return _nom + " est un "+ getclass() + " en position ("+to_string(_posx)+","+to_string(_posy)+") avec l'image : "+_image;  //affichage  nom  class  position  image
}