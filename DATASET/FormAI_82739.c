//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int player_health = 100;
int aliens_killed = 0;

void encounter() {
    int encountered_alien = rand() % 3 + 1;
    int damage_taken_by_player = rand() % 50 + 1;  // Random damage taken by player between 1 to 50
    
    switch (encountered_alien) {
        case 1:
            printf("The player encountered a weak alien and defeated it.\n");
            aliens_killed++;
            break;
        case 2:
            printf("The player encountered a strong alien and fought bravely.\n");
            player_health -= damage_taken_by_player;
            aliens_killed++;
            break;
        case 3:
            printf("The player encountered an ultra-powerful alien. The player's chances of survival are slim.\n");
            player_health -= 50;
            aliens_killed++;
            break;
        default:
            printf("The player escaped the encounter unscathed.\n");
    }
}

void game_over() {
    printf("GAME OVER. The player fought bravely and killed %d aliens before they died.\n", aliens_killed);
    exit(0);
}

int main() {
    srand(time(NULL));  // Seed the randomizer
    
    printf("Welcome to the Procedural Space Adventure!\n");
    printf("You are the lone survivor on a spacecraft lost in a distant galaxy.\n");
    printf("Your mission is to stay alive and return to Earth.\n");
    printf("Let the adventure begin...\n\n");
    
    while(1) {
        encounter();
        
        if(player_health <= 0) {
            game_over();
        } else if(aliens_killed >= 10) {
            printf("CONGRATULATIONS! The player has survived and defeated 10 aliens. The spacecraft is returning to Earth.\n");
            exit(0);
        } else {
            printf("Player health: %d.\n", player_health);
            printf("Total aliens killed: %d.\n\n", aliens_killed);
        }
    }
    
    return 0;
}