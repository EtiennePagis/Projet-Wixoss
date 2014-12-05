#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "matrice.h"
//#include "personnage.h"
#define N 9
#define M 7
int mat[N][M];


 // a corriger 
void deplacement_ennemi () 
{
	int i, j;
	int pos_x , pos_y;
	//int entite_alg1, entite;
	for(i = 1 ; i < N ; i++)
	{
		for(j = 1 ; j < M ; j++)
		{
			if(mat[i][j] == 2)
			{
				pos_x = rand()%(8)+1;
				pos_y = rand()%(6)+1;
				while(mat[pos_x][pos_y] != 0) 
				{
					pos_x = rand()%(8)+1;
					pos_y = rand()%(6)+1;
				}
				mat[pos_x][pos_y] = 4;
				mat[i][j] = 0 ; 
			}
			if(mat[i][j] == 3) //Deplacement du boss mais disparition de certaine unité car collision non programmé
			{
				pos_x = rand()%(8)+1;
				pos_y = rand()%(6)+1;
				while((mat[pos_x][pos_y] != 0)&&(mat[pos_x+1][pos_y+1] != 0)&&(mat[pos_x+1][pos_y] != 0)&&(mat[pos_x][pos_y+1] != 0)&&(mat[pos_x-1][pos_y-1] != 0)&&(mat[pos_x-1][pos_y] != 0)&&(mat[pos_x][pos_y-1] != 0)&&(pos_x > 7)&&(pos_y > 9)&&(pos_x < 1)&&(pos_y < 1)) 
				{
					pos_x = rand()%(8)+1;
					pos_y = rand()%(6)+1;
				}
				if((pos_y <= 3)&&(pos_x <= 3)) // a modifier probleme d'affichage
				{
					mat[pos_x][pos_y] = 5;
					mat[pos_x+1][pos_y+1] = 5;
					mat[pos_x+1][pos_y] = 5;
					mat[pos_x][pos_y+1] = 5;
					mat[i][j] = 0;
					mat[i-1][j-1] = 0;
					mat[i][j-1] = 0;
					mat[i-1][j] = 0;	
				}
				if((pos_y >= 4)&&(pos_x >= 4))// a modifier probleme d'affichage
				{
					mat[pos_x][pos_y] = 5;
					mat[pos_x-1][pos_y-1] = 5;
					mat[pos_x-1][pos_y] = 5;
					mat[pos_x][pos_y-1] = 5;
					mat[i][j] = 0;
					mat[i+1][j+1] = 0;
					mat[i][j+1] = 0;
					mat[i+1][j] = 0;
				}
			}
		
		}
	}
	
	for(i = 1 ; i < N ; i++) 
	{
		for(j = 1 ; j < M ; j++) 
		{
			if (mat[i][j] == 4) { mat[i][j] = 2; }
			
			if (mat[i][j] == 5) { mat[i][j] = 3; }
		}
	}
	affichage();
}
				
	
