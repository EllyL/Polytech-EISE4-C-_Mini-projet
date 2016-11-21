CC = g++
OPT = $(CC) -Wall -std=c++11


jeu : main.o carte.o composantM.o personnage.o objet.o obstacle.o joueur.o fantome.o bonus.o prison.o vote.o 
	$(OPT) -c jeu main.o carte.o composantM.o personnage.o object.o obstacle.o joueur.o fantome.o bonus.o prison.o vote.o

main.o : main.cc carte.hh composantM.hh personnage.hh objet.hh obstacle.hh joueur.hh fantome.hh bonus.hh prison.hh vote.hh 
	$(OPT) -o main.cc 


composantM.o : composantM.hh composantM.cc
	$(OPT) -o composantM.cc

personnage.o : personnage.hh personnage.cc composantM.hh
	$(OPT) -o personnage.cc 

objet.o : objet.cc objet.hh composantM.hh
	$(OPT) -o objet.cc

obstacle.o : obstacle.cc obstacle.hh composantM.hh
	$(OPT) -o obstacle.cc

joueur.o : joueur.cc joueur.hh personnage.hh
	$(OPT) -o joueur.cc

fantome.o : fantome.cc fantome.hh personnage.hh
	$(OPT) -o fantome.cc

bonus.o : bonus.cc bonus.hh object.hh
	$(OPT) -o bonus.cc

prison.o : prison.cc prison.hh object.hh
	$(OPT) -o prison.cc

vote.o : vote.cc vote.hh object.hh
	$(OPT) -o vote.cc

carte.o : carte.cc carte.hh
	$(OPT) -o carte.cc

clean :
	rm -f *.o 
