//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants
#define MAX_ENEMIES 3
#define MAX_HEALTH 100
#define MAX_AMMO 10

// Define structs
typedef struct {
    char name[20];
    int health;
    int ammo;
} Player;

typedef struct {
    char name[20];
    int health;
    int damage;
} Enemy;

// Function prototypes
void clearBuffer();
void printInstructions();
void createPlayer(Player* player);
void createEnemies(Enemy* enemies);
void battle(Player* player, Enemy* enemies);

// Main function
int main() {
    Player player;
    Enemy enemies[MAX_ENEMIES];

    // Print instructions
    printInstructions();

    // Create player and enemies
    createPlayer(&player);
    createEnemies(enemies);

    // Battle!
    battle(&player, enemies);

    return 0;
}

// Function to clear the buffer
void clearBuffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Function to print instructions
void printInstructions() {
    printf("Welcome to the Procedural Space Adventure!\n\n");
    printf("You are the captain of a space ship, and your mission is to\n");
    printf("destroy all the enemy ships in this sector. There are three\n");
    printf("enemy ships to defeat, so make sure to stock up on ammo and\n");
    printf("keep an eye on your health!\n\n");
    printf("Good luck, Captain.\n\n");
}

// Function to create the player
void createPlayer(Player* player) {
    printf("What is your name, Captain? ");
    fgets(player->name, 20, stdin);
    player->name[strcspn(player->name, "\n")] = 0;

    player->health = MAX_HEALTH;
    player->ammo = MAX_AMMO;

    printf("\nWelcome aboard, Captain %s!\n\n", player->name);
}

// Function to create the enemies
void createEnemies(Enemy* enemies) {
    strcpy(enemies[0].name, "Enemy Cruiser");
    enemies[0].health = 50;
    enemies[0].damage = 10;

    strcpy(enemies[1].name, "Enemy Destroyer");
    enemies[1].health = 75;
    enemies[1].damage = 15;

    strcpy(enemies[2].name, "Enemy Battleship");
    enemies[2].health = 100;
    enemies[2].damage = 20;

    printf("Enemy ships detected:\n");
    printf("%s (health: %d, damage: %d)\n", enemies[0].name, enemies[0].health, enemies[0].damage);
    printf("%s (health: %d, damage: %d)\n", enemies[1].name, enemies[1].health, enemies[1].damage);
    printf("%s (health: %d, damage: %d)\n\n", enemies[2].name, enemies[2].health, enemies[2].damage);
}

// Function for the battle
void battle(Player* player, Enemy* enemies) {
    int i, action, enemyCount = MAX_ENEMIES;
    Enemy* currentEnemy;

    // Start the battle with the first enemy
    currentEnemy = &enemies[0];
    printf("You have encountered a %s!\n", currentEnemy->name);

    // Loop through the enemies until all are defeated or the player is defeated
    while (enemyCount > 0 && player->health > 0) {

        // Print player and enemy stats
        printf("\n%s (health: %d, ammo: %d)\n", player->name, player->health, player->ammo);
        printf("%s (health: %d)\n", currentEnemy->name, currentEnemy->health);

        // Get player action
        printf("\nWhat will you do, Captain?\n");
        printf("1. Fire lasers\n");
        printf("2. Fire missiles (requires 2 ammo)\n");
        printf("3. Escape\n");
        printf("Action: ");
        scanf("%d", &action);

        // Perform player action
        switch (action) {
            case 1:
                printf("\nYou fire your lasers!\n");
                currentEnemy->health -= 10;
                break;
            case 2:
                if (player->ammo >= 2) {
                    printf("\nYou fire your missiles!\n");
                    currentEnemy->health -= 25;
                    player->ammo -= 2;
                } else {
                    printf("\nYou don't have enough ammo!\n");
                }
                break;
            case 3:
                printf("\nYou escape from the battle!\n");
                printf("\nGAME OVER\n");
                return;
            default:
                printf("\nInvalid option!\n");
                break;
        }

        // Check if enemy is defeated
        if (currentEnemy->health <= 0) {
            printf("\nYou have defeated the %s!\n", currentEnemy->name);
            enemyCount--;
            if (enemyCount > 0) {
                currentEnemy = &enemies[MAX_ENEMIES - enemyCount];
                printf("\nYou have encountered a %s!\n", currentEnemy->name);
            }
        } else {
            // Enemy attacks
            printf("\nThe %s fires its weapons!\n", currentEnemy->name);
            player->health -= currentEnemy->damage;
            if (player->health <= 0) {
                printf("\nYour ship has been destroyed!\n");
                printf("\nGAME OVER\n");
                return;
            }
        }
        clearBuffer();
    }

    // If all enemies are defeated, player wins
    printf("\nCONGRATULATIONS, CAPTAIN %s! YOU HAVE SAVED THE SECTOR!\n", player->name);
}