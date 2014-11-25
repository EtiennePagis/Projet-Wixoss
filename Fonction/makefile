Prog : main.o deplacement.o  matrice.o
	gcc -o Prog matrice.o deplacement.o main.o
matrice.o : matrice.c
	gcc -o matrice.o -c matrice.c 
deplacement.o : deplacement.c
	gcc -o deplacement.o -c deplacement.c
main.o : main.c deplacement.h matrice.h
	gcc -o main.o -c main.c
