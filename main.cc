
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


using namespace std;


void deplacementJoueur(Carte& C)
{
	bool Vchoix= false;
	int choix;
	int PosXJoueur, PosYJoueur;

	while(Vchoix == false){
		
		std::cout<< "Quelle direction ?"<<std::endl;
		std::cout << " 1.haut  2.droite 3.bas 4.gauche";
		cin>>choix;

		switch(choix)
		{
			case 1:
				PosYJoueur = C.getJoueur(PosXJoueur);
				C.setJoueur(PosXJoueur,PosYJoueur,0,-1);
				PosYJoueur = C.getJoueur(PosXJoueur);
				Vchoix=true;
			 	break;

			case 2: 
				PosYJoueur = C.getJoueur(PosXJoueur);
				C.setJoueur(PosXJoueur,PosYJoueur,1,0);
				PosYJoueur = C.getJoueur(PosXJoueur);
				Vchoix=true;
			break;

			case 3: 
				PosYJoueur = C.getJoueur(PosXJoueur);
				C.setJoueur(PosXJoueur,PosYJoueur,0,1);
				PosYJoueur = C.getJoueur(PosXJoueur);
				Vchoix=true;
			break;

			case 4: 
				PosYJoueur = C.getJoueur(PosXJoueur);
				C.setJoueur(PosXJoueur,PosYJoueur,-1,0);
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
	Carte C(20,20,1,2,4,15,2);

	while(1){
		C.afficherMap();
		deplacementJoueur(C);
		

	}


	return 0;
}
