//FormAI DATASET v1.0 Category: Memory Game ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

int main() {
    int cards[ROWS][COLS];
    int i, j, k;
    
    // initialize random seed
    srand(time(NULL));
    
    // populate cards with randomized numbers from 1 to 8
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            do {
                cards[i][j] = rand() % 8 + 1;
                // check if number already exists in previous cards
                for (k = 0; k < i * COLS + j; k++) {
                    if (cards[k / COLS][k % COLS] == cards[i][j]) {
                        break;
                    }
                }
            } while (k < i * COLS + j); // repeat until unique number is found
        }
    }
    
    // display cards on screen (face down)
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("[%d]", cards[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}