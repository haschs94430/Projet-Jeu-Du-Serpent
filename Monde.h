#ifndef __MONDE__
#define __MONDE__

#include "Serpent.h"
#include "Pomme.h"

#include <MLV/MLV_all.h>

/*type permettant de representer une situation de jeu, qui comprend le serpent, les positions des pommes et le nombres de pommes mangées*/

typedef struct monde {
	Serpent serpent;
	Pomme pomme[3];
	int nb_mange;
} Monde;

/*fonction qui ajoute une nouvelle pomme au monde, elle utilise la fonction pomme_gen_alea*/

void ajouter_pomme_monde(Monde *mon);

/*fonction ajoutee*/
Monde monde_gen();

/*fonction qui renvoie un monde dans une configuration initiale pour le jeu, des pommes y sont disposées, le serpent de trouve dans sa configuration initiale fournie par la fonction init_serpent*/

Monde init_monde(int nb_pommes);

/*fonction qui modifie le serpent du monde  de sorte a le faire avancer suivant sa direction vers une case vide, renvoie 1 si la tete du serpent arrive bien sur une case vide, et 0 si la tete arrive sur une case non vide*/

int deplacer_serpent(Monde *mon);

/*fonction qui modifie le serpent du monde de sorte a le faire avancer suivant sa direction vers une case occupée par une pomme, renvoie 1 si la tete du serpent arrive bien sur une case occupée par une pomme et donc supprimer la pomme mangée, et 0 si la case n'est pas occupée par une pomme*/

int manger_pomme(Monde *mon);

/*fonction ajoutée*/

void grandir_serpent(Monde *mon);

/*fonction qui renvoie 1 si le serpent du monde va se trouver dans une situation perdante a l'issue de son déplacement imposé par direction et 0 sinon*/

int mort_serpent(Monde *mon);

#endif
