#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
/*Stockage des perso à faire*/
#define MAX_PERSO 6
#define MAX_ENNEMI 10

#define Init_Warrior_Stats {320, 30, 10, 25, 25} 
#define Init_Archer_Stats {230, 25, 25, 20, 20} 
#define Init_Brawler_Stats {260, 50, 5, 20, 15}
#define Init_Mage_Stats {200, 10, 35, 20, 25} 
#define Init_Lancer_Stats {350, 20, 10, 30, 30}
 
#define Init_Knight_Stats {410, 65, 20, 60, 55} 
#define Init_Sniper_Stats {380, 55, 55, 45, 45} 
#define Init_Assassin_Stats {340, 115, 45, 25, 15} 
#define Init_Lord_Stats {500, 75, 45, 45, 35} 
#define Init_General_Stats {700, 30, 10, 85, 75} 
#define Init_White_Mage_Stats {350, 25, 50, 35, 90} 
#define Init_Black_Mage_Stats {350, 35, 90, 25, 50} 
#define Init_Cleric_Stats {400, 30, 70, 50, 50}

/**
*\file classes.c
*\brief Projet_Terra
*\author Etienne Pagis Stevy Fouquet Victorien Grude
*\version 0.1
*\date 19 novembre 2014
*/

/**
* \enum Race
*/
typedef enum {Humain = 1, Elfe , Neko_Girl , Pony} t_race;

/**
* \enum Race ennemie
*/
typedef enum {Bete = 1, Monstre, Golem, Dragon} t_race_ennemie;

/**
* \enum Job
*/
typedef enum {Warrior = 1 , Archer, Brawler, Mage, Lancer, Knight, Sniper, Assassin, Lord, General, White_Mage, Black_Mage, Cleric} t_job;

/**
* \enum Arme
*/
typedef enum {Epee = 1, Arc, Lance, Baton, Poing} t_arme;

/**
* \enum Attribut
*/
typedef enum {Neutre = 0, Feu, Glace, Lumiere , Tenebres ,Soin, Cure} t_attribut;

/**
* \enum Rang
*/
typedef enum {D = 1, C, B, A, S, SS} t_rank;

/**
* \struct Statistiques
*/
typedef struct {float HP ; float attack ; float mattack ; float def ; float mdef;} t_stat;

/**
* \struct Personnage
* \brief Cette structure détermine les informations relatives à un personnage
*/
typedef struct {char* nom; t_race race ; t_job job ; t_arme arme ; t_attribut attribut ; t_rank rank; t_stat stat; int level ;int exp;} t_personnage;

/**
* \struct Ennemi
* \brief Cette structure détermine les informations relatives à un ennemi
*/
typedef struct {char* nom; t_race_ennemie race_ennemie ; t_job job ; t_arme arme; t_attribut attribut ; t_rank rank; t_stat stat; int level; int exp;} t_ennemi;

/**
* \struct Escouade
* \brief Une escouade est composée de plusieurs personnages et possède un nombre de maximal de personnage
*/
typedef struct { t_personnage perso[MAX_PERSO]; int nb_perso;} t_escouade;

/**
* \struct Horde
* \brief Une horde est composée de plusieurs ennemis et possède un nombre de maximal de personnage
*/
typedef struct { t_ennemi ennemi[MAX_ENNEMI]; int nb_ennemi;} t_horde;

/*Faire une sauvegarde des personnages dans un fichier et pouvoir charger l'escouade FAIT*/
/*Faire des skills pour chaque classe*/
/*Faire l'algorithme de degat*/
/*Gerer le "P" pour augmenter les degats*/
/*Faire des tableaux dynamiques FAIT*/
/*Faire la fonction Attaque*/

t_stat Warrior_Stats = Init_Warrior_Stats;
t_stat Archer_Stats = Init_Archer_Stats;
t_stat Brawler_Stats = Init_Brawler_Stats;
t_stat Mage_Stats = Init_Mage_Stats;
t_stat Lancer_Stats = Init_Lancer_Stats;

t_stat Knight_Stats = Init_Knight_Stats;
t_stat Sniper_Stats = Init_Sniper_Stats;
t_stat Assassin_Stats = Init_Assassin_Stats;
t_stat Lord_Stats = Init_Lord_Stats;
t_stat General_Stats = Init_General_Stats;
t_stat White_Mage_Stats = Init_White_Mage_Stats;
t_stat Black_Mage_Stats = Init_Black_Mage_Stats;
t_stat Cleric_Stats = Init_Cleric_Stats;



t_personnage Neko_Brawler_S_defaut ; //= {"Sijya", Neko_Girl, Brawler, Poing, Neutre, S, Init_Brawler_Stats, 1, 15}; 
//t_personnage Neko_Brawler_S_defaut = {"Sijya", Neko_Girl, Brawler, Poing, Neutre, S, {Init_Brawler_Stats.HP, Init_Brawler_Stats.attack, Init_Brawler_Stats.mattack, Init_Brawler_Stats.def, Init_Brawler_Stats.mdef}, 1, 15}; 
t_personnage Elf_Archer_A_defaut ;
t_personnage Human_Lancer_A_defaut ;
t_personnage Pony_Warrior_A_defaut ;

/**
*\fn t_personnage creer_perso(char* nom, t_race race, t_job job, t_arme arme, t_attribut attribut, t_rank rank, t_stat stat, int level ,int exp)
*\brief Permet de créer un personnage en entrant ses caractéristiques en paramètres
*/

t_personnage creer_perso(char* nom, t_race race, t_job job, t_arme arme, t_attribut attribut, t_rank rank, t_stat stat, int level ,int exp){
		
		t_personnage p;
		float coef;
		
		switch(rank){
	
			case D : coef = 0.5; break;
			case C : coef = 0.8; break;
			case B : coef = 1; break;
			case A : coef = 1.1; break;
			case S : coef = 1.3; break;
			case SS : coef = 1.6; break;
		
		}
	
		p.nom = nom; // ATTENTION !!
		//strcpy();
		p.race = race;
		p.job = job;
		p.arme = arme;
		p.attribut = attribut;
		p.rank = rank;
		p.stat.HP = stat.HP*coef;
		p.stat.attack = stat.attack*coef;
		p.stat.mattack = stat.mattack*coef;
		p.stat.def = stat.def*coef;
		p.stat.mdef = stat.mdef*coef;
		p.level = level;
		p.exp = exp;
		
		return(p);
		
}

/**
*\fn t_ennemi creer_ennemi(char* nom, t_race_ennemie race, t_job job, t_arme arme, t_attribut attribut, t_rank rank, t_stat stat, int level ,int exp)
*\brief Permet de créer un ennemi en entrant ses caractéristiques en paramètres
*/

t_ennemi creer_ennemi(char* nom, t_race_ennemie race, t_job job, t_arme arme, t_attribut attribut, t_rank rank, t_stat stat, int level ,int exp){

	t_ennemi e;
	float coef;
		
	switch(rank){
	
		case D : coef = 0.8; break;
		case C : coef = 1; break;
		case B : coef = 1.2; break;
		case A : coef = 1.5; break;
		case S : coef = 1.8; break;
		case SS : coef = 2; break;
		
	}
	
	e.nom = nom;
	e.race_ennemie = race;
	e.job = job;
	e.arme = arme;
	e.attribut = attribut;
	e.rank = rank;
	e.stat.HP = stat.HP*coef;
	e.stat.attack = stat.attack*coef;
	e.stat.mattack = stat.mattack*coef;
	e.stat.def = stat.def*coef;
	e.stat.mdef = stat.mdef*coef;
	e.level = level;
	e.exp = exp;
		
	return(e);
}
		
/**
*\fn t_personnage charger_perso(char* nom, t_race race, t_job job, t_arme arme, t_attribut attribut, t_rank rank, t_stat stat, int level ,int exp)
*\brief Permet de charger un personnage
*/


t_personnage charger_perso(char* nom, t_race race, t_job job, t_arme arme, t_attribut attribut, t_rank rank, t_stat stat, int level ,int exp){
		
		t_personnage p;
		int taille;
				
		taille = strlen(nom);
		printf("%i", taille);
		p.nom = malloc(taille * sizeof(char));

		strcpy(p.nom, nom);
		p.race = race;
		p.job = job;
		p.arme = arme;
		p.attribut = attribut;
		p.rank = rank;
		p.stat.HP = stat.HP;
		p.stat.attack = stat.attack;
		p.stat.mattack = stat.mattack;
		p.stat.def = stat.def;
		p.stat.mdef = stat.mdef;
		p.level = level;
		p.exp = exp;
	
		return(p);
		
}

/**
*\fn void afficher_perso(t_personnage perso)
*\brief Permet d'afficher un personnage déjà créer
*/

void afficher_perso(t_personnage perso){
	
	printf("\n");
	
	printf("Nom : %s", perso.nom);
	
	printf("\n");
	
	switch(perso.race){
	
		case Humain : printf("Race : Human"); break;
		case Elfe : printf("Race : Elf"); break;
		case Neko_Girl : printf("Race : Neko Girl"); break;
		case Pony : printf("Race : Pony"); break;
		
	}
	
	printf("\n\n");
	
	switch(perso.rank){
	
		case D : printf("D-Rank"); break;
		case C : printf("C-Rank"); break;
		case B : printf("B-Rank"); break;
		case A : printf("A-Rang"); break;
		case S : printf("S-Rang"); break;
		case SS : printf("SS-Rang"); break;
	}
	
	printf("\n");
	
	switch(perso.job){
	
		case Warrior : printf("Job : Warrior"); break;
		case Archer : printf("Job : Archer"); break;
		case Brawler : printf("Job : Brawler"); break;
		case Mage : printf("Job : Mage"); break;
		case Lancer : printf("Job : Lancer"); break;
		case Knight : printf("Job : Knight"); break;
		case Sniper : printf("Job : Sniper"); break;
		case Assassin : printf("Job : Assassin"); break;
		case Lord : printf("Job : Lord"); break;
		case General : printf("Job : General"); break;
		case White_Mage : printf("Job : White Mage"); break;
		case Black_Mage : printf("Job : Black Mage"); break;
		case Cleric : printf("Job : Cleric"); break;
	}
	
	printf(" - Lvl %i / %i xp totale", perso.level, perso.exp);
	
	printf("\n");
	
	switch(perso.arme){
	
		case Epee : printf("Weapon : Sword"); break;
		case Arc : printf("Weapon : Bow"); break;
		case Lance : printf("Weapon : Spear"); break;
		case Baton : printf("Weapon : Rod"); break;
		case Poing : printf("Weapon : Unarmed"); break;

	}
	
	printf("\n");
	
	switch(perso.attribut){

		case Neutre : printf("Element : Neutral"); break;
		case Feu : printf("Element : Fire"); break;
		case Glace : printf("Element : Ice"); break;
		case Lumiere : printf("Element : Lightning"); break;
		case Tenebres : printf("Element : Darkness"); break;
		case Soin : printf("Element : Healing"); break;
		case Cure : printf("Element : Remedy"); break;

	}
	
	printf("\n\n");
	
	printf("===============STATISTICS===============");
	
	printf("\n\n");
	
	printf("- HP max :    %.0f\n", perso.stat.HP);
	printf("- Attack :    %.0f\n", perso.stat.attack);
	printf("- Defense :   %.0f\n", perso.stat.def);
	printf("- M-Attack :  %.0f\n", perso.stat.mattack);
	printf("- M-Defense : %.0f\n\n", perso.stat.mdef);	
	

}	

/**
*\fn afficher_ennemi(t_ennemi ennemi)
*\brief Permet d'afficher un ennemi
*/

void afficher_ennemi(t_ennemi ennemi){
	
	printf("\n");
	
	printf("Nom : %s", ennemi.nom);
	
	printf("\n");
	
	switch(ennemi.race_ennemie){
	
		case Bete : printf("Race : Bete"); break;
		case Monstre : printf("Race : Monstre"); break;
		case Golem : printf("Race : Golem"); break;
		case Dragon : printf("Race : Dragon"); break;
		
	}
	
	printf("\n\n");
	
	switch(ennemi.rank){
	
		case D : printf("D-Rank"); break;
		case C : printf("C-Rank"); break;
		case B : printf("B-Rank"); break;
		case A : printf("A-Rang"); break;
		case S : printf("S-Rang"); break;
		case SS : printf("SS-Rang"); break;
	}
	
	printf("\n");
	
	switch(ennemi.job){
	
		case Warrior : printf("Job : Warrior"); break;
		case Archer : printf("Job : Archer"); break;
		case Brawler : printf("Job : Brawler"); break;
		case Mage : printf("Job : Mage"); break;
		case Lancer : printf("Job : Lancer"); break;
		case Knight : printf("Job : Knight"); break;
		case Sniper : printf("Job : Sniper"); break;
		case Assassin : printf("Job : Assassin"); break;
		case Lord : printf("Job : Lord"); break;
		case General : printf("Job : General"); break;
		case White_Mage : printf("Job : White Mage"); break;
		case Black_Mage : printf("Job : Black Mage"); break;
		case Cleric : printf("Job : Cleric"); break;
	}
	
	printf(" - Lvl %i ", ennemi.level);
	
	printf("\n");
	
	switch(ennemi.arme){
	
		case Epee : printf("Weapon : Sword"); break;
		case Arc : printf("Weapon : Bow"); break;
		case Lance : printf("Weapon : Spear"); break;
		case Baton : printf("Weapon : Rod"); break;
		case Poing : printf("Weapon : Unarmed"); break;

	}
	
	printf("\n");
	
	switch(ennemi.attribut){

		case Neutre : printf("Element : Neutral"); break;
		case Feu : printf("Element : Fire"); break;
		case Glace : printf("Element : Ice"); break;
		case Lumiere : printf("Element : Lightning"); break;
		case Tenebres : printf("Element : Darkness"); break;
		case Soin : printf("Element : Healing"); break;
		case Cure : printf("Element : Remedy"); break;

	}
	
	printf("\n\n");
	
	printf("===============STATISTICS===============");
	
	printf("\n\n");
	
	printf("- HP max :    %.0f\n", ennemi.stat.HP);
	printf("- Attack :    %.0f\n", ennemi.stat.attack);
	printf("- Defense :   %.0f\n", ennemi.stat.def);
	printf("- M-Attack :  %.0f\n", ennemi.stat.mattack);
	printf("- M-Defense : %.0f\n\n", ennemi.stat.mdef);	
	

}

/**
*\fn t_personnage generer()
*\brief Permet de générer un personnage aléatoirement puis le crée
*/

t_personnage generer() {

		t_personnage p;
		
		/*Determine le rang du personnage aléatoirement*/
		int rang = rand()%(100) +1;
		
		if(rang <= 60) { p.rank = B; }
		if((rang > 60) && (rang <= 85)) { p.rank = A; }
		if((rang > 85) && (rang <= 95)) { p.rank = S; }
		if((rang > 95) && (rang <= 100)) { p.rank = SS; }
			
		
		/*Determine la race du personnage aléatoirement*/
		int race = rand()%(4) + 1;
		
		switch(race) {
				
				case(1) : p.race = Humain; break;
				case(2) : p.race = Elfe; break;
				case(3) : p.race = Neko_Girl; break;
				case(4) : p.race = Pony; break;				
		}
		
		/*Determine l'arme ainsi que la classe du personnage aléatoirement*/
		int arme = rand()%(5) + 1;
				
		switch(arme) {
				
				case(1) : p.arme = Epee; p.job = Warrior; break;
				case(2) : p.arme = Arc; p.job = Archer; break;
				case(3) : p.arme = Lance; p.job = Lancer; break;
				case(4) : p.arme = Baton; p.job = Mage; break;
				case(5) : p.arme = Poing; p.job = Brawler; break;				
		}
		
		if(p.arme == Baton) {
			
			/*Determine l'attribut d'un personnage Mage aléatoirement ( un Mage ne peut pas etre Neutre )*/
			int attribut = rand()%(6) + 1;
			
			switch(attribut) {
				
				case(1) : p.attribut = Feu; break;
				case(2) : p.attribut = Glace; break;
				case(3) : p.attribut = Lumiere; break;
				case(4) : p.attribut = Tenebres; break;
				case(5) : p.attribut = Soin; break;
				case(6) : p.attribut = Cure; break;		
								
			}
		}
		else {
			
			/*Determine l'attribut d'un personnage autre que Mage aléatoirement ( un personnage autre que Mage ne peut pas etre de l'attribut Soin ou Cure )*/
			int attribut = rand()%(5) + 1;
			
			switch(attribut) {
				
				case(1) : p.attribut = Neutre; break;
				case(2) : p.attribut = Feu; break;
				case(3) : p.attribut = Glace; break;
				case(4) : p.attribut = Lumiere; break;
				case(5) : p.attribut = Tenebres; break;				
			}
		
		}
		
		/*Le niveau et l'xp du personnage crée sont constants*/
		p.level = 10;
		p.exp = 0; 
		
		/*Détermine le nom du personnage en fonction de ses caractéristiques précédentes*/
		if ( p.job == Warrior ) { p.stat = Warrior_Stats; }
		if ( p.job == Archer ) { p.stat = Archer_Stats;	}
		if ( p.job == Lancer ) { p.stat = Lancer_Stats; }
		if ( p.job == Mage ) { p.stat = Mage_Stats; }
		if ( p.job == Brawler ) { p.stat = Brawler_Stats; }
		
		if( p.rank == SS && p.job == Mage && ( p.attribut == Soin || p.attribut == Cure )) { p.nom = "Amimari"; }
		if( p.rank == SS && p.job == Mage && ( p.attribut == Feu || p.attribut == Glace || p.attribut == Lumiere || p.attribut == Tenebres )) { p.nom = "A'misandra"; }
		if( p.rank == SS && p.job == Warrior ) { p.nom = "Gugba"; }
		if( p.rank == SS && p.job == Archer ) { p.nom = "Gaiga"; }
		if( p.rank == SS && p.job == Lancer ) { p.nom = "Samatha"; }
		if( p.rank == SS && p.job == Brawler ) { p.nom = "Yukken"; }
		
		if( p.rank == S && p.job == Mage && ( p.attribut == Soin || p.attribut == Cure )) { p.nom = "Bonna"; }
		if( p.rank == S && p.job == Mage && ( p.attribut == Feu || p.attribut == Glace || p.attribut == Lumiere || p.attribut == Tenebres )) { p.nom = "Puprope"; }
		if( p.rank == S && p.job == Warrior ) { p.nom = "Gatz"; }
		if( p.rank == S && p.job == Archer ) { p.nom = "Alika"; }
		if( p.rank == S && p.job == Lancer ) { p.nom = "Djugan"; }
		if( p.rank == S && p.job == Brawler ) { p.nom = "Zafitte"; }
		
		if( p.rank == A && p.job == Mage && ( p.attribut == Soin || p.attribut == Cure )) { p.nom = "Kana"; }
		if( p.rank == A && p.job == Mage && ( p.attribut == Feu || p.attribut == Glace || p.attribut == Lumiere || p.attribut == Tenebres )) { p.nom = "Daiana"; }
		if( p.rank == A && p.job == Warrior ) { p.nom = "Velraine"; }
		if( p.rank == A && p.job == Archer ) { p.nom = "Pahrl"; }
		if( p.rank == A && p.job == Lancer ) { p.nom = "Samupi"; }
		if( p.rank == A && p.job == Brawler ) { p.nom = "Eileen"; }
		
		if( p.rank == B && p.job == Mage && ( p.attribut == Soin || p.attribut == Cure )) { p.nom = "Kuscah"; }
		if( p.rank == B && p.job == Mage && ( p.attribut == Feu || p.attribut == Glace || p.attribut == Lumiere || p.attribut == Tenebres )) { p.nom = "Ba'gunar"; }
		if( p.rank == B && p.job == Warrior ) { p.nom = "Bahl"; }
		if( p.rank == B && p.job == Archer ) { p.nom = "Grace"; }
		if( p.rank == B && p.job == Lancer ) { p.nom = "Zenzoze"; }
		if( p.rank == B && p.job == Brawler ) { p.nom = "Amazora"; }
		
		/*Le personnage est créé à l'aide de la fonction creer_perso*/		
		p = creer_perso(p.nom, p.race, p.job, p.arme, p.attribut, p.rank, p.stat, p.level ,p.exp);
		
		return(p);		
}

/**
*\fn t_ennemi generer_ennemi(int niveau)
*\brief Permet de générer un ennemi aleatoirement en fonction du niveau
*/

t_ennemi generer_ennemi(int niveau){

		t_ennemi e;
		
		/*Determine le rang de l'ennemi aléatoirement en fonction du niveau*/
		int rang = rand()%(100) +1;
		
		if(niveau == 1){			
						
			if(rang <= 60) { e.rank = D; }
			if((rang > 61) && (rang <= 90)) { e.rank = C; }
			if((rang > 91) && (rang <= 100)) { e.rank = B; }
		}	
		
		if(niveau == 2){			
						
			if(rang <= 60) { e.rank = C; }
			if((rang > 61) && (rang <= 90)) { e.rank = B; }
			if((rang > 91) && (rang <= 100)) { e.rank = A; }
		}
		
		if(niveau == 3){			
						
			if(rang <= 60) { e.rank = B; }
			if((rang > 61) && (rang <= 100)) { e.rank = A; }

		}
		
		if(niveau == 4){			
						
			if(rang <= 60) { e.rank = A; }
			if((rang > 61) && (rang <= 100)) { e.rank = S; }
		}
		
		if( niveau != 1 && niveau != 2 && niveau != 3 && niveau != 4 ){
			
			if(rang <= 15) { e.rank = A; }
			if((rang > 16) && (rang <= 75)) { e.rank = S; }
			if((rang > 76) && (rang <= 100)) { e.rank = SS; }
		}	
		
		/*Determine la race de l'ennemi aléatoirement*/
		int race = rand()%(4) + 1;
		
		switch(race) {
				
				case(1) : e.race_ennemie = Bete; break;
				case(2) : e.race_ennemie = Monstre; break;
				case(3) : e.race_ennemie = Golem; break;
				case(4) : e.race_ennemie = Dragon; break;				
		}
		
		/*Determine l'arme ainsi que la classe de l'ennemi aléatoirement en fonction du rang*/
		int arme = rand()%(5) + 1;
		
		if(e.rank == D || e.rank == C || e.rank == B || e.rank == A){		
			switch(arme) {
				
				case(1) : e.arme = Epee; e.job = Warrior; break;
				case(2) : e.arme = Arc; e.job = Archer; break;
				case(3) : e.arme = Lance; e.job = Lancer; break;
				case(4) : e.arme = Baton; e.job = Mage; break;
				case(5) : e.arme = Poing; e.job = Brawler; break;				
			}
		}
		
		if(e.rank == S || e.rank == SS ){
			switch(arme) {
							
				case(1) : e.arme = Epee; e.job = Knight; break;
				case(2) : e.arme = Arc; e.job = Sniper; break;
				case(3) : e.arme = Lance; e.job = General; break;
				case(4) : e.arme = Baton; e.job = Black_Mage; break;
				case(5) : e.arme = Poing; e.job = Assassin; break;			
			}
		}	
		
		if(e.arme == Baton) {
			
			/*Determine l'attribut d'un personnage Mage aléatoirement ( un Mage ne peut pas etre Neutre )*/
			int attribut = rand()%(6) + 1;
			
			switch(attribut) {
				
				case(1) : e.attribut = Feu; break;
				case(2) : e.attribut = Glace; break;
				case(3) : e.attribut = Lumiere; break;
				case(4) : e.attribut = Tenebres; break;
				case(5) : e.attribut = Soin; break;
				case(6) : e.attribut = Cure; break;		
								
			}
		}
		else {
			
			/*Determine l'attribut d'un personnage autre que Mage aléatoirement ( un personnage autre que Mage ne peut pas etre de l'attribut Soin ou Cure )*/
			int attribut = rand()%(5) + 1;
			
			switch(attribut) {
				
				case(1) : e.attribut = Neutre; break;
				case(2) : e.attribut = Feu; break;
				case(3) : e.attribut = Glace; break;
				case(4) : e.attribut = Lumiere; break;
				case(5) : e.attribut = Tenebres; break;				
			}
		
		}
		
		/*Le niveau et l'xp du personnage crée sont constants*/
		int level;
		
		if ( niveau == 1 ){
			level = rand()%(5) + 5;
			e.level = level;
			e.exp = 50*level;
		}	
		
		if ( niveau == 2 ){
			level = rand()%(10) + 10;
			e.level = level;
			e.exp = 50*level;
		}
		
		if ( niveau == 3 ){
			level = rand()%(15) + 15;
			e.level = level;
			e.exp = 60*level;
		}
		
		if ( niveau == 4 ){
			level = rand()%(15) + 25;
			e.level = level;
			e.exp = 60*level;
		}
		
		if ( niveau != 1 && niveau != 2 && niveau != 3 && niveau != 4 ){
			level = rand()%(15) + 35;
			e.level = level;
			e.exp = 80*level;
		}
			
		
		/*Détermine les stats de l'ennemi grâce à sa classe*/
		if ( e.job == Warrior ) { e.stat = Warrior_Stats; }
		if ( e.job == Archer ) { e.stat = Archer_Stats;	}
		if ( e.job == Lancer ) { e.stat = Lancer_Stats; }
		if ( e.job == Mage ) { e.stat = Mage_Stats; }
		if ( e.job == Brawler ) { e.stat = Brawler_Stats; }
		
		if ( e.job == Knight ) { e.stat = Knight_Stats; }
		if ( e.job == Sniper ) { e.stat = Sniper_Stats;	}
		if ( e.job == General ) { e.stat = General_Stats; }
		if ( e.job == Black_Mage ) { e.stat = Black_Mage_Stats; }
		if ( e.job == Assassin ) { e.stat = Assassin_Stats; }
		
		/*Ameliore les stats de l'ennemi en fonction de fonction de son niveau*/
		
		int amelioration = e.level/5 + 1;
		
		if (e.level > 35 ) { amelioration = e.level/5 - 3; }
		
		e.stat.HP = e.stat.HP*amelioration;
		e.stat.attack = e.stat.attack*amelioration;
		e.stat.mattack = e.stat.mattack*amelioration;
		e.stat.def = e.stat.def*amelioration;
		e.stat.mdef = e.stat.mdef*amelioration;	
		
		/*Détermine le nom de l'ennemi en fonction de sa race*/
		if( e.race_ennemie == Bete ) { e.nom = "Bete"; }
		if( e.race_ennemie == Monstre ) { e.nom = "Monstre"; }
		if( e.race_ennemie == Golem ) { e.nom = "Golem"; }
		if( e.race_ennemie == Dragon ) { e.nom = "Dragon"; }		
			
		/*Le personnage est créé à l'aide de la fonction creer_perso*/		
		e = creer_ennemi(e.nom, e.race_ennemie, e.job, e.arme, e.attribut, e.rank, e.stat, e.level ,e.exp);
		
		return(e);		
}	

	

/**
*\fn t_personnage montee_statistiques ( t_personnage p )
*\brief Permet d'augmenter les statistiques d'un personnage si il gagne un niveau
*/

t_personnage montee_statistiques ( t_personnage p ){
	
	int bonus_HP;
	int bonus_attack;
	int bonus_def;
	int bonus_mattack;
	int bonus_mdef;
	
	if(p.rank == B) {
		
		bonus_HP = rand()%(25) + 10;
		bonus_attack = rand()%(3) + 1;
		bonus_mattack = rand()%(3) + 1;
		bonus_def = rand()%(3) + 1;
		bonus_mdef = rand()%(3) + 1; 
	}
	
	if(p.rank == A) {
		
		bonus_HP = rand()%(35) + 20;
		bonus_attack = rand()%(4) + 2;
		bonus_mattack = rand()%(4) + 2;
		bonus_def = rand()%(4) + 2;
		bonus_mdef = rand()%(4) + 2; 
	}
	
	if(p.rank == S) {
		
		bonus_HP = rand()%(50) + 25;
		bonus_attack = rand()%(5) + 3;
		bonus_mattack = rand()%(5) + 3;
		bonus_def = rand()%(5) + 3;
		bonus_mdef = rand()%(5) + 3; 
	}
	
	if(p.rank == SS) {
		
		bonus_HP = rand()%(75) + 35;
		bonus_attack = rand()%(7) + 4;
		bonus_mattack = rand()%(7) + 4;
		bonus_def = rand()%(7) + 4;
		bonus_mdef = rand()%(7) + 4; 
	}
	
	
	if(p.job == Warrior && p.rank == B) {
		p.stat.HP = p.stat.HP + bonus_HP + 5; 
		p.stat.attack = p.stat.attack + bonus_attack + 1;
		p.stat.mattack = p.stat.mattack + bonus_mattack - 1;
		p.stat.def = p.stat.def + bonus_def;
		p.stat.mdef = p.stat.mdef + bonus_mdef;		
	}
	
	if(p.job == Warrior && p.rank == A) {
		p.stat.HP = p.stat.HP + bonus_HP + 10; 
		p.stat.attack = p.stat.attack + bonus_attack + 2;
		p.stat.mattack = p.stat.mattack + bonus_mattack - 2;
		p.stat.def = p.stat.def + bonus_def;
		p.stat.mdef = p.stat.mdef + bonus_mdef;		
	}
	
	if(p.job == Warrior && p.rank == S) {
		p.stat.HP = p.stat.HP + bonus_HP + 12; 
		p.stat.attack = p.stat.attack + bonus_attack + 3;
		p.stat.mattack = p.stat.mattack + bonus_mattack - 3;
		p.stat.def = p.stat.def + bonus_def;
		p.stat.mdef = p.stat.mdef + bonus_mdef;		
	}
	
	if(p.job == Warrior && p.rank == SS) {
		p.stat.HP = p.stat.HP + bonus_HP + 20; 
		p.stat.attack = p.stat.attack + bonus_attack + 4;
		p.stat.mattack = p.stat.mattack + bonus_mattack - 4;
		p.stat.def = p.stat.def + bonus_def;
		p.stat.mdef = p.stat.mdef + bonus_mdef;		
	}
	
	if(p.job == Archer && p.rank == B) {
		
		p.stat.HP = p.stat.HP + bonus_HP + 2; 
		p.stat.attack = p.stat.attack + bonus_attack;
		p.stat.mattack = p.stat.mattack + bonus_mattack;
		p.stat.def = p.stat.def + bonus_def - 1;
		p.stat.mdef = p.stat.mdef + bonus_mdef - 1;
	}
	
	if(p.job == Archer && p.rank == A) {
		
		p.stat.HP = p.stat.HP + bonus_HP + 5; 
		p.stat.attack = p.stat.attack + bonus_attack + 1;
		p.stat.mattack = p.stat.mattack + bonus_mattack + 1;
		p.stat.def = p.stat.def + bonus_def - 1;
		p.stat.mdef = p.stat.mdef + bonus_mdef - 1;
	}
	
	if(p.job == Archer && p.rank == S) {
		
		p.stat.HP = p.stat.HP + bonus_HP + 7; 
		p.stat.attack = p.stat.attack + bonus_attack + 2;
		p.stat.mattack = p.stat.mattack + bonus_mattack + 2;
		p.stat.def = p.stat.def + bonus_def - 2;
		p.stat.mdef = p.stat.mdef + bonus_mdef - 2;
	}
	
	if(p.job == Archer && p.rank == SS) {
		
		p.stat.HP = p.stat.HP + bonus_HP + 10; 
		p.stat.attack = p.stat.attack + bonus_attack + 3;
		p.stat.mattack = p.stat.mattack + bonus_mattack + 3;
		p.stat.def = p.stat.def + bonus_def - 3;
		p.stat.mdef = p.stat.mdef + bonus_mdef - 3;
	}
	
	if(p.job == Lancer && p.rank == B) {
		
		p.stat.HP = p.stat.HP + bonus_HP + 7; 
		p.stat.attack = p.stat.attack + bonus_attack;
		p.stat.mattack = p.stat.mattack + bonus_mattack - 1;
		p.stat.def = p.stat.def + bonus_def + 1;
		p.stat.mdef = p.stat.mdef + bonus_mdef + 1;
	}
	
	if(p.job == Lancer && p.rank == A) {
		
		p.stat.HP = p.stat.HP + bonus_HP + 14; 
		p.stat.attack = p.stat.attack + bonus_attack;
		p.stat.mattack = p.stat.mattack + bonus_mattack - 1;
		p.stat.def = p.stat.def + bonus_def + 2;
		p.stat.mdef = p.stat.mdef + bonus_mdef + 2;
	}
	
	if(p.job == Lancer && p.rank == S) {
		
		p.stat.HP = p.stat.HP + bonus_HP + 17; 
		p.stat.attack = p.stat.attack + bonus_attack;
		p.stat.mattack = p.stat.mattack + bonus_mattack - 2;
		p.stat.def = p.stat.def + bonus_def + 3;
		p.stat.mdef = p.stat.mdef + bonus_mdef + 3;
	}
	
	if(p.job == Lancer && p.rank == SS) {
		
		p.stat.HP = p.stat.HP + bonus_HP + 24; 
		p.stat.attack = p.stat.attack + bonus_attack;
		p.stat.mattack = p.stat.mattack + bonus_mattack - 3;
		p.stat.def = p.stat.def + bonus_def + 4;
		p.stat.mdef = p.stat.mdef + bonus_mdef + 4;
	}
	
	if(p.job == Mage && p.rank == B) {
		
		p.stat.HP = p.stat.HP + bonus_HP; 
		p.stat.attack = p.stat.attack + bonus_attack - 1;
		p.stat.mattack = p.stat.mattack + bonus_mattack + 1;
		p.stat.def = p.stat.def + bonus_def;
		p.stat.mdef = p.stat.mdef + bonus_mdef + 1;
	
	}
	
	if(p.job == Mage && p.rank == A) {
		
		p.stat.HP = p.stat.HP + bonus_HP + 2; 
		p.stat.attack = p.stat.attack + bonus_attack - 2;
		p.stat.mattack = p.stat.mattack + bonus_mattack + 2;
		p.stat.def = p.stat.def + bonus_def;
		p.stat.mdef = p.stat.mdef + bonus_mdef + 1;
	
	}
	
	if(p.job == Mage && p.rank == S) {
		
		p.stat.HP = p.stat.HP + bonus_HP + 4; 
		p.stat.attack = p.stat.attack + bonus_attack - 3;
		p.stat.mattack = p.stat.mattack + bonus_mattack + 3;
		p.stat.def = p.stat.def + bonus_def;
		p.stat.mdef = p.stat.mdef + bonus_mdef + 2;
	
	}
	
	if(p.job == Mage && p.rank == SS) {
		
		p.stat.HP = p.stat.HP + bonus_HP + 10; 
		p.stat.attack = p.stat.attack + bonus_attack - 4;
		p.stat.mattack = p.stat.mattack + bonus_mattack + 4;
		p.stat.def = p.stat.def + bonus_def;
		p.stat.mdef = p.stat.mdef + bonus_mdef + 3;
	
	}
	
	if(p.job == Brawler && p.rank == B) {
		
		p.stat.HP = p.stat.HP + bonus_HP + 3; 
		p.stat.attack = p.stat.attack + bonus_attack + 2;
		p.stat.mattack = p.stat.mattack + bonus_mattack - 1;
		p.stat.def = p.stat.def + bonus_def;
		p.stat.mdef = p.stat.mdef + bonus_mdef - 1;
	}
	
	if(p.job == Brawler && p.rank == A) {
		
		p.stat.HP = p.stat.HP + bonus_HP + 6; 
		p.stat.attack = p.stat.attack + bonus_attack + 3;
		p.stat.mattack = p.stat.mattack + bonus_mattack - 2;
		p.stat.def = p.stat.def + bonus_def;
		p.stat.mdef = p.stat.mdef + bonus_mdef - 2;
	}
	
	if(p.job == Brawler && p.rank == S) {
		
		p.stat.HP = p.stat.HP + bonus_HP + 9; 
		p.stat.attack = p.stat.attack + bonus_attack + 4;
		p.stat.mattack = p.stat.mattack + bonus_mattack - 3;
		p.stat.def = p.stat.def + bonus_def;
		p.stat.mdef = p.stat.mdef + bonus_mdef - 3;
	}
	
	if(p.job == Brawler && p.rank == SS) {
		
		p.stat.HP = p.stat.HP + bonus_HP + 12; 
		p.stat.attack = p.stat.attack + bonus_attack + 5;
		p.stat.mattack = p.stat.mattack + bonus_mattack - 4;
		p.stat.def = p.stat.def + bonus_def;
		p.stat.mdef = p.stat.mdef + bonus_mdef - 4;
	}
	
	if(p.job == Knight && p.rank == B) {
		
		p.stat.HP = p.stat.HP + bonus_HP + 12; 
		p.stat.attack = p.stat.attack + bonus_attack + 2;
		p.stat.mattack = p.stat.mattack + bonus_mattack - 1;
		p.stat.def = p.stat.def + bonus_def + 2;
		p.stat.mdef = p.stat.mdef + bonus_mdef + 2;
	}
	
	if(p.job == Knight && p.rank == A) {
		
		p.stat.HP = p.stat.HP + bonus_HP + 24; 
		p.stat.attack = p.stat.attack + bonus_attack + 2;
		p.stat.mattack = p.stat.mattack + bonus_mattack - 2;
		p.stat.def = p.stat.def + bonus_def + 3;
		p.stat.mdef = p.stat.mdef + bonus_mdef + 3;
	}
	
	if(p.job == Knight && p.rank == S) {
		
		p.stat.HP = p.stat.HP + bonus_HP + 30; 
		p.stat.attack = p.stat.attack + bonus_attack + 3;
		p.stat.mattack = p.stat.mattack + bonus_mattack - 3;
		p.stat.def = p.stat.def + bonus_def + 4;
		p.stat.mdef = p.stat.mdef + bonus_mdef + 4;
	}
	
	if(p.job == Knight && p.rank == SS) {
		
		p.stat.HP = p.stat.HP + bonus_HP + 35; 
		p.stat.attack = p.stat.attack + bonus_attack + 4;
		p.stat.mattack = p.stat.mattack + bonus_mattack - 4;
		p.stat.def = p.stat.def + bonus_def + 5;
		p.stat.mdef = p.stat.mdef + bonus_mdef + 5;
	}
	
	if(p.job == Sniper && p.rank == B) {
		
		p.stat.HP = p.stat.HP + bonus_HP + 10; 
		p.stat.attack = p.stat.attack + bonus_attack + 2;
		p.stat.mattack = p.stat.mattack + bonus_mattack + 2;
		p.stat.def = p.stat.def + bonus_def;
		p.stat.mdef = p.stat.mdef + bonus_mdef;
	
	}
	
	if(p.job == Sniper && p.rank == A) {
		
		p.stat.HP = p.stat.HP + bonus_HP + 20; 
		p.stat.attack = p.stat.attack + bonus_attack + 2;
		p.stat.mattack = p.stat.mattack + bonus_mattack + 2;
		p.stat.def = p.stat.def + bonus_def;
		p.stat.mdef = p.stat.mdef + bonus_mdef;
	
	}
	
	if(p.job == Sniper && p.rank == S) {
		
		p.stat.HP = p.stat.HP + bonus_HP + 25; 
		p.stat.attack = p.stat.attack + bonus_attack + 3;
		p.stat.mattack = p.stat.mattack + bonus_mattack + 3;
		p.stat.def = p.stat.def + bonus_def;
		p.stat.mdef = p.stat.mdef + bonus_mdef;
	
	}
	
	if(p.job == Sniper && p.rank == SS) {
		
		p.stat.HP = p.stat.HP + bonus_HP + 35; 
		p.stat.attack = p.stat.attack + bonus_attack + 3;
		p.stat.mattack = p.stat.mattack + bonus_mattack + 3;
		p.stat.def = p.stat.def + bonus_def;
		p.stat.mdef = p.stat.mdef + bonus_mdef;
	
	}
	
	if(p.job == Assassin && p.rank == B ) {
		
		p.stat.HP = p.stat.HP + bonus_HP + 6; 
		p.stat.attack = p.stat.attack + bonus_attack + 4;
		p.stat.mattack = p.stat.mattack + bonus_mattack;
		p.stat.def = p.stat.def + bonus_def - 1;
		p.stat.mdef = p.stat.mdef + bonus_mdef - 1;
	
	}
	
	if(p.job == Assassin && p.rank == A ) {
		
		p.stat.HP = p.stat.HP + bonus_HP + 12; 
		p.stat.attack = p.stat.attack + bonus_attack + 5;
		p.stat.mattack = p.stat.mattack + bonus_mattack;
		p.stat.def = p.stat.def + bonus_def - 2;
		p.stat.mdef = p.stat.mdef + bonus_mdef - 2;
	
	}
	
	if(p.job == Assassin && p.rank == S ) {
		
		p.stat.HP = p.stat.HP + bonus_HP + 14; 
		p.stat.attack = p.stat.attack + bonus_attack + 6;
		p.stat.mattack = p.stat.mattack + bonus_mattack;
		p.stat.def = p.stat.def + bonus_def - 3;
		p.stat.mdef = p.stat.mdef + bonus_mdef - 3;
	
	}
	
	if(p.job == Assassin && p.rank == SS ) {
		
		p.stat.HP = p.stat.HP + bonus_HP + 17; 
		p.stat.attack = p.stat.attack + bonus_attack + 7;
		p.stat.mattack = p.stat.mattack + bonus_mattack;
		p.stat.def = p.stat.def + bonus_def - 4;
		p.stat.mdef = p.stat.mdef + bonus_mdef - 4;
	
	}
	
	if(p.job == Lord && p.rank == B) {
		
		p.stat.HP = p.stat.HP + bonus_HP + 14; 
		p.stat.attack = p.stat.attack + bonus_attack + 3;
		p.stat.mattack = p.stat.mattack + bonus_mattack;
		p.stat.def = p.stat.def + bonus_def;
		p.stat.mdef = p.stat.mdef + bonus_mdef - 1;
	
	}
	
	if(p.job == Lord && p.rank == A) {
		
		p.stat.HP = p.stat.HP + bonus_HP + 28; 
		p.stat.attack = p.stat.attack + bonus_attack + 4;
		p.stat.mattack = p.stat.mattack + bonus_mattack;
		p.stat.def = p.stat.def + bonus_def;
		p.stat.mdef = p.stat.mdef + bonus_mdef - 1;
	
	}
	
	if(p.job == Lord && p.rank == S) {
		
		p.stat.HP = p.stat.HP + bonus_HP + 35; 
		p.stat.attack = p.stat.attack + bonus_attack + 5;
		p.stat.mattack = p.stat.mattack + bonus_mattack;
		p.stat.def = p.stat.def + bonus_def;
		p.stat.mdef = p.stat.mdef + bonus_mdef - 2;
	
	}
	
	if(p.job == Lord && p.rank == SS) {
		
		p.stat.HP = p.stat.HP + bonus_HP + 42; 
		p.stat.attack = p.stat.attack + bonus_attack + 6;
		p.stat.mattack = p.stat.mattack + bonus_mattack;
		p.stat.def = p.stat.def + bonus_def;
		p.stat.mdef = p.stat.mdef + bonus_mdef - 2;
	
	}
	
	if(p.job == General && p.rank == B) {
		
		p.stat.HP = p.stat.HP + bonus_HP + 20; 
		p.stat.attack = p.stat.attack + bonus_attack - 1;
		p.stat.mattack = p.stat.mattack + bonus_mattack - 1;
		p.stat.def = p.stat.def + bonus_def + 3;
		p.stat.mdef = p.stat.mdef + bonus_mdef + 3;
	
	}
	
	if(p.job == General && p.rank == A) {
		
		p.stat.HP = p.stat.HP + bonus_HP + 40; 
		p.stat.attack = p.stat.attack + bonus_attack - 2;
		p.stat.mattack = p.stat.mattack + bonus_mattack - 2;
		p.stat.def = p.stat.def + bonus_def + 4;
		p.stat.mdef = p.stat.mdef + bonus_mdef + 4;
	
	}
	
	if(p.job == General && p.rank == S) {
		
		p.stat.HP = p.stat.HP + bonus_HP + 60; 
		p.stat.attack = p.stat.attack + bonus_attack - 3;
		p.stat.mattack = p.stat.mattack + bonus_mattack - 3;
		p.stat.def = p.stat.def + bonus_def + 5;
		p.stat.mdef = p.stat.mdef + bonus_mdef + 5;
	
	}
	
	if(p.job == General && p.rank == SS) {
		
		p.stat.HP = p.stat.HP + bonus_HP + 90; 
		p.stat.attack = p.stat.attack + bonus_attack - 4;
		p.stat.mattack = p.stat.mattack + bonus_mattack - 4;
		p.stat.def = p.stat.def + bonus_def + 6;
		p.stat.mdef = p.stat.mdef + bonus_mdef + 6;
	
	}
	
	if(p.job == White_Mage && p.rank == B) {
		
		p.stat.HP = p.stat.HP + bonus_HP + 7; 
		p.stat.attack = p.stat.attack + bonus_attack - 1;
		p.stat.mattack = p.stat.mattack + bonus_mattack + 2;
		p.stat.def = p.stat.def + bonus_def;
		p.stat.mdef = p.stat.mdef + bonus_mdef + 4;
	
	}
	
	if(p.job == White_Mage && p.rank == A) {
		
		p.stat.HP = p.stat.HP + bonus_HP + 14; 
		p.stat.attack = p.stat.attack + bonus_attack - 2;
		p.stat.mattack = p.stat.mattack + bonus_mattack + 3;
		p.stat.def = p.stat.def + bonus_def;
		p.stat.mdef = p.stat.mdef + bonus_mdef + 5;
	
	}
	
	if(p.job == White_Mage && p.rank == S) {
		
		p.stat.HP = p.stat.HP + bonus_HP + 16; 
		p.stat.attack = p.stat.attack + bonus_attack - 3;
		p.stat.mattack = p.stat.mattack + bonus_mattack + 4;
		p.stat.def = p.stat.def + bonus_def;
		p.stat.mdef = p.stat.mdef + bonus_mdef + 6;
	
	}
	
	if(p.job == White_Mage && p.rank == SS) {
		
		p.stat.HP = p.stat.HP + bonus_HP + 18; 
		p.stat.attack = p.stat.attack + bonus_attack - 4;
		p.stat.mattack = p.stat.mattack + bonus_mattack + 5;
		p.stat.def = p.stat.def + bonus_def;
		p.stat.mdef = p.stat.mdef + bonus_mdef + 7;
	
	}
	
	if(p.job == Black_Mage && p.rank == B) {
		
		p.stat.HP = p.stat.HP + bonus_HP + 7; 
		p.stat.attack = p.stat.attack + bonus_attack;
		p.stat.mattack = p.stat.mattack + bonus_mattack + 4;
		p.stat.def = p.stat.def + bonus_def - 1;
		p.stat.mdef = p.stat.mdef + bonus_mdef + 2;
	
	}
	
	if(p.job == Black_Mage && p.rank == A) {
		
		p.stat.HP = p.stat.HP + bonus_HP + 14; 
		p.stat.attack = p.stat.attack + bonus_attack;
		p.stat.mattack = p.stat.mattack + bonus_mattack + 5;
		p.stat.def = p.stat.def + bonus_def - 2;
		p.stat.mdef = p.stat.mdef + bonus_mdef + 3;
	
	}
	
	if(p.job == Black_Mage && p.rank == S) {
		
		p.stat.HP = p.stat.HP + bonus_HP + 16; 
		p.stat.attack = p.stat.attack + bonus_attack;
		p.stat.mattack = p.stat.mattack + bonus_mattack + 6;
		p.stat.def = p.stat.def + bonus_def - 3;
		p.stat.mdef = p.stat.mdef + bonus_mdef + 4;
	
	}
	
	if(p.job == Black_Mage && p.rank == SS) {
		
		p.stat.HP = p.stat.HP + bonus_HP + 18; 
		p.stat.attack = p.stat.attack + bonus_attack;
		p.stat.mattack = p.stat.mattack + bonus_mattack + 7;
		p.stat.def = p.stat.def + bonus_def - 4;
		p.stat.mdef = p.stat.mdef + bonus_mdef + 5;
	
	}
	
	if(p.job == Cleric && p.rank == B) {
		
		p.stat.HP = p.stat.HP + bonus_HP + 10; 
		p.stat.attack = p.stat.attack + bonus_attack - 1;
		p.stat.mattack = p.stat.mattack + bonus_mattack + 3;
		p.stat.def = p.stat.def + bonus_def + 2;
		p.stat.mdef = p.stat.mdef + bonus_mdef + 2;
	
	}
	
	if(p.job == Cleric && p.rank == A) {
		
		p.stat.HP = p.stat.HP + bonus_HP + 20; 
		p.stat.attack = p.stat.attack + bonus_attack - 2;
		p.stat.mattack = p.stat.mattack + bonus_mattack + 3;
		p.stat.def = p.stat.def + bonus_def + 2;
		p.stat.mdef = p.stat.mdef + bonus_mdef + 2;
	
	}
	
	if(p.job == Cleric && p.rank == S) {
		
		p.stat.HP = p.stat.HP + bonus_HP + 25; 
		p.stat.attack = p.stat.attack + bonus_attack - 3;
		p.stat.mattack = p.stat.mattack + bonus_mattack + 4;
		p.stat.def = p.stat.def + bonus_def + 3;
		p.stat.mdef = p.stat.mdef + bonus_mdef + 3;
	
	}
	
	if(p.job == Cleric && p.rank == SS) {
		
		p.stat.HP = p.stat.HP + bonus_HP + 35; 
		p.stat.attack = p.stat.attack + bonus_attack - 4;
		p.stat.mattack = p.stat.mattack + bonus_mattack + 5;
		p.stat.def = p.stat.def + bonus_def + 3;
		p.stat.mdef = p.stat.mdef + bonus_mdef + 3;
	
	}
	
	return(p);
}	

/**
*\fn t_personnage montee_level ( t_personnage p )
*\brief Permet d'augmenter le niveau d'un personnage si il possède l'xp nécessaire
*/

t_personnage montee_level ( t_personnage p ){
	
	int chain = 1;
	int level_max = 70;
    int temp_level = p.level;
	
	while (chain && p.level < level_max) {
		if( p.rank == B ) {
		
			if ( p.exp > (0.8 * p.level * p.level * p.level)){
			
				p.level = p.level + 1;
				p = montee_statistiques(p);		
			
			}
			else { chain = 0; }
		
		}
	
		if( p.rank == A ) {
			
			if ( p.exp > (p.level * p.level * p.level)){
			
				p.level = p.level + 1;
				p = montee_statistiques(p);			
			
			}
			else { chain = 0; }
	
		}
	
		if( p.rank == S ) {
		
			if ( p.exp > (1.2 * p.level * p.level * p.level - 15 * p.level * p.level + 100 * p.level -140 )){
			
				p.level = p.level + 1;
				p = montee_statistiques(p);			
			
			}
			else { chain = 0; }
	
		}
	
		if( p.rank == SS ) {
		
			if ( p.exp > (1.25 * p.level * p.level * p.level)){
			
				p.level = p.level + 1;
				p = montee_statistiques(p);			
			
			}
			else { chain = 0; }
	
		}
	}
    
	if(temp_level != p.level){ printf("\n%s est monté(e) level %i !", p.nom, p.level); }
	return(p);
	
	
}

/**
*\fn t_escouade montee_level_escouade ( t_escouade escouade )
*\brief Permet d'augmenter le niveau des personnages d'une escouade si ils possèdent l'xp nécessaire en faisant appel à une autre fonction
*/	

t_escouade montee_level_escouade ( t_escouade escouade ){
    
    int i;
    
    for( i = 0 ; i < escouade.nb_perso ; i++ ){
        
       escouade.perso[i] = montee_level(escouade.perso[i]);
        
    }
    
    return(escouade);
    
}

/**
*\fn t_escouade xp(t_escouade escouade, float xp)
*\brief Permet de distribuer l'xp equitablement entre chaque personnages de l'escouade
*/	

t_escouade xp(t_escouade escouade, float xp){
	
    int i;
    xp = xp / escouade.nb_perso;
    
    for( i = 0 ; i < escouade.nb_perso ; i++ ){
        
        escouade.perso[i].exp = escouade.perso[i].exp + xp;
    }
	
    printf("\nVos personnages ont tous gagné %.0f xp durant ce combat.", xp);
    
    return(escouade);
	
}	

/**
*\fn void afficher_escouade (t_escouade escouade)
*\brief Permet d'afficher tout les personnages d'une escouade
*/

void afficher_escouade (t_escouade escouade) {
    
    int i;
    printf("\nVoici le résumé des personnages présents dans votre escouade :\n\n");
    for( i = 0 ; i < escouade.nb_perso ; i++ ){
        afficher_perso(escouade.perso[i]);

    }
    printf("Il y a %i personnages dans votre escouade.\n\n", escouade.nb_perso);
}

/**
*\fn t_escouade recrutement ( t_escouade escouade )
*\brief Permet de recruter un personnage en faisant appel à une autre fonction puis l'ajoute à l'escouade
*/

t_escouade recrutement ( t_escouade escouade ) {
    
    int recrutement = 0;
    t_personnage new_perso;
    
    printf("\nSouhaitez vous recruter un personnage ? 0 / 1 : ");
    scanf("%i", &recrutement);
    
    if (recrutement == 1 && (escouade.nb_perso < MAX_PERSO)) {
        
        new_perso = generer();
        escouade.perso[escouade.nb_perso] = new_perso;
        escouade.nb_perso++;
    }
    
    return(escouade);
    
}

/**
*\fn void sauvegarde_escouade( t_escouade escouade )
*\brief Permet de sauvegarder son escouade
*/

void sauvegarde_escouade( t_escouade escouade ) {
    
    FILE* save;
    save = fopen("sauvegarde.txt","w");
    
    int i;
    
    for( i = 0 ; i < escouade.nb_perso ; i++ ){
        
        fprintf(save,"%s %i %i %i %i %i %.0f %.0f %.0f %.0f %.0f %i %i\n", escouade.perso[i].nom, escouade.perso[i].race, escouade.perso[i].job, escouade.perso[i].arme, escouade.perso[i].attribut, escouade.perso[i].rank, escouade.perso[i].stat.HP, escouade.perso[i].stat.attack, escouade.perso[i].stat.mattack, escouade.perso[i].stat.def, escouade.perso[i].stat.mdef, escouade.perso[i].level, escouade.perso[i].exp );
		
    }
  
	fclose(save);
    
}



/**
*\fn t_escouade charger_escouade ( t_escouade escouade )
*\brief Permet de charger son escouade a partir d'un fichier existant
*/

t_escouade charger_escouade ( t_escouade escouade ){

	FILE* save;
    save = fopen("sauvegarde.txt","r");
    
    char* nom = malloc(20 * sizeof(char));
    int race, job, arme, attribut, rank, level, exp;
    t_stat stat;
    
    int i;

    for( i = 0 ; (!feof(save)) && i <= MAX_PERSO; i++ ){
		
		fscanf(save,"%s %i %i %i %i %i %f %f %f %f %f %i %i", nom, &race, &job, &arme, &attribut, &rank, &(stat.HP), &(stat.attack), &(stat.mattack), &(stat.def), &(stat.mdef), &level, &exp);
		escouade.perso[i] = charger_perso(nom, race, job, arme, attribut, rank, stat, level, exp );
	}
	escouade.nb_perso = i-1;
	if (escouade.nb_perso < 0) escouade.nb_perso = 0;
	free(nom);
	return(escouade);	
}	

int main(){
	
	t_escouade escouade1;
	t_horde horde;

	escouade1.nb_perso = 0;
	horde.nb_ennemi = 0;
	srand(time(NULL));
	
	horde.ennemi[horde.nb_ennemi] = generer_ennemi(5);
	horde.nb_ennemi++;
	
	afficher_ennemi(horde.ennemi[0]);
	
	/*Neko_Brawler_S_defaut = creer_perso("Sijya", Neko_Girl, Brawler, Poing, Neutre, S, Brawler_Stats, 10,0 );
    
    escouade1.perso[escouade1.nb_perso] = Neko_Brawler_S_defaut;
    escouade1.nb_perso++;
    
    escouade1 = recrutement(escouade1);*/
    
    //random = generer();
	//afficher_perso(random);
	
	/*Elf_Archer_A_defaut = creer_perso("Elf", Elfe, Archer, Arc, Neutre, A, Archer_Stats, 1, 0);
	Human_Lancer_A_defaut = creer_perso("Human", Humain, Lancer, Lance, Neutre, A, Lancer_Stats, 1, 0);
	Pony_Warrior_A_defaut = creer_perso("AppleJack", Pony, Warrior, Epee, Neutre, A, Warrior_Stats, 1, 0);*/
	
	/*escouade1.perso[escouade1.nb_perso] = Elf_Archer_A_defaut;
    escouade1.nb_perso++;
    escouade1.perso[escouade1.nb_perso] = Human_Lancer_A_defaut;
    escouade1.nb_perso++;
    escouade1.perso[escouade1.nb_perso] = Pony_Warrior_A_defaut;
    escouade1.nb_perso++;*/
    
    //escouade1 = xp(escouade1, 210597);
	//escouade1 = montee_level_escouade(escouade1);
	//escouade1 = charger_escouade(escouade1);
	//afficher_escouade(escouade1);
	//sauvegarde_escouade(escouade1);
	
	return(EXIT_SUCCESS);
}
