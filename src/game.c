#include "../header/game.h"

void run(){
    EntitySystem player = player_init();
    EntitySystem enemy = enemy_init(SLIME, 12);
    display_entity(player);
    battle_loop(&player, &enemy);
}