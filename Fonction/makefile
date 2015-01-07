Prog : menu.o partie.o deplacement.o matrice.o deplacement_ennemi_test.o voisin.o classes.o
	gcc -o Prog menu.o partie.o deplacement.o matrice.o deplacement_ennemi_test.o voisin.o classes.o
deplacement.o : deplacement.c
	gcc -o deplacement.o -c deplacement.c
deplacement_ennemi_test.o : deplacement_ennemi_test.c
	gcc -o deplacement_ennemi_test.o -c deplacement_ennemi_test.c
matrice.o : matrice.c
	gcc -o matrice.o -c matrice.c
voisin.o : voisin.c
	gcc -o voisin.o -c voisin.c
classes.o : classes.c
	gcc -o classes.o -c classes.c
partie.o : partie.c deplacement.h matrice.h deplacement_ennemi.h voisin.h classes.h
	gcc -o partie.o -c partie.c
menu.o : menu.c partie.h 
	gcc -o menu.o -c menu.c

