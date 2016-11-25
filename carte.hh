/******************************************************************************************
 * [Polytech-EISE4-C++] 2016-2017 LEVERT MAURY                                            *
 * La Classe Carte doit afficher la carte dans laquelle les personnages évoluent.         *
 * Il faut afficher les obstacles (murs), objets et personnages.                          *
 * La position de tous doit être mise à jour à chaque déplacement, récupération d'objet.  *
 * L'affichage doit être rafraîchi après certaines action (déplacement, effet objet).     *
 ******************************************************************************************/

#include <iostream>
#include <string>
#include "composantM.hh"
#include "joueur.hh"
#include "prison.hh"
#include "bonus.hh"
#include "vote.hh"
#include "fantome.hh"
#include "chemin.hh"

#define DEF_SIZE 10

class Carte {
protected :
   unsigned int _ligne, _colonne;
	ComposantM ***_map;

public :
   Carte();
	Carte(unsigned int ligne, unsigned int colonne, unsigned int nbJoueur, unsigned int nbBonus, unsigned int nbFantome, unsigned int nbVote, unsigned int nbPrison);
	//~Carte();

	void afficherMap(void);

	//ComposantM** setIndex();
	//ComposantM** getIndex ();
};
