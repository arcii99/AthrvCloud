//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_HEIGHT 20
#define MAP_WIDTH 50

// Structure to store the position of player and enemies
typedef struct {
    int x;
    int y;
} position;

// Function to generate random integer between min and max
int random_int(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to print the map, with player and enemies represented by P and E respectively
void print_map(char map[][MAP_WIDTH], position player_pos, position enemy_pos) {
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            if (i == player_pos.y && j == player_pos.x) {
                printf("P");
            } else if (i == enemy_pos.y && j == enemy_pos.x) {
                printf("E");
            } else {
                printf("%c", map[i][j]);
            }
        }
        printf("\n");
    }
}

// Function to generate the map with '#' representing walls and '.' representing walkable floors
void generate_map(char map[][MAP_WIDTH]) {
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            if (i == 0 || i == MAP_HEIGHT - 1 || j == 0 || j == MAP_WIDTH - 1) {
                map[i][j] = '#';
            } else {
                map[i][j] = '.';
            }
        }
    }
}

int main() {
    char map[MAP_HEIGHT][MAP_WIDTH];

    position player_pos = {MAP_WIDTH / 2, MAP_HEIGHT / 2};
    position enemy_pos = {random_int(1, MAP_WIDTH - 2), random_int(1, MAP_HEIGHT - 2)};

    generate_map(map);

    // Seed the random number generator
    srand(time(NULL));

    int game_running = 1;
    while (game_running) {
        // Clear the console and print the map
        system("clear");
        print_map(map, player_pos, enemy_pos);

        // Get input from user to move the player
        char input;
        printf("Use wasd to move: ");
        scanf(" %c", &input);

        // Handle the player's movement
        switch (input) {
            case 'w':
                if (map[player_pos.y - 1][player_pos.x] != '#') {
                    player_pos.y--;
                }
                break;
            case 's':
                if (map[player_pos.y + 1][player_pos.x] != '#') {
                    player_pos.y++;
                }
                break;
            case 'a':
                if (map[player_pos.y][player_pos.x - 1] != '#') {
                    player_pos.x--;
                }
                break;
            case 'd':
                if (map[player_pos.y][player_pos.x + 1] != '#') {
                    player_pos.x++;
                }
                break;
        }

        // Handle the enemy's movement
        int enemy_move = random_int(1, 4);
        switch (enemy_move) {
            case 1:
                if (map[enemy_pos.y - 1][enemy_pos.x] != '#') {
                    enemy_pos.y--;
                }
                break;
            case 2:
                if (map[enemy_pos.y + 1][enemy_pos.x] != '#') {
                    enemy_pos.y++;
                }
                break;
            case 3:
                if (map[enemy_pos.y][enemy_pos.x - 1] != '#') {
                    enemy_pos.x--;
                }
                break;
            case 4:
                if (map[enemy_pos.y][enemy_pos.x + 1] != '#') {
                    enemy_pos.x++;
                }
                break;
        }

        // Check if the player has been caught by the enemy
        if (player_pos.x == enemy_pos.x && player_pos.y == enemy_pos.y) {
            printf("Game over!\n");
            game_running = 0;
        }
    }

    return 0;
}