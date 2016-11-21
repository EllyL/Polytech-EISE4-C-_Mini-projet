#pragma once

#include "composantM.hh"

using namespace std;

class Personnage: public ComposantM{

public:
	
	virtual string affichage() const =0;			//fonction d'affichage de l'objet 
	virtual string getclass() const=0;				//fonction renvoyant le nom de l'objet

	virtual void deplacement(int x,int y);			//déclaration du déplacement pour tout type de personnage

};