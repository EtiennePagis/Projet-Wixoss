#include <stdio.h>
#include <stdlib.h>
/*Stockage des perso à faire*/
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
#define Init_Dark_Mage_Stats {350, 35, 90, 25, 50} 
#define Init_Cleric_Stats {400, 30, 70, 50, 50}

typedef enum {Humain = 1, Elfe , Neko_Girl , Pony} t_race;
typedef enum {Orc = 1, Gobelin , Bete , Monstre , Insecte , Golem, Lezard} t_race_ennemie;
typedef enum {Warrior = 1 , Archer, Brawler, Mage, Lancer, Knight, Sniper, Assassin, Lord, General, White_Mage, Black_Mage, Cleric} t_job;
typedef enum {Epee = 1, Arc, Lance, Baton, Poing} t_arme;
typedef enum {Neutre = 0, Feu, Glace, Lumiere , Tenebres ,Soin, Cure} t_attribut;
typedef enum {D = 1, C, B, A, S, SS} t_rank;

typedef struct {float HP ; float attack ; float mattack ; float def ; float mdef;} t_stat; 
typedef struct {char* nom; t_race race ; t_job job ; t_arme arme ; t_attribut attribut ; t_rank rank; t_stat stat; int level ;int exp;} t_personnage;
typedef struct {t_race_ennemie race_ennemie ; t_job job ; t_arme arme; t_attribut attribut ; t_rank rank; t_stat stat; int level;} t_ennemi;
typedef struct {t_personnage perso_1 ; t_personnage perso_2 ; t_personnage perso_3 ; t_personnage perso_4 ; t_personnage perso_5 ; t_personnage perso_6 ;} t_escouade;

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
t_stat Dark_Mage_Stats = Init_Dark_Mage_Stats;
t_stat Cleric_Stats = Init_Cleric_Stats;



t_personnage Neko_Brawler_S_defaut ; //= {"Sijya", Neko_Girl, Brawler, Poing, Neutre, S, Init_Brawler_Stats, 1, 15}; 
//t_personnage Neko_Brawler_S_defaut = {"Sijya", Neko_Girl, Brawler, Poing, Neutre, S, {Init_Brawler_Stats.HP, Init_Brawler_Stats.attack, Init_Brawler_Stats.mattack, Init_Brawler_Stats.def, Init_Brawler_Stats.mdef}, 1, 15}; 


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
	
	printf(" - Lvl %i / %i xp", perso.level, perso.exp);
	
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


int main(){
	
	Neko_Brawler_S_defaut = creer_perso("Sijya", Neko_Girl, Brawler, Poing, Neutre, S, Brawler_Stats, 1, 15);
	afficher_perso(Neko_Brawler_S_defaut);
	return(EXIT_SUCCESS);
}	
