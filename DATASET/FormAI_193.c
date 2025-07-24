//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DRONES 4
#define GRID_SIZE 10

// Struct representing the state of a drone
typedef struct Drone {
    int x, y;   // Current position of the drone
    int battery;    // Remaining battery life
} Drone;

// Struct representing the state of the game
typedef struct Game {
    Drone drones[MAX_DRONES];   // Array of drones in the game
    int numDrones;  // Number of drones in the game
    int turnNumber; // Current turn number
    char grid[GRID_SIZE][GRID_SIZE];    // Grid representing the game world
} Game;

// Function to initialize a game
void initGame(Game *game) {
    // Initialize the grid to all '.' (empty spaces)
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            game->grid[i][j] = '.';
        }
    }

    // Choose a random number of drones (up to MAX_DRONES)
    game->numDrones = rand() % MAX_DRONES + 1;

    // Initialize each drone with a random position and battery level
    for (int i = 0; i < game->numDrones; i++) {
        game->drones[i].x = rand() % GRID_SIZE;
        game->drones[i].y = rand() % GRID_SIZE;
        game->drones[i].battery = rand() % 50 + 50;
        // Mark the drone position on the grid with its number (1 through MAX_DRONES)
        game->grid[game->drones[i].x][game->drones[i].y] = '0' + i + 1;
    }

    // Set the initial turn number to 1
    game->turnNumber = 1;
}

// Function to print the current state of the game
void printGame(Game *game) {
    printf("\nTurn %d:\n", game->turnNumber);

    // Print the grid with the drone positions
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%c ", game->grid[i][j]);
        }
        printf("\n");
    }

    // Print the battery levels of each drone
    for (int i = 0; i < game->numDrones; i++) {
        printf("Drone %d: Battery level %d\n", i + 1, game->drones[i].battery);
    }
}

// Function to move a drone in the given direction
void moveDrone(Game *game, int droneIndex, int dx, int dy) {
    // Update the drone's position on the grid
    game->grid[game->drones[droneIndex].x][game->drones[droneIndex].y] = '.';
    game->drones[droneIndex].x += dx;
    game->drones[droneIndex].y += dy;
    game->grid[game->drones[droneIndex].x][game->drones[droneIndex].y] = '0' + droneIndex + 1;

    // Consume some battery life for the movement
    game->drones[droneIndex].battery -= abs(dx) + abs(dy);
}

// Function to make a drone take a picture
void takePicture(Game *game, int droneIndex) {
    // Consume some battery life for the picture
    game->drones[droneIndex].battery -= 10;

    // Check all drones on the grid to see if they are within range of the picture
    for (int i = 0; i < game->numDrones; i++) {
        if (i != droneIndex && abs(game->drones[i].x - game->drones[droneIndex].x) <= 1
            && abs(game->drones[i].y - game->drones[droneIndex].y) <= 1) {
            printf("Drone %d is in range!\n", i + 1);
        }
    }
}

int main() {
    srand(time(NULL)); // Initialize the random number generator

    Game game;
    initGame(&game);    // Initialize the game state

    while (1) {
        printGame(&game);

        // Get the user's input for the drone and action to take
        int droneIndex, action;
        printf("Enter drone number (1-%d) and action (1=up, 2=down, 3=left, 4=right, 5=picture, 6=skip): ", game.numDrones);
        scanf("%d %d", &droneIndex, &action);

        // Perform the action, updating the game state as necessary
        if (action >= 1 && action <= 4) {
            int dx = 0, dy = 0;
            if (action == 1) dx = -1;
            else if (action == 2) dx = 1;
            else if (action == 3) dy = -1;
            else if (action == 4) dy = 1;

            if (game.drones[droneIndex - 1].battery >= abs(dx) + abs(dy)) {
                moveDrone(&game, droneIndex - 1, dx, dy);
            } else {
                printf("Drone %d doesn't have enough battery to move!\n", droneIndex);
            }
        } else if (action == 5) {
            takePicture(&game, droneIndex - 1);
        } else if (action == 6) {
            printf("Skipping turn...\n");
        }

        // Increment the turn number and check if the game is over
        game.turnNumber++;
        int dronesLeft = 0;
        for (int i = 0; i < game.numDrones; i++) {
            if (game.drones[i].battery <= 0) {
                printf("Drone %d is out of battery and has crashed!\n", i + 1);
            } else {
                dronesLeft++;
            }
        }
        if (dronesLeft <= 1) {
            printf("Game over!\n");
            break;
        }
    }

    return 0;
}