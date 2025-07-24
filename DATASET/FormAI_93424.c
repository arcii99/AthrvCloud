//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants for map size and character symbols
#define MAP_WIDTH 50
#define MAP_HEIGHT 20
#define PLAYER_SYMBOL '@'
#define WALL_SYMBOL '#'
#define FLOOR_SYMBOL ' '
#define STAIRS_SYMBOL '>'

// Struct for player information
typedef struct {
    int x;
    int y;
    int health;
} Player;

// Struct for enemies
typedef struct {
    int x;
    int y;
    int health;
} Enemy;

// Function to generate the map
void generate_map(char map[MAP_HEIGHT][MAP_WIDTH], Player *player) {
    int i, j;

    // Seed the random number generator
    srand(time(NULL));

    // Initialize the map with walls
    for (i = 0; i < MAP_HEIGHT; i++) {
        for (j = 0; j < MAP_WIDTH; j++) {
            map[i][j] = WALL_SYMBOL;
        }
    }

    // Place the player in the center
    player->x = MAP_WIDTH / 2;
    player->y = MAP_HEIGHT / 2;
    player->health = 100;
    map[player->y][player->x] = PLAYER_SYMBOL;

    // Place some floors and enemies randomly
    for (i = 0; i < 10; i++) {
        int x = rand() % MAP_WIDTH;
        int y = rand() % MAP_HEIGHT;
        if (map[y][x] == WALL_SYMBOL && x != player->x && y != player->y) {
            map[y][x] = FLOOR_SYMBOL;
        }
    }

    for (i = 0; i < 5; i++) {
        Enemy *enemy = malloc(sizeof(Enemy));
        enemy->x = rand() % MAP_WIDTH;
        enemy->y = rand() % MAP_HEIGHT;
        enemy->health = 20;
        if (map[enemy->y][enemy->x] == FLOOR_SYMBOL) {
            map[enemy->y][enemy->x] = 'E';
        } else {
            free(enemy);
        }
    }

    // Place the stairs to the next level randomly
    int x, y;
    do {
        x = rand() % MAP_WIDTH;
        y = rand() % MAP_HEIGHT;
    } while (map[y][x] != FLOOR_SYMBOL);
    map[y][x] = STAIRS_SYMBOL;
}

// Function to print the map
void print_map(char map[MAP_HEIGHT][MAP_WIDTH]) {
    int i, j;
    for (i = 0; i < MAP_HEIGHT; i++) {
        for (j = 0; j < MAP_WIDTH; j++) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Create the player and generate the map
    Player *player = malloc(sizeof(Player));
    char map[MAP_HEIGHT][MAP_WIDTH];
    generate_map(map, player);

    // Print the initial map
    printf("Level 1\n");
    print_map(map);

    // Free the player
    free(player);

    return 0;
}