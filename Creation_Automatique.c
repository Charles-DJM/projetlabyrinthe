#define MAX 100




int posx = 0, posy = 0;
int cursx = 30, cursy = 30;
int nbmouv = 0;

void Effacer_Curseur(int x, int y)
{
  set_drawing_color(color_WHITE);
	draw_circle_full(x, y, 15);
	update_graphics () ;
	return ;
}

int Verifier_Cases_Autour(int CASE[MAX][MAX], int n)
//Verifie si les cases autour de la case actuelle sont reliées au labyrinthe
//Renvoie 1 si toutes les cases autour sont reliées, 0 sinon
{
  if(CASE[posx][posy+1] == 1 && CASE[posx][posy-1] == 1 && CASE[posx+1][posy] == 1 && CASE[posx-1][posy] == 1)
    {return 1 ;
    }
  if (posx == 0 && CASE[posx][posy+1] == 1 && CASE[posx][posy-1] == 1 && CASE[posx+1][posy] == 1)
    {return 1 ;
    }
  if (posy == 0 && CASE[posx][posy+1] == 1 && CASE[posx+1][posy] == 1 && CASE[posx-1][posy] == 1)
    {return 1 ;
    }
  if (posx == n-1 && CASE[posx][posy+1] == 1 && CASE[posx][posy-1] == 1 && CASE[posx-1][posy] == 1)
    {return 1 ;
    }
  if (posy == n-1 && CASE[posx][posy-1] == 1 && CASE[posx+1][posy] == 1 && CASE[posx-1][posy] == 1)
    {return 1 ;
    }
  if (posx == 0 && posy == 0 && CASE[posx][posy+1] == 1 && CASE[posx+1][posy] == 1)
    {return 1 ;
    }
  if (posx == 0 && posy == n-1 && CASE[posx][posy-1] == 1 && CASE[posx+1][posy] == 1)
    {return 1 ;
    }
  if (posx == n-1 && posy == 0 && CASE[posx][posy+1] == 1 && CASE[posx-1][posy] == 1)
    {return 1 ;
    }
  if (posx == n-1 && posy == n-1 && CASE[posx][posy-1] == 1 && CASE[posx-1][posy] == 1)
    {return 1 ;
    }
  return 0;
}

int Verifier_Labyrinthe(int CASE[MAX][MAX], int n)
//Renvoie 1 si toutes les cases du labyrinthe sont reliées, 0 sinon
{
  int i, j ;

  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      if(CASE[i][j]==0)
        {return 0;}
    }
  }
  return 1;
}

void Demitour(int CHEMIN[MAX])
//Permet a la fonction CreationLabyrinthe de revenir en dans la case précédente
{
  Effacer_Curseur(cursx, cursy);
  if(CHEMIN[nbmouv] == 1)
    {
      posy = posy +1;
      cursy = cursy +60;
    }
  if(CHEMIN[nbmouv] == 2)
    {
      posx = posx +1;
      cursx = cursx +60;
    }
  if(CHEMIN[nbmouv] == 3)
    {
      posx = posx -1;
      cursx = cursx-60;
    }
  if(CHEMIN[nbmouv] == 4)
    {
      posy = posy -1;
      cursy = cursy -60;
    }
  Creer_Curseur(&cursx, &cursy);
  update_graphics () ;
  nbmouv = nbmouv -1;
}

void Creation(int CHEMIN[MAX], int MUR_auto[MAX][MAX], int CASE[MAX][MAX], int n)
//Crée le labyrinthe en reliant une case de la grille non reliée à la case actuelle
{
  if(Verifier_Cases_Autour(CASE, n)==1)
   {
     Demitour(CHEMIN);
     return ;
   }

   int c;
   c = rand()%4 +1;
   //printf("direction est %d\n", c);
   if(c==1)
    {
      if(posy-1>=0)
      {
        if(CASE[posx][posy-1] == 0)
        {
          posy = posy -1;
          CASE[posx][posy] = 1;
          MUR_auto[posx][posy * 2] = 0;
          nbmouv = nbmouv +1 ;
          CHEMIN[nbmouv] = c;

          Supprimer_Murs(2, cursx, cursy, posx, posy, MUR_auto);
          Effacer_Curseur(cursx, cursy);
          cursy = cursy -60;
          Creer_Curseur(&cursx, &cursy);
          update_graphics();
       }
      }
    }

    if(c==2)
     {
       if(posx-1>=0)
       {
         if(CASE[posx-1][posy] == 0)
         {
           posx = posx -1;
           CASE[posx][posy] = 1;
           MUR_auto[posx][posy*2 +1] = 0;
           nbmouv = nbmouv +1 ;
           CHEMIN[nbmouv] = c;

           Supprimer_Murs(4, cursx, cursy, posx, posy, MUR_auto);
           Effacer_Curseur(cursx, cursy);
           cursx = cursx -60;
           Creer_Curseur(&cursx, &cursy);
         }
       }
     }

     if(c==3)
      {
        if(posx+1<n)
        {
          if(CASE[posx+1][posy] == 0)
          {
            posx = posx +1;
            CASE[posx][posy] = 1;
            MUR_auto[posx+1][2*posy +1] = 0;
            nbmouv = nbmouv +1 ;
            CHEMIN[nbmouv] = c;

            Supprimer_Murs(6, cursx, cursy, posx, posy, MUR_auto);
            Effacer_Curseur(cursx, cursy);
            cursx = cursx +60;
            Creer_Curseur(&cursx, &cursy);
          }
        }
      }

      if(c==4)
       {
         if(posy+1<n)
         {
          if(CASE[posx][posy+1] == 0)
           {
             posy = posy +1;
             CASE[posx][posy] = 1;
             MUR_auto[posx][2*posy+2] = 0;
             nbmouv = nbmouv +1 ;
             CHEMIN[nbmouv] = c;

             Supprimer_Murs(8, cursx, cursy, posx, posy, MUR_auto);
             Effacer_Curseur(cursx, cursy);
             cursy = cursy +60;
             Creer_Curseur(&cursx, &cursy);
                        }
         }
       }
}

void Creation_Laby_Auto()
{
  printf("De quelle taille doit être le labyrinthe?\n");
  int n , i, j;
  scanf("%d", &n);
  int MUR_auto[MAX][MAX]; //tableau mur habituel
  int CASE[MAX][MAX]; //Sert a savoir si une case du laby est réliée
  int CHEMIN[MAX]; //Permet de connaitre les mouvements précédents

  for(i=0; i<=n; i++){
    for(j=0; j<=n; j++){
      CASE[i][j]=0;
    }
  }

  for(i=0; i<MAX; i++){
    for(j=0; j<MAX; j++){
      MUR_auto[i][j]=1;
    }
  }
  CASE[0][0] = 1;
  clear_screen();
  Grille(n);

  Creer_Curseur(&cursx, &cursy);

  while(Verifier_Labyrinthe(CASE, n) == 0)
  {
    Creation(CHEMIN, MUR_auto, CASE, n);
    update_graphics();
    get_key();
  }

  printf("fin creation auto");
  nbmouv = 0;
  posx = 0;
  posy = 0;
  cursx = 30;
  cursy = 30;
  get_key();
}
