//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants for the game
#define MAX_MAP_SIZE 20
#define MAX_ENEMIES 10
#define MAX_HEALTH 20

// Define the character struct
typedef struct {
    int x;
    int y;
    int health;
} character_t;

// Define the enemy struct
typedef struct {
    int x;
    int y;
    int health;
} enemy_t;

// Define the game map
char map[MAX_MAP_SIZE][MAX_MAP_SIZE];

// Define the player and enemy arrays
character_t player;
enemy_t enemies[MAX_ENEMIES];

// Define the function to generate the map
void generate_map(int size) {
    int x, y;
    for (y = 0; y < size; y++) {
        for (x = 0; x < size; x++) {
            int r = rand() % 100;
            if (r < 10) {
                map[x][y] = '#';
            } else {
                map[x][y] = '.';
            }
        }
    }
}

// Define the function to place the player
void place_player(int size) {
    int x = rand() % size;
    int y = rand() % size;
    player.x = x;
    player.y = y;
    player.health = MAX_HEALTH;
}

// Define the function to place the enemies
void place_enemies(int size, int num_enemies) {
    int i;
    for (i = 0; i < num_enemies; i++) {
        int x = rand() % size;
        int y = rand() % size;
        enemies[i].x = x;
        enemies[i].y = y;
        enemies[i].health = MAX_HEALTH;
    }
}

// Define the function to draw the map
void draw_map(int size) {
    int x, y;
    for (y = 0; y < size; y++) {
        for (x = 0; x < size; x++) {
            if (x == player.x && y == player.y) {
                printf("@");
            } else {
                int i;
                int enemy_found = 0;
                for (i = 0; i < MAX_ENEMIES; i++) {
                    if (enemies[i].x == x && enemies[i].y == y) {
                        printf("E");
                        enemy_found = 1;
                        break;
                    }
                }
                if (!enemy_found) {
                    printf("%c", map[x][y]);
                }
            }
        }
        printf("\n");
    }
}

// Define the function to move the player
void move_player(int dx, int dy) {
    int newx = player.x + dx;
    int newy = player.y + dy;
    if (newx >= 0 && newx < MAX_MAP_SIZE && newy >= 0 && newy < MAX_MAP_SIZE) {
        player.x = newx;
        player.y = newy;
    }
}

// Define the main function
int main() {
    srand(time(NULL));

    // Generate the map
    generate_map(MAX_MAP_SIZE);

    // Place the player and enemies
    place_player(MAX_MAP_SIZE);
    place_enemies(MAX_MAP_SIZE, MAX_ENEMIES);

    // Main game loop
    int playing = 1;
    while (playing) {
        // Draw the map
        draw_map(MAX_MAP_SIZE);

        // Get user input
        char input;
        scanf("%c", &input);

        // Move the player
        switch (input) {
            case 'w':
                move_player(0, -1);
                break;
            case 'a':
                move_player(-1, 0);
                break;
            case 's':
                move_player(0, 1);
                break;
            case 'd':
                move_player(1, 0);
                break;
            case 'q':
                playing = 0;
                break;
        }
    }

    return 0;
}