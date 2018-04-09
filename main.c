#include <stdio.h>
#include "libgraphique.h"
#include "Fonctions.c"

int main (void)
{
int n ;
n = Taille () ;
int x=30 , y= (n*60)-30 ;
start_graphics() ;

Grille (n) ;
Creer_Curseur (&x, &y) ;
//Mouvement (&x, &y, n) ;
Deplacement(&x, &y);
get_key () ;

stop_graphics () ;
return 0 ;
}
