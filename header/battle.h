#ifndef BATTLE_H
#define BATTLE_H

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "entity.h"

int roll_dice(int faces);
int roll_dices(int faces, int dices_number);

char* random_dead_sentence();

void take_damage(EntitySystem *entity, int damage);
void attaque_taget(EntitySystem *target_entity);
int is_dead(EntitySystem entity);
void battle_turn(EntitySystem *player, EntitySystem *enemy);

void battle_loop(EntitySystem*player, EntitySystem *enemy);


#endif //BATTLE_H