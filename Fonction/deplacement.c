#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define N 9
#define M 7
int mat[N][M];


void deplacement(){
	int i,j,memoire,nb_dep,dep;
	nb_dep = 0;
	printf("Donnez les coordonnées du personnage a deplacer : ");
	scanf("%i%i",&i,&j);
	while(mat[i][j]!=1){
		printf("Selection invalide \n");
		printf("Donnez les coordonnées du personnage a deplacer : ");
		scanf("%i%i",&i,&j);
	}
	while (nb_dep<4){
		
		printf("Selectionnez une direction \n 0 : up \n 1 : down \n 2 : right \n 3 : left \n");
		scanf("%i",&dep);
		if (dep==0){
			if(i==1){
				printf("Deplacement invalide \n");
			}else if(mat[i-1][j]!=2){
				memoire = mat[i-1][j];
				mat[i-1][j]=mat[i][j];
				mat[i][j]=memoire;
				i--;
				nb_dep++;
				affichage();
			}else{
				printf("Deplacement invalide \n");
			}
		}else if (dep==1){
			if(i==8){
				printf("Deplacement invalide \n");
			}else if(mat[i+1][j]!=2){
				memoire = mat[i+1][j];
				mat[i+1][j]=mat[i][j];
				mat[i][j]=memoire;
				i++;
				nb_dep++;
				affichage();
			}else{
				printf("Deplacement invalide \n");
			}
		}else if (dep==2){
			if(j==6){
				printf("Deplacement invalide \n");
			}else if(mat[i][j+1]!=2){
				memoire = mat[i][j+1];
				mat[i][j+1]=mat[i][j];
				mat[i][j]=memoire;
				j++;
				nb_dep++;
				affichage();
			}else{
				printf("Deplacement invalide \n");
			}
		}else if (dep==3){
			if(j==1){
				printf("Deplacement invalide \n");
			}else if(mat[i][j-1]!=2){
				memoire = mat[i][j-1];
				mat[i][j-1]=mat[i][j];
				mat[i][j]=memoire;
				j--;
				nb_dep++;
				affichage();
			}else{
				printf("Deplacement invalide \n");
			}
		}else{
			printf("Deplacement invalide \n");
		}
		
	}
}
