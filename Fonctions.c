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
for (i = 0 ; i < (n + 1) * 20 ; i = i + 20)
	{for (j = 0 ; j < (n + 1) * 20 ; j = j + 20)
		{draw_line (i, j, i + 20, j + 20) ;
		}
	}
update_graphics () ;
return ;
}

void Creer_Curseur(int n)
/* Crée le curseur en haut a gauche du labyrinthe*/
{
	set_drawing_color(black);
	draw_circle( 10, (n*20-10), 5);
}

void Deplacement (int direction, int *x, int *y)
/* Déplacement du curseur en fonction de la variable direction. */
/* si direction = 1  curseur déplacé vers le bas
 * si direction = 2 curseur déplacé vers la gauche
 *  direction = 3 curserur déplacé vers la droite
 *  direction = 4 curseur déplacé vers le haut */
{
	set_drawing_color(white);
	draw_circle(*x, *y, 5); //efface  le curseur à sa position précédente

	set_drawing_color(black);
	switch(direction){
		case 1 :
			*y = *y-20;
			draw_circle(*x, *y, 5);
			break;
		case 2 :
			*x = *x-20;
			draw_circle(*x, *y, 5);
			break;
		case 3 :
			*x = *x +20;
			draw_circle(*x, *y, 5);
			break;
		case 4 :
			*y= *y+20;
			draw_circle(*x, *y, 5);
			break;
	}
	update_graphics () ;
	return;
}
