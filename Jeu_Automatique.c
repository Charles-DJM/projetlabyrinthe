#define MAX 100
/*DONC FAUT faire selon les murs autours:
3 murs == impassse, donc on fait demitour et on scelle la case en, mettant un mur derriere nous
2 murs on prends une direction au pif mais faut pas que ça soit en arrière
1 mur parreil
demitour = on prends le chemin inverse et on mets un mur pour bloquer l'accès a la case*/

void Compter_Murs(int n, int MUR_Reso)
//Renvoie le nombre de murs autour du curseur
{
  return MUR[posx][posx*2] + MUR[posx][2*posy +1] + MUR[posx +1][2*posy +1] +MUR[posx][2*posy+2];
}


void Resolution_Automatique(int n, int MUR_Reso)
//Fonction Principale
{
  posx = 0; posy = n-1; cursx = 30; cursy = n-30; nbmouv = 0;
  int CHEMIN[MAX];
  int direction;

  if(Compter_Murs(n, MUR_Reso)==3)
    {Demi_Tour(n, MUR_Reso, CHEMIN);}

  if(Compter_Murs(n, MUR_Reso)==2)
  {
    direction = rand()%4+1;

    switch (direction) {
      case 1:
        if(CHEMIN[nbmouv] != 4 && MUR_Reso[posx][posy] == 0)
        {
          nbmouv++;
          CHEMIN[nbmouv] = direction;
          Effacer_Curseur(cursx, cursy);
          posy = posy -1;
          cursy = cursy -1;
          Creer_Curseur(&cursx, &cursy);
          break;
        }
        break;
    }
  }

}
