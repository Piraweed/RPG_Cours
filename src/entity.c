#include "../header/entity.h"

EntitySystem enemy_init(Race race, int lvl){
    EntitySystem enemy;
    enemy.race = race;
    switch(race){
        case DRAGON:
        define_enemy_stat(&enemy,"Dragon", lvl, 100, 20, 100, 50);break;  
        case SLIME:
        define_enemy_stat(&enemy,"Slime", lvl, 10, 10, 10, 5);break;
        case ORC:
        define_enemy_stat(&enemy,"Orc", lvl, 50, 13, 100, 20);break;
        case TROLL:
        define_enemy_stat(&enemy,"Troll", lvl, 50, 10, 50, 10);break;
        default:
        printf("erreur de l'initialisation de l'enemy de race %d", race);break;
    }
    return enemy;
}

/*(&enemy, "name", lvl,
hp(niv1), hp/niveaux )
*/
void define_enemy_stat(EntitySystem *enemy, char name[], int lvl, int hp, int bonus_hp, int stamina, int bonus_stamina){
    strcpy(enemy->name, name);
    enemy->level.lvl= lvl;
    enemy->life.max_hp = hp + bonus_hp*lvl -bonus_hp;
    enemy->life.activ_hp = enemy->life.max_hp;
    enemy->stamina.max_stamina = stamina +bonus_stamina*lvl - bonus_stamina;
    enemy->stamina.activ_stamina = enemy->stamina.max_stamina;
}

EntitySystem player_init(){
    EntitySystem player;
    define_name_player(&player);
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