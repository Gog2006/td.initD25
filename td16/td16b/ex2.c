1. Le principal avantage de Make est la compilation incrémentale : il ne recompile que les fichiers modifiés et leurs dépendances, ce qui fait gagner beaucoup de temps sur les gros projets.

2. Compilation monolithique : Tous les fichiers sources sont compilés en une seule commande pour produire directement l'exécutable.

Compilation séparée : Chaque fichier source est compilé indépendamment en fichier objet (.o), puis tous les fichiers objets sont liés ensemble pour former l'exécutable final.

L'avantage de la compilation séparée est qu'on peut recompiler uniquement les fichiers modifiés sans tout recompiler.


.PHONY: all clean

all: app

app: main.o lib/utils.o
	gcc -o app main.o lib/utils.o

main.o: main.c lib/utils.h
	gcc -c main.c

lib/utils.o: lib/utils.c lib/utils.h
	gcc -c lib/utils.c -o lib/utils.o

clean:
	rm -f *.o lib/*.o app 
   
 *\

3  . Pour définir une cible "clean" dans un Makefile qui supprime les fichiers objets et l'exécutable, on peut ajouter la section suivante à la fin du Makefile.


On utilise la directive .PHONY :
makefile.PHONY: clean all install

clean:
	rm -f *.o program
Cela indique à Make que clean est une cible "phony" (factice) qui ne correspond pas à un fichier réel, et qu'elle doit toujours être exécutée quand on l'appelle.