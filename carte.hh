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

class Carte {
protected :
	composantM **_map;

public :
	Carte();
	~Carte();
	void afficherMap();
	composantM** setIndex();
	composantM** getIndex ();
}
