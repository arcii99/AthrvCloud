//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_MAP_SIZE 50

// Character struct
typedef struct {
    char symbol;
    int x;
    int y;
    int health;
    int armor;
    int damage;
} Character;

// Map struct
typedef struct {
    char tiles[MAX_MAP_SIZE][MAX_MAP_SIZE];
    int width;
    int height;
} Map;

// Function to generate random number in range
int randRange(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to generate random map
void generateMap(Map* map) {
    for (int y = 0; y < map->height; y++) {
        for (int x = 0; x < map->width; x++) {
            if ((x == 0) || (y == 0) || (x == map->width - 1) || (y == map->height - 1)) {
                map->tiles[y][x] = '#';
            } else {
                int value = randRange(0, 100);
                if (value < 10) {
                    map->tiles[y][x] = '#';
                } else {
                    map->tiles[y][x] = '.';
                }
            }
        }
    }
}

// Function to print map
void printMap(Map* map, Character* player) {
    system("clear"); // Clear console

    for (int y = 0; y < map->height; y++) {
        for (int x = 0; x < map->width; x++) {
            if ((y == player->y) && (x == player->x)) {
                printf("%c", player->symbol);
            } else {
                printf("%c", map->tiles[y][x]);
            }
        }
        printf("\n");
    }

    printf("\nHealth: %d\nArmor: %d\nDamage: %d\n", player->health, player->armor, player->damage);
}

int main() {
    srand(time(0)); // Seed rand

    // Initialize player
    Character player = {'@', 1, 1, 100, 0, 10};

    // Initialize map
    Map map = {{0}, MAX_MAP_SIZE, MAX_MAP_SIZE};
    generateMap(&map);

    // Game loop
    while (1) {
        printMap(&map, &player);

        // Move player
        char input = getchar();
        getchar(); // Consume extra newline

        if (input == 'w') {
            if (map.tiles[player.y - 1][player.x] != '#') {
                player.y--;
            }
        } else if (input == 'a') {
            if (map.tiles[player.y][player.x - 1] != '#') {
                player.x--;
            }
        } else if (input == 's') {
            if (map.tiles[player.y + 1][player.x] != '#') {
                player.y++;
            }
        } else if (input == 'd') {
            if (map.tiles[player.y][player.x + 1] != '#') {
                player.x++;
            }
        }

        // Fight enemy
        if (map.tiles[player.y][player.x] == 'E') {
            Character enemy = {'E', player.x, player.y, 50, 2, 5};
            while ((player.health > 0) && (enemy.health > 0)) {
                int player_damage = player.damage - enemy.armor;
                if (player_damage < 0) {
                    player_damage = 0;
                }
                enemy.health -= player_damage;
                printf("Player attacks! Enemy health: %d\n", enemy.health);
                if (enemy.health <= 0) {
                    printf("Enemy defeated!\n");
                    getchar(); // Wait for input
                    map.tiles[enemy.y][enemy.x] = '.';
                    break;
                }
                int enemy_damage = enemy.damage - player.armor;
                if (enemy_damage < 0) {
                    enemy_damage = 0;
                }
                player.health -= enemy_damage;
                printf("Enemy attacks! Player health: %d\n", player.health);
                if (player.health <= 0) {
                    printf("Game over!\n");
                    return 0;
                }
            }
        }

        // Generate enemies
        int enemy_chance = randRange(0, 100);
        if (enemy_chance < 5) {
            int x = randRange(1, map.width - 2);
            int y = randRange(1, map.height - 2);
            if (map.tiles[y][x] == '.') {
                map.tiles[y][x] = 'E';
            }
        }
    }

    return 0;
}