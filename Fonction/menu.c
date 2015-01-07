#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "partie.h"
#include "classes.h"
#define N 9
#define M 7
int mat[N][M];

//#include "personnage.h"

/**
*\file menu.c
*\brief Projet 
*\author Etienne Pagis Stevy Fouquet Victorien Grude
*\version 0.1
*\date 6 Janvier 2015
*/

/**
*\fn main ()
*\brief lance le jeu
*/
int main () 
{
	srand(time(NULL));
	int choix = 0; 
	int niveau = 1;
	system("clear");
	
	do
	{
		
		printf("\nProjet Wixoss \n");
		//printf("1 - To create or choose your character \n");
		printf("1 - Launch game \n");
		printf("2 - See your squad or modif them \n");
		printf("3 - Change the difficulty \n");
		printf("4 - Quit  \n");
		printf("What is your choice  ? \n");
		scanf("%d",&choix); 
	
		switch(choix) 
		{
			case 1 : system("clear");if(escouade1.nb_perso >= 2){ partie();}else{printf("Vous devez avoir au moins 2 personnage dans votre escouade\n");}; break;
			case 2 : system("clear"); menu_personnage(); break;
			case 3 : system("clear");printf("Veuillez choisir la difficulté :\n1 : Tres facil \n2 : Facil \n3 : Moyen \n4 : Difficil \n5 : Tres Difficil");scanf("%i",&niveau);break;
			case 4 : break;
			default : printf("Your choice is undefined , your must put a number between 1 to 4 \n");
		
		}
	}
	while(choix != 3);
	printf("Good bye you fool\n");
	return (EXIT_SUCCESS);
}
		
		
