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
	int k,l,test = 0;
	int voisin = 0;
	int voisin_max = 0;
	int pos_x  , pos_y ;
	int ioris,joris;
	//int entite_alg1, entite;
	for(i = 1 ; i < N ; i++)
	{
		for(j = 1 ; j < M ; j++)
		{
			if(mat[i][j] == 1) 
			{
				k=i;
               for (l = 1 ;l < M; l++)
                {
                   if(mat[k][l]==1)
                    {
                       voisin++;
                    }
                }
			
				l = j;
			
				for (k = 1;k < N;k++)
                {
					if(mat[k][l]==1)
                     {
						voisin++;
                     }
				}
				if(voisin > voisin_max)
				{
					voisin_max = voisin;
					if (pos_y < M-1)
                    {
						pos_y++;
						pos_x = i;
					}else if (pos_x < N-1)
                    {
						pos_x++;
						pos_y = j;
					}else if(pos_x > 1)
                    {
						pos_x--;
						pos_y = j;
					}else if(pos_y > 1)
                    {
						pos_y--;
						pos_x = i;
					}else
                    {
						pos_x = 1;
						pos_y = 1;
					}
					ioris = i;
					joris = j;
				}
				
			}
        }
    }
				
       for (i = 1 ; i < N; i++)
        {
           for (j = 1; j < M; j++)
            {
               if(mat[i][j] == 2)
                {
                   /*pos_x = rand()%(8)+1;
                    pos_y = rand()%(6)+1;*/
                   assert((pos_x > 0)&&(pos_x < N));
                   assert((pos_y > 0)&&(pos_y < M));
                   while((mat[pos_x][pos_y] != 0)||((ioris < 1)&&(ioris > N))||((joris < 1)&&(joris > M)))
                    {
                    	if(mat[ioris][joris+1] == 0)
                    	{
                    		pos_y++;
                          	pos_x = ioris;
                    	}else if(mat[ioris][joris-1] == 0)
                    	{
                    		pos_y--;
                            pos_x = ioris;
                    	}else if(mat[ioris+1][joris] == 0)
                    	{
                    		pos_y = joris;
                            pos_x++;
                    	}else if(mat[ioris-1][joris] == 0)
                    	{
                    		pos_y = joris;
                            pos_x--;
                    	}else
                    	{
                      	 if (pos_y < M-1)
                      	  {
                        	 pos_y++;
                         	 pos_x = ioris;
                    	}else if (pos_x < N-1)
                       	 {
                           pos_x++;
                           pos_y = joris;
                       	}else if(pos_x > 1)
                        	{
                           	pos_x--;
                           	pos_y = joris;
                       	}else if(pos_y > 1){
                       	    pos_y--;
                       	    pos_x = ioris;
                       	}else if ((pos_x > N)&&(pos_y > M)){
                       	    pos_x = 1;
                       	    pos_y = 1;
                      	 }
                    	}
                    }
                   mat[pos_x][pos_y] = 4;
                   mat[i][j] = 0 ;
                }
               /*if(mat[i][j] == 3) //Deplacement du boss mais disparition de certaine unité car collision non programmé
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
			if (mat[i][j] == 4) { mat[i][j] = 2; }
			
			if (mat[i][j] == 5) { mat[i][j] = 3; }
            }
        }
     affichage();
}