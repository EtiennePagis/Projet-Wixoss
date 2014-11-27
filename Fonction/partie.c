#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <assert.h>
#include <time.h>
#include "deplacement.h"
#include "matrice.h"
#define N 9
#define M 7
int mat[N][M];

int partie (void)

{
	init();
	placement();
	affichage();
	deplacement();
}
