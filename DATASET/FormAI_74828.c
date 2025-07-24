//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10

int player_x, player_y;
int game_map[HEIGHT][WIDTH];

void generate_map() {
    // Seed the random number generator
    srand(time(NULL));

    // Fill the map with walls
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            game_map[y][x] = 1;
        }
    }

    // Carve out some empty spaces using a random walk algorithm
    int x = 1;
    int y = 1;
    for (int i = 0; i < 200; i++) {
        game_map[y][x] = 0;
        int direction = rand() % 4;
        switch (direction) {
            case 0: // Up
                if (y > 1) {
                    y--;
                }
                break;
            case 1: // Down
                if (y < HEIGHT - 2) {
                    y++;
                }
                break;
            case 2: // Left
                if (x > 1) {
                    x--;
                }
                break;
            case 3: // Right
                if (x < WIDTH - 2) {
                    x++;
                }
        }
    }

    // Place the player in an empty space
    do {
        player_x = rand() % WIDTH;
        player_y = rand() % HEIGHT;
    } while (game_map[player_y][player_x] == 1);
    game_map[player_y][player_x] = 2; // Player is represented by a "2" on the map
}

void print_map() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (game_map[y][x] == 0) {
                printf(".");
            } else if (game_map[y][x] == 1) {
                printf("#");
            } else if (game_map[y][x] == 2) {
                printf("@");
            }
        }
        printf("\n");
    }
}

int main() {
    generate_map();
    print_map();
    return 0;
}