//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

int main(void) {
    srand(time(NULL));
    char pixels[SIZE][SIZE];
    int r, g, b;

    // Generate random RGB values and fill in the pixels array
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            r = rand() % 256;
            g = rand() % 256;
            b = rand() % 256;
            sprintf(pixels[i] + 3 * j, "%02x%02x%02x", r, g, b);
        }
    }

    // Output the generated pixel art
    printf("+");
    for (int i = 0; i < SIZE; i++)
        printf("---+");
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        printf("|");
        for (int j = 0; j < SIZE; j++) {
            printf(" %s |", &pixels[i][3*j]);
        }
        printf("\n+");
        for (int j = 0; j < SIZE; j++) {
            printf("---+");
        }
        printf("\n");
    }

    return 0;
}