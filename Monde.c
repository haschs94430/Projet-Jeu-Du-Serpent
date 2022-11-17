#include "Monde.h"

/*fonction qui ajoute une nouvelle pomme au monde, elle utilise la fonction pomme_gen_alea*/

void ajouter_pomme_monde(Monde *mon) {
	Pomme p;
	int x;
	int y;
	int i;
	int j;

	p = pomme_gen_alea(N, M);
	x = p.position.ligne;
	y = p.position.colonne;

	/* verifie que la pomme n'apparaisse pas sur le serpent */
	for (i = 0; i < mon->serpent.taille; i++) {
		if (y == mon->serpent.corps[i].ligne && x == mon->serpent.corps[i].colonne) {
			ajouter_pomme_monde(mon);
			return ;
		}
	}

	/* verifie que la pomme n'apparaisse pas sur une pomme deja existante */
	for (j = 0; j < 3; j++) {
		if (x == mon->pomme[j].position.ligne && y == mon->pomme[j].position.colonne) {
			ajouter_pomme_monde(mon);
			return ;
		}
	}

	for (i = 0; mon->pomme[i].position.ligne != 0 && mon->pomme[i].position.colonne != 0; i++) {
		;
	}
	mon->pomme[i].position.ligne = x;
	mon->pomme[i].position.colonne = y;
}

/*fonction ajoutee */
Monde monde_gen() {
	Monde mon;
	int i;

	for (i = 0; i < 3; i++) {
		mon.pomme[i].position.ligne = 0;
		mon.pomme[i].position.colonne = 0;
	}
	mon.nb_mange = 0;
	return mon;
}

/*fonction qui renvoie un monde dans une configuration initiale pour le jeu, des pommes y sont disposées, le serpent de trouve dans sa configuration initiale fournie par la fonction init_serpent*/

Monde init_monde(int nb_pommes) {
	int i = 0;
	Monde mon;

	mon = monde_gen();
	mon.serpent = init_serpent();
	while (i < nb_pommes) {
		ajouter_pomme_monde(&mon);
		i++;
	}
	return mon;
}

/*fonction qui modifie le serpent du monde  de sorte a le faire avancer suivant sa direction vers une case vide, renvoie 1 si la tete du serpent arrive bien sur une case vide, et 0 si la tete arrive sur une case non vide*/

int deplacer_serpent(Monde *mon) {
	int i;
	int j = mon->serpent.taille;
	int tete_serp_x;
	int tete_serp_y;

	/* on stocke les coordonnees de la tete */
	tete_serp_x = mon->serpent.corps[0].ligne;
	tete_serp_y = mon->serpent.corps[0].colonne;

	while (j > 0) {
		mon->serpent.corps[j].ligne = mon->serpent.corps[j - 1].ligne;
		mon->serpent.corps[j].colonne = mon->serpent.corps[j - 1].colonne;
		j--;
	}

	if (mon->serpent.dir == NORD) {
		/* on compare les coordonnees de chaque pomme avec les coordonnees de la tete du serpent */
		for (i = 0; i < 3; i++){
			if (mon->pomme[i].position.ligne == tete_serp_x - 1 && mon->pomme[i].position.colonne == tete_serp_y) {
				return 0;
			}
		}
		mon->serpent.corps[0].colonne -= 1;
	}

	else if (mon->serpent.dir == SUD) {
		for (i = 0; i < 3; i++){
			if (mon->pomme[i].position.ligne == tete_serp_x + 1 && mon->pomme[i].position.colonne == tete_serp_y) {
				return 0;
			}
		}
		mon->serpent.corps[0].colonne += 1;
	}

	else if (mon->serpent.dir == EST) {
		for (i = 0; i < 3; i++){
			if (mon->pomme[i].position.ligne == tete_serp_x && mon->pomme[i].position.colonne == tete_serp_y + 1) {
				return 0;
			}
		}
		mon->serpent.corps[0].ligne += 1;
	}

	else if (mon->serpent.dir == OUEST) {
		for (i = 0; i < 3; i++){
			if (mon->pomme[i].position.ligne == tete_serp_x && mon->pomme[i].position.colonne == tete_serp_y - 1) {
				return 0;
			}
		}
		mon->serpent.corps[0].ligne -= 1;
	}

	return 1;
}

/*fonction qui modifie le serpent du monde de sorte a le faire avancer suivant sa direction vers une case occupée par une pomme, renvoie 1 si la tete du serpent arrive bien sur une case occupée par une pomme et donc supprimer la pomme mangée, et 0 si la case n'est pas occupée par une pomme*/

int manger_pomme(Monde *mon) {
	int i;
	int tete_x;
	int tete_y;

	tete_x = mon->serpent.corps[0].colonne;
	tete_y = mon->serpent.corps[0].ligne;
	for (i = 0; i < 3; i++) {
		if (tete_x == mon->pomme[i].position.ligne && tete_y == mon->pomme[i].position.colonne) {
			mon->nb_mange ++;
			mon->pomme[i].position.ligne = 0;
			mon->pomme[i].position.colonne = 0;
			return 1;
		}
	}
	return 0;
}

/*fonction ajoutée*/

void grandir_serpent(Monde *mon) {
	int queue_x;
	int queue_y;
	int avant_x;
	int avant_y;

	queue_x = mon->serpent.corps[mon->serpent.taille].ligne;
	queue_y = mon->serpent.corps[mon->serpent.taille].colonne;
	avant_x = mon->serpent.corps[mon->serpent.taille - 1].ligne;
	avant_y = mon->serpent.corps[mon->serpent.taille - 1].colonne;

	if (queue_x > avant_x) {
		mon->serpent.taille++;
		mon->serpent.corps[mon->serpent.taille].ligne = queue_x + 1;
		mon->serpent.corps[mon->serpent.taille].colonne = queue_y;
	}

	if (queue_y > avant_y) {
		mon->serpent.taille++;
		mon->serpent.corps[mon->serpent.taille].ligne = queue_x;
		mon->serpent.corps[mon->serpent.taille].colonne = queue_y + 1;
	}

	if (queue_x < avant_x) {
		mon->serpent.taille++;
		mon->serpent.corps[mon->serpent.taille].ligne = queue_x - 1;
		mon->serpent.corps[mon->serpent.taille].colonne = queue_y;
	}

	if (queue_y < avant_y) {
		mon->serpent.taille++;
		mon->serpent.corps[mon->serpent.taille].ligne = queue_x;
		mon->serpent.corps[mon->serpent.taille].colonne = queue_y - 1;
	}
}

/*fonction qui renvoie 1 si le serpent du monde va se trouver dans une situation perdante a l'issue de son déplacement imposé par direction et 0 sinon*/

int mort_serpent(Monde *mon) {
	int i;
	int tete_x;
	int tete_y;

	tete_x = mon->serpent.corps[0].ligne;
	tete_y = mon->serpent.corps[0].colonne;

	/* si la tete du serpent rencontre une partie du corps du serpent */
	for (i = 1; i < mon->serpent.taille; i++) {
		if (tete_x == mon->serpent.corps[i].ligne && tete_y == mon->serpent.corps[i].colonne) {
			return 1;
		}
	}

	/* si la tete du serpent sort du quadrillage */
	if (tete_x < 1 || tete_x > M || tete_y < 1 || tete_y > N) {
		return 1;
	}
	return 0;
}
