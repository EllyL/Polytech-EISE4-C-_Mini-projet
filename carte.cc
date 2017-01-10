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
   _nbEnv = _ligne*_colonne;

	_map = (ComposantM***) malloc(sizeof(ComposantM**)*_ligne);
   for(unsigned int i=0; i<_ligne; i++)
      _map[i] = (ComposantM**) malloc(sizeof(ComposantM*)*_colonne);

   for(unsigned int i=0; i< _ligne; i++)
      for(unsigned int j=0; j<_colonne; j++){
            _map[i][j] = new Chemin(0,0);
      }

}
Carte::~Carte(){
  for(int i=0;i< DEF_SIZE;i++)
  {
    for(int j=0;j<DEF_SIZE;j++)
    {
      delete[] _map[i][j];
    }
  }

  for(int i=0; i< DEF_SIZE ; i++)
  {
    delete[] _map[i];
  }

  delete[] _map;
}

/*
 * Le constructeur va prendre le nom du type d'élément que l'on veut mettre en place, puis le nombre voulu de ce type.
 * Une map de jeu est alors construite de façon aléatoire selon des conditions critiques pour des raisons de jouabilité.
 * La carte est modélisée par une matrice, une case correspondant à une position, la case contenant le type de l'élément.
 */

Carte::Carte(unsigned int ligne, unsigned int colonne, unsigned int nbJoueur, unsigned int nbBonus, unsigned int nbFantome, unsigned int nbVote, unsigned int nbPrison) : _ligne(ligne), _colonne(colonne){

   unsigned int i, j, k;

   _nbEnv = nbVote;

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
            _nbEnv--;
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

void Carte::getJoueur(int& k , int& l){

  unsigned int i,j;
   for(i=0;i<_ligne;i++)
   {
      for(j=0;j<_colonne;j++)
      {
         if(_map[i][j]->getclass()=="Joueur")
         {
            k= j;
            l= i;
         }
      }
   }
}

void Carte::setJoueur(int x, int y,int decX, int decY,bool& perdu, int& scoreJ, std::string& effet, bool& arreter)
{

   if(static_cast<Joueur*>(_map[y][x])->get_bonus() >0)
   {
      static_cast<Joueur*>(_map[y][x])->set_bonus(static_cast<Joueur*>(_map[y][x])->get_bonus() -1);
      effet = "il vous reste " + to_string(static_cast<Joueur*>(_map[y][x])->get_bonus())+ " tour d'invicibilité";
      std::cout << "il vous reste " <<  static_cast<Joueur*>(_map[y][x])->get_bonus() << " tour d'invicibilité"<< std::endl;
   }

if((x+decX) >=0 && (x+decX) <(int)_colonne && (y+decY)>= 0 && (y+decY) < (int)_ligne)
{
   if(_map[y+decY][x+decX]->getclass() == "Obstacle" )
   {
    
         std::cout<<"MUR!"<<std::endl;
          if(_map[y][x]->getclass() == "Joueur")
            scoreJ = static_cast<Joueur*>(_map[y][x])->get_score();

   }
   else if(_map[y+decY][x+decX]->getclass() == "Prison")
   {
      arreter = true;
      perdu =true;
       if(_map[y][x]->getclass() == "Joueur")
        scoreJ = static_cast<Joueur*>(_map[y][x])->get_score();

      if(effet != "")
          effet += "\n"+static_cast<Prison*>(_map[y+decY][x+decX])->get_effet();
      else
        effet = static_cast<Prison*>(_map[y+decY][x+decX])->get_effet();

       std::cout << static_cast<Prison*>(_map[y+decY][x+decX])->get_effet() << std::endl;
   }

   else
   {
       if(_map[y+decY][x+decX]->getclass() == "Vote")
      {
        static_cast<Joueur*>(_map[y][x])->set_score( static_cast<Vote*>(_map[y+decY][x+decX])->get_point() +  static_cast<Joueur*>(_map[y][x])->get_score() );
         std::cout << static_cast<Vote*>(_map[y+decY][x+decX])->get_effet() << std::endl;

      if(effet != "")
          effet += "\n"+static_cast<Vote*>(_map[y+decY][x+decX])->get_effet();
      else
        effet = static_cast<Vote*>(_map[y+decY][x+decX])->get_effet();
       }


       if(_map[y+decY][x+decX]->getclass() == "Bonus")
      {
        static_cast<Joueur*>(_map[y][x])->set_bonus(static_cast<Bonus*>(_map[y+decY][x+decX])->get_duree() );
         std::cout << static_cast<Bonus*>(_map[y+decY][x+decX])->get_effet() << std::endl;


      if(effet != "")
          effet += "\n"+static_cast<Bonus*>(_map[y+decY][x+decX])->get_effet();
      else
        effet = static_cast<Bonus*>(_map[y+decY][x+decX])->get_effet();
       }


      if(_map[y+decY][x+decX]->getclass() == "Fantome")
       {
         if(static_cast<Joueur*>(_map[y][x])->get_bonus() > 0 )
         {

         }
         else{
            perdu =true;
            std::cout << "Vous avez perdu !" << std::endl;
             if(_map[y][x]->getclass() == "Joueur")
                scoreJ = static_cast<Joueur*>(_map[y][x])->get_score();
         }  
      }  
   

      std::cout << "votre score est de :" <<  static_cast<Joueur*>(_map[y][x])->get_score() << std::endl;

      if(_map[y][x]->getclass() == "Joueur")
        scoreJ = static_cast<Joueur*>(_map[y][x])->get_score();

      if( ( scoreJ/10 + comptEnv() ) < (_nbEnv*50) /100 )
        perdu =true;

      _map[y][x]->set_posx(x+decX);
      _map[y][x]->set_posy(y+decY);
      _map[y+decY][x+decX] = _map[y][x];
      _map[y][x] = new Chemin(y,x);






   }
    
}

}

int Carte::comptEnv()
{
  int cpt=0;
   for(unsigned int i=0;i<_ligne;i++)
   {
      for(unsigned int j=0;j<_colonne;j++)
      {
         if(_map[i][j]->getclass()=="Vote")
           cpt++;
       }
     }

     return cpt;
}

void Carte::setFantome(int x, int y,int decX, int decY,bool& perdu)
{
   

if((x+decX) >=0 && (x+decX) <(int)_colonne && (y+decY)>= 0 && (y+decY) < (int)_ligne)
{
  
   if(_map[y+decY][x+decX]->getclass() == "Fantome" || _map[y+decY][x+decX]->getclass() == "Obstacle")
   {

   }
   else if(_map[y+decY][x+decX]->getclass() == "Joueur")
      {
         if(static_cast<Joueur*>(_map[y+decY][x+decX])->get_bonus() > 0)
         {
          delete _map[y][x];
           _map[y][x] = new Chemin(y,x);
         }
         else {
            perdu =true;
            std::cout << "Vous avez perdu !" << std::endl;
         }
         
      }
   else{
      _map[y][x]->set_posx(x+decX);
      _map[y][x]->set_posy(y+decY);
      _map[y+decY][x+decX] = _map[y][x];

      _map[y][x] = new Chemin(y,x);
   }
   
}
}





void Carte::DeplacementFantome(bool &perdu)
{

   unsigned int i,j;
   int depX,depY;                      //déplacement aléatoire des fantomes.
   
    for(i=0;i<_ligne;i++)
   {
      for(j=0;j<_colonne;j++)
      {
          if(_map[i][j]->getclass()=="Fantome")
         {
               depX =( rand()%3) -1;               // -1, 0, ou 1
               depY=( rand()%3) -1;
               setFantome(j,i,depX,depY,perdu);
         }

      }

   }

}

int** Carte::getTileMap(){
  int** tab;
 unsigned int i,j;

  tab = static_cast<int**>(malloc(sizeof(int**)*_ligne));
   for(i=0; i<_ligne; i++)
      tab[i] = static_cast<int*>(malloc(sizeof(int*)*_colonne));



  for(i=0;i<_ligne;i++)
  {
    for(j=0;j<_colonne;j++)
    {
      if(_map[i][j]->getclass() == "Chemin")
        tab[i][j] = 0;

      if(_map[i][j]->getclass() == "Obstacle")
        tab[i][j] = 1;

      if(_map[i][j]->getclass() == "Vote")
        tab[i][j] = 2;

      if(_map[i][j]->getclass() == "Joueur")
        tab[i][j] = 3;

      if(_map[i][j]->getclass() == "Fantome")
        tab[i][j] = 4;

      if(_map[i][j]->getclass() == "Bonus")
        tab[i][j] = 5;

      if(_map[i][j]->getclass() == "Prison")
        tab[i][j] = 6;
    }
  }
  return tab;
}