#include <stdio.h>
#include "libgraphique.h"
#include "Fonctions.c"



int main (void)
{
int n ; //Taille du labyrinthe

n = Taille () ;
int MUR [800][800] = {0} ; // Défini l'état des murs
int x=30 , y= (n*60)-30 ;
start_graphics() ;

Grille (n) ;
Creer_Curseur (&x, &y) ;
Mouvement (&x, &y, n) ;

get_key () ;

stop_graphics () ;
return 0 ;
}
