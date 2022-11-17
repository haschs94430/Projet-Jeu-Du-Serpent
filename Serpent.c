#include "Serpent.h"

/*fonction qui renvoie un serpent dont la tete est située au centre du quadrillage, dispose une partie corps située a gauche de sa tete, direction vers l'est*/

Serpent init_serpent() {
	Serpent ser;
	int i;

	ser.corps[0].ligne = M / 2;
	ser.corps[0].colonne = N / 2;
	for (i = 0; i < TAILLE_SERP - 1; i++) {
		ser.corps[i + 1].ligne = M / 2 - (i + 1);
		ser.corps[i + 1].colonne = N / 2;
	}
	ser.taille = TAILLE_SERP;
	ser.dir = EST;
	return ser;
}
