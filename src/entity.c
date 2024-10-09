#include "../header/entity.h"

EntitySystem enemy_init(Race race, int lvl){
    EntitySystem enemy;
    enemy.race = race;
    switch(race){
        case DRAGON:
        define_enemy_stat(&enemy,"Dragon", lvl, 200, 20, //base + HP
                            200, 30, 20, 30, 10, 5, //stamina
                            3,10,10, 5, 4,//dice
                            5, 1, //crit
                            1000, 5, 5);break;  //super
        case SLIME:
        define_enemy_stat(&enemy,"Slime", lvl, 10, 10, //base + HP
                            10, 5, 10, 10, 5, 1, //stamina
                            3,7, 4, 1, 2, //dice
                            0, 5, //crit
                            1000, 1, 1);break; //super
        printf("erreur de l'initialisation de l'enemy de race %d", race);break;
    }
    return enemy;
}

/*(&enemy, "name", lvl,
hp(niv1), hp/niveaux )
*/
void define_enemy_stat(EntitySystem *enemy, char name[], int lvl, int hp, int bonus_hp,
                        int stamina, int bonus_stamina, //fin
                        int atk_spent, int def_spent, int rest_step, int bonus_rest_step,
                        int dice_atk_num,int lvls_for_dice_atk, int dice_atk_faces, int dice_spd_num, int dice_def_num, 
                        int critical_hit, int bonus_crit,
                        int super, int step_super, int bonus_step_super){
    strcpy(enemy->name, name);
    enemy->in_defence = 0;
    enemy->level.lvl= lvl;
    enemy->life.max_hp = hp + bonus_hp*lvl -bonus_hp;
    enemy->life.activ_hp = enemy->life.max_hp;
    enemy->stamina.max_stamina = stamina +bonus_stamina*lvl - bonus_stamina;
    enemy->stamina.activ_stamina = enemy->stamina.max_stamina;
    enemy->stamina.atk_spent = atk_spent;
    enemy->stamina.def_spent = def_spent;
    enemy->stamina.rest_step = rest_step + bonus_rest_step*lvl - bonus_rest_step;
    enemy->dice.dice_atk_num = dice_atk_num; + lvls_for_dice_atk*(lvl/lvls_for_dice_atk);
    enemy->dice.dice_atk_faces = dice_atk_faces;
    enemy->dice.dice_spd_num = dice_spd_num;
    enemy->dice.dice_def_num = dice_def_num;
    enemy->dice.critical_hit_chance= critical_hit + bonus_crit*lvl;
    enemy->super.max_super = super;
    enemy->super.activ_super = super;
    enemy->super.step_super = step_super + bonus_step_super*(lvl-1);
}

EntitySystem player_init(){
    EntitySystem player;
    define_name_player(&player);
    player.in_defence = 0;
    player.level.lvl = 1;
    player.life.max_hp = 100;
    player.life.activ_hp = 100;
    player.stamina.max_stamina = 100;
    player.stamina.activ_stamina = 100;
    return player;
}

void define_name_player(EntitySystem *player){
    int attempt = 1;
    do{
        if(attempt > 1){
            printf("Aux moin un char est demande!\n");
        }
        printf("Ton nom ? : ");
        scanf("%s", player->name);
    }while(player->name == "");
}

void display_entity(EntitySystem entity){
    printf("===========================\n");
    int pv_max = entity.life.max_hp;
    int pv_activ = entity.life.activ_hp;
    printf("%s \\lvl:%d", entity.name, entity.level.lvl);
    printf("\n");
    printf("PV : %d/%d\n", pv_activ, pv_max);
}