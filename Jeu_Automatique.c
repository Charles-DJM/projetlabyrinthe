#define MAX 100

int Compter_murs(int n, int MUR)
//Compte le nombre de murs autour du curseur
{
  return MUR[posx][posx*2] + MUR[posx][2*posy +1] + MUR[posx +1][2*posy +1] +MUR[posx][2*posy+2];
}

void Deplacement_Auto(int n, int MUR)
{

  if(Compter_murs(n, MUR)>2)
  {
   Demitour(CHEMIN);
   return ;
  }

  int direct;
  direct = rand()%4+1

  if(direct==1 && posy-1>0 && CASE[posx][posy] == 0 && MUR[posx][posx*2])
  {
    posy = posy -1;
    CASE[posx][posy] = 1;
    nbmouv++;
    CHEMIN[nbmouv] = direct;
  }
  if(direct==2 && posx-1>=0 && CASE[posx-1][posy] == 0 && MUR[posx][2*posy +1])
  {
    posx = posx -1;
    CASE[posx][posy] = 1;
    nbmouv++;
    CHEMIN[nbmouv] = direct;
  }
  if(direct==3 && posx+1<n && CASE[posx+1][posy] == 0 && MUR[posx +1][2*posy +1])
  {
    posx = posx +1;
    CASE[posx][posy] = 1;
    nbmouv++;
    CHEMIN[nbmouv] = 3;
  }
  if(direct==4 && posy+1<n && CASE[posx][posy+1] == 0 && MUR[posx][2*posy+2])
  {
    posy = posy +1;
    CASE[posx][posy] = 1;
    nbmouv++;
    CHEMIN[nbmouv] = 4;
  }
}
void Trouver_intersection(int n, int MUR_reso)
{
  while(Compter_murs(n, MUR_reso)>=3)
  {

  }
}
void Resolution_Automatique(int n, int MUR_reso)
{
    posx = 0; posy = n-1; cursx = 30; cursy = n-30; nbmouv = 0;
    int i, j;
