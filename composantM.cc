#include <iostream>
#include <typeinfo>
#include <string>
#include "composantM.hh"
#include <sstream>


using namespace std; 

int ComposantM::_i =0;

ComposantM::ComposantM(  unsigned int x, unsigned int y,string image)
{
_nom = getclass()+itoa(_i);
_posx = x;
_posy=y;
_image = image;

_i++;
}



ComposantM::~ComposantM()
{
}

void ComposantM::affichage(){

	cout << _nom << " est un " <<getclass() <<" , placer en (" <<_posx<< ","<< _posy << "), son image est : " << _image <<endl;

}


string ComposantM::itoa ( int nb )
  {
     ostringstream ss;
     ss << nb;
     return ss.str();
  }
