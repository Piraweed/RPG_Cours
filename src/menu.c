
#include"../header/menu.h"

int menu_player_choice(){
    int choice = O;
    do{
        printf("CHOICE>");
        scanf("%d", &choice);
    }while(choice<= 4,&&choice>=1);
    return choice;
}

int display_menu(){
    int choice;
    printf("MENU=================\n");
    printf("1:ATK       2:DEF\n3:SUPER_ATK 4:REST");
    return menu_player_choice();
}

int 