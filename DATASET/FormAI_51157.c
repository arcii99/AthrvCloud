//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define constant variables
#define MAX_NAME_LENGTH 20
#define MAX_ENEMY_HEALTH 20
#define MAX_PLAYER_HEALTH 30
#define MIN_DAMAGE 5
#define MAX_DAMAGE 15

// Define structures
struct Player {
    char name[MAX_NAME_LENGTH];
    int health;
    int damage;
};

struct Enemy {
    char name[MAX_NAME_LENGTH];
    int health;
    int damage;
};

// Declare functions
int fight(struct Player*, struct Enemy*);
void generateEnemy(struct Enemy*);

// Define main function
int main() {
    // Seed random number generator
    srand(time(NULL));

    // Create player struct and get name
    struct Player player;
    printf("What's your name?\n");
    fgets(player.name, MAX_NAME_LENGTH, stdin);
    player.name[strcspn(player.name, "\n")] = 0;

    // Set player health and damage
    player.health = MAX_PLAYER_HEALTH;
    player.damage = MAX_DAMAGE;

    // Initialize game variables
    int score = 0;
    int gameRunning = 1;

    // Start game loop
    while(gameRunning) {
        // Generate enemy
        struct Enemy enemy;
        generateEnemy(&enemy);
        printf("A wild %s appears!\n", enemy.name);

        // Fight enemy
        int result = fight(&player, &enemy);

        // Check result of fight
        if(result == 1) {
            printf("Congratulations! You defeated the %s\n", enemy.name);
            score++;
        } else {
            printf("Game over! Your final score was %d\n", score);
            gameRunning = 0;
        }
    }

    return 0;
}

// Define function to generate enemy
void generateEnemy(struct Enemy *enemy) {
    // Generate random name
    char names[][MAX_NAME_LENGTH] = {"Goblin", "Skeleton", "Orc", "Zombie", "Dragon"};
    int nameIndex = rand() % 5;
    strcpy(enemy->name, names[nameIndex]);

    // Set enemy health and damage
    enemy->health = MAX_ENEMY_HEALTH - rand() % 6;
    enemy->damage = MIN_DAMAGE + rand() % (MAX_DAMAGE - MIN_DAMAGE + 1);
}

// Define function for fight sequence
int fight(struct Player *player, struct Enemy *enemy) {
    // Print health status
    printf("Your health: %d/%d\n", player->health, MAX_PLAYER_HEALTH);
    printf("%s's health: %d/%d\n", enemy->name, enemy->health, MAX_ENEMY_HEALTH);

    // Start fight loop
    while(1) {
        // Player attacks first
        int damage = MIN_DAMAGE + rand() % (player->damage - MIN_DAMAGE + 1);
        enemy->health -= damage;
        printf("You deal %d damage to the %s\n", damage, enemy->name);

        // Check if enemy is defeated
        if(enemy->health <= 0) {
            return 1;
        }

        // Enemy attacks back
        damage = MIN_DAMAGE + rand() % (enemy->damage - MIN_DAMAGE + 1);
        player->health -= damage;
        printf("The %s deals %d damage to you\n", enemy->name, damage);

        // Check if player is defeated
        if(player->health <= 0) {
            return 0;
        }
    }
}