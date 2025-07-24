//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 24

int map[HEIGHT][WIDTH];
int player_x, player_y;
int stairs_x, stairs_y;

void init_map() {
    srand(time(NULL));

    // Generate the map
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            map[y][x] = rand() % 3;
        }
    }

    // Place player randomly
    player_x = rand() % WIDTH;
    player_y = rand() % HEIGHT;
    map[player_y][player_x] = 4;

    // Place stairs randomly
    stairs_x = rand() % WIDTH;
    stairs_y = rand() % HEIGHT;
    map[stairs_y][stairs_x] = 5;
}

void draw_map() {
    // Clear screen
    printf("\033[2J");

    // Draw map
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            switch (map[y][x]) {
                case 0: // Wall
                    printf("#");
                    break;
                case 1: // Floor
                    printf(".");
                    break;
                case 4: // Player
                    printf("@");
                    break;
                case 5: // Stairs
                    printf(">");
                    break;
            }
        }
        printf("\n");
    }
}

int main() {
    init_map();

    while (1) {
        draw_map();

        // Check if player is at stairs
        if (player_x == stairs_x && player_y == stairs_y) {
            printf("You win!\n");
            break;
        }

        // Get input from user
        printf("Move (hjkl): ");
        char input = tolower(getchar());
        getchar(); // Discard newline

        // Move player
        switch (input) {
            case 'h':
                if (player_x > 0 && map[player_y][player_x - 1] != 0) {
                    player_x--;
                }
                break;
            case 'j':
                if (player_y < HEIGHT - 1 && map[player_y + 1][player_x] != 0) {
                    player_y++;
                }
                break;
            case 'k':
                if (player_y > 0 && map[player_y - 1][player_x] != 0) {
                    player_y--;
                }
                break;
            case 'l':
                if (player_x < WIDTH - 1 && map[player_y][player_x + 1] != 0) {
                    player_x++;
                }
                break;
        }
    }

    return 0;
}