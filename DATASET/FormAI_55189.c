//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// This function generates a random value between min and max (inclusive)
int randInRange(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// This function prints out a 8x8 pixel art, where each pixel is a random shade of grey between 0 and 255
void printPixelArt() {
    printf("=====\n");
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            int shade = randInRange(0, 255);
            printf("%02x ", shade);
        }
        printf("\n");
    }
    printf("=====\n");
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate and print 3 different 8x8 pixel arts
    for (int i = 0; i < 3; i++) {
        printf("Pixel Art %d:\n", i + 1);
        printPixelArt();
    }

    return 0;
}