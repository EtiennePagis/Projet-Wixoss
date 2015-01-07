#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "classes.h"
#include "deplacement.h"
#include "matrice.h"
#include "deplacement_ennemi.h"
#include "voisin.h"
#define N 9
#define M 7
int mat[N][M];


/**
*\file partie.c
*\brief Projet 
*\author Etienne Pagis Stevy Fouquet Victorien Grude
*\version 0.1
*\date 6 Janvier 2015
*/

/**
*\fn partie (void) 
*\brief lance les differente fonction utile au deroulement d'une partie
*/
int partie (int niveau) 

{
	int win = 0;
	int lose = 0;
	int i,j;
	
	init();
	horde1 = generer_horde(horde1,niveau);
	placement(escouade1,horde1);
	affichage();
	while(win == 0 && lose == 0){
		deplacement_joueur();
		attaque_allie();
		resolve_attaque();
		affichage();
		deplacement_ennemi();
		attaque_nemesis();
		resolve_attaque();
		affichage();
		win = 1;
		lose = 1;
		for(i = 1 ; i < N ; i++)
		{
			for(j = 1 ; j < M ; j++) 
			{
				if(mat[i][j] == 1){
					lose = 0;
				}else if (mat[i][j] == 2){
					win = 0;
				}
			}
		}
	}
	system("clear");
	if (win == 1){
		printf("You Rock !!\n");	
	}else if (lose == 1){
		printf("You Lose, try harder next time \n");
	}
	return(EXIT_SUCCESS);
}
