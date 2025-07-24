//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: configurable
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Function prototypes
void printRoom(char**, int);
int randomInt(int, int);

int main() {
    // Seed random number generator with current time
    srand(time(NULL));

    // Configurable variables
    const int ROOMS = 5;
    const int ROWS = 5;
    const int COLS = 7;
    const int MIN_GHOSTS = 1;
    const int MAX_GHOSTS = 5;
    const double GHOST_PROB = 0.25;

    // Create room layout
    char** rooms = (char**)malloc(sizeof(char*) * ROOMS);
    for (int i = 0; i < ROOMS; i++) {
        rooms[i] = (char*)malloc(sizeof(char) * (ROWS * COLS));
    }

    // Populate rooms with objects and ghosts
    for (int i = 0; i < ROOMS; i++) {
        for (int j = 0; j < ROWS * COLS; j++) {
            if (j == (ROWS * COLS) / 2) {
                rooms[i][j] = 'X'; // Mark center of room with X
            } else {
                rooms[i][j] = ' '; // Empty space
            }

            // Add ghosts with probability GHOST_PROB
            if ((double)rand() / RAND_MAX < GHOST_PROB) {
                rooms[i][j] = 'G'; // Ghost
            }
        }

        // Ensure minimum number of ghosts
        int ghostCount = 0;
        for (int k = 0; k < ROWS * COLS; k++) {
            if (rooms[i][k] == 'G') {
                ghostCount++;
            }
        }
        int ghostsToAdd = randomInt(MIN_GHOSTS - ghostCount, MAX_GHOSTS - ghostCount);
        for (int l = 0; l < ghostsToAdd; l++) {
            int index = randomInt(0, ROWS * COLS - 1);
            if (rooms[i][index] == ' ') {
                rooms[i][index] = 'G';
            }
        }
    }

    // Print initial room layout
    printRoom(rooms, 0);
    printf("You are in room 1. Be careful, there are ghosts lurking around!\n");

    // Game loop
    int currentRoom = 0;
    char input;
    while (1) {
        printf("Enter a direction (n/s/e/w) or q to quit: ");
        scanf(" %c", &input);

        // Check if input is valid
        if (input == 'q') {
            break; // Quit game
        } else if (input != 'n' && input != 's' && input != 'e' && input != 'w') {
            printf("Invalid input. Try again.\n");
            continue;
        }

        // Move player to new room
        switch (input) {
            case 'n':
                if (currentRoom - COLS < 0) {
                    printf("Cannot move north. Try again.\n");
                    continue;
                }
                currentRoom -= COLS;
                break;
            case 's':
                if (currentRoom + COLS >= ROWS * COLS) {
                    printf("Cannot move south. Try again.\n");
                    continue;
                }
                currentRoom += COLS;
                break;
            case 'e':
                if ((currentRoom % COLS) == COLS - 1) {
                    printf("Cannot move east. Try again.\n");
                    continue;
                }
                currentRoom++;
                break;
            case 'w':
                if ((currentRoom % COLS) == 0) {
                    printf("Cannot move west. Try again.\n");
                    continue;
                }
                currentRoom--;
                break;
        }

        // Check for ghosts
        if (rooms[currentRoom][(ROWS * COLS) / 2] == 'G') {
            printf("You've encountered a ghost! You lose.\n");
            break; // End game
        }

        // Print current room layout
        printRoom(rooms, currentRoom);
        printf("You are in room %d.\n", currentRoom + 1);
    }

    // Free memory allocated for rooms array
    for (int i = 0; i < ROOMS; i++) {
        free(rooms[i]);
    }
    free(rooms);
    
    return 0;
}

/**
 * Prints a single room in the Haunted House Simulator game.
 * The current room is marked with an 'O'.
 */
void printRoom(char** rooms, int currentRoom) {
    const int ROWS = 5;
    const int COLS = 7;

    for (int i = 0; i < ROWS * COLS; i++) {
        int roomIndex = i / (ROWS * COLS / 5);

        if (i % COLS == 0) {
            printf("\n");
        }

        if (roomIndex == currentRoom) {
            printf("O ");
        } else {
            printf("%c ", rooms[roomIndex][i % (ROWS * COLS / 5)]);
        }
    }
    printf("\n");
}

/**
 * Generates a random integer between min and max (inclusive).
 */
int randomInt(int min, int max) {
    return min + rand() % (max - min + 1);
}