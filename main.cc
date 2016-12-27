
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
#define NBF 4

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



int main()
{
	std::srand(std::time(0));
//parametre ligne , colonne ,Joueur, Bonus, Fantome, Vote, Prison
	Carte C(20,20,1,2,NBF,15,2);

	bool perdu=false;
	

	while(perdu != true){
		C.afficherMap();
		deplacementJoueur(C,perdu);
		C.DeplacementFantome(perdu);

	
	}
	

	return 0;
}
