Prog2 : menu.o partie.o deplacement.o matrice.o  
	gcc -o Prog menu.o partie.o deplacement.o matrice.o
deplacement.o : deplacement.c
	gcc -o deplacement.o -c deplacement.c
matrice.o : matrice.c
	gcc -o matrice.o -c matrice.c
partie.o : partie.c deplacement.h matrice.h
	gcc -o partie.o -c partie.c
menu.o : menu.c partie.h 
	gcc -o menu.o -c menu.c
