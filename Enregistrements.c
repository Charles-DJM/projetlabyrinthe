#define MAX 100

void Enregistrement (FILE *f, int MUR[MAX][MAX])
/* Enregistre le tableau MUR dans un fichier texte */
{int i, j ;
for (i = 0 ; i < MAX ; i++)
	{for (j = 0 ; j < MAX ; j++)
		{fprintf(f, "%d", MUR[i][j]) ;
		}
	fprintf(f, "\n") ;
	}
return ;
}

void Enregistrement_n (FILE *f, int n)
/* Enregistre le n correspondant au labyrinthe */
{fprintf(f, "%d", n) ;
return ;
}

void Charger_Labyrinthe (FILE *f, int MUR2[MAX][MAX])
/* Reconstitue le tableau MUR2 à partir du fichier texte */
{int i, j ;
for (i = 0 ; i < MAX ; i++)
	{for (j = 0 ; j < MAX ; j++)
		{if (getc(f) == '0')
      {MUR2[i][j] = 0 ;
      }
    else
      {MUR2[i][j] = 1 ;
      }
		}
    getc(f) ;
	}
return ;
}

void Charger_n (FILE *f, int *n)
/* Reconstitue le n associé au labyrinthe */
{*n = getc(f) - 48 ;
return ;
}

void Generer_Labyrinthe (int n, int MUR2[MAX][MAX])
/* Génère le labyrinthe à partir de MUR2 */
{int x2, y2, x = 30, y = 30 ;
set_drawing_color(color_BLACK) ;
for (x2 = 0 ; x2 < n ; x2++)
  {for (y2 = 0 ; y2 < n ; y2++)
    {if (MUR2[x2][2 * y2] == 1)
      {draw_line(x - 30, y - 30, x + 30, y - 30) ;
      }
    if (MUR2[x2][(2*y2)+1] == 1)
      {draw_line(x - 30, y - 30, x - 30, y + 30) ;
      }
    if (MUR2[x2+1][(2*y2)+1] == 1)
      {draw_line(x + 30, y - 30, x + 30, y + 30) ;
      }
    if (MUR2[x2][(2*y2)+2] == 1)
      {draw_line(x - 30, y + 30, x + 30, y + 30) ;
      }
    y = y + 60 ;
    }
  y = 30 ;
  x = x + 60 ;
  }
update_graphics () ;
return ;
}
