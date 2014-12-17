#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "matrice.h"
//#include "personnage.h"
#define N 9
#define M 7
int mat[N][M];
int allie1,allie2,ennemis,ennemis2;
int boss_mort = 0;

int init_voisin(int i,int j){
	if(mat[i][j] == 1){
        allie1 = 1;
        allie2 = 1;
        ennemis = 2;
        ennemis2 = 3;
    }else if(mat[i][j] == 2){
        allie1 = 2;
        allie2 = 3;
        ennemis = 1;
        ennemis2 = 1;
	}else if(mat[i][j] == 3){
		allie1 = 2;
        allie2 = 2;
        ennemis = 1;
        ennemis2 = 1;
	}else{
        return(-1);
    }
}


int est_tenaille(int i,int j){
	
	init_voisin(i,j);
	
	if((i == 1 || i == 8 )&&( j == 1 || j == 6)){
		
		return(0);
	}
	
	if(i != 1 && i != 8 ){
		if(mat[i-1][j] == ennemis || mat[i-1][j] == ennemis2){
			while(mat[i+1][j] !=0 && i <= 7){
				if (mat[i+1][j] == ennemis || mat[i+1][j] == ennemis2){
					return(1);
				}
				i++;
			}
		}
		if(mat[i+1][j] == ennemis || mat[i+1][j] == ennemis2){
			while(mat[i-1][j] !=0 && i >= 2){
				if (mat[i-1][j] == ennemis || mat[i-1][j] == ennemis2){
					return(1);
				}
				i--;
			}
		}
	}
	if(j != 1 && j != 6 ){
		if(mat[i][j-1] == ennemis || mat[i][j-1] == ennemis2){
			while(mat[i][j+1] !=0 && j <= 5){
				if (mat[i][j+1] == ennemis || mat[i][j+1] == ennemis2){
					return(1);
				}
				j++;
			}
		}
		if(mat[i][j+1] == ennemis || mat[i][j+1] == ennemis2){
			while(mat[i][j-1] !=0 && j >= 2){
				if (mat[i][j-1] == ennemis || mat[i][j-1] == ennemis2){
					return(1);
				}
				j--;
			}
		}
	}
	return(0);
}

int voisin(int i,int j)
{
	int k,l;
	int voisin = 0;
	int test;
	test = init_voisin(i,j);
    
    if (test == -1){
		printf("cette unité n'est pas valide\n");
		return(-1);
	}
    
    k = i;
    
    for(l = j;(l < M)&&(mat[k][l] != ennemis && mat[k][l] != ennemis2);l++){
        if(mat[k][l] == allie1){
            voisin++;
        }else if(mat[k][l] == allie2){
            voisin++;
            allie2 = allie1;
        }
    }
    for(l = j;(l > 0)&&(mat[k][l] != ennemis && mat[k][l] != ennemis2);l--){
        if(mat[k][l] == allie1){
            voisin++;
        }else if(mat[k][l] == allie2){
            voisin++;
            allie2 = allie1;
        }
    }
    
    l = j;
    
    for(k = i;(k < N)&&(mat[k][l] != ennemis && mat[k][l] != ennemis2);k++){
        if(mat[k][l] == allie1){
            voisin++;
        }else if(mat[k][l] == allie2){
            voisin++;
            allie2 = allie1;
        }
    }
    for(k = i;(k > 0)&&(mat[k][l] != ennemis && mat[k][l] != ennemis2);k--){
        if(mat[k][l] == allie1){
            voisin++;
        }else if(mat[k][l] == allie2){
            voisin++;
            allie2 = allie1;
        }
    }
    if (mat[i][j] != 3){
		return(voisin - 4); //return voisin -4 car dans chacune des boucles on compte la case mat[i][j] qui est le personnage
	}else{
		return(voisin); // ici il ne faut pas return voisin -4 car nous ne comptons pas la case cibler ni les autres cases du boss
	}
}








typedef struct element{int c;struct element* suivant;}t_element;
t_element* pile;

void initpile(){
	pile = NULL;
}

int pilevide(){
	return(pile==NULL);
}

void empiler(int caract){
	t_element* nouv;
	nouv=(t_element*)malloc(sizeof(t_element));
	nouv->c = caract;
	nouv->suivant=pile;
	pile=nouv;
}

void depiler(int *caract){
	t_element* sommet;
	
	if(pile!=NULL){
		*caract = pile->c;
		sommet = pile;
		pile= sommet->suivant;
		free(sommet);
	}
}

int sommetpile(){
	if(pile!=NULL){
		return(pile->c);
	}
}

void attaque_joueur(int i,int j){
	int ei,ej;		//ici les variabes ei et ej servent a données les coordonnées de l'ennemis
	int nb_ennemis;
	nb_ennemis = 0;
	initpile();
	
	if (i <= 7){
		if (mat[i+1][j] == 2 || mat[i+1][j] == 3){
			empiler(i+1);
			empiler(j);
			nb_ennemis++;
		}
	}
	if (i >= 2){
		if (mat[i-1][j] == 2 || mat[i-1][j] == 3){
			empiler(i-1);
			empiler(j);
			nb_ennemis++;
		}
	}
	if (j <= 5){
		if (mat[i][j+1] == 2 || mat[i][j+1] == 3){
			empiler(i);
			empiler(j+1);
			nb_ennemis++;
		}
	}
	if (j >= 2){
		if (mat[i][j-1] == 2 || mat[i][j-1] == 3){
			empiler(i);
			empiler(j-1);
			nb_ennemis++;
		}
	}
	while(nb_ennemis > 0){
		depiler(&ej);
		depiler(&ei);
		if (est_tenaille(ei,ej)){
			
			if(mat[ei][ej] == 2){
				mat[ei][ej] = 5;
				printf("L'ennemis en %i %i est mort\n",ei,ej);
			}else if ((!boss_mort)&&(mat[ei][ej] == 3)){
				boss_mort = 1;
				printf("Le boss est mort ce soir\n");
			}
		}
		nb_ennemis--;
	} 
}











int main(){
	srand(time(NULL));
	// initialisation de la matrice a 0
	int i,j;
	for(i=0 ; i< N;i++){
		for(j=0; j < M; j++){
			if (i==0){
				mat[i][j] = j;
			}else{
				if(j==0){
					mat[i][j] = i;
				}else{
					mat[i][j] = 0;
				}
			}
		}
	}
	
	mat[1][1] = 2;
	mat[1][2] = 1;
	mat[1][3] = 1;
	mat[1][4] = 2;
	mat[6][2] = 1;
	mat[7][2] = 2;
	mat[8][2] = 2;

	int pos_x , pos_y;
	int player , ennemy;
	int boss = 1;
	printf("Veuillez rentrer le nombre d'entité du joueur a placer : \n");
	player = 8;
	ennemy = 6;
	for(ennemy =ennemy ; ennemy > 0; ennemy--) {
		pos_x = rand()%(8)+1;
		pos_y = rand()%(6)+1;
		
		while(mat[pos_x][pos_y] != 0) {
			pos_x = rand()%(8)+1;
			pos_y = rand()%(6)+1;
		}
		
		mat[pos_x][pos_y] = 2;
	}
	for(boss=boss ; boss > 0; boss--) 
	{
		pos_x = rand()%(7)+1;
		pos_y = rand()%(5)+1;
		while((mat[pos_x][pos_y] != 0)||(mat[pos_x+1][pos_y+1] != 0)||(mat[pos_x+1][pos_y] != 0)||(mat[pos_x][pos_y+1] != 0))  
		{
			pos_x = rand()%(7)+1;
			pos_y = rand()%(5)+1;
		}
		mat[pos_x][pos_y] = 3;
		mat[pos_x+1][pos_y+1] = 3;
		mat[pos_x+1][pos_y] = 3;
		mat[pos_x][pos_y+1] = 3;
	}
	for(player=player ; player > 0; player--) {
		pos_x = rand()%(8)+1;
		pos_y = rand()%(6)+1;
		
		while(mat[pos_x][pos_y] != 0) {
			pos_x = rand()%(8)+1;
			pos_y = rand()%(6)+1;
		}
		
		mat[pos_x][pos_y] = 1;
	}

	system("clear");
	printf("  ");
	for(i=0 ; i< N;i++){
		for(j = 0; j < M; j++){
			if(i!=0||j!=0){
				if (mat[i][j]!=0){
					printf("|%i",mat[i][j]) ;
				}else{
					printf("| ");
				}
			}
		}
		printf("|\n");
	}
	
	/*int voisins;
	printf("Donnez les coordonnées de l'unite dont vous voulez le nombre de voisin : ");
	scanf("%i%i",&i,&j);
	voisins = voisin(i,j);
	if (voisins != -1) {
		printf("Cette unite a %i voisins \n",voisins);
	}
	*/
	for(i=1 ; i< N;i++){
		for(j = 1; j < M; j++){
			if(mat[i][j] == 1){
				attaque_joueur(i,j);
			}
		}
	}
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
	printf("  ");
	for(i=0 ; i< N;i++){
		for(j = 0; j < M; j++){
			if(i!=0||j!=0){
				if (mat[i][j]!=0){
					printf("|%i",mat[i][j]) ;
				}else{
					printf("| ");
				}
				
			}
		}
		printf("|\n");
	}
}




