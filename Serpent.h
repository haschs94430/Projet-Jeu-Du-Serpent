#ifndef __SERPENT__
#define __SERPENT__

#include "Case.h"

#define N 32
#define M 64
#define TAILLE_SERP 4

/*type permettant de representer les 4 directions cardinales*/

typedef enum {
	NORD,
	SUD,
	EST,
	OUEST
} Direction;

/*type qui permet de representer un serpent par un tableau statique N*M, sa taille ainsi que sa direction*/

typedef struct serpent {
	Case corps[N * M];
	int taille;
	Direction dir;
} Serpent;

/*fonction qui renvoie un serpent dont la tete est située au centre du quadrillage, dispose une partie corps située a gauche de sa tete, direction vers l'est*/

Serpent init_serpent();

#endif
