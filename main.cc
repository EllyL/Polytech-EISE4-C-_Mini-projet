
/**************************************************************

	[projet-EISE4-c++] Elisabeth Levert, Alexandre Maury


**************************************************************/

#include <ctime>
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
#include "chemin.hh"
#include "carte.hh"


using namespace std;

int main()
{
std::srand(std::time(0));
Carte C(20,20,1,2,4,15,2);
C.afficherMap();

return 0;
}
