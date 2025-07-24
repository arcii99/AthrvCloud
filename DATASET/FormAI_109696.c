//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define global constants
#define ROWS 10
#define COLS 10
#define GHOST_ROW 5
#define GHOST_COL 5
#define DOOR_ROW 0
#define DOOR_COL 0

// Define function to print the game board
void print_board(int player_row, int player_col, int ghost_row, int ghost_col) {
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            if (i==player_row && j==player_col) {
                printf("X ");
            }
            else if (i==ghost_row && j==ghost_col) {
                printf("G ");
            }
            else if (i==DOOR_ROW && j==DOOR_COL) {
                printf("D ");
            }
            else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

// Define function to randomly move the ghost
void move_ghost(int *ghost_row, int *ghost_col) {
    int rand_dir = rand() % 4; // Generate a random number between 0 and 3
    switch (rand_dir) {
        case 0: // Move up
            if (*ghost_row > 0) {
                (*ghost_row)--;
            }
            break;
        case 1: // Move down
            if (*ghost_row < ROWS-1) {
                (*ghost_row)++;
            }
            break;
        case 2: // Move left
            if (*ghost_col > 0) {
                (*ghost_col)--;
            }
            break;
        case 3: // Move right
            if (*ghost_col < COLS-1) {
                (*ghost_col)++;
            }
            break;
        default:
            break;
    }
}

int main() {
    int player_row = ROWS-1;
    int player_col = COLS-1;
    int ghost_row = GHOST_ROW;
    int ghost_col = GHOST_COL;
    char input;

    printf("Welcome to the haunted house simulator!\n");
    printf("You are trapped in a haunted house and must find your way out.\n");
    printf("You are represented by X, the ghost is represented by G, and the door is represented by D.\n");
    printf("Use the W,A,S,D keys to move around.\n");

    srand(time(NULL)); // Seed the random number generator using the current time

    while (1) { // Infinite game loop
        print_board(player_row, player_col, ghost_row, ghost_col);
        printf("Enter your move: ");
        scanf(" %c", &input); // Get user input

        switch (input) { // Move the player based on user input
            case 'w': // Move up
                if (player_row > 0) {
                    player_row--;
                }
                break;
            case 's': // Move down
                if (player_row < ROWS-1) {
                    player_row++;
                }
                break;
            case 'a': // Move left
                if (player_col > 0) {
                    player_col--;
                }
                break;
            case 'd': // Move right
                if (player_col < COLS-1) {
                    player_col++;
                }
                break;
            default:
                break;
        }

        move_ghost(&ghost_row, &ghost_col); // Move the ghost
        if (ghost_row==player_row && ghost_col==player_col) { // Check if the player has been caught by the ghost
            printf("You have been caught by the ghost! Game over.\n");
            break;
        }
        if (player_row==DOOR_ROW && player_col==DOOR_COL) { // Check if the player has reached the door
            printf("Congratulations! You have escaped from the haunted house.\n");
            break;
        }
    }

    return 0;
}