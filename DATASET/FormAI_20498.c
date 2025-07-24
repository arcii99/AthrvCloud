//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int player_hp = 100; // Player's starting health points
int enemy_hp = 100; // Enemy's starting health points
int round_num = 1; // Starting round number

int main() {
    srand(time(NULL)); // Set random seed

    // Introduction
    printf("Welcome to Brave Battle!\n\n");
    printf("You are a brave warrior fighting against the evil enemy!\n");
    printf("You will take turns attacking each other until one of you runs out of health points.\n\n");

    // Game loop
    while(player_hp > 0 && enemy_hp > 0) {
        printf("ROUND %d\n", round_num);

        // Player turn
        int player_damage = rand() % 11 + 10; // Random damage between 10 and 20
        enemy_hp -= player_damage; // Subtract damage from enemy's health points
        printf("You attacked the enemy, dealing %d damage!\n", player_damage);
        if(enemy_hp <= 0) { // Check if enemy is defeated
            printf("You have defeated the enemy! Congratulations!\n");
            break; // End game
        }

        // Enemy turn
        int enemy_damage = rand() % 11 + 10; // Random damage between 10 and 20
        player_hp -= enemy_damage; // Subtract damage from player's health points
        printf("The enemy attacked you, dealing %d damage!\n", enemy_damage);
        if(player_hp <= 0) { // Check if player is defeated
            printf("You have been defeated by the enemy. Game over.\n");
            break; // End game
        }

        round_num++; // Increment round number
    }

    // Exit message
    printf("\nThank you for playing Brave Battle!\n");

    return 0;
}