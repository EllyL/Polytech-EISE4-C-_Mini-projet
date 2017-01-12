/******************************************************************************************
 * [Polytech-EISE4-C++] 2016-2017 LEVERT MAURY                                            *
 * La Classe Carte doit afficher la carte dans laquelle les personnages évoluent.         *
 * Il faut afficher les obstacles (murs), objets et personnages.                          *
 * La position de tous doit être mise à jour à chaque déplacement, récupération d'objet.  *
 * L'affichage doit être rafraîchi après certaines action (déplacement, effet objet).     *
 ******************************************************************************************/
#pragma once
#include <iostream>
#include <string>
#include "composantM.hh"
#include "joueur.hh"
#include "prison.hh"
#include "bonus.hh"
#include "vote.hh"
#include "fantome.hh"
#include "chemin.hh"
#include "obstacle.hh"

#define DEF_SIZE 10

class Carte {
protected :
   unsigned int _ligne, _colonne;			
	ComposantM ***_map;						//carte du jeu
	int _nbEnv;
	int** tab;

public :
   Carte();
	Carte(unsigned int ligne, unsigned int colonne, unsigned int nbJoueur, unsigned int nbBonus, unsigned int nbFantome, unsigned int nbVote, unsigned int nbPrison);
	//Carte(unsigned int nbJoueur, unsigned int nbBonus, unsigned int nbFantome, unsigned int nbVote, unsigned int nbPrison);
	// constructeur créant une carte avec les murs déja fait! 

	~Carte();

	void afficherMap(void);

	//ComposantM** setIndex();
	//ComposantM** getIndex ();


	//fonctions permettant de récupérer la position et de déplacer le joueur
	void getJoueur(int& k,int& l);			
	void setJoueur(int x, int y,int decX, int decY,bool& perdu, int& scoreJ, std::string& effet, bool& arreter);

	//fonctions permettant de déplacer les fantomes
	void DeplacementFantome(bool& perdu);
	void setFantome(int x, int y,int decX, int decY,bool& perdu);

	int get_nbEnv(){return _nbEnv;};
	int comptEnv();

	int** getTileMap();
	
};
