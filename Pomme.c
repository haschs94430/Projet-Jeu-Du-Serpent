#include "Pomme.h"

#include <time.h>
#include <stdlib.h>

/*fonction qui renvoie une pomme générée aleatoirement de sorte qu'elle tienne dans un quadrillage n*m*/

Pomme pomme_gen_alea(int n, int m) {
	Pomme p;

	p.position.ligne = rand() % n + 1;
	p.position.colonne = rand() % m + 1;
	return p;
}
