//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

#define MAX_LEVEL 5 // Maximum number of levels
#define MIN_LEVEL 1 // Minimum number of levels
#define MAX_HEALTH 100 // Maximum health of the player
#define MAX_ENEMY_HEALTH 50 // Maximum health of the enemies
#define MAX_ENEMIES 3 // Maximum number of enemies on a level

// Function to generate random integer between min and max
int generate_random(int min, int max){
    int rand_num = rand() % (max - min + 1) + min;
    return rand_num;
}

// Function to simulate a battle between the player and the enemy
bool battle(int player_hp, int enemy_hp){
    while(player_hp > 0 && enemy_hp > 0){
        int player_dmg = generate_random(10, 20); // Generate random player attack value
        enemy_hp = enemy_hp - player_dmg;
        printf("Player hits enemy for %d damage. Enemy HP: %d\n", player_dmg, enemy_hp);

        if(enemy_hp <= 0){
            return true; // Enemy defeated
        }

        int enemy_dmg = generate_random(5, 15); // Generate random enemy attack value
        player_hp = player_hp - enemy_dmg;
        printf("Enemy hits player for %d damage. Player HP: %d\n", enemy_dmg, player_hp);
    }

    if(player_hp <= 0){
        return false; // Player defeated
    }
}

int main(){
    srand(time(0)); // Seed the random number generator
    int level = MIN_LEVEL; // Initialize level to minimum level
    int player_health = MAX_HEALTH; // Initialize player health to maximum health

    printf("Welcome to the Procedural Space Adventure game!\n");

    while(level <= MAX_LEVEL && player_health > 0){
        printf("\n-----------------------------\n");
        printf("Entering Level %d...\n", level);

        int num_enemies = generate_random(1, MAX_ENEMIES); // Generate random number of enemies on this level
        printf("Defeat %d enemies to proceed to the next level.\n", num_enemies);

        int enemies_defeated = 0; // Initialize number of enemies defeated to 0

        while(enemies_defeated < num_enemies && player_health > 0){
            printf("\nEnemy %d encountered!\n", enemies_defeated+1);
            int enemy_health = generate_random(10, MAX_ENEMY_HEALTH); // Generate random enemy health for this enemy
            bool result = battle(player_health, enemy_health); // Call the battle function
            if(result){
                printf("Enemy %d defeated!\n", enemies_defeated+1);
                enemies_defeated++;
            }
            else{
                printf("Game over! Player defeated in Level %d.\n", level);
                return 0;
            }
            printf("Player HP: %d\n", player_health); // Print remaining player health
        }

        if(enemies_defeated == num_enemies){
            printf("\nAll enemies defeated in Level %d! Proceeding to the next level...\n", level);
            level++;
        }
    }

    if(player_health > 0){
        printf("\nCongratulations! Game completed successfully!\n");
    }

    return 0; // End of program
}