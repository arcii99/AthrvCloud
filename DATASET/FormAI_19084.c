//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: energetic
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void createPixelArt(char art[10][10]) {
    int i, j, randNum;
    char pixels[4] = {'#', '*', '@', '+'}; // pixel characters to use
    srand(time(NULL)); // seed random number generator
    for (i=0; i<10; i++) {
        for (j=0; j<10; j++) {
            randNum = rand() % 4; // generate random number between 0 and 3
            art[i][j] = pixels[randNum]; // set pixel character according to random number
        }
    }
}

int main() {
    char pixelArt[10][10];
    createPixelArt(pixelArt); // generate random pixel art
    int i, j;
    for (i=0; i<10; i++) {
        for (j=0; j<10; j++) {
            printf("%c ", pixelArt[i][j]); // output pixel art to console
        }
        printf("\n"); // newline after each row
    }
    return 0;
}