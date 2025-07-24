//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: irregular
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {

    srand(time(NULL)); // Seed random number generator with current time
    int map[10][10]; // 10x10 grid for map

    // Populate map randomly
    int i, j;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            map[i][j] = rand() % 2; // Randomly set as 1 or 0 
        }
    }

    // Display map
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }

    return 0;
}