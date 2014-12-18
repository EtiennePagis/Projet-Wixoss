#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "deplacement.h"
#include "matrice.h"
#include "deplacement_ennemi.h"

int partie (void) 

{
	init();
	placement();
	affichage();
	deplacement_joueur();
	deplacement_ennemi();
	
}
