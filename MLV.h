#ifndef __MLV__
#define __MLV__

#include "Monde.h"

#define CARRE 20
#define TAILLE_X CARRE * M
#define TAILLE_Y CARRE * N
#define BORD 50

/*fonction qui affiche le quadrillage */

void afficher_quadrillage(Monde *mon);

/*fonction qui affiche la pomme selon sa position*/

void afficher_pomme(Pomme *pom);

/*fonction qui affiche le serpent selon sa position*/

void afficher_serpent(Serpent *ser);

/*fonction qui affiche le monde, dessine la situation de jeu au complet, le quadrillage, le serpent, les pommes et le nombres de pommes mangées*/

void afficher_monde(Monde *mon);

/* fonction ajoutee */

void afficher_score(Monde *mon);

/*fonction ajoutée*/

void fin_partie(Monde mon);

/* fonction ajoutee */

void direction_serpent(Monde *mon, MLV_Keyboard_button touche);

#endif
