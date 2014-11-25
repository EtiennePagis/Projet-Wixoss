#include <stdio.h>
#include <stdlib.h>

enum typedef(Humain = 1, Elfe , Neko-Girl , Pony ) t_race;
enum typedef(Orc = 1, Gobelin , Bete , Monstre , Insecte , Golem, Lezard) t_race_ennemie;
enum typedef(Warrior = 1 , Archer , Healer, Knight, Sniper, Assassin, Lord, General, Brawler, White-Mage, Black-Mage, Cleric) t_classe;
enum typedef(Epee = 1, Arc, Lance, Baton, Poing) t_arme;
enum typedef(Feu = 1, Glace, Lumiere , Tenebre ,Soin, Cure )t_attribut;
struct typedef (int con ; int Hp ; int force ; int intel ; int def ; int res; int agi;) t_stat; 
struct typedef (char nom; t_race race ; t_classe classe ; t_arme arme ; t_attribut attribut ; t_stat stat; int level ;int exp;) t_personnage;
struct typedef (t_race_ennemie race_ennemie ; t_classe classe ; t_attribut attribut ; t_stat stat;) t_ennemie;
struct typedef (t_personnage perso_1 ; t_personnage perso_2 ; t_personnage perso_3 ; t_personnage perso_4 ; t_personnage perso_5 ; t_personnage perso_6 ;) t_escouade;

/*Stockage des perso à faire*/
