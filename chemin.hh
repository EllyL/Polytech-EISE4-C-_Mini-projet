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

class Chemin: public ComposantM{
   protected :

   public :
      Chemin(unsigned int x, unsigned int y);
      Chemin(const Chemin &a);
      ~Chemin();

      string affichage() const;							
      string getclass() const{return "Chemin";}
      void operator= (const Chemin &a);


      void set_posx(unsigned int x){_posx = x;}
      unsigned int get_posx() {return _posx;}

      void set_posy(unsigned int y){_posy = y;}
      unsigned int get_posy() {return _posy;}
};


