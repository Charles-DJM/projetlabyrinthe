#define MAX 100

int Taille ()
/* Demande paramètre n. */
{int n ;
printf("Afin de créer un labyrinthe carré, il faut un nombre entier qui correspondra aux nombres de cases. Veuillez saisir ce dernier : ") ;
scanf("%d", &n) ;
return n ;
}

void Grille (int n)
/* Création d'une grille de taile n * n. */
{set_drawing_color(color_BLACK);
int i, j ;
i = 0 ;
for (j = 0 ; j < (n + 1) * 60 ; j = j + 60)
	{draw_line (i, j, (n * 60), j) ;
	}
j = 0 ;
for (i = 0 ; i < (n + 1) * 60 ; i = i + 60)
	{draw_line (i, j, i, (n * 60)) ;
	}
update_graphics () ;
return ;
}

void Grille_Limites (int n)
/* Création d'une grille de taile n * n. */
{set_drawing_color(color_BLACK);
draw_line (0, 0, (n * 60), 0) ;
draw_line (0, 0, 0, (n * 60)) ;
draw_line ((n * 60), 0, (n * 60), (n * 60)) ;
draw_line (0, (n * 60), (n * 60), (n * 60)) ;
update_graphics () ;
return ;
}

void Creer_Curseur (int *x, int *y)
/* Crée le curseur en haut a gauche du labyrinthe*/
{
	set_drawing_color(color_BLACK);
	draw_circle_full(*x, *y, 15);
	update_graphics () ;
	return ;
}

void Effacer_Score ()
/* Efface le labyrinthe affiché à l'écran */
{set_drawing_color(color_WHITE);
draw_rectangle_full (530, 100, 700, 500) ;
update_graphics () ;
return ;
}

void Case_Arrivee (int n)
{set_drawing_color(color_GREEN) ;
draw_rectangle_full (((n - 1) * 60) + 1, 1, (n * 60) - 1, 59) ;
update_graphics () ;
return ;
}
