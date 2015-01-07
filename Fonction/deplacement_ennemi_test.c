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

 

void chercher_entite() //cherche toutes les entités presentes dans la matrice
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
			//else if((mat[i][j] == 1) && (((((mat[i+1][j]==2)||(mat[i+1][j]==4))&&((mat[i-1][j]==2)||(mat[i-1][j]==4))))||(((mat[i][j+1] == 2)||(mat[i][j+1] == 4)&&((mat[i][j-1] == 2)||(mat[i][j-1] == 4)))))) // Change l'affichage temporairement afin de ne plus le considere comme une cible
			
				else if (mat[i][j] == 1){
				
					if (est_tenaille(i,j)){
						mat[i][j] = 6;
					}else{
						nb_cible++;
						// Calcul les voisin et prend ces coordonnées
						
						//voisins = 0;
						
						//voisins = voisin(i,j);
						//if(voisins > voisin_max)
						//{
						//voisin_max = voisins;
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


void dplct_ennemi_mltcib () // deplace les entites "chassant" lorsqu'il y a plusieurs "cibles"
{
	int tenaille = 0;
	
	if(((joris == 1)||(joris == M-1))&&((ioris == 1)||(ioris == N-1))) //on est sur un coin
	{/*
		if(((mat[ioris][joris-1] == 4)||(mat[ioris][joris-1] == 2))&&((mat[ioris+1][joris] == 4)||(mat[ioris+1][joris] == 2)))
		{
			mat[ioris][joris] = 6;
			tenaille = 1;
		}
		else if(((mat[ioris][joris+1] == 4)||(mat[ioris][joris+1] == 2))&&((mat[ioris-1][joris] == 4)||(mat[ioris-1][joris] == 2)))
		{
			mat[ioris][joris] = 6;
			tenaille = 1;
		}
		else if(((mat[ioris][joris-1] == 4)||(mat[ioris][joris-1] == 2))&&((mat[ioris-1][joris] == 4)||(mat[ioris-1][joris] == 2))){
			mat[ioris][joris] = 6;
			tenaille = 1;	
		}
		else if(((mat[ioris][joris+1] == 4)||(mat[ioris][joris+1] == 2))&&((mat[ioris+1][joris] == 4)||(mat[ioris+1][joris] == 2)))
		{
			mat[ioris][joris] = 6;
			tenaille = 1;
		}
		if (est_tenaille(ioris,joris)){
			mat[ioris][joris] = 6;
			tenaille = 1;
		}
		 // Verif des prise en tenaille
		else // la cible (qui est dans un coin) n'est pas en tenaille
		{
			if((joris == M-1)&&(ioris == N-1))// identifie pour tout les cas, les cases permettant de prendre en tenaille
			{
				if((mat[ioris][joris-1] == 0))
				{
					if(!((pos_x > 0)&&(pos_x < N))&&(pos_y > 1)&&(pos_y < M)){
						pos_x = ioris;
						pos_y--;
					}
				
				}
				if((mat[ioris-1][joris] == 0))
				{
					if(!((pos_x > 1)&&(pos_x < N))&&(pos_y > 0)&&(pos_y < M)){
						pos_x--;
						pos_y = joris;
					}
					
				}
			}else if((joris == M-1)&&(ioris == 1))
			{
				if((mat[ioris][joris-1] == 0))
				{
					if(!((pos_x > 0)&&(pos_x < N))&&(pos_y > 1)&&(pos_y < M)){
						pos_x = ioris;
						pos_y--;
					}
					
				}
				if((mat[ioris+1][joris] == 0))
				{
					if(!((pos_x > 0)&&(pos_x < N-1))&&(pos_y > 0)&&(pos_y < M)){
						pos_x++;
						pos_y = joris;
					}
					
				}
			
			}else if((joris == 1)&&(ioris == N-1))
				{
					if((mat[ioris][joris+1] == 0))
					{
						if(!((pos_x > 0)&&(pos_x < N))&&(pos_y > 0)&&(pos_y < M-1)){
							pos_x = ioris;
							pos_y++;
						}
						
					}
					if((mat[ioris-1][joris] == 0))
					{
						if(!((pos_x > 1)&&(pos_x < N))&&(pos_y > 0)&&(pos_y < M)){
							pos_x--;
							pos_y = joris;
						}
						
					}
			/*	
			}else if((ioris == N) && (joris == M))
			{
				if((mat[ioris][joris-1] == 0))
				{
					pos_x = ioris;
					pos_y--;
				}
				if((mat[ioris-1][joris] == 0))
				{
					pos_x--;
					pos_y = joris;
				}
				*/
			}else if((ioris == 1)&&(joris == 1)){
				if((mat[ioris][joris+1] == 0))
				{
					if(!((pos_x > 0)&&(pos_x < N))&&(pos_y > 0)&&(pos_y < M-1)){
						pos_x = ioris;
						pos_y++;
					}
					
				}
				if((mat[ioris+1][joris] == 0))
				{
					if(!((pos_x > 0)&&(pos_x < N-1))&&(pos_y > 0)&&(pos_y < M)){
						pos_x++;
						pos_y = joris;
					}
					
				}
				
			}
				
		}
	}*/
	else if (joris == 1 ||  joris==M-1 )//on est sur un bord vertical, et PAS sur un coin
	{
	/*
			//if(((mat[ioris+1][joris] == 4)||(mat[ioris+1][joris] == 2))&&((mat[ioris-1][joris] == 4)||(mat[ioris-1][joris] == 2))){mat[ioris][joris]=6;tenaille = 1;}
			if (est_tenaille(ioris,joris)){mat[ioris][joris]=6;tenaille = 1;}
			else // la cible (qui est sur un bord vertical) n'est pas en tenaille
			{
				if((ioris < N-1)&&(ioris > 1))
				{
						if(mat[ioris][joris+1] == 0)
						{
							pos_y++;
							pos_x = ioris;
						}
						else if(mat[ioris][joris-1] == 0)
						{
							pos_y--;
							pos_x = ioris;
						}
						if(mat[ioris+1][joris] == 0)
						{
							if(!((pos_x > 0)&&(pos_x < N-1))&&(pos_y > 0)&&(pos_y < M)){
								pos_y = joris;
								pos_x++;
							}
							
						}
						else if(mat[ioris-1][joris] == 0)
						{
							if(!((pos_x > 1)&&(pos_x < N))&&(pos_y > 0)&&(pos_y < M)){
								pos_y = joris;
								pos_x--;
							}
							
						}
				}	
			}*/
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
	{/*
		//if(((mat[ioris][joris+1] == 4)||(mat[ioris][joris+1] == 2))&&((mat[ioris][joris-1] == 4)||(mat[ioris][joris-1] == 2))){mat[ioris][joris]=6;tenaille = 1;}
		if (est_tenaille(ioris,joris)){mat[ioris][joris]=6;tenaille = 1;}
		else 
		{
			if((joris < M-1)&&(joris > 1))
			{
				if(mat[ioris][joris+1] == 0)
				{
					if(((pos_x > 0)&&(pos_x < N))&&(pos_y > 0)&&(pos_y < M-1)){
						pos_y++;
						pos_x = ioris;
					}
					
				}
				else if(mat[ioris][joris-1] == 0)
				{
					if(!((pos_x > 0)&&(pos_x < N))&&(pos_y > 1)&&(pos_y < M)){
						pos_y--;
						pos_x = ioris;
					}
					
				}
				else if(mat[ioris+1][joris] == 0)
				{
					pos_y = joris;
					pos_x++;
				}
				else if(mat[ioris-1][joris] == 0)
				{
					pos_y = joris;
					pos_x--;
				}
			}		// la cible (qui est sur un bord horizontal) n'est pas en tenaille
		}*/
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
	/*else if(((((mat[ioris][joris+1] == 4)||(mat[ioris][joris+1] == 2))&&((mat[ioris][joris-1] == 4)||(mat[ioris][joris-1] == 2)))	|| 	(((mat[ioris+1][joris] == 4)||(mat[ioris+1][joris] == 2))&&((mat[ioris-1][joris] == 4)||(mat[ioris-1][joris] == 2)))))
	{
		mat[ioris][joris]=6;
		tenaille = 1;
	}*/
	//if (est_tenaille(ioris,joris)){mat[ioris][joris]=6;tenaille = 1;}
	else
	{/*
		if((((mat[ioris][joris+1] == 0)&&(mat[ioris][joris-1] == 0)))&&((joris < M-1)&&(joris > 2))) //la cible n'est pas en tenaille
		{
			if(!((pos_x > 0)&&(pos_x < N))&&(pos_y > 0)&&(pos_y < M-1)){
				pos_x = ioris;
				pos_y++;
			}
			
		}
		else if ((((mat[ioris][joris+1] == 0)&&(mat[ioris][joris-1] == 0)))&&(joris > 2))
		{
			if(!((pos_x > 0)&&(pos_x < N))&&(pos_y > 1)&&(pos_y < M)){
				pos_x = ioris;
				pos_y--;
			}
			
		}
			
		else if((((mat[ioris][joris+1] == 4)||(mat[ioris][joris+1] == 2))&&(mat[ioris][joris-1] == 0))&&(joris > 2))
		{
			if(!((pos_x > 0)&&(pos_x < N))&&(pos_y > 1)&&(pos_y < M)){
				pos_x = ioris;
				pos_y--;
			}
			
		}
			
		else if((((mat[ioris][joris-1] == 4)||(mat[ioris][joris-1] == 2))&&(mat[ioris][joris+1] == 0))&&(joris < M-1))
		{
			if(!((pos_x > 0)&&(pos_x < N))&&(pos_y > 0)&&(pos_y < M-1)){
				pos_x = ioris;
				pos_y++;
			}
		}
			
			
		else if((((mat[ioris+1][joris] == 0)&&(mat[ioris-1][joris] == 0)))&&(ioris < N-1))
		{
			if(!((pos_x > 0)&&(pos_x < N-1))&&(pos_y > 0)&&(pos_y < M)){
				pos_x++;
				pos_y = joris;
			}
			
		} 
			
		else if((((mat[ioris+1][joris] == 0)&&(mat[ioris-1][joris] == 0)))&&(ioris > 2))
		{
			if(!((pos_x > 1)&&(pos_x < N))&&(pos_y > 0)&&(pos_y < M)){
				pos_x--;
				pos_y = joris;
			}
			
		} 
			
		else if((((mat[ioris-1][joris] == 4)||(mat[ioris-1][joris] == 2)) && ((mat[ioris+1][joris] == 0)))&&(ioris < N-1 ))
		{
			if(!((pos_x > 0)&&(pos_x < N-1))&&(pos_y > 0)&&(pos_y < M)){
				pos_x++;
				pos_y = joris;
			}
			
		}
			
		else if((((mat[ioris+1][joris] == 4)||(mat[ioris+1][joris] == 2)) && ((mat[ioris-1][joris] == 0)))&&(ioris > 2))
		{
			if(!((pos_x > 1)&&(pos_x < N))&&(pos_y > 0)&&(pos_y < M)){
				pos_x--;
				pos_y = joris;
			}
			
		}
		// tout ce qui precede permet le deplacement de l'ia dans la quasi totalité de la matrice
		*/	
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
	// si la cible n'est pas en tenaille, on cherche les positions autour d'elle permettant de le faire
	/*else if((tenaille == 0)&&(((ioris < N)&&(ioris > 1))||((joris < M)&&(joris > 1))))
    {	
		else
			
			//Positionnement de l'ia sur les lignes de bord de la matrice 	
	}
	//printf("l'unité se deplace en %i %i\n",pos_x,pos_y);
		
	*/
}		
			
		
		
void deplacement_ennemi () 
{
	int i, j;
	int choix;
	//int cut;
	//int entite_alg1, entite;		
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
					if((nb_cible > 0) && (ennemi > 0) && ((ioris >= 1)&&(ioris <= N-1)) && ((joris >= 1)&&(joris <= M-1)) )
					{
						printf("===================L'unite a deplacer est en %i %i ====================\n",i,j);
							/*if(((i == 1) || (i == N-1))&&((j == 1)||(j == M-1)))
							{
								if( i == 1 && j == 1 ) 
								{
									if(mat[i+1][j] == 1 || mat[i][j+1]) {mat[i][j] = 4;}
								}
								if( i == 1 &&((j > 1)||(j < M-1)))
								{
									if(mat[i+1][j] == 1 || mat[i][j+1] ==1 || mat[i][j-1] == 1) {mat[i][j] = 4;}
								}
								if(i == 1 && j == M-1)
								{
									if(mat[i+1][j] == 1 || mat[i][j-1] == 1) {mat[i][j] = 4;}
								}
									if( j == 1 && ((i > 1)||(i< N-1))) 
								{
									if(mat[i+1][j] == 1 || mat[i][j+1] == 1 || mat[i-1][j] == 1) {mat[i][j] = 4;}
								}
									if(i == N-1 && j == M-1)
								{
									if(mat[i-1][j] == 1 || mat[i][j-1] == 1) {mat[i][j] = 4;}
								}
							}*/
						dplct_ennemi_mltcib(); //modifie pos_x pos_y
						
						ennemi--;
						
						
						
					
							if (mat[pos_x][pos_y] == 0){
								mat[pos_x][pos_y] = 4;
								mat[i][j] = 0 ;
								printf("=====================elle se deplace en %i %i===================\n",pos_x,pos_y);
							}
						
						chercher_entite();
						
					}
                 }
                 
              /* if(mat[i][j] == 3) //Deplacement du boss mais disparition de certaine unité car collision non programmé
                {
                   pos_x = rand()%(7)+1;
                   pos_y = rand()%(5)+1;
                   while((mat[pos_x][pos_y] != 0)||(mat[pos_x+1][pos_y+1] != 0)||(mat[pos_x+1][pos_y] != 0)||(mat[pos_x][pos_y+1] != 0))
                    {
                       pos_x = rand()%(6)+1;
                       pos_y = rand()%(5)+1;
                    }
				
                   mat[pos_x][pos_y] = 5;
                   mat[pos_x+1][pos_y+1] = 5;
                   mat[pos_x+1][pos_y] = 5;
                   mat[pos_x][pos_y+1] = 5;
                   mat[i][j] = 0;
                   mat[i+1][j+1] = 0;
                   mat[i][j+1] = 0;
                   mat[i+1][j] = 0;
                }*/
			
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
	printf("Entrez le chiffre 1 ");
	scanf("%i",&choix);
	if(choix == 1){
		affichage();
	}
    
}
