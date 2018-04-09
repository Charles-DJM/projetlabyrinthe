int Taille ()
/* Demande paramètre n. */
{int n ;
printf("Afin de créer un labyrinthe carré, il faut un nombre entier qui correspondra aux nombres de cases. Veuillez saisir ce dernier : ") ;
scanf("%d", &n) ;
return n ;
}

void Grille (int n)
/* Création d'une grille de taile n * n. */
{int i, j ;
i = 0 ;
for (j = 0 ; j <= (n + 1) * 60 ; j = j + 60)
	{draw_line (i, j, (n * 60), j) ;
	}
j = 0 ;
for (i = 0 ; i < (n + 1) * 60 ; i = i + 60)
	{draw_line (i, j, i, ((n + 1) * 60)) ;
	}
update_graphics () ;
return ;
}

void Creer_Curseur(int n)
/* Crée le curseur en haut a gauche du labyrinthe*/
{
	set_drawing_color(color_BLACK);
	draw_circle_full( 30, (n*60 - 30), 15);
	update_graphics () ;
}

void Deplacement (int direction, int *x, int *y)
/* Déplacement du curseur en fonction de la variable direction. */
/* si direction = 1  curseur déplacé vers le bas
 * si direction = 2 curseur déplacé vers la gauche
 *  direction = 3 curserur déplacé vers la droite
 *  direction = 4 curseur déplacé vers le haut */
{
	set_drawing_color(color_WHITE);
	draw_circle_full(*x, *y, 15); //efface  le curseur à sa position précédente

	set_drawing_color(color_BLACK);
	switch(direction){
		case 1 :
			*y = *y-60;
			draw_circle_full(*x, *y, 15);
			break;
		case 2 :
			*x = *x-60;
			draw_circle_full(*x, *y, 15);
			break;
		case 3 :
			*x = *x +60;
			draw_circle_full(*x, *y, 15);
			break;
		case 4 :
			*y= *y+60;
			draw_circle_full(*x, *y, 15);
			break;
	}
	update_graphics () ;
	return;
}
