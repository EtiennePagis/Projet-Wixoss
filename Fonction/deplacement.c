#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define N 9
#define M 7
int mat[N][M];

void deplacementpossible(int* i,int* j,int dep,int* nb_dep){
	int memoire;
	if (dep==8){
		if(*i==1){                                   //deplacement vers le haut
			affichage();
			printf("Deplacement invalide \n");
		}else if((mat[*i-1][*j]!=2)&&(mat[*i-1][*j]!=3)){
			memoire = mat[*i-1][*j];
			mat[*i-1][*j]=mat[*i][*j];
			mat[*i][*j]=memoire;
			(*i)--;
			(*nb_dep)++;
			affichage();
		}else{									
			affichage();
			printf("Deplacement invalide \n");		
		}
	}else if (dep==2){								//deplacement vers le bas
		if(*i==8){
			affichage();
			printf("Deplacement invalide \n");
		}else if((mat[*i+1][*j]!=2)&&(mat[*i+1][*j]!=3)){
			memoire = mat[*i+1][*j];
			mat[*i+1][*j]=mat[*i][*j];
			mat[*i][*j]=memoire;
			(*i)++;
			(*nb_dep)++;
			affichage();
		}else{
			affichage();
			printf("Deplacement invalide \n");
		}
	}else if (dep==6){								//deplacement vers la droite
		if(*j==6){
			affichage();
			printf("Deplacement invalide \n");
		}else if((mat[*i][*j+1]!=2)&&(mat[*i][*j+1]!=3)){
			memoire = mat[*i][*j+1];
			mat[*i][*j+1]=mat[*i][*j];
			mat[*i][*j]=memoire;
			(*j)++;
			(*nb_dep)++;
			affichage();
		}else{
			affichage();
			printf("Deplacement invalide \n");
		}
	}else if (dep==4){								//deplacement vers la gauche
		if(*j==1){
			affichage();
			printf("Deplacement invalide \n");
		}else if((mat[*i][*j-1]!=2)&&(mat[*i][*j-1]!=3)){
			memoire = mat[*i][*j-1];
			mat[*i][*j-1]=mat[*i][*j];
			mat[*i][*j]=memoire;
			(*j)--;
			(*nb_dep)++;
			affichage();
		}else{
			affichage();
			printf("Deplacement invalide \n");
		}
	}else if (dep==1){								//deplacement vers le bas à gauche
		if((*i==8)||(*j==1)){
			affichage();
			printf("Deplacement invalide \n");
		}else if(((mat[*i+1][*j-1]!=2)&&(mat[*i+1][*j-1]!=3))&&!(((mat[*i+1][*j]==2)||(mat[*i+1][*j]==3))&&((mat[*i][*j-1]==2)||(mat[*i][*j-1]==3)))){
			memoire = mat[*i+1][*j-1];
			mat[*i+1][*j-1]=mat[*i][*j];
			mat[*i][*j]=memoire;
			(*i)++;
			(*j)--;
			(*nb_dep)++;
			affichage();
		}else{
			affichage();
			printf("Deplacement invalide \n");
		}
	}else if (dep==3){								//deplacement vers le bas à droite 
		if((*i==8)||(*j==6)){
			affichage();
			printf("Deplacement invalide \n");
		}else if(((mat[*i+1][*j+1]!=2)&&(mat[*i+1][*j+1]!=3))&&!(((mat[*i+1][*j]==2)||(mat[*i+1][*j]==3))&&((mat[*i][*j+1]==2)||(mat[*i][*j+1]==3)))){
			memoire = mat[*i+1][*j+1];
			mat[*i+1][*j+1]=mat[*i][*j];
			mat[*i][*j]=memoire;
			(*i)++;
			(*j)++;
			(*nb_dep)++;
			affichage();
		}else{
			affichage();
			printf("Deplacement invalide \n");
		}
	}else if (dep==7){								//deplacement vers le haut à gauche
		if((*i==1)||(*j==1)){
			affichage();
			printf("Deplacement invalide \n");
		}else if(((mat[*i-1][*j-1]!=2)&&(mat[*i-1][*j-1]!=3))&&!(((mat[*i-1][*j]==2)||(mat[*i-1][*j]==3))&&((mat[*i][*j-1]==2)||(mat[*i][*j-1]==3)))){
			memoire = mat[*i-1][*j-1];
			mat[*i-1][*j-1]=mat[*i][*j];
			mat[*i][*j]=memoire;
			(*i)--;
			(*j)--;
			(*nb_dep)++;
			affichage();
		}else{
			affichage();
			printf("Deplacement invalide \n");
		}
	}else if (dep==9){								//deplacement vers le haut à droite
		if((*i==1)||(*j==6)){
			affichage();
			printf("Deplacement invalide \n");
		}else if(((mat[*i-1][*j+1]!=2)&&(mat[*i-1][*j+1]!=3))&&!(((mat[*i-1][*j]==2)||(mat[*i-1][*j]==3))&&((mat[*i][*j+1]==2)||(mat[*i][*j+1]==3)))){
			memoire = mat[*i-1][*j+1];
			mat[*i-1][*j+1]=mat[*i][*j];
			mat[*i][*j]=memoire;
			(*i)--;
			(*j)++;
			(*nb_dep)++;
			affichage();
		}else{
			affichage();
			printf("Deplacement invalide \n");
		}
	}else if (dep == 5){
		affichage();
	}else{
		affichage();
		printf("Deplacement invalide \n");
	}
}






void deplacement(){
	int i,j,nb_dep,dep;
	nb_dep = 0;
	dep = 0;
	printf("Donnez les coordonnées du personnage a deplacer : ");
	scanf("%i%i",&i,&j);
	while(mat[i][j]!=1){
		printf("Selection invalide \n");
		printf("Donnez les coordonnées du personnage a deplacer : ");
		scanf("%i%i",&i,&j);
	}

	mat[i][j]=8;
	affichage();
	while ((nb_dep<15)&&(dep!=5)){
		
		printf("Selectionnez une direction \n");
		printf("7 : up/left     |           8 : up           | 9 : up/right\n");
		printf("4 : left        | 5 : Arreter le deplacement | 6 : right  \n");
		printf("1 : bottom/left |          2 : down          | 3 : bottom/right \n");
		scanf("%i",&dep);
		deplacementpossible(&i,&j,dep,&nb_dep);
		
	}
	mat[i][j]=1;
	affichage();
}

