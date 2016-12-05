/******************************************************************************************
 * [Polytech-EISE4-C++] 2016-2017 LEVERT MAURY                                            *
 * La Classe Carte doit afficher la carte dans laquelle les personnages évoluent.         *
 * Il faut afficher les obstacles (murs), objets et personnages.                          *
 * La position de tous doit être mise à jour à chaque déplacement, récupération d'objet.  *
 * L'affichage doit être rafraîchi après certaines action (déplacement, effet objet).     *
 ******************************************************************************************/

#include "carte.hh"

using namespace std;

Carte::Carte(){

   _ligne = DEF_SIZE;
   _colonne = DEF_SIZE;

	_map = (ComposantM***) malloc(sizeof(ComposantM**)*_ligne);
   for(unsigned int i=0; i<_ligne; i++)
      _map[i] = (ComposantM**) malloc(sizeof(ComposantM*)*_colonne);

   for(unsigned int i=0; i< _ligne; i++)
      for(unsigned int j=0; j<_colonne; j++){
            _map[i][j] = new Chemin(0,0);
      }

}

/*
 * Le constructeur va prendre le nom du type d'élément que l'on veut mettre en place, puis le nombre voulu de ce type.
 * Une map de jeu est alors construite de façon aléatoire selon des conditions critiques pour des raisons de jouabilité.
 * La carte est modélisée par une matrice, une case correspondant à une position, la case contenant le type de l'élément.
 */

Carte::Carte(unsigned int ligne, unsigned int colonne, unsigned int nbJoueur, unsigned int nbBonus, unsigned int nbFantome, unsigned int nbVote, unsigned int nbPrison) : _ligne(ligne), _colonne(colonne){

   unsigned int i, j, k;

	_map = (ComposantM***) malloc(sizeof(ComposantM**)*_ligne);
   for(i=0; i<ligne; i++)
      _map[i] = (ComposantM**) malloc(sizeof(ComposantM*)*_colonne);

   for(unsigned int i=0; i< _ligne; i++)
      for(unsigned int j=0; j<_colonne; j++)
         _map[i][j] = new Chemin(i, j);


   k=0;
   while(k<nbJoueur){
      i = rand()%_ligne;
      j = rand()%_colonne;
       if(_map[i][j]->getclass()=="Chemin"){
            _map[i][j] = new Joueur(i, j);
            k++;
         }
   }

   k=0;
   while(k<nbBonus){
  
      i = rand()%ligne;
      j = rand()%colonne;
      if(_map[i][j]->getclass()=="Chemin"){
            _map[i][j] = new Bonus(i, j);
            k++;
         }
   }

   k=0;
   while(k<nbPrison){
   
      i = rand()%ligne;
      j = rand()%colonne;
      if(_map[i][j]->getclass()=="Chemin"){
          _map[i][j] = new Prison(i, j);
          k++;
       }
   }

   k=0;
   while(k<nbVote){
   
      i = rand()%ligne;
      j = rand()%colonne;
      if(_map[i][j]->getclass()=="Chemin"){
         _map[i][j] = new Vote(i, j);
         k++;
      }
   }

    k=0;
   while(k<nbFantome){
  
      i = rand()%ligne;
      j = rand()%colonne;
      if(_map[i][j]->getclass()=="Chemin"){
         _map[i][j] = new Fantome(i, j);
         k++;
      }
   }

   k=0;
  while(k<(ligne*colonne)/4){
      i = rand()%ligne;
      j = rand()%colonne;
      if(_map[i][j]->getclass()=="Chemin"){
          _map[i][j] = new Obstacle(i, j);
          k++;
      }
   }
}



/*Carte::Carte(unsigned int nbJoueur, unsigned int nbBonus, unsigned int nbFantome, unsigned int nbVote, unsigned int nbPrison);
 {

}*/

void Carte::afficherMap(void){

   unsigned int i, j;

   for(j=0; j<_colonne+2; j++){
      cout << "-";
   }
   for(i=0; i<_ligne; i++){
         cout << endl << "|";
      for(j=0; j<_colonne; j++){
         if (_map[i][j]->getclass()=="Joueur")
               cout << "J";

         else if (_map[i][j]->getclass()=="Bonus")
               cout << "B";

         else if (_map[i][j]->getclass()=="Fantome")
               cout << "F";

         else if (_map[i][j]->getclass()=="Prison")
               cout << "P";

         else if (_map[i][j]->getclass()=="Vote")
               cout << "V";

         else if (_map[i][j]->getclass()=="Obstacle")
            cout << "#";

         else if (_map[i][j]->getclass()=="Chemin")
            cout << " ";
      }
      cout << "|";
   }
   cout << endl;
   for(j=0; j<_colonne+2; j++){
      cout << "-";
   }
   cout << endl;
}

