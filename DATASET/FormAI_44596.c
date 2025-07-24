//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: all-encompassing
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define GHOST_COUNT 3

// Structure for holding coordinates
typedef struct Coordinates {
    int x;
    int y;
} Coordinates;

// Function to generate random coordinates
Coordinates generateRandomCoordinates() {
    Coordinates coords;
    coords.x = rand() % ROWS;
    coords.y = rand() % COLS;
    return coords;
}

// Function to get player input
char getPlayerInput() {
    printf("Enter a direction (n/s/e/w): ");
    char input;
    scanf(" %c", &input);
    return input;
}

// Function to move player
bool movePlayer(char direction, Coordinates* playerCoords) {
    int newX = playerCoords->x;
    int newY = playerCoords->y;
    switch(direction) {
        case 'n':
            newX--;
            break;
        case 's':
            newX++;
            break;
        case 'e':
            newY++;
            break;
        case 'w':
            newY--;
            break;
        default:
            printf("Invalid input.\n");
            return false;
    }
    if(newX < 0 || newX >= ROWS || newY < 0 || newY >= COLS) {
        printf("You have reached the edge of the house. Please turn around.\n");
        return false;
    }
    playerCoords->x = newX;
    playerCoords->y = newY;
    return true;
}

// Function to check if player has encountered a ghost
bool checkGhostEncounter(Coordinates playerCoords, Coordinates* ghostCoords) {
    for(int i=0; i<GHOST_COUNT; i++) {
        if(playerCoords.x == ghostCoords[i].x && playerCoords.y == ghostCoords[i].y) {
            printf("You have encountered a ghost! Game over.\n");
            return true;
        }
    }
    return false;
}

// Main function
int main() {
    // Seed random generator
    srand(time(0));

    // Initialize player and ghost coordinates
    Coordinates playerCoords = generateRandomCoordinates();
    Coordinates ghostCoords[GHOST_COUNT];
    for(int i=0; i<GHOST_COUNT; i++) {
        ghostCoords[i] = generateRandomCoordinates();
    }

    // Main game loop
    while(true) {
        // Display game board
        for(int i=0; i<ROWS; i++) {
            for(int j=0; j<COLS; j++) {
                if(i == playerCoords.x && j == playerCoords.y) {
                    printf("P");
                } else {
                    bool isGhost = false;
                    for(int k=0; k<GHOST_COUNT; k++) {
                        if(i == ghostCoords[k].x && j == ghostCoords[k].y) {
                            printf("G");
                            isGhost = true;
                            break;
                        }
                    }
                    if(!isGhost) {
                        printf(".");
                    }
                }
            }
            printf("\n");
        }

        // Get player input and move player
        char input = getPlayerInput();
        if(movePlayer(input, &playerCoords)) {
            // Check for ghost encounter
            if(checkGhostEncounter(playerCoords, ghostCoords)) {
                break;
            }
        }
    }

    return 0;
}