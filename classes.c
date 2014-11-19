#include <stdio.h>
#include <stdlib.h>

enum typedef(Humain = 1, Elfe , Neko-Girl , Pony ) t_race;
enum typedef(Orc = 1, Gobelin , Bete , Monstre , Insecte , Golem, Lezard) t_race_ennemie;
enum typedef(Warrior = 1 , Archer , Mage , Invoker, Druid , Paladin , Singer, Summoner, Thief, Necromancian, Healer, Speed-fighter,Dragonborn)t_classe; 
enum typedef(Feu = 1, Glace, Lumiere , Tenebre ,Soin )t_attribut;
struct typedef (int con ; int Hp ; int force ; int intel ; int def ; int res; int agi;)t_stat; 
struct typedef (char nom; t_race race ; t_classe classe ; t_attribut attribut ; t_stat stat; int level ;) t_personnage;
struct typedef (t_race_ennemie race_ennemie ; t_classe classe ; t_attribut attribut ; t_stat stat;) t_ennemie;
