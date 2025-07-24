//FormAI DATASET v1.0 Category: Educational ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // seed the random number generator with the current time
    int player_health = 100;
    int enemy_health = 75;
    int player_damage, enemy_damage;
    int run_chance = 50;
    
    printf("Welcome to the post-apocalyptic fight simulator!\n");
    
    while (player_health > 0 && enemy_health > 0) {
        printf("Your health: %d\nEnemy health: %d\n", player_health, enemy_health);
        
        // player's turn
        printf("Enter your damage amount (between 5-15): ");
        scanf("%d", &player_damage);
        player_damage = (player_damage < 5) ? 5 : player_damage; // minimum player damage is 5
        player_damage = (player_damage > 15) ? 15 : player_damage; // maximum player damage is 15
        
        enemy_health -= player_damage;
        if (enemy_health <= 0) { // if the enemy dies
            printf("\nYou have defeated the enemy!\n");
            break;
        }
        
        // enemy's turn
        if (rand() % 100 < run_chance) { // chance for enemy to run away
            printf("\nThe enemy has run away!\n");
            break;
        }
        
        printf("\nThe enemy is attacking!\n");
        enemy_damage = rand() % 10 + 5; // enemy's damage is between 5-14
        player_health -= enemy_damage;
        if (player_health <= 0) { // if the player dies
            printf("\nYou have been defeated by the enemy!\n");
            break;
        }
    }
    
    printf("\nGame Over.\n");
    
    return 0;
}