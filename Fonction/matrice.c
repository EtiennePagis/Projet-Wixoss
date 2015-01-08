#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "classes.h"
#define N 9
#define M 7
int mat[N][M];
int tab_a[20];
int nombre_a;
int iallie;
int tab_e[20];
int nombre_e;
int iennemi;

/**
*\file matrice.c
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
void placement (t_escouade escouade,t_escouade horde) 
{ 
	
	int pos_x , pos_y;
	int player , ennemy;
	int i = 0;
	
	iallie = 0;
	iennemi = 0;
	
	player = escouade.nb_perso;
	ennemy = horde.nb_perso;
	printf("Le nombre d'entité ennemis a placer est de %i : \n",horde.nb_perso);
	
	nombre_e = horde.nb_perso;
	
	for(ennemy ; ennemy > 0; ennemy--) { // Place les entité ennemi dans la matrice
		pos_x = rand()%(8)+1;
		pos_y = rand()%(6)+1;
		
		while(mat[pos_x][pos_y] != 0) {
			pos_x = rand()%(8)+1;
			pos_y = rand()%(6)+1;
		}
		
		mat[pos_x][pos_y] = 2;
		
		tab_e[iennemi] = nombre_e - ennemy;
		tab_e[iennemi+1] = pos_x;
		tab_e[iennemi+2] = pos_y;
		iennemi = iennemi + 3;
		
		afficher_perso_uni(horde.perso[i]);
		printf(" / est en %i %i \n",pos_x,pos_y);
		i++;
	}
	i = 0;
	printf("\n\nLe nombre d'entité du joueur a placer est de %i : \n",escouade.nb_perso);
	
	nombre_a = escouade.nb_perso;
	
	for(player ; player > 0; player--) {
		pos_x = rand()%(8)+1;
		pos_y = rand()%(6)+1;
		
		while(mat[pos_x][pos_y] != 0) {
			pos_x = rand()%(8)+1;
			pos_y = rand()%(6)+1;
		}
		
		mat[pos_x][pos_y] = 1;
		
		tab_a[iallie] = nombre_a - player;
		tab_a[iallie+1] = pos_x;
		tab_a[iallie+2] = pos_y;
		iallie = iallie + 3;
		
		afficher_perso_uni(escouade1.perso[i]);
		printf(" / est en %i %i \n",pos_x,pos_y);
		i++;
		
	}
	printf("\n\n");
	
}


	 
	

