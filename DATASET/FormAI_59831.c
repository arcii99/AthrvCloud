//FormAI DATASET v1.0 Category: Fractal Generation ; Style: Cyberpunk
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define SIZE 1000 // Size of the fractal

int main() {
    srand(time(NULL)); // Initialize random seed

    int fractal[SIZE][SIZE]; // 2D array to hold fractal values
    fractal[0][0] = rand() % 256; // Initialize first value

    // Populate top row with random values
    for (int i = 1; i < SIZE; i++) {
        fractal[0][i] = (fractal[0][i - 1] + rand() % 256) % 256;
    }

    // Populate remaining values using the Bifurcation Formula
    for (int i = 1; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            fractal[i][j] = (fractal[i - 1][j] * fractal[i - 1][(j + 1) % SIZE]) % 256;
        }
    }

    // Print fractal to console in ASCII format
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            char symbol = ' '; // Default symbol is empty space
            int value = fractal[i][j];

            if (value >= 0 && value < 64) {
                symbol = '.'; // Low values represented by dots
            } else if (value >= 64 && value < 128) {
                symbol = '|'; // Mid values represented by vertical bars
            } else if (value >= 128 && value < 192) {
                symbol = '='; // High values represented by equal signs
            } else if (value >= 192) {
                symbol = '#'; // Very high values represented by hashtags
            }

            printf("%c", symbol);
        }

        printf("\n");
    }

    return 0;
}