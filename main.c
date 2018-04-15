#include <stdio.h>
#include "libgraphique.h"
#include "Fonctions.c"
#include "Creation_interactive.c"
#include "Enregistrements.c"

#define MAX 100



int main (void)
{int i, j, a ;
FILE *f ;
int n ; //Taille du labyrinthe

n = Taille () ;
int MUR [MAX][MAX] ;
int MUR2 [MAX][MAX] ;
for (i = 0 ; i < MAX ; i++)
  {for (j = 0 ; j < MAX ; j++)
    {MUR[i][j] = 1 ;
    }
  } // Défini l'état des murs initiallement

int x=30 , y= (n*60)-30, x2 = 0, y2 = n - 1 ;
start_graphics() ;

Grille (n) ;
Creer_Curseur (&x, &y) ;
Mouvement_Creation (&x, &y, &x2, &y2, n, MUR) ;

f = fopen ("Labyrinthe.txt", "w") ;
Enregistrement (f, MUR) ;
fclose (f) ;

get_key () ;
Effacer_Labyrinthe (n) ;

f = fopen("Labyrinthe.txt", "r") ;
Charger_Labyrinthe (f, MUR2) ;
fclose (f) ;

get_key () ;
Generer_Labyrinthe (n, MUR2) ;

get_key () ;

stop_graphics () ;
return 0 ;
}
