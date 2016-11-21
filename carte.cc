/****************************************************************************************** 
 * [Polytech-EISE4-C++] 2016-2017 LEVERT MAURY                                            *
 * La Classe Carte doit afficher la carte dans laquelle les personnages évoluent.         *
 * Il faut afficher les obstacles (murs), objets et personnages.                          *
 * La position de tous doit être mise à jour à chaque déplacement, récupération d'objet.  *
 * L'affichage doit être rafraîchi après certaines action (déplacement, effet objet).     *
 ******************************************************************************************/

#include "carte.hh"

/*
 * Le constructeur va prendre le nom du type d'élément que l'on veut mettre en place, puis le nombre voulu de ce type.
 * Une map de jeu est alors construite de façon aléatoire selon des conditions critiques pour des raisons de jouabilité.
 */
Carte::Carte(unsigned int ligne, unsigned int colonne, ){
	map = (composantM**)malloc(sizeof(composantM*)*ligne);

}


