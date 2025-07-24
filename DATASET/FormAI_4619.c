//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_HEALTH 100
#define ATTACK_RANGE 30

// Structure for holding the player information
typedef struct {
    int health;
    int attack_power;
} Player;

// Structure for holding the enemy information
typedef struct {
    int health;
    int attack_power;
} Enemy;

// Function to generate a random number within a range
int random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to simulate a player's attack on an enemy
void player_attack(Player* player, Enemy* enemy) {
    int damage = random_number(player->attack_power/2, player->attack_power);
    enemy->health -= damage;
    printf("Player deals %d damage to enemy!\n", damage);
}

// Function to simulate an enemy's attack on a player
void enemy_attack(Player* player, Enemy* enemy) {
    int damage = random_number(enemy->attack_power/2, enemy->attack_power);
    player->health -= damage;
    printf("Enemy deals %d damage to player!\n", damage);
}

int main() {
    srand(time(NULL)); // Seed random number generator with current time
    Player player = { MAX_HEALTH, ATTACK_RANGE };
    Enemy enemy = { MAX_HEALTH, ATTACK_RANGE };
    int turn = 1;

    printf("You encounter an enemy!\n\n");

    while (player.health > 0 && enemy.health > 0) {
        printf("Turn %d\n", turn++);

        // Player's turn to attack
        player_attack(&player, &enemy);

        // Check if enemy is dead
        if (enemy.health <= 0) {
            printf("You have defeated the enemy!\n");
            break;
        }

        // Enemy's turn to attack
        enemy_attack(&player, &enemy);

        // Check if player is dead
        if (player.health <= 0) {
            printf("You have been defeated by the enemy.\n");
            break;
        }

        printf("Player health: %d\n", player.health);
        printf("Enemy health : %d\n", enemy.health);
    }

    return 0;
}