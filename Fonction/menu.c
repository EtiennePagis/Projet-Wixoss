#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <time.h>
#include "partie.h"
#define N 9
#define M 7
int mat[N][M];

//#include "personnage.h"


int main (void) 
{
	int choix; 
	system("clear");
	
	do
	{
		
		printf("\n Projet Wixoss \n");
		//printf("1 - To create or choose your character \n");
		printf("1 - Launch game \n");
		printf("2 - Quit  \n");
		printf(" What is your choice  ? \n ");
		scanf("%d",&choix); 
	
		switch(choix) 
		{
			case 1 : system("clear"); partie(); break;
			case 2 : break;
			default : printf("Your choice is undefined , your most put a number between 1 to 3 \n");
		
		}
	}
	while(choix != 2);
	printf("Good bye you fool");
	return (EXIT_SUCCESS);
}
		
		
