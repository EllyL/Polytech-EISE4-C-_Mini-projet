#include "fenetre.hh"

fenetre::fenetre()
{

   //parametre ligne , colonne ,Joueur, Bonus, Fantome, Vote, Prison
   _C= new Carte(NBLINE,NBCOLONE,1,2,NBF,15,2);
   _perdu = false;

   _C->afficherMap();
   affiche(_C->getTileMap());

 
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

void fenetre::keyPressEvent(QKeyEvent* event){
	
int PosYJoueur,PosXJoueur;
if(_perdu != true)
{
      if(event->key() == Qt::Key_Up)
        {

           PosYJoueur = _C->getJoueur(PosXJoueur);
            _C->setJoueur(PosXJoueur,PosYJoueur,0,-1,_perdu);
            PosYJoueur = _C->getJoueur(PosXJoueur);

            affiche(_C->getTileMap());
      }
      if(event->key() == Qt::Key_Down)
        {

           PosYJoueur = _C->getJoueur(PosXJoueur);
            _C->setJoueur(PosXJoueur,PosYJoueur,0,1,_perdu);
            PosYJoueur = _C->getJoueur(PosXJoueur);

            affiche(_C->getTileMap());
      }
      if(event->key() == Qt::Key_Right)
        {

           PosYJoueur = _C->getJoueur(PosXJoueur);
            _C->setJoueur(PosXJoueur,PosYJoueur,1,0,_perdu);
            PosYJoueur = _C->getJoueur(PosXJoueur);

            affiche(_C->getTileMap());
      }
      if(event->key() == Qt::Key_Left)
        {

           PosYJoueur = _C->getJoueur(PosXJoueur);
            _C->setJoueur(PosXJoueur,PosYJoueur,-1,0,_perdu);
            PosYJoueur = _C->getJoueur(PosXJoueur);

            affiche(_C->getTileMap());
      }

      _C->DeplacementFantome(_perdu);
   }

}





/* void fenetre::keyReleaseEvent(QKeyEvent *event)
   {
     
     
   }*/