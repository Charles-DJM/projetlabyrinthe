#include <stdio.h>
#include "libgraphique.h"
#include "Fonctions.c"
#include "Creation_interactive.c"



int main (void)
{FILE *f ;
int n ; //Taille du labyrinthe

n = Taille () ;
int MUR [100][100] = {1}{1} ; // Défini l'état des murs
int x=30 , y= (n*60)-30, x2 = 0, y2 = n ;
start_graphics() ;

Grille (n) ;
Creer_Curseur (&x, &y) ;
Mouvement_Creation (&x, &y, &x2, &y2, n, MUR) ;

f = fopen ("Labyrinthe.txt", "w") ;
Enregistrement (f, MUR) ;

get_key () ;

stop_graphics () ;
fclose (f) ;
return 0 ;
}
