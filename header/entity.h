#ifndef ENTITY_H
#define ENTITY_H

#include<stdio.h>
#include<string.h>


typedef enum{
    HUMAIN, //0
    DRAGON,//1
    SLIME, //2
    ORC, //3
    TROLL //4
} Race;


typedef struct{
    int max_hp;
    int activ_hp;
}LifeSystem;


typedef struct{
    int lvl;
    int max_exp;
    int activ_exp;
}LevelSystem;

typedef struct{
    int max_stamina;
    int activ_stamina;
}StaminaSystem;


typedef struct{
    Race race;
    char name[100];
    LifeSystem life;
    LevelSystem level;
    StaminaSystem stamina;
    int in_defence;
}EntitySystem;



EntitySystem enemy_init(Race race, int lvl);
void define_enemy_stat(EntitySystem *enemy, char name[], int lvl, int hp, int bonus_hp, int stamina, int bonus_stamina);// Possible UPDATE ICI PLUS TARD SI NOUVEAUX STATS COMME POWER, SPEED, LVL et tout

EntitySystem player_init();
void define_name_player(EntitySystem *player);

void display_entity(EntitySystem entity);



#endif //PLAYER_H