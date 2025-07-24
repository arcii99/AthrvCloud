//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_MAP_SIZE 20 // maximum map size
#define MAX_MONSTERS 10 // maximum number of monsters
#define PLAYER_HP 100 // player's starting hit points

// Define struct for player and monster
typedef struct {
    int x;
    int y;
    int hp;
    int damage;
} Entity;

// Define struct for game map
typedef struct {
    char terrain[MAX_MAP_SIZE][MAX_MAP_SIZE];
    int num_monsters;
    Entity monsters[MAX_MONSTERS];
} Map;

// Generate random integer within given range
int get_random_int(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Generate random map with terrain and monsters
void generate_map(Map *map) {
    // Generate terrain
    for (int i = 0; i < MAX_MAP_SIZE; i++) {
        for (int j = 0; j < MAX_MAP_SIZE; j++) {
            if (i == 0 || i == MAX_MAP_SIZE - 1 || j == 0 || j == MAX_MAP_SIZE - 1) {
                map->terrain[i][j] = '#';
            } else {
                map->terrain[i][j] = '.';
            }
        }
    }

    // Generate monsters
    map->num_monsters = get_random_int(5, MAX_MONSTERS);
    for (int i = 0; i < map->num_monsters; i++) {
        // Randomly place monster on map
        int x = get_random_int(1, MAX_MAP_SIZE - 2);
        int y = get_random_int(1, MAX_MAP_SIZE - 2);
        // Make sure monster is not placed on player
        if (x == map->monsters[0].x && y == map->monsters[0].y) {
            y++;
        }
        map->monsters[i].x = x;
        map->monsters[i].y = y;
        map->monsters[i].hp = get_random_int(50, 100);
        map->monsters[i].damage = get_random_int(10, 20);
    }
}

// Draw map on screen
void draw_map(Map *map) {
    for (int i = 0; i < MAX_MAP_SIZE; i++) {
        for (int j = 0; j < MAX_MAP_SIZE; j++) {
            // Draw player
            if (i == map->monsters[0].y && j == map->monsters[0].x) {
                printf("@");
            }
            // Draw monster
            else {
                int is_monster = 0;
                for (int k = 1; k < map->num_monsters; k++) {
                    if (i == map->monsters[k].y && j == map->monsters[k].x) {
                        printf("M");
                        is_monster = 1;
                        break;
                    }
                }
                // Draw terrain if not player or monster
                if (!is_monster) {
                    printf("%c", map->terrain[i][j]);
                }
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL)); // Seed random number generator

    Map map;
    generate_map(&map); // Generate map

    Entity player = {1, 1, PLAYER_HP, 20}; // Initialize player

    // Game loop
    while (1) {
        // Draw map and player stats
        system("clear"); // Clear screen
        draw_map(&map);
        printf("Player HP: %d\n", player.hp);

        // Ask player for input
        char direction;
        printf("Enter direction (w/a/s/d): ");
        scanf("%c", &direction);
        getchar(); // Consume newline character

        // Move player
        int new_x = player.x;
        int new_y = player.y;
        switch (direction) {
            case 'w':
                new_y--;
                break;
            case 's':
                new_y++;
                break;
            case 'a':
                new_x--;
                break;
            case 'd':
                new_x++;
                break;
            default:
                printf("Invalid input\n");
        }

        // Check if player has hit a monster
        for (int i = 1; i < map.num_monsters; i++) {
            if (new_x == map.monsters[i].x && new_y == map.monsters[i].y) {
                printf("You hit a monster!\n");
                map.monsters[i].hp -= player.damage;
                if (map.monsters[i].hp <= 0) {
                    printf("You killed the monster!\n");
                    // Remove dead monster from map
                    for (int j = i; j < map.num_monsters - 1; j++) {
                        map.monsters[j].x = map.monsters[j+1].x;
                        map.monsters[j].y = map.monsters[j+1].y;
                        map.monsters[j].hp = map.monsters[j+1].hp;
                        map.monsters[j].damage = map.monsters[j+1].damage;
                    }
                    map.num_monsters--;
                }
            }
        }

        // Check if player has hit terrain
        if (map.terrain[new_y][new_x] != '.') {
            printf("You can't go there!\n");
        // Check if player has hit a monster
        } else {
            player.x = new_x;
            player.y = new_y;

            for (int i = 1; i < map.num_monsters; i++) {
                if (player.x == map.monsters[i].x && player.y == map.monsters[i].y) {
                    printf("You are attacked by a monster!\n");
                    player.hp -= map.monsters[i].damage;
                    if (player.hp <= 0) {
                        printf("You died!\n");
                        return 0;
                    }
                }
            }
        }
    }

    return 0;
}