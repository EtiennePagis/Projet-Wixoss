#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "matrice.h"
#include "voisin.h"
//#include "personnage.h"
#define N 9
#define M 7
int mat[N][M];
int ioris;
int joris;
int ienem;
int jenem;
int pos_x   , pos_y  ;
int ennemi = 0;
int nb_cible = 0;

/**
*\file deplacement_ennemi_test.c
*\brief Projet 
*\author Etienne Pagis Stevy Fouquet Victorien Grude
*\version 0.1
*\date 6 Janvier 2015
*/
 
/**
*\fn chercher_entite()
*\brief cherche toutes les entités presentes dans la matrice
*/
void chercher_entite() 
{
	nb_cible = 0;
	int i , j ; 

	int voisins ;
	int voisin_max = 0;
	int test = 1;
	for(i = 1 ; i < N ; i++)
	{
		for(j = 1 ; j < M ; j++)
		{
			if(mat[i][j] == 2) {ennemi++;} //Incremente le nombre d'ennemi a deplacer 
			
				else if (mat[i][j] == 1){
				
					if (est_tenaille(i,j)){
						mat[i][j] = 6;
					}else{
						nb_cible++;
						
						if (test == 1){
							
							ioris = i;
							joris = j;
							pos_x = ioris;
							pos_y = joris;
							printf("Notre cible est en %i %i\n",ioris,joris);
							test = 0;
						}					
						//}
					}
				}
				
		
			
        }
    }
    printf("le nombre de cible %i\n",nb_cible);
}

/**
*\fn dplct_ennemi_mltcib ()
*\brief deplace les entites "chassant" lorsqu'il y a plusieurs "cibles"
*/
void dplct_ennemi_mltcib () 
{
	int tenaille = 0;
	
	if(((joris == 1)||(joris == M-1))&&((ioris == 1)||(ioris == N-1))) //on est sur un coin
	{
		if (!est_tenaille(ioris,joris)){
			if(ioris == 1 && joris == 1){
				if(mat[2][1] == 0){
					pos_x = 2;
					pos_y = 1;
				}else if(mat[1][2] == 0){
					pos_x = 1;
					pos_y = 2;
				}else{
					pos_x = 0;
					pos_y = 0;
				}
			}else if(ioris == 1 && joris == M-1){
				if(mat[2][M-1] == 0){
					pos_x = 2;
					pos_y = M-1;
				}else if(mat[1][M-2] == 0){
					pos_x = 1;
					pos_y = M-2;
				}else{
					pos_x = 0;
					pos_y = 0;
				}
			}else if(ioris == N-1 && joris == 1){
				if(mat[N-2][1] == 0){
					pos_x = N-2;
					pos_y = 1;
				}else if(mat[N-1][2] == 0){
					pos_x = N-1;
					pos_y = 2;
				}else{
					pos_x = 0;
					pos_y = 0;
				}
			}else if(ioris == N-1 && joris == M-1){
				if(mat[N-2][M-1] == 0){
					pos_x = N-2;
					pos_y = M-1;
				}else if(mat[N-1][M-2] == 0){
					pos_x = N-1;
					pos_y = M-2;
				}else{
					pos_x = 0;
					pos_y = 0;
				}
			}
		}else{
			tenaille = 1;
		}
	}else if (joris == 1 ||  joris==M-1 )//on est sur un bord vertical, et PAS sur un coin
	{
	
			if (!est_tenaille(ioris,joris)){
				if (mat[pos_x+1][pos_y]==0){
					pos_x++;
				}else if (mat[pos_x-1][pos_y] ==0){
					pos_x--;
				}else{
					mat[ioris][joris] = 6;
					pos_x = 0;
					pos_y = 0;
				}
			}else{
				tenaille = 1;
			}
	}
	else if ( ioris==1 || ioris == N-1 )  //on est sur un bord horizontal, et PAS sur un coin
	{
		if (!est_tenaille(ioris,joris)){
				if (mat[pos_x][pos_y+1]==0){
					pos_y++;
				}else if (mat[pos_x][pos_y-1] ==0){
					pos_y--;
				}else{
					mat[ioris][joris] = 6;
					pos_x = 0;
					pos_y = 0;
				}
			}else{
				tenaille = 1;
			}
	}
	
	else
	{
		// tout ce qui precede permet le deplacement de l'ia dans la quasi totalité de la matrice
			
		if (!est_tenaille(ioris,joris)){
				if (mat[pos_x+1][pos_y]==0){
					pos_x++;
				}else if (mat[pos_x-1][pos_y] ==0){
					pos_x--;
				}else{
					mat[ioris][joris] = 6;
					pos_x = 0;
					pos_y = 0;
				}
			}else{
				tenaille = 1;
			}
	}
	
	if (tenaille == 1) 
	{
		nb_cible--;
		
	}
	
}		
			
		
/**
*\fn deplacement_ennemi ()
*\brief deplace les entites "ennemis" 
*/		
void deplacement_ennemi () 
{
	int i, j;
	int choix;
			
       for (i = 1 ; i < N; i++)
        {
           for (j = 1; j < M; j++)
            {
               if(mat[i][j] == 2)
                {
					chercher_entite();
					assert((pos_x > 0)&&(pos_x < N));
					assert((pos_y > 0)&&(pos_y < M));
					// s'il reste une cible
					// ET ( case de la cible (pos_x pos_y) est valable 
					// ET num ligne et num colonnes origine valides )
					if((nb_cible > 0) && (ennemi > 1) && ((ioris >= 1)&&(ioris <= N-1)) && ((joris >= 1)&&(joris <= M-1)) )
					{
						printf("===================L'unite a deplacer est en %i %i ====================\n",i,j);
							
						dplct_ennemi_mltcib(); //modifie pos_x pos_y
						
						ennemi--;
						
							if (pos_x != 0 && pos_y != 0){
								assert((pos_x > 0)&&(pos_x < N));
								assert((pos_y > 0)&&(pos_y < M));
								// s'il reste une cible
								// ET ( case de la cible (pos_x pos_y) est valable 
								// ET num ligne et num colonnes origine valides )
								iennemi = 1;
								while(tab_e[iennemi] != i || tab_e[iennemi+1] != j){
									iennemi = iennemi + 3;
								}						
								mat[i][j] = 0 ;
								mat[pos_x][pos_y] = 4;
								tab_e[iennemi] = pos_x;
								tab_e[iennemi+1] = pos_y;
								printf("=====================elle se deplace en %i %i===================\n",pos_x,pos_y);
							}
						
						chercher_entite();
						
					}
                 }
			
            }
       }
	
	for(i = 1 ; i < N ; i++)
	{
		for(j = 1 ; j < M ; j++) 
		{
			if (mat[i][j] == 7) { mat[i][j] = 0; }
			
			if (mat[i][j] == 4) { mat[i][j] = 2; }
			
			if (mat[i][j] == 5) { mat[i][j] = 3; }
			
			if (mat[i][j] == 6) { mat[i][j] = 1; }
		}
	}

	affichage();
	
    
}
