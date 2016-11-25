
/**************************************************************

	[projet-EISE4-c++] Elisabeth Levert, Alexandre Maury


**************************************************************/


#include <iostream>
#include "composantM.hh"
#include "personnage.hh"
#include "joueur.hh"
#include "fantome.hh"
#include "obstacle.hh"
#include "objet.hh"
#include "prison.hh"
#include "vote.hh"
#include "bonus.hh"


using namespace std;

int main()
{

Joueur a(0,0);
Fantome b(1,0);
Obstacle c(2,0);

Prison e(4,0);
Vote f(5,0);
Bonus g(6,0);


cout << a.affichage()<<endl;
cout <<endl;


cout << b.affichage() << endl;
cout <<endl;
cout << c.affichage() << endl;
cout <<endl;
cout << e.affichage() << endl;
cout <<endl;
cout << f.affichage() << endl;
cout <<endl;
cout << g.affichage() << endl;

return 0;
}
