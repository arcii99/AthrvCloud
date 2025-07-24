//FormAI DATASET v1.0 Category: Memory Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random numbers between 0 and 9
int randNum() {
    return (rand() % 10);
}

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to shuffle an array
void shuffle(int *arr, int n) {
    for (int i = n - 1; i >= 0; i--) {
        int j = rand() % (i + 1);
        swap(&arr[i], &arr[j]);
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    int size = 4; // Size of the memory game grid
    int numTiles = size * size; // Number of tiles in the game
    int tiles[numTiles]; // Array to hold the tile values
    int opened[numTiles]; // Array to keep track of which tiles are opened
    int selections[2]; // Array to keep track of the player's selections
    int numOpened = 0; // Number of tiles that have been opened
    int attempts = 0; // Number of attempts made by the player
    int matches = 0; // Number of successful matches made by the player

    // Generate the tiles for the game
    for (int i = 0; i < numTiles; i += 2) {
        tiles[i] = randNum();
        tiles[i + 1] = tiles[i]; // Each tile has a matching tile with the same value
    }

    shuffle(tiles, numTiles); // Shuffle the tiles

    printf("Welcome to the Memory Game!\n");
    printf("Try to match all of the tiles in as few attempts as possible.\n\n");

    // Main game loop
    while (matches < size) { // The game ends when all the tiles have been matched
        printf("Attempts: %d\n\n", attempts);

        // Print the game grid
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                int index = i * size + j;

                if (opened[index]) {
                    printf("%d ", tiles[index]);
                } else {
                    printf("* ");
                }
            }
            printf("\n");
        }
        printf("\n");

        // Get the player's selection
        printf("Enter the row and column of a tile to open.\n");
        printf("Row: ");
        scanf("%d", &selections[0]);
        printf("Column: ");
        scanf("%d", &selections[1]);

        int index = (selections[0] - 1) * size + (selections[1] - 1);

        if (!opened[index]) { // Make sure the tile hasn't already been opened
            opened[index] = 1;

            if (numOpened == 0) { // First selection
                numOpened++;
            } else if (numOpened == 1) { // Second selection
                numOpened++;

                // Check for a match
                if (tiles[index] == tiles[selections[0] * size + selections[1] - 2] || tiles[index] == tiles[(selections[0] - 2) * size + selections[1] - 1]) {
                    printf("Match!\n");
                    matches++;
                } else {
                    printf("No match.\n");
                }

                attempts++;
                numOpened = 0;
            }
        } else {
            printf("That tile has already been opened.\n");
        }

        printf("\n");
    }

    printf("Congratulations, you matched all of the tiles in %d attempts!\n", attempts);

    return 0;
}