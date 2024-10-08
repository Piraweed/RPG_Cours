#ifndef BATTLE_H
#define BATTLE_H

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "entity.h"
#include "menu.h"

int roll_dice(int faces);
int roll_dices(int faces, int dices_number);

char* random_dead_sentence();

void take_damage(EntitySystem *entity, int damage);
void attack_taget(EntitySystem *target_entity);
int is_dead(EntitySystem entity);
void battle_turn(EntitySystem *player, EntitySystem *enemy);

void activate_defence(EntitySystem *entity);
void made_super_attack(EntitySystem *entity_atk, EntitySystem *entity_target);

void battle_loop(EntitySystem*player, EntitySystem *enemy);


#endif //BATTLE_H