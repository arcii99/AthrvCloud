//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20 // Number of rows in the game map
#define COLS 50 // Number of columns in the game map

void generateMap(char map[][COLS]); // Function to generate the map
void displayMap(char map[][COLS], int playerX, int playerY); // Function to display the map
void movePlayer(char map[][COLS], int *playerX, int *playerY, char direction); // Function to move the player

int main() {
    char map[ROWS][COLS]; // 2D array to store the game map
    int playerX = 0, playerY = 0; // Player's starting position

    srand(time(NULL)); // Seed the random number generator

    generateMap(map); // Generate the game map
    displayMap(map, playerX, playerY); // Display the game map

    // Game loop
    char input;
    while (1) {
        printf("Enter a direction (w/a/s/d): ");
        scanf(" %c", &input); // Get input from the player

        movePlayer(map, &playerX, &playerY, input); // Move the player in the chosen direction
        displayMap(map, playerX, playerY); // Display the game map with the updated player position

        // If the player reaches the bottom right corner, display a message and end the game
        if (playerX == ROWS-1 && playerY == COLS-1) {
            printf("Congratulations, you have reached the end of the game!\n");
            break;
        }
    }

    return 0;
}

void generateMap(char map[][COLS]) {
    int i, j;

    // Generate the map layout randomly
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (rand() % 100 < 40) {
                map[i][j] = '#'; // 40% chance of a wall
            } else {
                map[i][j] = '.'; // 60% chance of a floor
            }
        }
    }

    // Place the player at the top left corner
    map[0][0] = '@';

    // Place the exit at the bottom right corner
    map[ROWS-1][COLS-1] = 'X';
}

void displayMap(char map[][COLS], int playerX, int playerY) {
    int i, j;

    system("clear"); // Clear the console window

    // Print the map
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (i == playerX && j == playerY) {
                printf("@"); // Print the player symbol
            } else {
                printf("%c", map[i][j]); // Print the map symbol
            }
        }
        printf("\n");
    }
}

void movePlayer(char map[][COLS], int *playerX, int *playerY, char direction) {
    int newX = *playerX, newY = *playerY;

    // Calculate the new position based on the chosen direction
    switch (direction) {
        case 'w': newX--; break;
        case 'a': newY--; break;
        case 's': newX++; break;
        case 'd': newY++; break;
    }

    // Check if the new position is within the bounds of the map
    if (newX >= 0 && newX < ROWS && newY >= 0 && newY < COLS) {
        // Check if the new position is not a wall
        if (map[newX][newY] != '#') {
            // Update the player's position
            *playerX = newX;
            *playerY = newY;
        }
    }
}