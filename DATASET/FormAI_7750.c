//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
    srand(time(NULL)); // initialise the random number generator with current time

    int map[10][10]; // create a 10 x 10 map

    // fill the map with random values
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            map[i][j] = rand() % 2; // randomly assign 0 or 1
        }
    }

    // print out the generated map
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }

    return 0;
}