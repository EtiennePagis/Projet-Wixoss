#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#inclide <assert.h>
#define N 9
#define M 7
int mat[N][M];

void affichage ()
{ // affiche la matrice 
	system("clear");
	int i,j;
	printf(" ");
	for(i=0 ; i< N;i++){
		for(j = 0; j < M; j++){
			if(i!=0||j!=0){
				printf("|%i",mat[i][j]) ;
			}
		}
		printf("|\n");
	}
}
void init()
{ // initialise la matrice a 0 

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
	//mat[7][5] = 1;
}

void placement () 
{ // postionne les entites du joueur et de l'ennemi
	srand(time(NULL));
	int pos_x , pos_y;
	int player , ennemy;
	printf(" Veuillez rentrez le nombre d'entité du joueur a placer : ");
	scanf("%i",&player);
	ennemy = rand()%(15 - 1)+1;
	for(player; player > 0; player--) {
		pos_x = rand()%(8-1)+1;
		pos_y = rand()%(6-1)+1;
		
		while(mat[pos_x][pos_y] != 0) {
			pos_x = rand()%(8-1)+1;
			pos_y = rand()%(6-1)+1;
		}
		
		mat[pos_x][pos_y] = 1;
	}
	for(ennemy; ennemy > 0; ennemy--) {
		pos_x = rand()%(8-1)+1;
		pos_y = rand()%(6-1)+1;
		
		while(mat[pos_x][pos_y] != 0) {
			pos_x = rand()%(8-1)+1;
			pos_y = rand()%(6-1)+1;
		}
		
		mat[pos_x][pos_y] = 2;
	}
}
	 
	
void main ()
{
	init();
	placement();
	affichage();
}
