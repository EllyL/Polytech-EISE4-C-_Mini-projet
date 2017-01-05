
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

/****************/

//Pas sur d'avoir besoin de tous ça
/******************/
#include <QApplication>
#include <QtCore>
#include <QtGui>
#include <QPushButton>
#include <QGridLayout>
#include <QtWidgets>
//#include <QDialog>



/*#define NBLINE	20
#define NBCOLONE 20
#define NBF 4*/

using namespace std;



int main(int argc, char *argv[])
{

	std::srand(std::time(0));
	QApplication app(argc, argv);
	fenetre *F1 = new fenetre();
	

	QGraphicsView vue(F1);
    vue.setFixedSize(500, 500);
    vue.setWindowTitle("PacMan");
    vue.show();


	return app.exec();
}
