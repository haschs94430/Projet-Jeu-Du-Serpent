#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <MLV/MLV_all.h>

#include "Monde.h"
#include "MLV.h"

#define TAILLE_X CARRE * M
#define TAILLE_Y CARRE * N
#define BORD 50
#define NB_POMMES 3

int main(int argc, char* argv[]){
	Monde mon;
	MLV_Keyboard_button touche;
	MLV_Button_state etat;
	MLV_Event event;

	srand(time(NULL));
	MLV_create_window("Snake", "", TAILLE_X + BORD, TAILLE_Y + BORD);
	mon = init_monde(NB_POMMES);
	afficher_monde(&mon);
	MLV_wait_keyboard(&touche, NULL, NULL);
	if (touche == MLV_KEYBOARD_SPACE) {
		while (mort_serpent(&mon) != 1) {

			event = MLV_get_event(&touche, NULL, NULL, NULL, NULL, NULL, NULL, NULL, &etat);
			if (event == MLV_KEY) {
				if (etat == MLV_PRESSED) {
					;
				}
			}

			if (manger_pomme(&mon) == 1) {
				ajouter_pomme_monde(&mon);
				grandir_serpent(&mon);
			}

			direction_serpent(&mon, touche);			
			deplacer_serpent(&mon);
			MLV_clear_window(MLV_COLOR_BLACK);
			afficher_monde(&mon);
			MLV_wait_milliseconds(75);
		}
		fin_partie(mon);
		MLV_wait_keyboard(&touche, NULL, NULL);
	}

	MLV_actualise_window();
	MLV_free_window();
	
	return 0;
}
