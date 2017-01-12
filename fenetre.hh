#pragma once
#include <QtWidgets>
   #include <QKeyEvent>
#include <QMessageBox>

#include <QApplication>
#include <QtCore>

#include <QPushButton>
#include <QGridLayout>
#include <QGraphicsScene>
#include <QMainWindow>

#include "carte.hh"


#define NBLINE	20
#define NBCOLONE 20
#define NBF 4
#define NBENV 10

/*
	Classe permettant l'affichage de la fenetre
*/

class fenetre :  public QGraphicsScene
{

	public : 
	fenetre();
	~fenetre();
	void keyPressEvent(QKeyEvent* event);				//Fonction prenant en compte les évenements d'appuie sur la touche
	void MessageBox(std::string Msg);					//Fonction  d'affichage d'un messageBox
	//void keyReleaseEvent(QKeyEvent *event);

	void affiche(int** tab);

protected: 
	Carte* _C;											//Carte du jeu
		
	QGraphicsTextItem * score;							//Affichage score de la partie
	QGraphicsTextItem * effetP;							//Affichage 
	bool _perdu;										//booléen permettant de savoir si la partie est fini ou non
	bool _arreter;
};