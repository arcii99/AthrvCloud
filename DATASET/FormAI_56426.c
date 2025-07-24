//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 20

int main()
{
    srand(time(NULL)); // Seed random generator

    char map[HEIGHT][WIDTH];

    // Fill map with random characters
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            int r = rand() % 4;
            if(r == 0) map[i][j] = '#';
            else if(r == 1) map[i][j] = '.';
            else if(r == 2) map[i][j] = '@';
            else map[i][j] = ' ';
        }
    }

    // Print map
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }

    return 0;
}