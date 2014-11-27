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
typedef enum {Neutre = 0, Feu, Glace, Lumiere , Tenebre ,Soin, Cure} t_attribut;
typedef enum {D = 1, C, B, A, S, SS} t_rank;

typedef struct {int HP ; int attack ; int mattack ; int def ; int mdef;} t_stat; 
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
		p.nom = nom; // ATTENTION !!
		//strcpy();
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


int main(){
	
	Neko_Brawler_S_defaut = creer_perso("Sijya", Neko_Girl, Brawler, Poing, Neutre, S, st, 1, 15);
	//printf("%s est une %i %i, son arme du type %i, son attribut est %i, son rang est %i, ses stats sont : %i %i %i %i %i, elle est au level %i, possédant %i d'xp.", Neko_Brawler_S_defaut.nom, Neko_Brawler_S_defaut.race, Neko_Brawler_S_defaut.job, Neko_Brawler_S_defaut.arme, Neko_Brawler_S_defaut.attribut, Neko_Brawler_S_defaut.rank, Neko_Brawler_S_defaut.stat.HP, Neko_Brawler_S_defaut.stat.attack, Neko_Brawler_S_defaut.stat.mattack, Neko_Brawler_S_defaut.stat.def, Neko_Brawler_S_defaut.stat.mdef, Neko_Brawler_S_defaut.level, Neko_Brawler_S_defaut.exp);
	return(EXIT_SUCCESS);
}	
