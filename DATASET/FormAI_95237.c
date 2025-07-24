//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Initializing variables
    int player_health = 100;
    int enemy_health = 75;
    int player_attack_min = 5;
    int player_attack_max = 15;
    int enemy_attack_min = 10;
    int enemy_attack_max = 20;
    int player_score = 0;
    int enemy_score = 0;
    int round = 1;
    srand(time(0)); // For random numbers

    printf("Welcome to the Procedural Space Adventure!\n\n");

    // Loop until one player has no health left
    while (player_health > 0 && enemy_health > 0)
    {
        // Display round number and player/enemy health
        printf("Round %d\n", round);
        printf("Player Health: %d\n", player_health);
        printf("Enemy Health: %d\n\n", enemy_health);

        // Player's turn
        int player_attack = rand() % (player_attack_max - player_attack_min + 1) + player_attack_min;
        enemy_health -= player_attack;
        printf("Player attacks for %d damage!\n", player_attack);
        if (enemy_health <= 0) // If enemy's health reaches 0 or below, player wins
        {
            printf("Enemy defeated!\n\n");
            player_score++;
            break;
        }

        // Enemy's turn
        int enemy_attack = rand() % (enemy_attack_max - enemy_attack_min + 1) + enemy_attack_min;
        player_health -= enemy_attack;
        printf("Enemy attacks for %d damage!\n", enemy_attack);
        if (player_health <= 0) // If player's health reaches 0 or below, enemy wins
        {
            printf("Player defeated!\n\n");
            enemy_score++;
            break;
        }

        round++; // Increment round number
    }

    // Display final scores
    printf("Final scores:\n");
    printf("Player: %d\n", player_score);
    printf("Enemy: %d", enemy_score);

    return 0;
}