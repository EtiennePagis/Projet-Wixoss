#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "deplacement.h"
#include "matrice.h"
#include "deplacement_ennemi.h"


/**
*\file partie.c
*\brief Projet 
*\author Etienne Pagis Stevy Fouquet Victorien Grude
*\version 0.1
*\date 6 Janvier 2015
*/

/**
*\fn partie (void) 
*\brief lance les differente fonction utile au deroulement d'une partie
*/
int partie (void) 

{
	init();
	placement();
	affichage();
	deplacement_joueur();
	deplacement_ennemi();
	
}
