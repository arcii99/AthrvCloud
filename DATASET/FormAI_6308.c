//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 20

typedef struct {
   char name[MAX_NAME_LEN];
   int health;
   int attack;
} spaceship;

void battle(spaceship* player, spaceship* enemy){
    player->health -= enemy->attack;
    enemy->health -= player->attack;
    
    printf("Your ship has %d health left.\n", player->health);
    printf("Enemy ship has %d health left.\n", enemy->health);
}

int main(){
    spaceship player;
    spaceship enemy;
    
    // Initializing player ship
    printf("Enter a name for your spaceship (max %d characters): ", MAX_NAME_LEN);
    fgets(player.name, MAX_NAME_LEN, stdin);
    player.health = 100;
    player.attack = 10;
    
    // Initializing enemy ship
    strcpy(enemy.name, "Alien Cruiser");
    enemy.health = 100;
    enemy.attack = 15;
    
    printf("\nWelcome, captain %s! Your mission is to defeat the Alien Cruiser and save our planet.\n\n", player.name);
    
    while(player.health > 0 && enemy.health > 0){
        char input[10];

        printf("Press any key to fire your laser. ('q' to quit)\n");
        fgets(input, 10, stdin);

        if(input[0] == 'q'){
            printf("Aborting mission...\n");
            return 0;
        }

        printf("Pew pew! Your laser hits the enemy ship!\n");
        battle(&player, &enemy);
    }

    if(player.health <= 0){
        printf("You have been defeated. The Alien Cruiser destroyed your ship and our planet.\n");
    } else {
        printf("Congratulations, captain! You have saved our planet by defeating the Alien Cruiser.\n");
    }

    return 0;
}