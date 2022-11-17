#ifndef __POMME__
#define __POMME__

#include "Case.h"

/*type permettant de codé une pomme par sa position*/

typedef struct pomme {
	Case position;
} Pomme;

/*fonction qui renvoie une pomme générée aleatoirement de sorte qu'elle tienne dans un quadrillage n*m*/

Pomme pomme_gen_alea(int n, int m);

#endif
