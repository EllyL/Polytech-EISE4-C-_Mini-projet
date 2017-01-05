#include "fenetre.hh"

fenetre::fenetre()
{

   //parametre ligne , colonne ,Joueur, Bonus, Fantome, Vote, Prison
   _C= new Carte(NBLINE,NBCOLONE,1,2,NBF,NBENV,2);
   _arreter = false;
   _perdu = false;

   _C->afficherMap();
   
   affiche(_C->getTileMap());

	addRect(-1,-1,401,401, QPen(), QBrush());

	score = addText("Votre score est de : 0.");
	effetP =addText(" ");

	score->setPos(0,410);
	effetP->setPos(0,430);

 	
}

void fenetre::affiche(int** tab)
{
  
   int   width = 0;
   int   heigth = 0;
   
   QPixmap image;
   // QLabel  *label  = new QLabel(this);
    QGraphicsItem* item =NULL;

   for (int i = 0; i < NBLINE; i++)
    {
      for (int j = 0; j < NBCOLONE; j++)
        {
         if(tab[i][j] == 0)
            {
               image.load("./image/chemin.jpg", 0, Qt::AutoColor);
               item = this->addPixmap(image);
              item->setPos(width, heigth);
              item->show();
              width += 20;
               
            }
         
            if (tab[i][j] == 1)
            {
              image.load("./image/mur.jpg", 0, Qt::AutoColor);
               item = this->addPixmap(image);
              item->setPos(width, heigth);
              item->show();
              width += 20;
            }
         

            if (tab[i][j] == 2)
            {
              image.load("./image/env.png", 0, Qt::AutoColor);
              item = this->addPixmap(image);
              item->setPos(width, heigth);
              item->show();
              width += 20;
            }

            if (tab[i][j] == 3)
            {
              image.load("./image/pacman.png", 0, Qt::AutoColor);
            item = this->addPixmap(image);
              item->setPos(width, heigth);
              item->show();
              width += 20;
            }

            if (tab[i][j] == 4)
            {
              image.load("./image/fantome.png", 0, Qt::AutoColor);
            item = this->addPixmap(image);
              item->setPos(width, heigth);
              item->show();
              width += 20;
            }
            if (tab[i][j] == 5)
            {
              image.load("./image/bonus.jpg", 0, Qt::AutoColor);
            item = this->addPixmap(image);
              item->setPos(width, heigth);
              item->show();
              width += 20;
            }
            if (tab[i][j] == 6)
            {
              image.load("./image/prison.jpg", 0, Qt::AutoColor);
               item = this->addPixmap(image);
              item->setPos(width, heigth);
              item->show();
              width += 20;
            }
            
        }
      heigth += 20;
      width = 0;
    }

    }


fenetre::~fenetre()
{


}





void fenetre::MessageBox(std::string Msg)
{
				QMessageBox msgBox;
				msgBox.setWindowTitle("Fin de la partie");
				msgBox.setText(QString::fromStdString(Msg));

				msgBox.setStandardButtons(QMessageBox::Ok);

					if(msgBox.exec() == QMessageBox::Ok)
					{
						exit(0);
					}

}

void fenetre::keyPressEvent(QKeyEvent* event){
	
int PosYJoueur,PosXJoueur;
int scoreJ;
std::string effet;




if(_perdu != true)
{
      if(event->key() == Qt::Key_Up)
        {

           _C->getJoueur(PosXJoueur,PosYJoueur);
            _C->setJoueur(PosXJoueur,PosYJoueur,0,-1,_perdu,scoreJ,effet,_arreter);
           _C->getJoueur(PosXJoueur,PosYJoueur);

            affiche(_C->getTileMap());


      }
      if(event->key() == Qt::Key_Down)
        {

           _C->getJoueur(PosXJoueur,PosYJoueur);
            _C->setJoueur(PosXJoueur,PosYJoueur,0,1,_perdu,scoreJ,effet,_arreter);
           _C->getJoueur(PosXJoueur,PosYJoueur);

            affiche(_C->getTileMap());


          
      }
      if(event->key() == Qt::Key_Right)
        {

           _C->getJoueur(PosXJoueur,PosYJoueur);
            _C->setJoueur(PosXJoueur,PosYJoueur,1,0,_perdu,scoreJ,effet,_arreter);
           _C->getJoueur(PosXJoueur,PosYJoueur);

            affiche(_C->getTileMap());


      }
      if(event->key() == Qt::Key_Left)
        {

           _C->getJoueur(PosXJoueur,PosYJoueur);
            _C->setJoueur(PosXJoueur,PosYJoueur,-1,0,_perdu,scoreJ,effet,_arreter);
           _C->getJoueur(PosXJoueur,PosYJoueur);

            affiche(_C->getTileMap());
      }


      if( scoreJ/10 > (NBENV*50)/100)		// si on obtient 70% des votes on gagne
        {
            	
            		MessageBox("Vous avez gagné !");
       }
      _C->DeplacementFantome(_perdu);


  }
   else
   {

		if(_arreter == true)
			MessageBox("Vous avez été arrêté !");
		
		else
			MessageBox("Vous avez perdu !");

   }
   
  score->setPlainText("Votre score est de : " + QString::number(scoreJ));

  effetP->setPlainText(QString::fromStdString(effet));

}





/* void fenetre::keyReleaseEvent(QKeyEvent *event)
   {
     
     
   }*/