#include <stdio.h>
#include "libgraphique.h"
#include "Fonctions.c"

int main (void)
{int *x, *y ;
int n ;
n = Taille () ;
Grille (n) ;
Creer_Curseur (n) ;
get_key () ;
return 0 ;
}
