//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 5
#define COLUMNS 10

// Structure to store the information of each invader
struct Invader {
    int x;
    int y;
    bool alive;
};

// Function to print the current game state
void printGame(char space[ROWS][COLUMNS], struct Invader invaderArray[]) {
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (space[i][j] == 'S') {
                printf("| ");
            } else {
                bool invadersFound = false;
                for (int k = 0; k < ROWS*COLUMNS; k++) {
                    if (invaderArray[k].x == j && invaderArray[k].y == i && invaderArray[k].alive) {
                        printf("X ");
                        invadersFound = true;
                        break;
                    }
                }
                if (!invadersFound) {
                    printf("  ");
                }
            }
        }
        printf("|\n");
    }
}

int main() {
    srand(time(NULL)); // Initializing random number generator
    
    // Initializing game board
    char space[ROWS][COLUMNS] = {
        {'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S'},
        {'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S'},
        {'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S'},
        {'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S'},
        {'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S'},
    };

    // Initializing invader array
    struct Invader invaderArray[ROWS*COLUMNS];
    for (int i = 0; i < ROWS*COLUMNS; i++) {
        invaderArray[i].x = i % COLUMNS;
        invaderArray[i].y = i / COLUMNS;
        invaderArray[i].alive = true;
    }

    // Initializing player position
    int playerX = COLUMNS/2;

    // Starting game loop
    bool gameRunning = true;
    while (gameRunning) {
        // Printing current game state
        printGame(space, invaderArray);
        printf("\n");

        // Checking for win condition
        bool invadersRemaining = false;
        for (int i = 0; i < ROWS*COLUMNS; i++) {
            if (invaderArray[i].alive) {
                invadersRemaining = true;
                break;
            }
        }
        if (!invadersRemaining) {
            printf("You won!\n");
            break;
        }

        // Getting player input
        printf("Enter 'l' to move left, 'r' to move right, 'q' to quit: ");
        char userInput;
        scanf("%c", &userInput);
        getchar(); // Consuming newline character from input

        // Processing player input
        if (userInput == 'l') {
            if (playerX > 0) {
                playerX--;
            }
        } else if (userInput == 'r') {
            if (playerX < COLUMNS-1) {
                playerX++;
            }
        } else if (userInput == 'q') {
            printf("Quitting...\n");
            break;
        } else {
            printf("Invalid input!\n");
        }

        // Moving invaders
        for (int i = 0; i < ROWS*COLUMNS; i++) {
            if (invaderArray[i].alive) {
                int moveDirection = (rand() % 3) - 1; // Randomly choosing left, stay or right
                if (moveDirection == -1) {
                    if (invaderArray[i].x > 0) {
                        invaderArray[i].x--;
                    }
                } else if (moveDirection == 1) {
                    if (invaderArray[i].x < COLUMNS-1) {
                        invaderArray[i].x++;
                    }
                }
            }
        }

        // Checking for collision between player and invaders
        for (int i = 0; i < ROWS*COLUMNS; i++) {
            if (invaderArray[i].alive && invaderArray[i].x == playerX && invaderArray[i].y == ROWS-1) { // Player collided with invader
                printf("You lost!\n");
                gameRunning = false;
                break;
            }
        }

        // Checking for collision between laser and invaders
        for (int i = ROWS-2; i >= 0; i--) {
            for (int j = 0; j < COLUMNS; j++) {
                if (space[i][j] == 'L') { // Laser found
                    space[i][j] = 'S';
                    for (int k = 0; k < ROWS*COLUMNS; k++) {
                        if (invaderArray[k].alive && invaderArray[k].x == j && invaderArray[k].y == i) { // Invader hit by laser
                            invaderArray[k].alive = false;
                            break;
                        }
                    }
                }
            }
        }

        // Adding new laser
        if (rand() % 5 == 0) { // 20% chance of adding new laser
            int laserX = rand() % COLUMNS;
            space[ROWS-1][laserX] = 'L';
        }
    }

    return 0;
}