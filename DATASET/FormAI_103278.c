//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

void printPixelArt(char art[HEIGHT][WIDTH]);
int getRandomNumber(int min, int max);

int main() {
    srand(time(NULL)); // Seed random number generator
    char art[HEIGHT][WIDTH]; // Create empty pixel art

    // Fill pixel art with random characters
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            int randomNumber = getRandomNumber(0, 2);
            if(randomNumber == 0) {
                art[i][j] = '#'; // Hash symbol
            } else if(randomNumber == 1) {
                art[i][j] = '*'; // Asterisk symbol
            } else {
                art[i][j] = ' '; // Space
            }   
        }
    }

    printPixelArt(art); // Print pixel art to console

    return 0;
}

// Print pixel art to console
void printPixelArt(char art[HEIGHT][WIDTH]) {
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            printf("%c", art[i][j]);
        }
        printf("\n");
    }
}

// Generate random number between min and max (inclusive)
int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}