
/**************************************************************

	[projet-EISE4-c++] Elisabeth Levert, Alexandre Maury
Class virtuel définissant les caractéristiques de bases d'un
objet sur la carte.

**************************************************************/


#include <iostream>
#include "composantM.hh"
#include "personnage.hh"
#include "joueur.hh"

using namespace std;

int main()
{

Joueur a(0,0,"test.jpg");

cout << a.affichage()<<endl;
a.set_posx(5);
int b = a.get_posx();

cout << a.affichage() << endl;
cout << b << endl;
//b.affichage();

return 0;
}
