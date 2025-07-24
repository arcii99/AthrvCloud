//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int player_health = 100, enemy_health = 100, player_attack, enemy_attack, round_count = 1;
    
    // set random seed for generating random numbers
    srand(time(NULL));
    
    // game loop
    while (player_health > 0 && enemy_health > 0) {
        printf("Round %d:\n", round_count);
        
        // player attack
        printf("Player's turn\n");
        printf("Enter attack strength (1-10): ");
        scanf("%d", &player_attack);
        if (player_attack < 1 || player_attack > 10) {
            printf("Invalid attack strength. Please enter a number between 1 and 10.\n");
            continue;
        }
        enemy_health -= player_attack;
        printf("Enemy's health decreased to %d\n", enemy_health);
        if (enemy_health <= 0) {
            printf("Player wins!\n");
            break;
        }
        
        // enemy attack
        printf("Enemy's turn\n");
        enemy_attack = rand() % 10 + 1;
        player_health -= enemy_attack;
        printf("Player's health decreased to %d\n", player_health);
        if (player_health <= 0) {
            printf("Enemy wins!\n");
            break;
        }
        
        round_count++;
    }
    
    printf("Game over.\n");
    
    return 0;
}