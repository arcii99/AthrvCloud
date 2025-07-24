//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the size of the haunted house
#define HOUSE_HEIGHT 10
#define HOUSE_WIDTH 20

// Define the character for the player
#define PLAYER_CHAR 'P'

// Define the character for the walls
#define WALL_CHAR '#'

// Define the character for the haunted objects
#define OBJECT_CHAR '*'

// Define the character for the exit
#define EXIT_CHAR 'E'

// Define the maximum number of haunted objects
#define MAX_OBJECTS 10

// Define the probability of finding a haunted object
#define OBJECT_PROBABILITY 30

// Define the maximum number of moves the player can make
#define MAX_MOVES 20

// Function to print the haunted house
void print_house(char house[HOUSE_HEIGHT][HOUSE_WIDTH]) {
    for (int i = 0; i < HOUSE_HEIGHT; i++) {
        for (int j = 0; j < HOUSE_WIDTH; j++) {
            printf("%c", house[i][j]);
        }
        printf("\n");
    }
}

// Function to generate a random number between 0 and 99
int random_number() {
    return rand() % 100;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Define the haunted house
    char house[HOUSE_HEIGHT][HOUSE_WIDTH];

    // Generate the walls of the haunted house
    for (int i = 0; i < HOUSE_HEIGHT; i++) {
        for (int j = 0; j < HOUSE_WIDTH; j++) {
            if (i == 0 || i == HOUSE_HEIGHT - 1 || j == 0 || j == HOUSE_WIDTH - 1) {
                house[i][j] = WALL_CHAR;
            } else {
                house[i][j] = ' ';
            }
        }
    }

    // Generate the haunted objects
    int num_objects = 0;
    while (num_objects < MAX_OBJECTS) {
        for (int i = 1; i < HOUSE_HEIGHT - 1; i++) {
            for (int j = 1; j < HOUSE_WIDTH - 1; j++) {
                if (random_number() < OBJECT_PROBABILITY) {
                    if (house[i][j] == ' ') {
                        house[i][j] = OBJECT_CHAR;
                        num_objects++;
                    }
                }
            }
        }
    }

    // Generate the exit of the haunted house
    int exit_row = 0, exit_col = 0;
    while (house[exit_row][exit_col] != ' ') {
        exit_row = random_number() % (HOUSE_HEIGHT - 2) + 1;
        exit_col = random_number() % (HOUSE_WIDTH - 2) + 1;
    }
    house[exit_row][exit_col] = EXIT_CHAR;

    // Generate the player's starting position
    int player_row = 0, player_col = 0;
    while (house[player_row][player_col] != ' ') {
        player_row = random_number() % (HOUSE_HEIGHT - 2) + 1;
        player_col = random_number() % (HOUSE_WIDTH - 2) + 1;
    }
    house[player_row][player_col] = PLAYER_CHAR;

    // Print the initial state of the haunted house
    print_house(house);

    // Play the game
    int num_moves = 0;
    while (num_moves < MAX_MOVES) {
        // Get the player's move
        char move;
        printf("Enter your move (WASD): ");
        scanf(" %c", &move);

        // Shift the player's position accordingly
        int old_row = player_row, old_col = player_col;
        switch (move) {
            case 'W': player_row--; break;
            case 'A': player_col--; break;
            case 'S': player_row++; break;
            case 'D': player_col++; break;
            default: printf("Invalid move!\n"); continue;
        }

        // Check if the player has hit a wall
        if (house[player_row][player_col] == WALL_CHAR) {
            printf("You hit a wall!\n");
            player_row = old_row;
            player_col = old_col;
            continue;
        }

        // Check if the player has found an object
        if (house[player_row][player_col] == OBJECT_CHAR) {
            printf("You found a haunted object!\n");
            house[player_row][player_col] = ' ';
        }

        // Check if the player has found the exit
        if (house[player_row][player_col] == EXIT_CHAR) {
            printf("You escaped the haunted house!\n");
            break;
        }

        // Update the player's position in the haunted house
        house[old_row][old_col] = ' ';
        house[player_row][player_col] = PLAYER_CHAR;

        // Print the updated state of the haunted house
        print_house(house);

        // Increment the number of moves
        num_moves++;
    }

    // End the game
    printf("Game Over!\n");

    return 0;
}