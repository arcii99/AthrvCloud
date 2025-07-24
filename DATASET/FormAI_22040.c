//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random integer between two values
int rand_int(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to print out the game map
void print_map(char map[20][20], int player_x, int player_y) {
    system("clear"); // clear the console
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if (i == player_y && j == player_x) {
                printf("@"); // print player symbol
            } else {
                printf("%c", map[i][j]); // print map symbol
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL)); // seed random number generator with current time

    char map[20][20]; // 20x20 game map
    int player_x = 10; // initial player x position
    int player_y = 10; // initial player y position

    // Generate random map
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if (rand_int(0, 3) == 0) {
                map[i][j] = '#'; // 25% chance of a wall
            } else {
                map[i][j] = '.'; // 75% chance of a floor
            }
        }
    }

    // Place the exit
    int exit_x = rand_int(1, 18);
    int exit_y = rand_int(1, 18);
    map[exit_y][exit_x] = 'X';

    // Game loop
    while (1) {
        print_map(map, player_x, player_y); // print out the game map

        // Get player input
        char input;
        printf("Enter a direction (w, a, s, d): ");
        scanf(" %c", &input);

        // Move the player
        switch (input) {
            case 'w': // up
                if (player_y > 0 && map[player_y - 1][player_x] != '#') {
                    player_y--;
                }
                break;
            case 'a': // left
                if (player_x > 0 && map[player_y][player_x - 1] != '#') {
                    player_x--;
                }
                break;
            case 's': // down
                if (player_y < 19 && map[player_y + 1][player_x] != '#') {
                    player_y++;
                }
                break;
            case 'd': // right
                if (player_x < 19 && map[player_y][player_x + 1] != '#') {
                    player_x++;
                }
                break;
            default: // invalid input
                printf("Invalid input, try again.\n");
                break;
        }

        // Check for exit
        if (player_x == exit_x && player_y == exit_y) {
            printf("Congratulations, you escaped the dungeon!\n");
            break;
        }
    }

    return 0;
}