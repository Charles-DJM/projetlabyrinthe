#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "libgraphique.h"
#include "Fonctions.c"
#include "Creation_interactive.c"
#include "Enregistrements.c"
#include "Jeu_Interactif.c"
#include "Creation_Automatique.c"
#include "Jeu_Automatique.c"

#define MAX 100

int main (void)
{int i, j, Score, Choix, Choix2, Choix3, Choix4, Choix5, Choix6, Choix8, Boucle ;
int x, y, x2, y2, n ;
FILE *f ;
srand(time(0));

start_graphics() ;

// Menu graphique
set_drawing_color (color_BLACK) ;
set_font (font_HELVETICA_18) ;
draw_string (190, 330, "T H E    M A Z E    R U N N E R") ;
draw_rectangle (130, 300, 510, 380) ;
set_drawing_color (color_RED) ;
draw_string (160, 250, "CLERC Billy") ;
draw_string (320, 250, "DE JAHAM Charles") ;
set_drawing_color (color_BLACK) ;
set_font (font_HELVETICA_12) ;
draw_string (200, 210, "Pour commencer, appuyez sur une touche") ;
update_graphics () ;
get_key () ;

do
{

  // Initialisation MUR
  int MUR [MAX][MAX] ;
  int MUR2 [MAX][MAX] ;
  for (i = 0 ; i < MAX ; i++)
    {for (j = 0 ; j < MAX ; j++)
      {MUR[i][j] = 1 ;
      }
    }

  // Menu 1
  clear_screen () ;
  set_drawing_color (color_RED) ;
  set_font (font_HELVETICA_18) ;
  draw_string (100, 400, "Entrez le chiffre correspondant a votre choix :") ;
  set_drawing_color (color_BLACK) ;
  set_font (font_HELVETICA_12) ;
  draw_string (120, 360, "1 : Construction interactive d'un labyrinthe") ;
  draw_string (120, 320, "2 : Construction automatique d'un labyrinthe") ;
  draw_string (120, 280, "3 : Jouer a un labyrinthe precedemment sauvegarde") ;
  draw_string (120, 240, "4 : Resolution automatique d'un labyrinthe sauvegarde") ;
  draw_string (120, 200, "5 : Quitter le jeu") ;
  update_graphics () ;
  Choix = get_key () - 48 ;

  if (Choix == 1)
  {
    // Taille du labyrinthe
    clear_screen () ;
    set_drawing_color (color_RED) ;
    set_font (font_HELVETICA_18) ;
    draw_string (100, 290, "Le labyrinthe que vous allez construire sera un carre") ;
    set_drawing_color (color_BLACK) ;
    set_font (font_HELVETICA_12) ;
    draw_string (120, 250, "Saisir le parametre n correspondant aux nombres de lignes/colonnes") ;
    update_graphics () ;
    n = get_key () - 48 ;
    clear_screen () ;
    update_graphics () ;

    x=30 , y= (n*60)-30, x2 = 0, y2 = n - 1 ;

    // Créer labyrinthe Interactivement
    Grille (n) ;
    Creer_Curseur (&x, &y) ;
    Case_Arrivee (n) ;
    Mouvement_Creation (&x, &y, &x2, &y2, n, MUR) ;
    set_drawing_color (color_BLACK) ;
    set_font (font_HELVETICA_12) ;
    draw_string (530, 210, "Pour finir,") ;
    draw_string (490, 170, "appuyez sur une touche") ;
    update_graphics () ;
    get_key () ;

    // Choix emplacement de sauvegarde
    clear_screen () ;
    set_drawing_color (color_RED) ;
    set_font (font_HELVETICA_18) ;
    draw_string (100, 400, "Entrez le chiffre correspondant a votre choix :") ;
    set_drawing_color (color_BLACK) ;
    set_font (font_HELVETICA_12) ;
    draw_string (120, 360, "1 : Sauvegarde du labyrinthe dans 'Labyrinthe1.txt'") ;
    draw_string (120, 320, "2 : Sauvegarde du labyrinthe dans 'Labyrinthe2.txt'") ;
    draw_string (120, 280, "3 : Sauvegarde du labyrinthe dans 'Labyrinthe3.txt'") ;
    update_graphics () ;
    Choix2 = get_key () - 48 ;

    if (Choix2 == 1)
      // Enregister dans 'Labyrinthe1.txt'
      {f = fopen ("Labyrinthe1.txt", "w") ;
      Enregistrement (f, MUR) ;
      fclose (f) ;
      f = fopen ("Labyrinthe1n.txt", "w") ;
      Enregistrement_n (f, n) ;
      fclose (f) ;
      }

    if (Choix2 == 2)
      // Enregister dans 'Labyrinthe2.txt'
      {f = fopen ("Labyrinthe2.txt", "w") ;
      Enregistrement (f, MUR) ;
      fclose (f) ;
      f = fopen ("Labyrinthe2n.txt", "w") ;
      Enregistrement_n (f, n) ;
      fclose (f) ;
      }

    if (Choix2 == 3)
      // Enregister dans 'Labyrinthe3.txt'
      {f = fopen ("Labyrinthe3.txt", "w") ;
      Enregistrement (f, MUR) ;
      fclose (f) ;
      f = fopen ("Labyrinthe3n.txt", "w") ;
      Enregistrement_n (f, n) ;
      fclose (f) ;
      }


    Boucle = 1 ;
    }

  if (Choix == 2)
    {
    // CHoix entre n aléatoire ou prédéfinis
    clear_screen () ;
    set_drawing_color (color_RED) ;
    set_font (font_HELVETICA_18) ;
    draw_string (100, 400, "Entrez le chiffre correspondant a votre choix :") ;
    set_drawing_color (color_BLACK) ;
    set_font (font_HELVETICA_12) ;
    draw_string (120, 360, "1 : Parametre n choisit aleatoirement") ;
    draw_string (120, 320, "2 : Choisir parametre n") ;
    update_graphics () ;
    Choix5 = get_key () - 48 ;

    if (Choix5 == 1)
      {
      // Taille du labyrinthe aléatoire
      n = (rand() % 6) + 3 ;
      clear_screen () ;
      set_drawing_color (color_RED) ;
      set_font (font_HELVETICA_18) ;
      draw_string (120, 290, "Le labyrinthe qui va etre construit sera un carre") ;
      set_drawing_color (color_BLACK) ;
      set_font (font_HELVETICA_12) ;
		  draw_printf (120, 250, "Le parametre n correspondant aux nombres de lignes/colonnes est %d", n) ;
		  draw_printf (200, 210, "Pour continuer, appuyez sur une touche", n) ;
      update_graphics () ;
      get_key () ;

      clear_screen () ;
      set_drawing_color (color_RED) ;
      set_font (font_HELVETICA_18) ;
      draw_string (100, 400, "Entrez le chiffre correspondant a votre choix :") ;
      set_drawing_color (color_BLACK) ;
      set_font (font_HELVETICA_12) ;
      draw_string (120, 360, "1 : Voir la creation automatique") ;
      draw_string (120, 320, "2 : Passer directement au choix de sauvegarde") ;
      update_graphics () ;
      Choix6 = get_key () - 48 ;

      if (Choix6 == 1)
        {
        Creation_Laby_Auto(n, 1) ;
        }
      if (Choix6 == 2)
        {
        Creation_Laby_Auto_Passer(n, 0) ;
        }
      }

    if (Choix5 == 2)
      {
      // Taille du labyrinthe
      clear_screen () ;
      set_drawing_color (color_RED) ;
      set_font (font_HELVETICA_18) ;
      draw_string (100, 290, "Le labyrinthe que vous allez construire sera un carre") ;
      set_drawing_color (color_BLACK) ;
      set_font (font_HELVETICA_12) ;
      draw_string (120, 250, "Saisir le parametre n correspondant aux nombres de lignes/colonnes") ;
      update_graphics () ;
      n = get_key () - 48 ;

      clear_screen () ;
      set_drawing_color (color_RED) ;
      set_font (font_HELVETICA_18) ;
      draw_string (100, 400, "Entrez le chiffre correspondant a votre choix :") ;
      set_drawing_color (color_BLACK) ;
      set_font (font_HELVETICA_12) ;
      draw_string (120, 360, "1 : Voir la creation automatique") ;
      draw_string (120, 320, "2 : Passer directement au choix de sauvegarde") ;
      update_graphics () ;
      Choix6 = get_key () - 48 ;

      if (Choix6 == 1)
        {
        Creation_Laby_Auto(n, 1) ;
        }
      if (Choix6 == 2)
        {
        Creation_Laby_Auto_Passer(n, 0) ;
        }
      }


    Boucle = 1 ;
    }

  if (Choix == 3)
    {

    // Choix emplacement de chargement
    clear_screen () ;
    set_drawing_color (color_RED) ;
    set_font (font_HELVETICA_18) ;
    draw_string (100, 400, "Entrez le chiffre correspondant a votre choix :") ;
    set_drawing_color (color_BLACK) ;
    set_font (font_HELVETICA_12) ;
    draw_string (120, 360, "1 : Chargement du labyrinthe dans 'Labyrinthe1.txt'") ;
    draw_string (120, 320, "2 : Chargement du labyrinthe dans 'Labyrinthe2.txt'") ;
    draw_string (120, 280, "3 : Chargement du labyrinthe dans 'Labyrinthe3.txt'") ;
    update_graphics () ;
    Choix3 = get_key () - 48 ;

    if (Choix3 == 1)
      // Charger 'Labyrinthe1.txt'
      {f = fopen ("Labyrinthe1n.txt", "r") ;
      Charger_n (f, &n) ;
      fclose (f) ;
      f = fopen("Labyrinthe1.txt", "r") ;
      Charger_Labyrinthe (f, MUR2) ;
      fclose (f) ;
      }

    if (Choix3 == 2)
      // Charger 'Labyrinthe2.txt'
      {f = fopen ("Labyrinthe2n.txt", "r") ;
      Charger_n (f, &n) ;
      fclose (f) ;
      f = fopen("Labyrinthe2.txt", "r") ;
      Charger_Labyrinthe (f, MUR2) ;
      fclose (f) ;
      }

    if (Choix3 == 3)
      // Charger 'Labyrinthe3.txt'
      {f = fopen ("Labyrinthe3n.txt", "r") ;
      Charger_n (f, &n) ;
      fclose (f) ;
      f = fopen("Labyrinthe3.txt", "r") ;
      Charger_Labyrinthe (f, MUR2) ;
      fclose (f) ;
      }


    clear_screen () ;
    set_drawing_color (color_RED) ;
    set_font (font_HELVETICA_18) ;
    draw_string (100, 400, "Entrez le chiffre correspondant a votre choix :") ;
    set_drawing_color (color_BLACK) ;
    set_font (font_HELVETICA_12) ;
    draw_string (120, 360, "1 : Jouer en voyant les limites du labyrinthe") ;
    draw_string (120, 320, "2 : Jouer en decouvrant les limites du labyrinthe") ;
    update_graphics () ;
    Choix4 = get_key () - 48 ;

    if (Choix4 == 1)
      // Générer labyrinthe et jeu joueur (limite visible)
      {clear_screen () ;
      Case_Arrivee (n) ;
      Generer_Labyrinthe (n, MUR2) ;
      x=30 , y= (n*60)-30, x2 = 0, y2 = n - 1 ;
      Score = 0 ;
      Creer_Curseur (&x, &y) ;
      Mouvement_Jeu_Limites_Visibles (&x, &y, &x2, &y2, n, MUR2, &Score) ;
  		Effacer_Score () ;
  		set_font (font_HELVETICA_12) ;
      set_drawing_color (color_RED) ;
  		draw_printf (530, 210, "Bravo !") ;
  		set_drawing_color (color_BLACK) ;
 		  draw_printf (530, 170, "Score : %d", Score) ;
  		update_graphics () ;
      get_key () ;
      }

    if (Choix4 == 2)
      // Jeu du joueur avec limite invisible
      {clear_screen () ;
      Case_Arrivee (n) ;
      Grille_Limites (n) ;
      x=30 , y= (n*60)-30, x2 = 0, y2 = n - 1 ;
      Score = 0 ;
      Creer_Curseur (&x, &y) ;
      Mouvement_Jeu_Limites_Invisibles (&x, &y, &x2, &y2, n, MUR2, &Score) ;
  		Effacer_Score () ;
  		set_font (font_HELVETICA_12) ;
      set_drawing_color (color_RED) ;
  		draw_printf (530, 210, "Bravo !") ;
  		set_drawing_color (color_BLACK) ;
 		  draw_printf (530, 170, "Score : %d", Score) ;
  		update_graphics () ;
      get_key () ;
      }

    Boucle = 1 ;
    }

  if (Choix == 4)
    {

    // Choix emplacement de chargement
    clear_screen () ;
    set_drawing_color (color_RED) ;
    set_font (font_HELVETICA_18) ;
    draw_string (100, 400, "Entrez le chiffre correspondant a votre choix :") ;
    set_drawing_color (color_BLACK) ;
    set_font (font_HELVETICA_12) ;
    draw_string (120, 360, "1 : Chargement du labyrinthe dans 'Labyrinthe1.txt'") ;
    draw_string (120, 320, "2 : Chargement du labyrinthe dans 'Labyrinthe2.txt'") ;
    draw_string (120, 280, "3 : Chargement du labyrinthe dans 'Labyrinthe3.txt'") ;
    update_graphics () ;
    Choix8 = get_key () - 48 ;

    if (Choix8 == 1)
      // Charger 'Labyrinthe1.txt'
      {f = fopen ("Labyrinthe1n.txt", "r") ;
      Charger_n (f, &n) ;
      fclose (f) ;
      f = fopen("Labyrinthe1.txt", "r") ;
      Charger_Labyrinthe (f, MUR2) ;
      fclose (f) ;
      }

    if (Choix8 == 2)
      // Charger 'Labyrinthe2.txt'
      {f = fopen ("Labyrinthe2n.txt", "r") ;
      Charger_n (f, &n) ;
      fclose (f) ;
      f = fopen("Labyrinthe2.txt", "r") ;
      Charger_Labyrinthe (f, MUR2) ;
      fclose (f) ;
      }

    if (Choix8 == 3)
      // Charger 'Labyrinthe3.txt'
      {f = fopen ("Labyrinthe3n.txt", "r") ;
      Charger_n (f, &n) ;
      fclose (f) ;
      f = fopen("Labyrinthe3.txt", "r") ;
      Charger_Labyrinthe (f, MUR2) ;
      fclose (f) ;
      }

      clear_screen();
      Case_Arrivee (n) ;
      Score = 0 ;
      Generer_Labyrinthe(n, MUR2);
      Resolution_Automatique(n, MUR2, &Score);
  		Effacer_Score () ;
  		set_font (font_HELVETICA_12) ;
      set_drawing_color (color_RED) ;
  		draw_printf (530, 210, "Bravo !") ;
  		set_drawing_color (color_BLACK) ;
 		  draw_printf (530, 170, "Score : %d", Score) ;
      update_graphics () ;
      get_key () ;

      Boucle = 1 ;
    }

  if (Choix == 5)
    {Boucle = 0 ;
    }

}
while (Boucle == 1) ;

stop_graphics () ;
return 0 ;
}
