#include "../header/battle.h"

const int NUM_DEAD_SENT = 15;

char DEAD_SENT[15][100]={
    " c'est fait casse en deux ", //0
    " a ete Atomise", //1
    " c'est fait ecarte", //2
    " mange les asticots", //3
    " a rejoint ta grands mère", //4
    " a retrouve sont Createur", //5
    " a rencontre l'inflexible force du destin", //6
    " est parti bouffer les pissenlits par la racine", //7
    " habite maintenet le boulevard des allonges", //8
    " a renconte la faucheuse", //9
    " est maintenent en enfer", //10
    " ne vera plus la lumier du jours", //11
    " c'est fait reduir en poussiere", //12
    " est mort", //13
    " a ete tuer",//14
};

int roll_dice(int faces){
    return (rand() % faces)+1;
}


int roll_dices(int number, int faces){
    int i, result = 0;
    for(i=0;i<number;i++){
        result += roll_dice(faces);
    }
    return result;
}


void take_damage(EntitySystem *entity, int damage){
    printf("%s subis %d de points de dégats\n", entity->name, damage);
    entity->life.activ_hp-=damage;
    if(entity->life.activ_hp < 0){
        entity->life.activ_hp = 0;
    };
}


void attack_taget(EntitySystem *target_entity){
    if(target_entity->in_defence != 1){
        int power = roll_dices(3,6);
        take_damage(target_entity, power);
        display_entity(*target_entity);
    }else{
        int power = roll_dices(1,6);
        target_entity->in_defence = 0;
    }
}


int is_dead(EntitySystem entity){
    if (entity.life.activ_hp <= 0){
        return 0;
    }
    return 1;
}


void player_move(EntitySystem *player, EntitySystem *enemy){
    int choice = 0;
    choice = display_menu();
    switch(choice){
        case 1:attack_taget(enemy);break;
        case 2:activate_defence(player);break;
        case 3:made_super_attack(player, enemy);break;
        case 4:printf("UNREADY\n");
    }
}

void made_super_attack(EntitySystem *entity_atk, EntitySystem *entity_target){
    printf("%s fait une super attack imblocable!!!\n", entity_atk->name);
    int power = roll_dices(10,6);
    take_damage(entity_target, power);
    display_entity(*entity_target);
}


void activate_defence(EntitySystem *entity){
    printf("%s ce defend", entity->name);
    entity->in_defence = 1;
}


void battle_turn(EntitySystem *player, EntitySystem *enemy){
    int player_speed_dice = 0;
    int enemy_speed_dice = 0;
    do{
        player_speed_dice = roll_dice(6);
        enemy_speed_dice = roll_dice(6);
    }while(player_speed_dice==enemy_speed_dice);
    if(player_speed_dice > enemy_speed_dice){
        player_move(player, enemy);
        attack_taget(player);
    }else{
        attack_taget(player);
        player_move(player, enemy);
    }
}


void battle_loop(EntitySystem *player, EntitySystem *enemy){
    while(is_dead(*player)==1 && is_dead(*enemy)==1){
        battle_turn(player, enemy);
    }if(is_dead(*player)==0){
        printf("%s%s\n", &player->name, random_dead_sentence());
    }else{
        printf("%s%s\n", &enemy->name, random_dead_sentence());
    }
}

char* random_dead_sentence(){
    return DEAD_SENT[rand()%NUM_DEAD_SENT];
}