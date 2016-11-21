#include "personnage.hh"

using namespace std;


void Personnage::deplacement(int x,int y){

	_posx = _posx + x;
	_posy = _posy + y;
}
