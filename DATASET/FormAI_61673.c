//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 20

char map[MAP_SIZE][MAP_SIZE];
int player_x, player_y;

void generate_map() {
    // Generate a random map with walls and floors
    // This is just an example implementation
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            if (i == 0 || j == 0 || i == MAP_SIZE-1 || j == MAP_SIZE-1) {
                map[i][j] = '#';
            } else {
                if (rand() % 100 < 40) {
                    map[i][j] = '#';
                } else {
                    map[i][j] = '.';
                }
            }
        }
    }
}

void print_map() {
    // Print the current map to the console
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            if (i == player_y && j == player_x) {
                printf("@");
            } else {
                printf("%c", map[i][j]);
            }
        }
        printf("\n");
    }
}

int move_player(int x, int y) {
    // Move the player in the specified direction
    if (map[y][x] == '#') {
        return 0;
    }
    player_x = x;
    player_y = y;
    return 1;
}

int main() {
    srand(time(NULL));

    generate_map();
    player_x = MAP_SIZE / 2;
    player_y = MAP_SIZE / 2;

    while (1) {
        system("clear"); // Clear the console
        print_map();

        // Handle player input
        char input;
        printf("Move (w, a, s, d): ");
        scanf(" %c", &input);
        switch (input) {
            case 'w':
                move_player(player_x, player_y-1);
                break;
            case 'a':
                move_player(player_x-1, player_y);
                break;
            case 's':
                move_player(player_x, player_y+1);
                break;
            case 'd':
                move_player(player_x+1, player_y);
                break;
            default:
                printf("Invalid input!\n");
        }
    }

    return 0; // Not necessary, but good practice
}