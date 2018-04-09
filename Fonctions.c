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

void Creer_Curseur (int *x, int *y)
/* Crée le curseur en haut a gauche du labyrinthe*/
{
	set_drawing_color(color_BLACK);
	draw_circle_full(*x, *y, 15);
	update_graphics () ;
}

void Enregistrement (FILE *f, int MUR[100][100])
{int i, j ;
for (i = 0 ; i < 100 ; i++)
	{for (j = 0 ; j < 100 ; j++)
		{putc(MUR[i][j], f) ;
		}
	putc('\n', f) ;
	}
return ;
}
