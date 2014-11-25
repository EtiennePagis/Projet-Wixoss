#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define N 9
#define M 7
int mat[N][M];

void affichage (){
	
	int i,j;
	
	printf("  ");
	for(i=0 ; i< N;i++){
		for(j = 0; j < M; j++){
			if(i!=0||j!=0){
				printf("|%i",mat[i][j]) ;
			}
		}
		printf("|\n");
	}

}

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
	mat[7][5] = 1;
}

void deplacement(){
	int i,j;
	char dep[10];
	printf("Donnez les coordonnées du personnage a deplacer : ");
	scanf("%i%i",&i,&j);
	while(mat[i][j]!=1){
		printf("Selection invalide\n");
		printf("Donnez les coordonnées du personnage a deplacer : ");
		scanf("%i%i",&i,&j);
	}
	printf("");
	
}

int main(){
	init();
	affichage();
	deplacement();
	affichage();
}
