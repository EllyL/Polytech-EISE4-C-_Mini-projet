
#include <iostream>
#include "composantM.hh"
#include "personnage.hh"
#include "joueur.hh"

using namespace std;

int main()
{

Joueur a(0,0,"test.jpg");
// b(1,1,"test.jpg");
cout << a.affichage()<<endl;
//b.affichage();

return 0;
}
