/**
* \enum Race
*/
typedef enum {Humain = 1, Elfe, Neko_Girl, Pony, Bete, Monstre, Golem, Dragon} t_race;

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
typedef struct {char* nom; t_race race ; t_job job ; t_arme arme ; t_attribut attribut ; t_rank rank; t_stat stat; int level; int exp;} t_personnage;

/**
* \struct Escouade
* \brief Une escouade est composée de plusieurs personnages et possède un nombre de maximal de personnage
*/
typedef struct { t_personnage perso[MAX_PERSO]; int nb_perso;} t_escouade;

/**
* \struct Liste
* \brief La liste contient tout les personnages du joueur 
*/
typedef struct {int numero_perso ; t_personnage liste_perso[MAX_LISTE];} t_liste;

t_personnage creer_perso(char* nom, t_race race, t_job job, t_arme arme, t_attribut attribut, t_rank rank, t_stat stat, int level ,int exp);
t_personnage charger_perso(char* nom, t_race race, t_job job, t_arme arme, t_attribut attribut, t_rank rank, t_stat stat, int level ,int exp);
void afficher_perso(t_personnage perso);
t_personnage generer();
t_personnage generer_ennemi(int niveau);
t_personnage montee_statistiques ( t_personnage p );
t_personnage montee_level ( t_personnage p );
t_escouade montee_level_escouade ( t_escouade escouade );
t_escouade xp(t_escouade escouade, float xp);
void afficher_escouade (t_escouade escouade);
void sauvegarde_liste( t_liste liste );
t_liste charger_liste ( t_liste liste );
t_liste verification ( t_liste liste, int numero_personnage, char* nom, t_race race );
t_liste suppression_doublons ( t_liste liste, t_personnage p );
int est_present ( t_liste liste, t_personnage p);
t_liste recrutement ( t_liste liste );
void choix_recruter();
void afficher_liste ( t_liste liste );
t_personnage recherche_membre_liste ( char* nom );
int recherche_membre_escouade ( char* nom );
t_escouade ajouter_membre (t_escouade escouade);
t_escouade retirer_membre (t_escouade escouade);
void init_liste();
void init_escouade();
t_liste mise_a_jour_liste (t_escouade escouade, t_liste liste);
void menu_personnage();
