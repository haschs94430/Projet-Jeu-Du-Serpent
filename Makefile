FLAGS = -ansi -pedantic -Wall -lMLV

Snake : Main.o Monde.o MLV.o Pomme.o Serpent.o Case.o
	gcc -o Snake Main.o Monde.o MLV.o Pomme.o Serpent.o Case.o $(FLAGS)

Main.o : Main.c Monde.h MLV.h
	gcc -c Main.c $(FLAGS)

Monde.o : Monde.c Monde.h Pomme.h Serpent.h
	gcc -c Monde.c $(FLAGS)

MLV.o : MLV.c MLV.h Monde.h
	gcc -c MLV.c $(FLAGS)

Pomme.o : Pomme.c Pomme.h Case.h
	gcc -c Pomme.c $(FLAGS)

Serpent.o : Serpent.c Serpent.h Case.h
	gcc -c Serpent.c $(FLAGS)

Case.o : Case.c Case.h
	gcc -c Case.c $(FLAGS)