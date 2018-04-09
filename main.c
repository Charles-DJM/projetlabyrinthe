#include <stdio.h>
#include "libgraphique.h"
#include "Fonctions.c"

int MUR [n + 1][2n + 1] = {0} ; // Défini l'état des murs
int n ; //Taille du labyrinthe
int main (void)
{

n = Taille () ;

int x=30 , y= (n*60)-30 ;
start_graphics() ;

Grille () ;
Creer_Curseur (&x, &y) ;
Mouvement (&x, &y) ;

get_key () ;

stop_graphics () ;
return 0 ;
}
