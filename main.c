#include <stdio.h>
#include "libgraphique.h"
#include "Fonctions.c"

int main (void)
{int *x, *y ;
int n ;
n = Taille () ;
start_graphics() ;
Grille (n) ;
Creer_Curseur (n) ;
get_key () ;
stop_graphics () ;
return 0 ;
}
