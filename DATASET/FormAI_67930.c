//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define constants for the game
#define MAX_NAME_LENGTH 20
#define MAX_DESCRIPTION_LENGTH 50
#define MAX_INVENTORY_SIZE 5
#define MAX_ENEMY_HEALTH 30
#define MAX_PLAYER_HEALTH 50
#define MAX_WEAPON_DAMAGE 10
#define MAX_ARMOR_PROTECTION 5
#define MAX_NUM_ENEMIES 3
#define MIN_NUM_ENEMIES 1
#define NUM_MAP_LOCATIONS 3
#define WIN_CONDITION 3

// Define structures for the game
typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int damage;
} Weapon;

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int protection;
} Armor;

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int health;
    Weapon weapon;
    Armor armor;
} Player;

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int health;
    Weapon weapon;
} Enemy;

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
} Location;

// Declare functions for the game
void generateEnemies(Enemy enemies[]);
void printEnemyInfo(Enemy enemy);
void printLocationInfo(Location location);
void printPlayerStatus(Player player);
void fight(Enemy enemy, Player *player);
void victory(Player *player, Location *currentLocation);
void gameLost();
void gameWon();

int main() {
    srand(time(NULL)); // Seed random numbers with time
    Player player = {"Player", "A survivor of the apocalypse", MAX_PLAYER_HEALTH, {"Fists", "No description", 5}, {"Clothes", "No description", 0}};
    Enemy enemies[MAX_NUM_ENEMIES];
    Location map[NUM_MAP_LOCATIONS] = {{"Abandoned City", "A once-thriving city, now reduced to rubble and ruin"}, {"The Wasteland", "Endless desert, dotted with the ruins of civilization"}, {"The Bunker", "A hidden underground stronghold, built to withstand the apocalypse"}};
    int currentEnemies = MIN_NUM_ENEMIES;
    Location currentLocation = map[0];
    int locationsVisited = 0;

    printf("Welcome to the post-apocalyptic adventure game!\n");
    printf("Your goal is to navigate through the wasteland and defeat the enemies to achieve victory.\n");

    while (locationsVisited < WIN_CONDITION) {
        printf("\nYou are currently at: %s\n", currentLocation.name);
        printLocationInfo(currentLocation);
        printf("\n");

        // Generate enemies to fight
        printf("Looking around, you see ");
        generateEnemies(enemies);
        printEnemyInfo(enemies[0]);
        if (currentEnemies > 1) {
            printf(" and ");
            printEnemyInfo(enemies[1]);
        }
        if (currentEnemies > 2) {
            printf(" and ");
            printEnemyInfo(enemies[2]);
        }
        printf(".\n\n");

        // Fight enemies
        int allEnemiesDefeated = 0;
        while (!allEnemiesDefeated && player.health > 0) {
            printf("You have encountered enemies! Prepare to fight.\n");
            int i;
            for (i = 0; i < currentEnemies; i++) {
                printf("Fighting ");
                printEnemyInfo(enemies[i]);
                printf(".\n");
                fight(enemies[i], &player);
                if (player.health <= 0) {
                    gameLost();
                    return 0;
                }
            }
            allEnemiesDefeated = 1;
            for (i = 0; i < currentEnemies; i++) {
                if (enemies[i].health > 0) {
                    allEnemiesDefeated = 0;
                }
            }
            if (allEnemiesDefeated) {
                printf("You have defeated all the enemies.\n");
            }
        }

        // Move to next location
        printf("\n");
        locationsVisited++;
        if (locationsVisited == WIN_CONDITION) {
            gameWon();
            return 0;
        }
        printf("You move on to the next location.\n\n");
        currentEnemies++;
        if (currentEnemies > MAX_NUM_ENEMIES) {
            currentEnemies = MAX_NUM_ENEMIES;
        }
        currentLocation = map[rand() % NUM_MAP_LOCATIONS];
    }

    return 0;
}

/**
 * Generates an array of random enemies
 * @param enemies: the array to store the generated enemies in
 */
void generateEnemies(Enemy enemies[]) {
    int i;
    for (i = 0; i < MAX_NUM_ENEMIES; i++) {
        Enemy enemy = {"No enemy", "No description", 0};
        if (rand() % 2 == 0) {
            enemy = (Enemy){"Zombie", "The undead, with a hunger for flesh", MAX_ENEMY_HEALTH, {"Rotting limbs", "No description", MAX_WEAPON_DAMAGE}};
        } else {
            enemy = (Enemy){"Raider", "A hostile human, surviving by any means necessary", MAX_ENEMY_HEALTH, {"Rusty knife", "No description", MAX_WEAPON_DAMAGE}};
        }
        enemies[i] = enemy;
    }
}

/**
 * Prints information about an enemy
 * @param enemy: the enemy to print information about
 */
void printEnemyInfo(Enemy enemy) {
    printf("%s (%s)", enemy.name, enemy.description);
    if (enemy.health > 0) {
        printf(" with %d health", enemy.health);
    }
}

/**
 * Prints information about a location
 * @param location: the location to print information about
 */
void printLocationInfo(Location location) {
    printf("%s (%s)", location.name, location.description);
}

/**
 * Prints the current status of the player
 * @param player: the player to print the status of
 */
void printPlayerStatus(Player player) {
    printf("%s (%s)", player.name, player.description);
    printf(" with %d health", player.health);
    printf(", wielding a %s (%d damage)", player.weapon.name, player.weapon.damage);
    if (player.armor.protection > 0) {
        printf(" and wearing %s (%d protection)", player.armor.name, player.armor.protection);
    }
    printf(".\n");
}

/**
 * Initiates a fight with an enemy
 * @param enemy: the enemy to fight
 * @param player: a pointer to the player object
 */
void fight(Enemy enemy, Player *player) {
    while (enemy.health > 0 && player->health > 0) {
        // Player attacks enemy
        int playerDamage = rand() % player->weapon.damage;
        printf("You attack the %s with your %s and deal %d damage.\n", enemy.name, player->weapon.name, playerDamage);
        enemy.health -= playerDamage;

        // Enemy attacks player
        if (enemy.health > 0) {
            int enemyDamage = rand() % enemy.weapon.damage;
            int netDamage = enemyDamage - player->armor.protection;
            if (netDamage < 0) {
                netDamage = 0;
            }
            printf("The %s attacks you with its %s and deals %d damage (%d after armor).\n", enemy.name, enemy.weapon.name, enemyDamage, netDamage);
            player->health -= netDamage;
            printPlayerStatus(*player);
        }
    }

    if (enemy.health <= 0) {
        printf("You have defeated the %s!\n", enemy.name);
    }
}

/**
 * Displays victory message and update game stats
 * @param player: a pointer to the player object
 * @param currentLocation: a pointer to the current location object
 */
void victory(Player *player, Location *currentLocation) {
    printf("You have conquered the %s and made it out alive!\n", currentLocation->name);
    player->health = MAX_PLAYER_HEALTH; // Reset player health
}

/**
 * Displays game lost message
 */
void gameLost() {
    printf("\n\n***********************************\n");
    printf("*                                 *\n");
    printf("*          GAME OVER :(           *\n");
    printf("*                                 *\n");
    printf("***********************************\n");
}

/**
 * Displays game won message
 */
void gameWon() {
    printf("\n\n***********************************\n");
    printf("*                                 *\n");
    printf("*     CONGRATULATIONS, YOU WON!    *\n");
    printf("*                                 *\n");
    printf("***********************************\n");
}