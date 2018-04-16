#include <stdio.h>
#include <stdlib.h>

#include "libgraphique.h"
#include "Fonctions.c"
#include "Creation_interactive.c"
#include "Enregistrements.c"
#include "Jeu_Interactif.c"
#include "Jeu_Automatique.c"
#include "Creation_Automatique.c"

#define MAX 100

int main (void)
{int i, j, Score ;
FILE *f ;

start_graphics() ;

// Menu graphique
set_drawing_color (color_BLACK) ;
set_font (font_HELVETICA_18) ;
draw_string (240, 290, "The Maze Runner") ;
draw_string (160, 250, "CLERC Billy") ;
draw_string (320, 250, "DE JAHAM Charles") ;
set_font (font_HELVETICA_12) ;
draw_string (200, 210, "Pour commencer, appuyez sur une touche") ;
update_graphics () ;
get_key () ;
clear_screen () ;
update_graphics () ;

// Taille du labyrinthe
int n ;
n = Taille () ;
//n = get_key () ;

// Initialisation MUR
int MUR [MAX][MAX] ;
int MUR2 [MAX][MAX] ;
for (i = 0 ; i < MAX ; i++)
  {for (j = 0 ; j < MAX ; j++)
    {MUR[i][j] = 1 ;
    }
  }

int x=30 , y= (n*60)-30, x2 = 0, y2 = n - 1 ;

// Créer labyrinthe Interactivement
Grille (n) ;
Creer_Curseur (&x, &y) ;
Mouvement_Creation (&x, &y, &x2, &y2, n, MUR) ;

// Enregister Labyrinthe
f = fopen ("Labyrinthe.txt", "w") ;
Enregistrement (f, MUR) ;
fclose (f) ;

// Effacer labyrinthe écran
get_key () ;
Effacer_Labyrinthe (n) ;

// Charger labyrinthe
f = fopen("Labyrinthe.txt", "r") ;
Charger_Labyrinthe (f, MUR2) ;
fclose (f) ;

// Générer labyrinthe et jeu joueur (limite visible)
get_key () ;
Generer_Labyrinthe (n, MUR2) ;
x=30 , y= (n*60)-30, x2 = 0, y2 = n - 1 ;
Score = 0 ;
Creer_Curseur (&x, &y) ;
Mouvement_Jeu_Limites_Visibles (&x, &y, &x2, &y2, n, MUR2, &Score) ;
printf("%d\n", Score) ;

// Générer labyrinthe et jeu joueur (limite invisible)
get_key () ;
Effacer_Labyrinthe (n) ;
Grille_Limites (n) ;
x=30 , y= (n*60)-30, x2 = 0, y2 = n - 1 ;
Score = 0 ;
Creer_Curseur (&x, &y) ;
Mouvement_Jeu_Limites_Invisibles (&x, &y, &x2, &y2, n, MUR2, &Score) ;
printf("%d\n", Score) ;

get_key () ;

stop_graphics () ;
return 0 ;
}
