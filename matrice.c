#include <stdio.h>
#include <stdlib.h>
#define N 10
#define M 20


int main (){
	char mat[N][M];
	int i,j;
	for(i=0 ; i< N;i++){
		for(j=0; j < M; j++){
			mat[i][j] = '_' ;
		}
	}
	printf("|" );
	for(i=0 ; i< N;i++){
		
		for(j = 0; j < M; j++){
			if(i%2 == 1) {
				printf("%c|",mat[i][j]) ;
			}else {
				printf("| ");
			}
			
		}
		if(i%2 == 1) printf("\n|");
		if(i%2 == 0) printf("\n");
	}// a marche pas

}
