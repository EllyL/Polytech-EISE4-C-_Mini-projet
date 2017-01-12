
/**************************************************************

	[projet-EISE4-c++] Elisabeth Levert, Alexandre Maury


**************************************************************/
#include <limits>
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

#include "fenetre.hh"


using namespace std;



int main(int argc, char *argv[])
{

	std::srand(std::time(0));					//définition de la graine pour faire des randoms

	QApplication app(argc, argv);
	fenetre *F1 = new fenetre();				//création de la fenetre
	

	QGraphicsView vue(F1);
    vue.setFixedSize(500, 500);					// setup de la fenetre
    vue.setWindowTitle("PacMan");
    vue.show();


	return app.exec();
}
