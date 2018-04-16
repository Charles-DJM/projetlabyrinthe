#define MAX 100

void Deplacement_Jeu_Limites_Visibles (int *x, int *y, int *x2, int *y2, int n, int MUR[MAX][MAX])
/* Déplacement du curseur en fonction de la variable direction. */
/* si direction = 1  curseur déplacé vers le bas
 * si direction = 2 curseur déplacé vers la gauche
 *  direction = 3 curserur déplacé vers la droite
 *  direction = 4 curseur déplacé vers le haut */
{
	switch(get_key()){
		case '2' :
			if ((*y > 30) && (MUR[*x2][2 * *y2] == 0))
				{set_drawing_color(color_WHITE);
				draw_circle_full(*x, *y, 15); //efface  le curseur à sa position précédente
				set_drawing_color(color_BLACK);
				*y = *y-60;
				*y2 = *y2 - 1 ;
				draw_circle_full(*x, *y, 15);
				}
			break;
		case '4' :
			if ((*x > 30) && (MUR[*x2][(2 * *y2)+1] == 0))
				{set_drawing_color(color_WHITE);
				draw_circle_full(*x, *y, 15); //efface  le curseur à sa position précédente
				set_drawing_color(color_BLACK);
				*x = *x-60;
				*x2 = *x2 - 1 ;
				draw_circle_full(*x, *y, 15);
				}
			break;
		case '6' :
			if ((*x < (60 * n) - 30) && (MUR[*x2+1][(2 * *y2)+1] == 0))
				{set_drawing_color(color_WHITE);
				draw_circle_full(*x, *y, 15); //efface  le curseur à sa position précédente
				set_drawing_color(color_BLACK);
				*x = *x +60;
				*x2 = *x2 + 1 ;
				draw_circle_full(*x, *y, 15);
				}
			break;
		case '8' :
			if ((*y < (60 * n) - 30) && (MUR[*x2][(2 * *y2)+2] == 0))
				{set_drawing_color(color_WHITE);
				draw_circle_full(*x, *y, 15); //efface  le curseur à sa position précédente
				set_drawing_color(color_BLACK);
				*y= *y+60;
				*y2 = *y2 + 1 ;
				draw_circle_full(*x, *y, 15) ;
				}
			break;
	}
	update_graphics () ;
	return;
}

void Deplacement_Jeu_Limites_Invisibles (int *x, int *y, int *x2, int *y2, int n, int MUR[MAX][MAX])
/* Déplacement du curseur en fonction de la variable direction. */
/* si direction = 1  curseur déplacé vers le bas
 * si direction = 2 curseur déplacé vers la gauche
 *  direction = 3 curserur déplacé vers la droite
 *  direction = 4 curseur déplacé vers le haut */
{
	switch(get_key()){
		case '2' :
			if ((*y > 30) && (MUR[*x2][2 * *y2] == 0))
				{set_drawing_color(color_WHITE);
				draw_circle_full(*x, *y, 15); //efface  le curseur à sa position précédente
				set_drawing_color(color_BLACK);
				*y = *y-60;
				*y2 = *y2 - 1 ;
				draw_circle_full(*x, *y, 15);
				}
      else
        {set_drawing_color(color_BLACK);
        draw_line(*x - 30, *y - 30, *x + 30, *y - 30) ;
        }
			break;
		case '4' :
			if ((*x > 30) && (MUR[*x2][(2 * *y2)+1] == 0))
				{set_drawing_color(color_WHITE);
				draw_circle_full(*x, *y, 15); //efface  le curseur à sa position précédente
				set_drawing_color(color_BLACK);
				*x = *x-60;
				*x2 = *x2 - 1 ;
				draw_circle_full(*x, *y, 15);
				}
      else
        {set_drawing_color(color_BLACK);
        draw_line(*x - 30, *y - 30, *x - 30, *y + 30) ;
        }
			break;
		case '6' :
			if ((*x < (60 * n) - 30) && (MUR[*x2+1][(2 * *y2)+1] == 0))
				{set_drawing_color(color_WHITE);
				draw_circle_full(*x, *y, 15); //efface  le curseur à sa position précédente
				set_drawing_color(color_BLACK);
				*x = *x +60;
				*x2 = *x2 + 1 ;
				draw_circle_full(*x, *y, 15);
				}
      else
        {set_drawing_color(color_BLACK);
        draw_line(*x + 30, *y - 30, *x + 30, *y + 30) ;
        }
			break;
		case '8' :
			if ((*y < (60 * n) - 30) && (MUR[*x2][(2 * *y2)+2] == 0))
				{set_drawing_color(color_WHITE);
				draw_circle_full(*x, *y, 15); //efface  le curseur à sa position précédente
				set_drawing_color(color_BLACK);
				*y= *y+60;
				*y2 = *y2 + 1 ;
				draw_circle_full(*x, *y, 15) ;
				}
      else
        {set_drawing_color(color_BLACK);
        draw_line(*x - 30, *y + 30, *x + 30, *y + 30) ;
        }
			break;
	}
	update_graphics () ;
	return;
}

void Mouvement_Jeu_Limites_Visibles (int *x, int *y, int *x2, int *y2, int n, int MUR[MAX][MAX], int *Score)
/*Lance le mouvement pour la creation Creation_interactive, s arrete une fois a la sortie du labyrinthe*/
{do
	{
		Deplacement_Jeu_Limites_Visibles (x, y, x2, y2, n, MUR) ;
    *Score = *Score + 1 ;
	}
while ((*x != (60 * n) - 30) || (*y != 30)) ;
return ;
}

void Mouvement_Jeu_Limites_Invisibles (int *x, int *y, int *x2, int *y2, int n, int MUR[MAX][MAX], int *Score)
/*Lance le mouvement pour la creation Creation_interactive, s arrete une fois a la sortie du labyrinthe*/
{do
	{
		Deplacement_Jeu_Limites_Invisibles (x, y, x2, y2, n, MUR) ;
    *Score = *Score + 1 ;
	}
while ((*x != (60 * n) - 30) || (*y != 30)) ;
return ;
}
