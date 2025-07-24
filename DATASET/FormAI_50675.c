//FormAI DATASET v1.0 Category: Memory Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// The memory game
int main()
{
    int n = 4; // We start with a 4x4 grid
    int count = 0;
    char values[n*n]; // Array that stores the values of each block
    char display[n*n]; // Array that displays each block's current state
    int flipped1 = -1;
    int flipped2 = -1;
    int score = 0;

    // Assign a random value to each block
    srand(time(0));
    for(int i=0; i<n*n; i++) {
        values[i] = 'A'+i/2;
    }
    for(int i=0; i<n*n; i++) {
        int pos = rand()%(n*n-i) + i;
        char temp = values[pos];
        values[pos] = values[i];
        values[i] = temp;
    }

    // Set all blocks to 'hidden'
    for(int i=0; i<n*n; i++) {
        display[i] = ' ';
    }

    // Start the game loop
    while(score < n*n/2) { // Game ends when all pairs have been found
        // Display the current state of the board
        printf("\n");
        for(int i=0; i<n*n; i++) {
            printf("[%c] ", display[i]);
            if((i+1)%n == 0) printf("\n");
        }

        // Get input from user
        int pos;
        printf("Enter a position to flip (-1 to exit): ");
        scanf("%d", &pos);
        if(pos == -1) break;

        if(display[pos] != ' ') {
            printf("Block has already been flipped!\n");
            continue;
        }

        // Flip the selected block
        display[pos] = values[pos];
        count++;

        if(count % 2 == 1) {
            flipped1 = pos;
        } else {
            flipped2 = pos;
            // Check if the two flipped blocks match
            if(values[flipped1] == values[flipped2]) {
                printf("Match found!\n");
                score++;
            } else {
                printf("No match.\n");
                // Flip the blocks back over after a 1 second delay
                sleep(1);
                display[flipped1] = ' ';
                display[flipped2] = ' ';
            }
        }
    }

    // Game over
    printf("Game Over!\n");
    printf("Score: %d/%d\n", score, n*n/2);
    return 0;
}