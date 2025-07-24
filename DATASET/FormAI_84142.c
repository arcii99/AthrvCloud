//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants
#define MAX_NAME_LENGTH 20
#define MAX_ENEMY_HEALTH 100
#define MAX_PLAYER_HEALTH 100
#define MAX_ENEMY_DAMAGE 10
#define MAX_PLAYER_DAMAGE 15

// Define structs
struct player {
    char name[MAX_NAME_LENGTH];
    int health;
    int damage;
};

struct enemy {
    char name[MAX_NAME_LENGTH];
    int health;
    int damage;
};

// Function prototypes
void generate_enemy(struct enemy* enemy);
void player_attack(struct player* player, struct enemy* enemy);
void enemy_attack(struct player* player, struct enemy* enemy);

int main() {
    // Seed random number generator
    srand(time(NULL));

    // Initialize player and enemy structs
    struct player my_player = {"Player 1", MAX_PLAYER_HEALTH, MAX_PLAYER_DAMAGE};
    struct enemy my_enemy;

    // Generate initial enemy
    generate_enemy(&my_enemy);

    // Game loop
    int game_running = 1;
    while (game_running) {
        printf("Player: %s (%d HP)\n", my_player.name, my_player.health);
        printf("Enemy: %s (%d HP)\n", my_enemy.name, my_enemy.health);

        // Player's turn
        player_attack(&my_player, &my_enemy);
        if (my_enemy.health <= 0) {
            printf("You defeated the %s!\n", my_enemy.name);
            generate_enemy(&my_enemy);
        }

        // Enemy's turn
        enemy_attack(&my_player, &my_enemy);
        if (my_player.health <= 0) {
            printf("You were defeated by the %s.\n", my_enemy.name);
            game_running = 0;
        }
    }

    return 0;
}

void generate_enemy(struct enemy* enemy) {
    // Generate random name for enemy
    char names[5][MAX_NAME_LENGTH] = {"Alien", "Robot", "Mutant", "Creature", "Monster"};
    int random_index = rand() % 5;
    for (int i = 0; i < MAX_NAME_LENGTH; i++) {
        enemy->name[i] = names[random_index][i];
        if (enemy->name[i] == '\0') {
            break;
        }
    }

    // Set enemy health and damage
    enemy->health = MAX_ENEMY_HEALTH;
    enemy->damage = rand() % MAX_ENEMY_DAMAGE + 1;
}

void player_attack(struct player* player, struct enemy* enemy) {
    int damage_dealt = rand() % player->damage + 1;
    printf("You attack the %s for %d damage.\n", enemy->name, damage_dealt);
    enemy->health -= damage_dealt;
}

void enemy_attack(struct player* player, struct enemy* enemy) {
    int damage_dealt = rand() % enemy->damage + 1;
    printf("The %s attacks you for %d damage.\n", enemy->name, damage_dealt);
    player->health -= damage_dealt;
}