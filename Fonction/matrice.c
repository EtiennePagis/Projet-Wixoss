#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define N 9
#define M 7
int mat[N][M];

/**
*\file voisin.c
*\brief Projet 
*\author Etienne Pagis Stevy Fouquet Victorien Grude
*\version 0.1
*\date 6 Janvier 2015
*/

/**
*\fn affichage ()
*\brief Affiche la matrice
*/
void affichage (){
	int i,j;
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
		printf("|\n"); //permet un meilleur esthetisme
	}
}

/**
*\fn init()
*\brief Intialise la matrice a 0
*/
void init(){
	
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

}

/**
*\fn placement () 
*\brief Place les entité des joueurs et des ennemis
*/
void placement () 
{ 
	
	int pos_x , pos_y;
	int player , ennemy;
	int boss = 0;
	printf("Veuillez rentrer le nombre d'entité du joueur a placer : \n");
	scanf("%i",&player);
	while((player <= 0)||(player >= 7))
	{
		printf("Nombre d'entité du joueur invalide\n"); 
		printf("Veuillez rentrer à nouveaux le nombre d'entité du joueur a placer : \n");
		scanf("%i",&player);
	}
	ennemy = rand()%(6)+1;
	for(ennemy ; ennemy > 0; ennemy--) { // Place les entité ennemi dans la matrice
		pos_x = rand()%(8)+1;
		pos_y = rand()%(6)+1;
		
		while(mat[pos_x][pos_y] != 0) {
			pos_x = rand()%(8)+1;
			pos_y = rand()%(6)+1;
		}
		
		mat[pos_x][pos_y] = 2;
	}
	for(boss ; boss > 0; boss--) 
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
	for(player ; player > 0; player--) {
		pos_x = rand()%(8)+1;
		pos_y = rand()%(6)+1;
		
		while(mat[pos_x][pos_y] != 0) {
			pos_x = rand()%(8)+1;
			pos_y = rand()%(6)+1;
		}
		
		mat[pos_x][pos_y] = 1;
	}
}


	 
	

