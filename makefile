CC = g++
OPT = $(CC) -Wall -std=c++11


jeu : main.o composantM.o joueur.o fantome.o obstacle.o  prison.o vote.o bonus.o  carte.o chemin.o
	$(OPT) -o jeu main.o composantM.o joueur.o fantome.o obstacle.o  prison.o vote.o bonus.o  chemin.o  carte.o 

main.o : main.cc composantM.hh personnage.hh  joueur.hh fantome.hh obstacle.hh objet.hh prison.hh vote.hh carte.hh chemin.hh #bonus.hh   carte.hh  
	$(OPT) -c main.cc 


composantM.o : composantM.hh composantM.cc
	$(OPT) -c composantM.cc


#objet.o : objet.cc objet.hh composantM.hh
#	$(OPT) -c objet.cc

obstacle.o : obstacle.cc obstacle.hh composantM.hh
	$(OPT) -c obstacle.cc

joueur.o : joueur.cc joueur.hh personnage.hh
	$(OPT) -c joueur.cc

fantome.o : fantome.cc fantome.hh personnage.hh
	$(OPT) -c fantome.cc

bonus.o : bonus.cc bonus.hh objet.hh
	$(OPT) -c bonus.cc

prison.o : prison.cc prison.hh objet.hh
	$(OPT) -c prison.cc

vote.o : vote.cc vote.hh objet.hh
	$(OPT) -c vote.cc

carte.o : carte.cc carte.hh
	$(OPT) -c carte.cc

chemin.o : chemin.cc chemin.hh composantM.hh
	$(OPT) -c chemin.cc
 
clean :
	rm -f *.o 
