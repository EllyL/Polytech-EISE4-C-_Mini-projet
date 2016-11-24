/**************************************************************

	[projet-EISE4-c++] Elisabeth Levert, Alexandre Maury
Class virtuel définissant les caractéristiques de bases d'un
objet sur la carte.

**************************************************************/

#pragma once

#include "composantM.hh"

using namespace std;

class Personnage: public ComposantM{

public:
	
	virtual string affichage() const =0;			//fonction d'affichage de l'objet 
	virtual string getclass() const=0;				//fonction renvoyant le nom de l'objet

	

};