
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

void deplacementJoueur(Carte& C,bool& perdu)
{
	bool Vchoix= false;
	int choix;
	int PosXJoueur, PosYJoueur;

	while(Vchoix == false){
		
		std::cout<< "Quelle direction ?"<<std::endl;
		std::cout << " 8.haut  6.droite 2.bas 4.gauche";
		cin>>choix;

		switch(choix)
		{
			case 8:
				PosYJoueur = C.getJoueur(PosXJoueur);
				C.setJoueur(PosXJoueur,PosYJoueur,0,-1,perdu);
				PosYJoueur = C.getJoueur(PosXJoueur);
				Vchoix=true;
			 	break;

			case 6: 
				PosYJoueur = C.getJoueur(PosXJoueur);
				C.setJoueur(PosXJoueur,PosYJoueur,1,0,perdu);
				PosYJoueur = C.getJoueur(PosXJoueur);
				Vchoix=true;
			break;

			case 2: 
				PosYJoueur = C.getJoueur(PosXJoueur);
				C.setJoueur(PosXJoueur,PosYJoueur,0,1,perdu);
				PosYJoueur = C.getJoueur(PosXJoueur);
				Vchoix=true;
			break;

			case 4: 
				PosYJoueur = C.getJoueur(PosXJoueur);
				C.setJoueur(PosXJoueur,PosYJoueur,-1,0,perdu);
				PosYJoueur = C.getJoueur(PosXJoueur);
				Vchoix=true;
				break;

			default : 
				Vchoix=false;
				cin.clear();
			 	cin.ignore(numeric_limits<streamsize>::max(), '\n');
				std::cout<< "Erreur de choix."<<std::endl;
		}
	}
	Vchoix=false;

}


void affiche(int** tab,QGraphicsScene* scene,QGraphicsItem* item,QPixmap image)
{
	int   width = 0;
	int   heigth = 0;
	
	for (int i = 0; i < NBLINE; i++)
    {
      for (int j = 0; j < NBCOLONE; j++)
        {
        	if(tab[i][j] == 0)
            {
            	
              width += 20;
            	
            }
        	
            if (tab[i][j] == 1)
            {
              image.load("./image/mur.jpg", 0, Qt::AutoColor);
              item = scene->addPixmap(image);
              item->setPos(width, heigth);
              item->show();
              width += 20;
            }

            if (tab[i][j] == 2)
            {
              image.load("./image/env.png", 0, Qt::AutoColor);
              item = scene->addPixmap(image);
              item->setPos(width, heigth);
              item->show();
              width += 20;
            }

            if (tab[i][j] == 3)
            {
              image.load("./image/pacman.png", 0, Qt::AutoColor);
              item = scene->addPixmap(image);
              item->setPos(width, heigth);
              item->show();
              width += 20;
            }

            if (tab[i][j] == 4)
            {
              image.load("./image/fantome.png", 0, Qt::AutoColor);
              item = scene->addPixmap(image);
              item->setPos(width, heigth);
              item->show();
              width += 20;
            }
            if (tab[i][j] == 5)
            {
              image.load("./image/bonus.jpg", 0, Qt::AutoColor);
              item = scene->addPixmap(image);
              item->setPos(width, heigth);
              item->show();
              width += 20;
            }
            if (tab[i][j] == 6)
            {
              image.load("./image/prison.jpg", 0, Qt::AutoColor);
              item = scene->addPixmap(image);
              item->setPos(width, heigth);
              item->show();
              width += 20;
            }
            
        }
      heigth += 20;
      width = 0;
    }

    }



int main(int argc, char *argv[])
{

	/*QApplication app(argc, argv);
  	QGraphicsScene *scene = new QGraphicsScene; //creation de la scene

	QWidget * window = new QWidget();
    window->resize(500, 500);

	QGraphicsItem *item = NULL;
	QPixmap image;
	



	
//parametre ligne , colonne ,Joueur, Bonus, Fantome, Vote, Prison
	Carte C(NBLINE,NBCOLONE,1,2,NBF,15,2);
	int** tab;
	

	bool perdu=false;

		
	
		

	while(perdu != true){
		C.afficherMap();					//terminale
		tab = C.getTileMap();

		affiche(tab,scene,item,image);		//graphique


		
      

		QGraphicsView vue(scene);
      vue.setFixedSize(500, 500);
      vue.setWindowTitle("PacMan");
      vue.show();
		//deplacementJoueur(C,perdu);
		//C.DeplacementFantome(perdu);
      
		
		app.exec();
	}*/
	std::srand(std::time(0));
	QApplication app(argc, argv);
	fenetre *F1 = new fenetre();
	

QGraphicsView vue(F1);
      vue.setFixedSize(500, 500);
      vue.setWindowTitle("PacMan");
      vue.show();


	return app.exec();
}
