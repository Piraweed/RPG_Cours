#ifndef ENTITY_H
#define ENTITY_H

#include<stdio.h>
#include<string.h>


typedef enum{
    HUMAIN, //0
    DRAGON,//1
    SLIME, //2
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

typedef struct{ //add3
    int max_stamina;
    int activ_stamina;
    int atk_spent;
    int def_spent;
    int rest_step;
}StaminaSystem;

typedef struct{//add2
    int max_super;
    int activ_super;
    int step_super;
}SuperAttackSystem;

typedef struct{ //add1
    int dice_atk_num;
    int dice_atk_faces;
    int dice_spd_num;
    int dice_def_num;
    int critical_hit_chance;//des 100 (de 0 à 99);
}DiceSystem;

typedef struct{
    //const===
    Race race;
    char name[100];
    //var===
    DiceSystem dice;//add1
    LifeSystem life;
    LevelSystem level;
    StaminaSystem stamina;
    SuperAttackSystem super;//add3
    //act===
    int in_defence;
}EntitySystem;



EntitySystem enemy_init(Race race, int lvl);
void define_enemy_stat(EntitySystem *enemy, char name[], int lvl, int hp, int bonus_hp,
                        int stamina, int bonus_stamina, //fin
                        int atk_spent, int def_spent, int rest_step, int bonus_rest_step,
                        int dice_atk_num,int lvls_for_dice_atk, int dice_atk_faces, int dice_spd_num, int dice_def_num, 
                        int critical_hit, int bonus_crit,
                        int super, int step_super, int bonus_step_super);// Possible UPDATE ICI PLUS TARD SI NOUVEAUX STATS COMME POWER, SPEED, LVL et tout

EntitySystem player_init();
void define_name_player(EntitySystem *player);

void display_entity(EntitySystem entity);



#endif //PLAYER_H