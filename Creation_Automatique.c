#define MAX 100




int posx = 0, posy = 0;
int cursx = 30, cursy = 30;



int Verifier_Cases_Autour(int CASE[MAX][MAX])
//Verifie si les cases autour de la case actuelle sont reliées au labyrinthe
//Renvoie 1 si toutes les cases autour sont reliées, 0 sinon
{
  if(CASE[posx][posy+1] == 1 && CASE[posx][posy-1] == 1 && CASE[posx+1][posy] == 1 && CASE[posx-1][posy] == 1)
    {return 1;}
  return 0;
}

int Verifier_Labyrinthe(int CASE[MAX][MAX], int n)
//Renvoie 1 si toutes les cases du labyrinthe sont reliées, 0 sinon
{
  int i=0 , j=0;

  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      if(CASE[i][j]==1)
        {return 1;}
    }
  }
  return 0;
}

void Demitour(int CHEMIN[MAX], int nbmouv)
//Permet a la fonction CreationLabyrinthe de revenir en dans la case précédente
{
  if(CHEMIN[nbmouv-1] == 1)
    {posy = posy +1;}
  if(CHEMIN[nbmouv-1] == 2)
    {posx = posx +1;}
  if(CHEMIN[nbmouv-1] == 3)
    {posx = posx -1;}
  if(CHEMIN[nbmouv-1] == 4)
    {posy = posy -1;}

  nbmouv = nbmouv -1;
}

void Creation(int CHEMIN[MAX], int MUR_auto[MAX][MAX], int nbmouv, int CASE[MAX][MAX], int n)
//Crée le labyrinthe en reliant une case de la grille non reliée à la case actuelle
{
  if(Verifier_Cases_Autour(CASE)==1)
   {
     Demitour(CHEMIN, nbmouv);
     return;
   }

   int c;
   c = rand()%4 +1;

   if(c==1)
    {
      if(posy-1>=0)
      {
        if(CASE[posx][posy-1] = 0)
        {
          posy = posy -1;
          CASE[posx][posy] = 1;
          MUR_auto[posx][posy * 2] = 0;
          CHEMIN[nbmouv] = c;
          nbmouv++;
        }
      }
    }

    if(c==2)
     {
       if(posx-1>=0)
       {
         if(CASE[posx-1][posy] = 0)
         {
           posx = posx -1;
           CASE[posx][posy] = 1;
           MUR_auto[posx][posy*2 +1] = 0;
           CHEMIN[nbmouv] = c;
           nbmouv++;
         }
       }
     }

     if(c==3)
      {
        if(posy+1<n)
        {
          if(CASE[posx+1][posy] = 0)
          {
            posx = posx +1;
            CASE[posx][posy] = 1;
            MUR_auto[posx+1][2*posy +1] = 0;
            CHEMIN[nbmouv] = c;
            nbmouv++;
          }
        }
      }

      if(c==4)
       {
         if(posy+1<n)
         {
           if(CASE[posx][posy+1] = 0)
           {
             posy = posy +1;
             CASE[posx][posy] = 1;
             MUR_auto[posx][2*posy+2] = 0;
             CHEMIN[nbmouv] = c;
             nbmouv++;
           }
         }
       }
}

void Creation_Laby_Auto()
{
  printf("De quelle taille doit être le labyrinthe?\n");
  int n, i, j, nbmouv =0;
  scanf("%d", &n);
  int MUR_auto[MAX][MAX]; //tableau mur habituel
  int CASE[MAX][MAX]; //Sert a savoir si une case du laby est réliée
  int CHEMIN[MAX]; //Permet de connaitre les mouvements précédents

  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      CASE[i][j]=0;
    }
  }

  for(i=0; i<MAX; i++){
    for(j=0; j<MAX; j++){
      MUR_auto[i][j]=0;
    }
  }
  Grille(n);
  Grille_Limites(n);
  Creer_Curseur(&cursx, &cursy);

  while(Verifier_Labyrinthe(CASE, n) == 0)
  {
    Creation(CHEMIN, MUR_auto, nbmouv, CASE, n);
  }
  printf("fin creation auto");
}