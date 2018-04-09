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

void Creer_Curseur(int *x, int *y)
/* Crée le curseur en haut a gauche du labyrinthe*/
{
	set_drawing_color(color_BLACK);
	draw_circle_full(*x, *y, 15);
	update_graphics () ;
}

void Supprimer_Murs(int dir, int x, int y, int x2, int y2, int MUR[500][500] ){
/*Supprime un mur dans le tableau mur et graphiquement*/
	set_drawing_color(color_WHITE);
	switch(dir){
		case 2 :
			MUR[x2][2 * y2] = 0 ;
			draw_line(x - 30, y - 30, x + 30, y - 30) ;
			break;
		case 4 :
			MUR[x2][(2*y2)+1] = 0 ;
			draw_line(x - 30, y - 30, x - 30, y + 30) ;
			break;
		case 6 :
			MUR[x2+1][(2*y2)+1] = 0 ;
			draw_line(x + 30, y - 30, x + 30, y + 30) ;
			break;
		case 8 :
			MUR[x2][(2*y2)+2] = 0 ;
			draw_line(x - 30, y + 30, x + 30, y + 30) ;
			break ;
	}
}

void Deplacement_Creation (int *x, int *y, int *x2, int *y2, int n, int MUR[500][500])
/* Déplacement du curseur en fonction de la variable direction. */
/* si direction = 1  curseur déplacé vers le bas
 * si direction = 2 curseur déplacé vers la gauche
 *  direction = 3 curserur déplacé vers la droite
 *  direction = 4 curseur déplacé vers le haut */
{
	switch(get_key()){
		case '2' :
			if (*y > 30)
				{set_drawing_color(color_WHITE);
				draw_circle_full(*x, *y, 15); //efface  le curseur à sa position précédente
				set_drawing_color(color_BLACK);
				*y = *y-60;
				*y2 -- ;
				draw_circle_full(*x, *y, 15);
				Supprimer_Murs (2, *x, *y, *x2, *y2, MUR) ;
				}
			break;
		case '4' :
			if (*x > 30)
				{set_drawing_color(color_WHITE);
				draw_circle_full(*x, *y, 15); //efface  le curseur à sa position précédente
				set_drawing_color(color_BLACK);
				*x = *x-60;
				*x2 -- ;
				draw_circle_full(*x, *y, 15);
				Supprimer_Murs (4, *x, *y, *x2, *y2, MUR) ;
				}
			break;
		case '6' :
			if (*x < (60 * n) - 30)
				{set_drawing_color(color_WHITE);
				draw_circle_full(*x, *y, 15); //efface  le curseur à sa position précédente
				set_drawing_color(color_BLACK);
				*x = *x +60;
				*x2 ++ ;
				draw_circle_full(*x, *y, 15);
				Supprimer_Murs (6, *x, *y, *x2, *y2, MUR) ;
				}
			break;
		case '8' :
			if (*y < (60 * n) - 30)
				{set_drawing_color(color_WHITE);
				draw_circle_full(*x, *y, 15); //efface  le curseur à sa position précédente
				set_drawing_color(color_BLACK);
				*y= *y+60;
				*y2 ++ ;
				draw_circle_full(*x, *y, 15);
				Supprimer_Murs (8, *x, *y, *x2, *y2, MUR) ;
				}
			break;
	}
	update_graphics () ;
	return;
}

void Mouvement_Creation (int *x, int *y, int *x2, int *y2, int n, int MUR[500][500])
/**/
{do
	{
		Deplacement_Creation(x, y, x2, y2, n, MUR) ;
	}
while ((*x != (60 * n) - 30) || (*y != 30)) ;
return ;
}
