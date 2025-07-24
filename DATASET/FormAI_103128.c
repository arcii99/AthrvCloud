//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLUMNS 20

int playerRow, playerColumn; // Global variables to represent the current player position

void clearScreen() {
    system("clear||cls"); // Clear the screen depending on OS (Linux or Windows)
}

void printGrid(int grid[ROWS][COLUMNS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLUMNS; j++) {
            if(i == playerRow && j == playerColumn) {
                printf("X "); // Print the player position with an X
            } else {
                printf("%d ", grid[i][j]); // Print the tile value
            }
        }
        printf("\n");
    }
}

void updatePlayerPosition(int direction) {
    // Move the player in the given direction if possible
    switch(direction) {
        case 1: // Up
            if(playerRow > 0) {
                playerRow--;
            }
            break;
        case 2: // Down
            if(playerRow < ROWS-1) {
                playerRow++;
            }
            break;
        case 3: // Left
            if(playerColumn > 0) {
                playerColumn--;
            }
            break;
        case 4: // Right
            if(playerColumn < COLUMNS-1) {
                playerColumn++;
            }
            break;
        default:
            break;
    }
}

void generateRandomTiles(int grid[ROWS][COLUMNS]) {
    // Generate random tile values for each tile in the grid
    srand(time(NULL)); // Seed the random number generator with the current time
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLUMNS; j++) {
            grid[i][j] = rand() % 5; // Generate a random number between 0 and 4
        }
    }
}

void playGame() {
    int grid[ROWS][COLUMNS];
    generateRandomTiles(grid);
    playerRow = ROWS / 2; // Place the player in the middle of the grid
    playerColumn = COLUMNS / 2;
    int score = 0; // Initialize the score to 0

    while(1) { // Infinite loop until the game is over
        clearScreen();
        printGrid(grid);
        printf("Score: %d\n", score);
        printf("Use arrow keys to move. Press Q to quit.\n");

        // Get key input from the user
        int direction;
        char input = getchar();
        if(input == 'q' || input == 'Q') { // Quit the game if the user presses Q
            break;
        } else if(input == 27 && getchar() == 91) { // Arrow key input
            switch(getchar()) {
                case 65: // Up arrow
                    direction = 1;
                    break;
                case 66: // Down arrow
                    direction = 2;
                    break;
                case 68: // Left arrow
                    direction = 3;
                    break;
                case 67: // Right arrow
                    direction = 4;
                    break;
                default:
                    direction = 0; // Invalid input
                    break;
            }
            updatePlayerPosition(direction);
            int tileValue = grid[playerRow][playerColumn];
            if(tileValue == 0) {
                printf("You found nothing.\n");
            } else if(tileValue == 1) {
                printf("You found some food!\n");
                score += 10;
                grid[playerRow][playerColumn] = 0;
            } else if(tileValue == 2) {
                printf("You found a weapon!\n");
                score += 20;
                grid[playerRow][playerColumn] = 0;
            } else if(tileValue == 3) {
                printf("You found some medical supplies!\n");
                score += 30;
                grid[playerRow][playerColumn] = 0;
            } else if(tileValue == 4) {
                printf("You encountered an enemy!\n");
                printf("You fought valiantly, but were outnumbered and killed.\n");
                printf("Game over. Final score: %d\n", score);
                return;
            }
        }
    }
}

int main() {
    playGame();
    return 0;
}