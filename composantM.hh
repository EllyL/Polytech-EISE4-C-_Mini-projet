/**************************************************************

	[projet-EISE4-c++] Elisabeth Levert, Alexandre Maury
Class virtuel définissant les caractéristiques de bases d'un
objet sur la carte.

**************************************************************/


#pragma once

using namespace std;


class ComposantM{


private :

public:
	void affichage();
	ComposantM(unsigned int x, unsigned int y,string image);
	~ComposantM();
	string getclass(){return "ComposantM";}
	
	
	string itoa ( int nb );

protected:
	string _nom;
	unsigned int _posx;
	unsigned int _posy;
	string _image;								// type de l'image à changer , ou mettre le chemin de donné de l'image
	static int _i;
};




