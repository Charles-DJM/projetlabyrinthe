#define MAX 100
/*il faut faire selon les murs autours:
3 murs == impassse, donc on fait demitour et on scelle la case en, mettant un mur derriere nous
2 murs on prends une direction au pif mais faut pas que ça soit en arrière
1 mur parreil
demitour = on prends le chemin inverse et on mets un mur pour bloquer l'accès a la case*/

int pos2x, pos2y ,curs2x ,curs2y ,nbmouv2 ;

void Effacer_Curseur2(int x, int y)
{
  set_drawing_color(color_WHITE);
	draw_circle_full(x, y, 15);
	update_graphics () ;
	return ;
}

int Compter_Murs(int n, int MUR_Reso[MAX][MAX])
//Renvoie le nombre de murs autour du curseur
{
  return MUR_Reso[pos2x][pos2y*2] + MUR_Reso[pos2x][2*pos2y +1] + MUR_Reso[pos2x +1][2*pos2y +1] + MUR_Reso[pos2x][2*pos2y+2] ;

}

void Demi_Tour(int n, int MUR_Reso[MAX][MAX], int CHEMIN[MAX])
//Permet a la fonction CreationLabyrinthe de revenir en dans la case précédente
{
  Effacer_Curseur(curs2x, curs2y);
  if(CHEMIN[nbmouv2] == 1)
    {
      pos2y = pos2y +1;
      curs2y = curs2y +60;
      MUR_Reso[pos2x][2*pos2y] = 1;
    }
  if(CHEMIN[nbmouv2] == 2)
    {
      pos2x = pos2x +1;
      curs2x = curs2x +60;
      MUR_Reso[pos2x][2*pos2y +1] = 1;
    }
  if(CHEMIN[nbmouv2] == 3)
    {
      pos2x = pos2x -1;
      curs2x = curs2x-60;
      MUR_Reso[pos2x +1][2*pos2y+1] = 1;
    }
  if(CHEMIN[nbmouv2] == 4)
    {
      pos2y = pos2y -1;
      curs2y = curs2y -60;
      MUR_Reso[pos2x][2*pos2y+2] = 1;
    }
  Creer_Curseur(&curs2x, &curs2y);
  update_graphics () ;
  nbmouv2 = nbmouv2 -1;
}

void Resolution_Automatique(int n, int MUR_Reso[MAX][MAX])
//Fonction Principale
{
  pos2x = 0; pos2y = n-1; curs2x = 30; curs2y = (n * 60) - 30 ; nbmouv2 = 0;
  int CHEMIN[MAX];
  int direction;
  Creer_Curseur(&curs2x, &curs2y);
  update_graphics();

  do{

    if ( (Compter_Murs(n, MUR_Reso) !=3) || ((Compter_Murs (n, MUR_Reso) == 3) && (pos2x == 0 && pos2y == n - 1)) )
    {
      direction = rand()%4+1;
      switch (direction) {
        case 1:
          if (CHEMIN[nbmouv2] != 4 && MUR_Reso[pos2x][2*pos2y] == 0)
          {
            nbmouv2++;
            CHEMIN[nbmouv2] = direction;
            Effacer_Curseur(curs2x, curs2y);
            pos2y = pos2y -1;
            curs2y = curs2y -60;
            Creer_Curseur(&curs2x, &curs2y);
            break;
          }
          break;
        case 2:
          if (CHEMIN[nbmouv2] != 3 && MUR_Reso[pos2x][2*pos2y+1] == 0)
          {
            nbmouv2++;
            CHEMIN[nbmouv2] = direction;
            Effacer_Curseur(curs2x, curs2y);
            pos2x = pos2x -1;
            curs2x = curs2x -60;
            Creer_Curseur(&curs2x, &curs2y);
            break;
          }
          break;
        case 3:
          if (CHEMIN[nbmouv2] !=2 && MUR_Reso[pos2x+1][2*pos2y+1] == 0)
          {
            nbmouv2++;
            CHEMIN[nbmouv2] = direction;
            Effacer_Curseur(curs2x, curs2y);
            pos2x = pos2x +1;
            curs2x = curs2x +60;
            Creer_Curseur(&curs2x, &curs2y);
            break;
          }
          break;
        case 4:
          if (CHEMIN[nbmouv2] !=1 && MUR_Reso[pos2x][2*pos2y+2] == 0)
          {
            nbmouv2++;
            CHEMIN[nbmouv2] = direction;
            Effacer_Curseur2(curs2x, curs2y);
            pos2y = pos2y +1;
            curs2y = curs2y +60;
            Creer_Curseur(&curs2x, &curs2y);
            break;
          }
          break;
        }
        update_graphics () ;
    }

    else
      {Demi_Tour(n, MUR_Reso, CHEMIN) ;
      }

    usleep(50000);

  } while((pos2x != (n - 1)) || (pos2y != 0));

  get_key() ;
}
