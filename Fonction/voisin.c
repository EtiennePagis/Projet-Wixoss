#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>
#include "matrice.h"
#include "classes.h"
//#include "personnage.h"
#define N 9
#define M 7
#define TMAX 100
int mat[N][M];
int boss_mort = 0;
int pile_ennemi[TMAX];
int sommet_ennemi =-1;
float experiencetotal = 0;
/**
*\file voisin.c
*\brief Projet 
*\author Etienne Pagis Stevy Fouquet Victorien Grude
*\version 0.1
*\date 6 Janvier 2015
*/

/**
*\fn initpile(int pile[],int* sommet)
*\brief Initialise une pile mise en parametre
*/
void initpile(int pile[],int* sommet){
	*sommet = -1;
}

/**
*\fn empiler(int e,int pile[],int* sommet)
*\brief Empile un entier mit en parametre sur une pile mise en parametre 
*/
void empiler(int e,int pile[],int* sommet){
	if (*sommet < TMAX - 1){
		*sommet = *sommet + 1;
		pile[*sommet] = e;
	}
}

/**
*\fn depiler(int* e, int pile[], int* sommet)
*\brief Depile un entier dans un pointeur mit en parametre sur une pile mise en parametre 
*/
void depiler(int* e, int pile[], int* sommet){
	if(*sommet > -1){
		*e = pile[*sommet];
		*sommet = *sommet -1;
	}	
} 

/**
*\fn pilevide(int pile[],int sommet)
*\brief Renvoie vrai si la pile mise en parametre est vide 
*/
int pilevide(int pile[],int sommet){
	return(sommet == -1);
}


/**
 *\fn est_ennemi(int i,int j,int joueur)
 *\brief Renvoie vrai si la premiere unite mise en parametre est enemis a la deuxieme unite mise en parametre 
 */
int est_ennemi(int i,int j,int joueur){
	if (joueur != 0){
		if(joueur == 1){
			if (mat[i][j] == 2 || mat[i][j] == 3 || mat[i][j] == 4 || mat[i][j] == 5){return(1);}
		}else if(joueur == 2){
			if (mat[i][j] == 1|| mat[i][j] == 6){return(1);}
		}else if(joueur == 3){
			if(mat[i][j] == 1 || mat[i][j] == 6){return(1);}
		}else{
			return(-1);
		}
		return(0);
	}else{
		return(-1);
	}
}

/**
 *\fn est_allie(int i, int j,int joueur)
 *\brief Renvoie vrai si la premiere unite mise en parametre est allie a la deuxieme unite mise en parametre 
 */
int est_allie(int i, int j,int joueur){
	if (joueur != 0){
		if(est_ennemi(i,j,joueur)){
			return(0);
		}else if (mat[i][j] != 0 && mat[i][j] != 5 && mat[i][j] != 4){
			return(1);
		}else{
			return(0);
		}
	}else{
		return(-1);
	}
}



/**
*\fn est_tenaille_vertical(int i,int j)
*\brief Renvoie vrai si l'unite mise en parametre est prise en tenaille verticalement
*/
int est_tenaille_vertical(int i,int j){
	if(i != 1 && i != 8 ){ //on n'est pas sur un bord horizontale
		while((i >= 2 )&& (!est_ennemi(i-1,j,mat[i][j])) && (mat[i-1][j] !=0)){
			i--;
		}
		if ((i == 1)||(mat[i-1][j] == 0)){
			printf("l'unite %i %i (%i) n'est pas en tenaille vertical\n",i,j,mat[i][j]);
			return(0);
		}else if(est_ennemi(i-1,j,mat[i][j])){
			while(i <= 7 && mat[i+1][j] !=0){
				if (est_ennemi(i+1,j,mat[i][j])){
					
					while(!est_ennemi(i-1,j,mat[i][j])){
						printf("L'unite %i %i (%i) est en tenaille vertical\n",i,j,mat[i][j]);
						empiler(i,pile_ennemi,&sommet_ennemi);
						empiler(j,pile_ennemi,&sommet_ennemi);
						i--;
					}
					printf("L'unite %i %i (%i) est en tenaille vertical\n",i,j,mat[i][j]);
					empiler(i,pile_ennemi,&sommet_ennemi);
					empiler(j,pile_ennemi,&sommet_ennemi);
					return(1);
				}
				i++;
			}
		}
	}
	printf("l'unite %i %i (%i) n'est pas en tenaille vertical\n",i,j,mat[i][j]);
	return(0);
}

/**
*\fn est_tenaille_horizontal(int i,int j)
*\brief Renvoie vrai si l'unite mise en parametre est prise en tenaille horizontalement
*/
int est_tenaille_horizontal(int i,int j){
	
	if(j != 1 && j != 6 ){ //on n'est pas sur un bord vertical
		while((j >= 2 )&& (!est_ennemi(i,j-1,mat[i][j])) && (mat[i][j-1] !=0)){
			j--;
		}
		if ((j == 1)||(mat[i][j-1] ==0)){
			printf("l'unite %i %i (%i) n'est pas en tenaille horizontal\n",i,j,mat[i][j]);
			return(0);
		}else if(est_ennemi(i,j-1,mat[i][j])){
			while(j <= 5 && mat[i][j+1] !=0){
				if (est_ennemi(i,j+1,mat[i][j])){
					
					while(!est_ennemi(i,j-1,mat[i][j])){
						printf("L'unite %i %i (%i) est en tenaille horizontal\n",i,j,mat[i][j]);
						empiler(i,pile_ennemi,&sommet_ennemi);
						empiler(j,pile_ennemi,&sommet_ennemi);
						j--;
					}
					printf("L'unite %i %i (%i) est en tenaille horizontal\n",i,j,mat[i][j]);
					empiler(i,pile_ennemi,&sommet_ennemi);
					empiler(j,pile_ennemi,&sommet_ennemi);
					return(1);
				}
				j++;
			}
		}
	}
	printf("l'unite %i %i (%i) n'est pas en tenaille horizontal\n",i,j,mat[i][j]);
	return(0);
	
}

/**
*\fn est_tenaille_coin(int i,int j)
*\brief Renvoie vrai si l'unite mise en parametre est prise en tenaille alors qu'elle est dans un coin
*/
int est_tenaille_coin(int i,int j){
	//pour le moment, dans les coins, on ne eput pas etre pris en tenaille
	if(i == 1 && j == 1){
		if(est_ennemi(2,1,mat[1][1]) && est_ennemi(1,2,mat[1][1])){
			printf("L'unite %i %i (%i) est en tenaille dans un coin\n",i,j,mat[i][j]);
			return(1);
		}
	}else if(i == 1 && j == M-1){
		if(est_ennemi(2,M-1,mat[1][M-1]) && est_ennemi(1,M-2,mat[1][M-1])){
			printf("L'unite %i %i (%i) est en tenaille dans un coin\n",i,j,mat[i][j]);
			return(1);
		}
	}else if(i == N-1 && j == 1){
		if(est_ennemi(N-2,1,mat[N-1][1]) && est_ennemi(N-1,2,mat[N-1][1])){
			printf("L'unite %i %i (%i) est en tenaille dans un coin\n",i,j,mat[i][j]);
			return(1);
		}
	}else if(i == N-1 && j == M-1){
		if(est_ennemi(N-2,M-1,mat[N-1][M-1]) && est_ennemi(N-1,M-2,mat[N-1][M-1])){
			printf("L'unite %i %i (%i) est en tenaille dans un coin\n",i,j,mat[i][j]);
			return(1);
		}
	}
	printf("l'unite %i %i (%i) n'est pas en tenaille dans un coin\n",i,j,mat[i][j]);
	return(0);
	
}

/**
*\fn est_tenaille(int i,int j)
*\brief Renvoie vrai si l'unite mise en parametre est prise en tenaille
*/
int est_tenaille(int i,int j){
	if(est_tenaille_vertical(i,j)||est_tenaille_horizontal(i,j)||est_tenaille_coin(i,j)){
		return(1);
	}
	return(0);
}


/**
*\fn voisin(int i,int j)
*\brief Renvoie le nombre de voisin de l'unite mise en parametre
*/
int voisin(int i,int j)
{
	int k,l;
	int voisin = 0;
	int test;
	test = est_allie(i,j,mat[i][j]);
    
    if (test == -1){
		printf("cette unité n'est pas valide\n");
		return(-1);
	}
    
    k = i;
    
    for(l = j;(l < M)&&(!est_ennemi(k,l,mat[i][j]));l++){
        if(est_allie(k,l,mat[i][j])){
			if(!(k == i && l == j)){
				printf("l'unité en %i %i est un voisin à l'unité %i %i\n",k,l,i,j);
				voisin++;
			}
        }
    }
    for(l = j;(l > 0)&&(!est_ennemi(k,l,mat[i][j]));l--){
        if(est_allie(k,l,mat[i][j])){
			if(!(k == i && l == j)){
				printf("l'unité en %i %i est un voisin à l'unité %i %i\n",k,l,i,j);
				voisin++;
			}
        }
    }
    
    l = j;
    
    for(k = i;(k < N)&&(!est_ennemi(k,l,mat[i][j]));k++){
        if(est_allie(k,l,mat[i][j])){
			
			if(!(k == i && l == j)){
				printf("l'unité en %i %i est un voisin à l'unité %i %i\n",k,l,i,j);
				voisin++;
			}
        }
    }
    for(k = i;(k > 0)&&(!est_ennemi(k,l,mat[i][j]));k--){
        if(est_allie(k,l,mat[i][j])){
			
			if(!(k == i && l == j)){
				printf("l'unité en %i %i est un voisin à l'unité %i %i\n",k,l,i,j);
				voisin++;
			}
        }
    }
   /* if (mat[i][j] != 3){
		return(voisin - 4); //return voisin -4 car dans chacune des boucles on compte la case mat[i][j] qui est le personnage
	}else{
		return(voisin); // ici il ne faut pas return voisin -4 car nous ne comptons pas la case cibler ni les autres cases du boss
	}*/
	return(voisin);
}


/**
*\fn attaque_joueur(int i,int j)
*\brief Fais l'attaque de l'unite joueur mis en parametre
*/
void attaque_joueur(int i,int j){
	int ei,ej;		//ici les variables ei et ej servent à donner les coordonnées de l'ennemi
	int nb_ennemis;
    int pile_att[TMAX];
    int sommet_att;
	nb_ennemis = 0;
	initpile(pile_att,&sommet_att);
	
	
	if (i <= 7){
		if (mat[i+1][j] == 2 || mat[i+1][j] == 3){
			empiler(i+1,pile_att,&sommet_att);
			empiler(j,pile_att,&sommet_att);
			nb_ennemis++;
		}
	}
	if (i >= 2){
		if (mat[i-1][j] == 2 || mat[i-1][j] == 3){
			empiler(i-1,pile_att,&sommet_att);
			empiler(j,pile_att,&sommet_att);
			nb_ennemis++;
		}
	}
	if (j <= 5){
		if (mat[i][j+1] == 2 || mat[i][j+1] == 3){
			empiler(i,pile_att,&sommet_att);
			empiler(j+1, pile_att,&sommet_att);
			nb_ennemis++;
		}
	}
	if (j >= 2){
		if (mat[i][j-1] == 2 || mat[i][j-1] == 3){
			empiler(i,pile_att,&sommet_att);
			empiler(j-1,pile_att,&sommet_att);
			nb_ennemis++;
		}
	}
	while(nb_ennemis > 0){
		depiler(&ej,pile_att,&sommet_att);
		depiler(&ei,pile_att,&sommet_att);
		if (est_tenaille(ei,ej)){
			if(mat[ei][ej] == 2){
				
				while(!pilevide(pile_ennemi,sommet_ennemi)){
					depiler(&ej,pile_ennemi,&sommet_ennemi);
					depiler(&ei,pile_ennemi,&sommet_ennemi);
					iallie = 1;
					while((tab_a[iallie] != i || tab_a[iallie+1] != j)&&(iallie<20)){
						iallie = iallie + 3;
					}
					iennemi = 1;
					while((tab_e[iennemi] != ei || tab_e[iennemi+1] != ej)&&(iennemi<20)){
						iennemi = iennemi + 3;
					}
					if((iallie != 20)&&(iennemi !=20)){
						afficher_perso_uni(horde1.perso[tab_e[iennemi-1]]);
						printf(" Il est maintenant ");
						if (escouade1.perso[tab_a[iallie-1]].stat.attack >= escouade1.perso[tab_a[iallie-1]].stat.mattack){
							horde1.perso[tab_e[iennemi-1]].stat.HP = horde1.perso[tab_e[iennemi-1]].stat.HP-((((escouade1.perso[tab_a[iallie-1]].level*0.4+2)*escouade1.perso[tab_a[iallie-1]].stat.attack*40)/(horde1.perso[tab_e[iennemi-1]].stat.def*50))+2)*4;
						}else{
							horde1.perso[tab_e[iennemi-1]].stat.HP = horde1.perso[tab_e[iennemi-1]].stat.HP-((((escouade1.perso[tab_a[iallie-1]].level*0.4+2)*escouade1.perso[tab_a[iallie-1]].stat.mattack*40)/(horde1.perso[tab_e[iennemi-1]].stat.mdef*50))+2)*4;
						}
						if (horde1.perso[tab_e[iennemi-1]].stat.HP <= 0){
							mat[ei][ej] = 5;
							printf("L'ennemis en %i %i est mort\n",ei,ej);
							experiencetotal = experiencetotal + horde1.perso[tab_e[iennemi-1]].exp;
							xp(escouade1,experiencetotal);	
							escouade1 = montee_level_escouade(escouade1);
						}else{
							printf("a %.0f PV\n",horde1.perso[tab_e[iennemi-1]].stat.HP);
						}
					}else{
						printf("Erreur cible non trouvé\n");
					}
					
				}
				
			}
		}
		nb_ennemis--;
	} 
}

/**
*\fn attaque_ennemis(int i,int j)
*\brief Fais l'attaque de l'unite ennemis mis en parametre
*/
void attaque_ennemis(int i,int j){
	int ei,ej;		//ici les variables ei et ej servent à donner les coordonnées de l'ennemi
	int nb_ennemis;
    int pile_att[TMAX];
    int voisins;
    int sommet_att;
	nb_ennemis = 0;
	voisins = voisin(i,j);
	initpile(pile_att,&sommet_att);
	

	
	if (i <= 7){
		if (mat[i+1][j] == 1){
			empiler(i+1,pile_att,&sommet_att);
			empiler(j,pile_att,&sommet_att);
			nb_ennemis++;
		}
	}
	if (i >= 2){
		if (mat[i-1][j] == 1){
			empiler(i-1,pile_att,&sommet_att);
			empiler(j,pile_att,&sommet_att);
			nb_ennemis++;
		}
	}
	if (j <= 5){
		if (mat[i][j+1] == 1){
			empiler(i,pile_att,&sommet_att);
			empiler(j+1, pile_att,&sommet_att);
			nb_ennemis++;
		}
	}
	if (j >= 2){
		if (mat[i][j-1] == 1){
			empiler(i,pile_att,&sommet_att);
			empiler(j-1,pile_att,&sommet_att);
			nb_ennemis++;
		}
	}
	while(nb_ennemis > 0){
		depiler(&ej,pile_att,&sommet_att);
		depiler(&ei,pile_att,&sommet_att);
		if (est_tenaille(ei,ej)){
			
			while(!pilevide(pile_ennemi,sommet_ennemi)){
				depiler(&ej,pile_ennemi,&sommet_ennemi);
				depiler(&ei,pile_ennemi,&sommet_ennemi);
				iallie = 1;
				while((tab_a[iallie] != ei || tab_a[iallie+1] != ej)&&(iallie<20)){
					iallie = iallie + 3;
				}
				iennemi = 1;
				while((tab_e[iennemi] != i || tab_e[iennemi+1] != j)&&(iennemi<20)){
					iennemi = iennemi + 3;
				}
				if((iallie != 20)&&(iennemi !=20)){
					
					afficher_perso_uni(escouade1.perso[tab_a[iallie-1]]);
					printf(" Il est maintenant ");
					if (horde1.perso[tab_e[iennemi-1]].stat.attack >= horde1.perso[tab_e[iennemi-1]].stat.mattack){
						
						escouade1.perso[tab_a[iallie-1]].stat.HP = escouade1.perso[tab_a[iallie-1]].stat.HP-(((((horde1.perso[tab_e[iennemi-1]].level*0.4+2)*horde1.perso[tab_e[iennemi-1]].stat.attack*10)/(escouade1.perso[tab_a[iallie-1]].stat.def*50))+2)*(voisins +1));
					}else{
						
						escouade1.perso[tab_a[iallie-1]].stat.HP = escouade1.perso[tab_a[iallie-1]].stat.HP-(((((horde1.perso[tab_e[iennemi-1]].level*0.4+2)*horde1.perso[tab_e[iennemi-1]].stat.mattack*10)/(escouade1.perso[tab_a[iallie-1]].stat.mdef*50))+2)*(voisins +1));
					}
					if (escouade1.perso[tab_a[iallie-1]].stat.HP <= 0){
						mat[ei][ej] = 5;		
						printf("L'allie en %i %i est mort\n",ei,ej);
					}else{
						printf("a %.0f PV\n",escouade1.perso[tab_a[iallie-1]].stat.HP);
					}
				}else{
					printf("Erreur cible non trouvé\n");
				}
				
			}
		}
		nb_ennemis--;
	} 
}

/**
*\fn attaque_allie()
*\brief Fais l'attaque de toute les unites joueur
*/
void attaque_allie(){
	int i,j;
	for(i=1 ; i< N;i++){
		for(j = 1; j < M; j++){
			if(mat[i][j] == 1){
				printf("\n\n ===================== attaque du perso en %i %i (%i) pour l'équipe Joueur ===================== \n\n", i, j ,mat[i][j]);
				attaque_joueur(i,j);
			}
		}
	}
	/*
	if(mat[1][1] != 0 && est_tenaille(1,1)){
		iallie = 1;
		while((tab_a[iallie] != 2 || tab_a[iallie+1] != 1)&&(iallie<20)){
			iallie = iallie + 3;
		}
		iennemi = 1;
		while((tab_e[iennemi] != 1 || tab_e[iennemi+1] != 1)&&(iennemi<20)){
			iennemi = iennemi + 3;
		}
		if((iallie != 20)&&(iennemi !=20)){
			afficher_perso_uni(horde1.perso[tab_e[iennemi-1]]);
			printf(" Il est maintenant ");
			if (escouade1.perso[tab_a[iallie]].stat.attack >= escouade1.perso[tab_a[iallie]].stat.mattack){
				horde1.perso[tab_e[iennemi-1]].stat.HP = horde1.perso[tab_e[iennemi-1]].stat.HP-((((escouade1.perso[tab_a[iallie]].level*0.4+2)*escouade1.perso[tab_a[iallie]].stat.attack*50)/(horde1.perso[tab_e[iennemi-1]].stat.def*50))+2)*4;
			}else{
				horde1.perso[tab_e[iennemi-1]].stat.HP = horde1.perso[tab_e[iennemi-1]].stat.HP-((((escouade1.perso[tab_a[iallie]].level*0.4+2)*escouade1.perso[tab_a[iallie]].stat.mattack*50)/(horde1.perso[tab_e[iennemi-1]].stat.mdef*50))+2)*4;
			}
			if (horde1.perso[tab_e[iennemi-1]].stat.HP <= 0){
				mat[1][1] = 5;		
				printf("L'ennemis en 1 1 est mort\n");
			}else{
				printf("a %.0f PV\n",horde1.perso[tab_e[iennemi-1]].stat.HP);
			}
		}else{
			printf("Erreur cible non trouvé\n");
		}
	}else if(mat[1][M-1] != 0 && est_tenaille(1,M-1)){
		iallie = 1;
		while((tab_a[iallie] != 2 || tab_a[iallie+1] != M-1)&&(iallie<20)){
			iallie = iallie + 3;
		}
		iennemi = 1;
		while((tab_e[iennemi] != 1 || tab_e[iennemi+1] != M-1)&&(iennemi<20)){
			iennemi = iennemi + 3;
		}
		if((iallie != 20)&&(iennemi !=20)){
			afficher_perso_uni(horde1.perso[tab_e[iennemi-1]]);
			printf(" Il est maintenant ");
			if (escouade1.perso[tab_a[iallie]].stat.attack >= escouade1.perso[tab_a[iallie]].stat.mattack){
				horde1.perso[tab_e[iennemi-1]].stat.HP = horde1.perso[tab_e[iennemi-1]].stat.HP-((((escouade1.perso[tab_a[iallie]].level*0.4+2)*escouade1.perso[tab_a[iallie]].stat.attack*50)/(horde1.perso[tab_e[iennemi-1]].stat.def*50))+2)*4;
			}else{
				horde1.perso[tab_e[iennemi-1]].stat.HP = horde1.perso[tab_e[iennemi-1]].stat.HP-((((escouade1.perso[tab_a[iallie]].level*0.4+2)*escouade1.perso[tab_a[iallie]].stat.mattack*50)/(horde1.perso[tab_e[iennemi-1]].stat.mdef*50))+2)*4;
			}
			if (horde1.perso[tab_e[iennemi-1]].stat.HP <= 0){
				mat[1][M-1] = 5;		
				printf("L'ennemis en 1 6 est mort\n");
			}else{
				printf("a %.0f PV\n",horde1.perso[tab_e[iennemi-1]].stat.HP);
			}
		}else{
			printf("Erreur cible non trouvé\n");
		}
	}else if(mat[N-1][1] != 0 && est_tenaille(N-1,1)){
		iallie = 1;
		while((tab_a[iallie] != N-1 || tab_a[iallie+1] != 2)&&(iallie<20)){
			iallie = iallie + 3;
		}
		iennemi = 1;
		while((tab_e[iennemi] != N-1 || tab_e[iennemi+1] != 1)&&(iennemi<20)){
			iennemi = iennemi + 3;
		}
		if((iallie != 20)&&(iennemi !=20)){
			afficher_perso_uni(horde1.perso[tab_e[iennemi-1]]);
			printf(" Il est maintenant ");
			if (escouade1.perso[tab_a[iallie]].stat.attack >= escouade1.perso[tab_a[iallie]].stat.mattack){
				horde1.perso[tab_e[iennemi-1]].stat.HP = horde1.perso[tab_e[iennemi-1]].stat.HP-((((escouade1.perso[tab_a[iallie]].level*0.4+2)*escouade1.perso[tab_a[iallie]].stat.attack*50)/(horde1.perso[tab_e[iennemi-1]].stat.def*50))+2)*4;
			}else{
				horde1.perso[tab_e[iennemi-1]].stat.HP = horde1.perso[tab_e[iennemi-1]].stat.HP-((((escouade1.perso[tab_a[iallie]].level*0.4+2)*escouade1.perso[tab_a[iallie]].stat.mattack*50)/(horde1.perso[tab_e[iennemi-1]].stat.mdef*50))+2)*4;
			}
			if (horde1.perso[tab_e[iennemi-1]].stat.HP <= 0){
				mat[N-1][1] = 5;		
				printf("L'ennemis en 8 1 est mort\n");
			}else{
				printf("a %.0f PV\n",horde1.perso[tab_e[iennemi-1]].stat.HP);
			}
		}else{
			printf("Erreur cible non trouvé\n");
		}
	}else if(mat[N-1][M-1] != 0 && est_tenaille(N-1,M-1)){
		iallie = 1;
		while((tab_a[iallie] != N-2 || tab_a[iallie+1] != M-1)&&(iallie<20)){
			iallie = iallie + 3;
		}
		iennemi = 1;
		while((tab_e[iennemi] != N-1 || tab_e[iennemi+1] != M-1)&&(iennemi<20)){
			iennemi = iennemi + 3;
		}
		if((iallie != 20)&&(iennemi !=20)){
			afficher_perso_uni(horde1.perso[tab_e[iennemi-1]]);
			printf(" Il est maintenant ");
			if (escouade1.perso[tab_a[iallie]].stat.attack >= escouade1.perso[tab_a[iallie]].stat.mattack){
				horde1.perso[tab_e[iennemi-1]].stat.HP = horde1.perso[tab_e[iennemi-1]].stat.HP-((((escouade1.perso[tab_a[iallie]].level*0.4+2)*escouade1.perso[tab_a[iallie]].stat.attack*50)/(horde1.perso[tab_e[iennemi-1]].stat.def*50))+2)*4;
			}else{
				horde1.perso[tab_e[iennemi-1]].stat.HP = horde1.perso[tab_e[iennemi-1]].stat.HP-((((escouade1.perso[tab_a[iallie]].level*0.4+2)*escouade1.perso[tab_a[iallie]].stat.mattack*50)/(horde1.perso[tab_e[iennemi-1]].stat.mdef*50))+2)*4;
			}
			if (horde1.perso[tab_e[iennemi-1]].stat.HP <= 0){
				mat[N-1][M-1] = 5;		
				printf("L'ennemis en 8 6 est mort\n");
			}else{
				printf("a %.0f PV\n",horde1.perso[tab_e[iennemi-1]].stat.HP);
			}
		}else{
			printf("Erreur cible non trouvé\n");
		}
	}*/
}

/**
*\fn attaque_nemesis()
*\brief Fais l'attaque de toute les unites ennemis
*/
void attaque_nemesis(){
	int i,j;
	int voisins;
	for(i=1 ; i< N;i++){
		for(j = 1; j < M; j++){
			if(mat[i][j] == 2){
				printf("\n\n ===================== attaque du perso en %i %i (%i) pour l'équipe Bot ===================== \n\n", i, j ,mat[i][j]);
				attaque_ennemis(i,j);
			}
		}
	}/*
	if(mat[1][1] != 0 && est_tenaille(1,1)){
		iallie = 1;
		while((tab_a[iallie] != 1 || tab_a[iallie+1] != 1)&&(iallie<20)){
			iallie = iallie + 3;
		}
		iennemi = 1;
		while((tab_e[iennemi] != 2 || tab_e[iennemi+1] != 1)&&(iennemi<20)){
			iennemi = iennemi + 3;
		}
		if((iallie != 20)&&(iennemi !=20)){
			voisins = voisin(2,1);
			afficher_perso_uni(escouade1.perso[tab_a[iallie-1]]);
			printf(" Il est maintenant ");
			if (horde1.perso[tab_a[iallie]].stat.attack >= horde1.perso[tab_a[iallie]].stat.mattack){
				escouade1.perso[tab_e[iennemi-1]].stat.HP = escouade1.perso[tab_e[iennemi-1]].stat.HP-((((horde1.perso[tab_a[iallie]].level*0.4+2)*horde1.perso[tab_a[iallie]].stat.attack*10)/(escouade1.perso[tab_e[iennemi-1]].stat.def*50))+2)*(voisins +1);
			}else{
				escouade1.perso[tab_e[iennemi-1]].stat.HP = escouade1.perso[tab_e[iennemi-1]].stat.HP-((((horde1.perso[tab_a[iallie]].level*0.4+2)*horde1.perso[tab_a[iallie]].stat.mattack*10)/(escouade1.perso[tab_e[iennemi-1]].stat.mdef*50))+2)*(voisins +1);
			}
			if (escouade1.perso[tab_e[iennemi-1]].stat.HP <= 0){
				mat[1][1] = 5;		
				printf("L'allie en 1 1 est mort\n");
			}else{
				printf("a %.0f PV\n",escouade1.perso[tab_e[iennemi-1]].stat.HP);
			}
		}else{
			printf("Erreur cible non trouvé\n");
		}
	}else if(mat[1][M-1] != 0 && est_tenaille(1,M-1)){
		iallie = 1;
		while((tab_a[iallie] != 1 || tab_a[iallie+1] != M-1)&&(iallie<20)){
			iallie = iallie + 3;
		}
		iennemi = 1;
		while((tab_e[iennemi] != 2 || tab_e[iennemi+1] != M-1)&&(iennemi<20)){
			iennemi = iennemi + 3;
		}
		if((iallie != 20)&&(iennemi !=20)){
			voisins = voisin(2,M-1);
			afficher_perso_uni(escouade1.perso[tab_a[iallie-1]]);
			printf(" Il est maintenant ");
			if (horde1.perso[tab_a[iallie]].stat.attack >= horde1.perso[tab_a[iallie]].stat.mattack){
				escouade1.perso[tab_e[iennemi-1]].stat.HP = escouade1.perso[tab_e[iennemi-1]].stat.HP-((((horde1.perso[tab_a[iallie]].level*0.4+2)*horde1.perso[tab_a[iallie]].stat.attack*10)/(escouade1.perso[tab_e[iennemi-1]].stat.def*50))+2)*(voisins +1);
			}else{
				escouade1.perso[tab_e[iennemi-1]].stat.HP = escouade1.perso[tab_e[iennemi-1]].stat.HP-((((horde1.perso[tab_a[iallie]].level*0.4+2)*horde1.perso[tab_a[iallie]].stat.mattack*10)/(escouade1.perso[tab_e[iennemi-1]].stat.mdef*50))+2)*(voisins +1);
			}
			if (escouade1.perso[tab_e[iennemi-1]].stat.HP <= 0){
				mat[1][M-1] = 5;		
				printf("L'allie en 1 6 est mort\n");
			}else{
				printf("a %.0f PV\n",escouade1.perso[tab_e[iennemi-1]].stat.HP);
			}
		}else{
			printf("Erreur cible non trouvé\n");
		}
	}else if(mat[N-1][1] != 0 && est_tenaille(N-1,1)){
		iallie = 1;
		while((tab_a[iallie] != N-1 || tab_a[iallie+1] != 1)&&(iallie<20)){
			iallie = iallie + 3;
		}
		iennemi = 1;
		while((tab_e[iennemi] != N-2 || tab_e[iennemi+1] != 1)&&(iennemi<20)){
			iennemi = iennemi + 3;
		}
		if((iallie != 20)&&(iennemi !=20)){
			voisins = voisin(N-2,1);
			afficher_perso_uni(escouade1.perso[tab_a[iallie-1]]);
			printf(" Il est maintenant ");
			if (horde1.perso[tab_a[iallie]].stat.attack >= horde1.perso[tab_a[iallie]].stat.mattack){
				escouade1.perso[tab_e[iennemi-1]].stat.HP = escouade1.perso[tab_e[iennemi-1]].stat.HP-((((horde1.perso[tab_a[iallie]].level*0.4+2)*horde1.perso[tab_a[iallie]].stat.attack*10)/(escouade1.perso[tab_e[iennemi-1]].stat.def*50))+2)*(voisins +1);
			}else{
				escouade1.perso[tab_e[iennemi-1]].stat.HP = escouade1.perso[tab_e[iennemi-1]].stat.HP-((((horde1.perso[tab_a[iallie]].level*0.4+2)*horde1.perso[tab_a[iallie]].stat.mattack*10)/(escouade1.perso[tab_e[iennemi-1]].stat.mdef*50))+2)*(voisins +1);
			}
			if (escouade1.perso[tab_e[iennemi-1]].stat.HP <= 0){
				mat[N-1][1] = 5;		
				printf("L'allie en 8 1 est mort\n");
			}else{
				printf("a %.0f PV\n",escouade1.perso[tab_e[iennemi-1]].stat.HP);
			}
		}else{
			printf("Erreur cible non trouvé\n");
		}
	}else if(mat[N-1][M-1] != 0 && est_tenaille(N-1,M-1)){
		iallie = 1;
		while((tab_a[iallie] != N-1 || tab_a[iallie+1] != M-1)&&(iallie<20)){
			iallie = iallie + 3;
		}
		iennemi = 1;
		while((tab_e[iennemi] != N-2 || tab_e[iennemi+1] != M-1)&&(iennemi<20)){
			iennemi = iennemi + 3;
		}
		if((iallie != 20)&&(iennemi !=20)){
			voisins = voisin(N-2,M-1);
			afficher_perso_uni(escouade1.perso[tab_a[iallie-1]]);
			printf(" Il est maintenant ");
			if (horde1.perso[tab_a[iallie]].stat.attack >= horde1.perso[tab_a[iallie]].stat.mattack){
				escouade1.perso[tab_e[iennemi-1]].stat.HP = escouade1.perso[tab_e[iennemi-1]].stat.HP-((((horde1.perso[tab_a[iallie]].level*0.4+2)*horde1.perso[tab_a[iallie]].stat.attack*10)/(escouade1.perso[tab_e[iennemi-1]].stat.def*50))+2)*(voisins +1);
			}else{
				escouade1.perso[tab_e[iennemi-1]].stat.HP = escouade1.perso[tab_e[iennemi-1]].stat.HP-((((horde1.perso[tab_a[iallie]].level*0.4+2)*horde1.perso[tab_a[iallie]].stat.mattack*10)/(escouade1.perso[tab_e[iennemi-1]].stat.mdef*50))+2)*(voisins +1);
			}
			if (escouade1.perso[tab_e[iennemi-1]].stat.HP <= 0){
				mat[N-1][M-1] = 5;		
				printf("L'allie en 8 6 est mort\n");
			}else{
				printf("a %.0f PV\n",escouade1.perso[tab_e[iennemi-1]].stat.HP);
			}
		}else{
			printf("Erreur cible non trouvé\n");
		}
	}*/
	
}

/**
*\fn resolve_attaque()
*\brief Supprime les unites tuees
*/
void resolve_attaque(){
	int i,j;
	for(i=1 ; i< N;i++){
		for(j = 1; j < M; j++){
			if(mat[i][j] == 5){
				mat[i][j] = 0;
			}
			if (boss_mort&&mat[i][j] == 3){
				mat[i][j] = 0;
			}
		}
	}
}



