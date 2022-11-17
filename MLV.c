#include "MLV.h"

/*fonction qui affiche le quadrillage */

void afficher_quadrillage(Monde *mon) {
	int i;
	int carre;

	carre = 0;
	for (i = 0; i < M + 1; i++) {
		MLV_draw_line(carre + BORD / 2, 0  + BORD / 2, carre + BORD / 2, TAILLE_Y + BORD / 2, MLV_COLOR_WHITE);
		carre += CARRE;
	}

	carre = 0;
	for (i = 0; i < N + 1; i++) {
		MLV_draw_line(0 + BORD / 2, carre + BORD / 2, TAILLE_X + BORD / 2, carre + BORD / 2, MLV_COLOR_WHITE);
		carre += CARRE;
	}
}

/*fonction qui affiche la pomme selon sa position*/

void afficher_pomme(Pomme *pom) {
	int x;
	int y;

	x = pom->position.colonne;
	y = pom->position.ligne;
	MLV_draw_filled_circle(x * CARRE - (CARRE / 2)  + BORD / 2, y * CARRE - (CARRE / 2) + BORD / 2, CARRE / 3, MLV_COLOR_RED);
}

/*fonction qui affiche le serpent selon sa position*/

void afficher_serpent(Serpent *ser) {
	int i;
	int tete_x;
	int tete_y;

	tete_x = ser->corps[0].ligne;
	tete_y = ser->corps[0].colonne;
	MLV_draw_filled_circle(tete_x * CARRE - (CARRE / 2) + BORD / 2, tete_y * CARRE - (CARRE / 2) + BORD / 2, CARRE / 3, MLV_COLOR_YELLOW);
	for (i = 1; i < ser->taille; i++) {
		MLV_draw_filled_rectangle(ser->corps[i].ligne * CARRE - (3 * CARRE / 4) + BORD / 2, ser->corps[i].colonne * CARRE - (3 * CARRE / 4) + BORD / 2, CARRE / 2, CARRE / 2, MLV_COLOR_GREEN);
	}
}

/*fonction qui affiche le monde, dessine la situation de jeu au complet, le quadrillage, le serpent, les pommes et le nombres de pommes mangées*/

void afficher_monde(Monde *mon) {
	int i;

	afficher_score(mon);
	afficher_quadrillage(mon);
	afficher_serpent(&mon->serpent);
	for (i = 0; i < 3; i++) {
		afficher_pomme(&mon->pomme[i]);

		MLV_actualise_window();
	}
}

/*fonction ajoutee */
void afficher_score(Monde *mon){
	MLV_draw_text(TAILLE_X / 2, 5, "Score: %d", MLV_COLOR_WHITE, mon->nb_mange);
}

/*fonction ajoutée*/

void fin_partie(Monde mon) {
	MLV_clear_window(MLV_COLOR_BLACK);
	MLV_draw_text((TAILLE_X + BORD) / 2 - 45, (TAILLE_Y + BORD) / 2, "Partie terminee", MLV_COLOR_WHITE);
	MLV_draw_text((TAILLE_X + BORD) / 2 - 25, (TAILLE_Y + BORD) / 2 + 12, "Score: %d", MLV_COLOR_WHITE, mon.nb_mange);
	MLV_actualise_window();
}

/*fonction ajoutee */
void direction_serpent(Monde *mon, MLV_Keyboard_button touche) {
	if (touche == MLV_KEYBOARD_UP) {
		if (mon->serpent.dir != SUD) {
			mon->serpent.dir = NORD;
		}
	}

	if (touche == MLV_KEYBOARD_DOWN) {
		if (mon->serpent.dir != NORD) {
			mon->serpent.dir = SUD;
		}
	}

	if (touche == MLV_KEYBOARD_LEFT) {
		if (mon->serpent.dir != EST) {
			mon->serpent.dir = OUEST;
		}
	}

	if (touche == MLV_KEYBOARD_RIGHT) {
		if (mon->serpent.dir != OUEST) {
			mon->serpent.dir = EST;
		}
	}	
}
