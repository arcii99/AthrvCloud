//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL)); // seed random number generator

    // Declare variables
    int knight_attack, knight_defense, knight_health;
    int enemy_attack, enemy_defense, enemy_health;
    int round = 1;

    // Initialize knight's attributes
    knight_attack = rand() % 20 + 10;
    knight_defense = rand() % 10 + 5;
    knight_health = rand() % 50 + 50;

    // Initialize enemy's attributes
    enemy_attack = rand() % 20 + 5;
    enemy_defense = rand() % 5 + 3;
    enemy_health = rand() % 30 + 70;

    printf("The battle has begun! May the best warrior win!\n");

    // Loop until one of the warriors dies
    while (knight_health > 0 && enemy_health > 0) {
        
        // Display round number
        printf("Round %d\n", round);

        // Knight goes first
        int attack_damage = knight_attack - enemy_defense;
        if (attack_damage > 0) {
            enemy_health = enemy_health - attack_damage;
            printf("The knight strikes the enemy for %d damage!\n", attack_damage);
        } else {
            printf("The knight's attack is blocked by the enemy's defense!\n");
        }

        // Check if enemy is still alive
        if (enemy_health <= 0) {
            printf("The knight emerges victorious!\n");
            break;
        }

        // Enemy's turn to attack
        attack_damage = enemy_attack - knight_defense;
        if (attack_damage > 0) {
            knight_health = knight_health - attack_damage;
            printf("The enemy strikes the knight for %d damage!\n", attack_damage);
        } else {
            printf("The enemy's attack is blocked by the knight's defense!\n");
        }

        // Check if knight is still alive
        if (knight_health <= 0) {
            printf("The enemy emerges victorious!\n");
            break;
        }

        // Display both warrior's health
        printf("Knight's Health: %d\nEnemy's Health: %d\n", knight_health, enemy_health);

        // Increment round number
        round++;
    }

    return 0;
}