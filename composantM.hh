/**************************************************************

	[projet-EISE4-c++] Elisabeth Levert, Alexandre Maury
Class virtuel définissant les caractéristiques de bases d'un
objet sur la carte.

**************************************************************/


#pragma once
#include <string>

using namespace std;


class ComposantM{


private :

public:
	virtual string getclass() const =0;			//fonction renvoyant le nom de l'objet
	virtual string affichage() const =0;		//fonction d'affichage de l'objet 

protected:
	string _nom;
	unsigned int _posx;
	unsigned int _posy;
	string _image;								// type de l'image à changer , ou mettre le chemin de donné de l'image
	static int _i;
};




