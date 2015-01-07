#ifndef MATRICE_H
#define MATRICE_H
#endif
#ifndef VOISIN_H
#define VOISIN_H
#endif

void initpile(int pile[],int* sommet);
void empiler(int e,int pile[],int* sommet);
void depiler(int* e, int pile[], int* sommet);
int pilevide(int pile[],int sommet);

int est_ennemi(int i,int j,int joueur);
int est_allie(int i, int j,int joueur);

int est_tenaille_vertical(int i,int j);
int est_tenaille_horizontal(int i,int j);
int est_tenaille_coin(int i,int j);
int est_tenaille(int i,int j);

int voisin(int i,int j);

void attaque_joueur(int i,int j);
void attaque_ennemis(int i,int j);

void attaque_allie();
void attaque_nemesis();

void resolve_attaque();
