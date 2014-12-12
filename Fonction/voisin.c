#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "matrice.h"
//#include "personnage.h"
#define N 9
#define M 7
int mat[N][M];


// a corriger
int voisin(int i,int j)
{

	int k,l;
	int voisin = 0;
    int allie1,allie2,ennemis;
    
    
    if(mat[i][j] == 1){
        allie1 = 1;
        allie2 = 1;
        ennemis = 2;
    }else if(mat[i][j] == 2){
        allie1 = 2;
        allie2 = 3;/info/etu/l2spi/spi2023/InfoS3_Dashie/Projet/Projet-Wixoss/Fonction/voisin.h
        ennemis = 1;
    }else{
        return(0);
    }
    
    
    k = i;
    
    for(l = j;(l < M)&&(mat[k][l] != ennemis);l++){
        if(mat[k][l] == allie1){
            voisin++;
        }else if(mat[k][l] == allie2){
            voisin++;
            allie2 = allie1;
        }
    }
    for(l = j;(l > 0)&&(mat[k][l] != ennemis);l--){
        if(mat[k][l] == allie1){
            voisin++;
        }else if(mat[k][l] == allie2){
            voisin++;
            allie2 = allie1;
        }
    }
    
    l = j;
    
    for(k = i;(k < N)&&(mat[k][l] != ennemis);k++){
        if(mat[k][l] == allie1){
            voisin++;
        }else if(mat[k][l] == allie2){
            voisin++;
            allie2 = allie1;
        }
    }
    for(k = i;(k > 0)&&(mat[k][l] != ennemis);k--){
        if(mat[k][l] == allie1){
            voisin++;
        }else if(mat[k][l] == allie2){
            voisin++;
            allie2 = allie1;
        }
    }
    
    return(voisin - 4); //return voisin -4 car dans chacune des boucles on compte la case mat[i][j] qui est le personnage
    
}




