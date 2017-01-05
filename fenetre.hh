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

class fenetre :  public QGraphicsScene
{

	public : 
	fenetre();
	~fenetre();
	void keyPressEvent(QKeyEvent* event);
	void MessageBox(std::string Msg);
	//void keyReleaseEvent(QKeyEvent *event);

	void affiche(int** tab);

protected: 
	Carte* _C;
	
	QGraphicsTextItem * score;
	QGraphicsTextItem * effetP;
	bool _perdu;
	bool _arreter;
};