//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Function to generate random numbers from a given range
int getRandom(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    srand(time(NULL)); // Seed for the random number generator

    // Characters used in the pixel art
    char characters[] = {' ', '.', ':', 'o', 'O', '0', '@', 'S', '%', '&', '#'};

    // Dimensions of the pixel art
    int width, height;

    printf("Welcome to the Sherlock Holmes Pixel Art Generator!\n");
    printf("Please enter the width and height of the image (min 10x10, max 100x100):\n");

    // User inputs the dimensions of the pixel art
    scanf("%d %d", &width, &height);

    // Validation for the dimensions
    if (width < 10 || height < 10 || width > 100 || height > 100) {
        printf("Invalid dimensions! Please enter dimensions between 10x10 and 100x100.\n");
        return 0; // Exit the program
    }

    printf("Generating pixel art...\n");

    // Loop to generate the pixel art image
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", characters[getRandom(0, 10)]); // Prints a random character from the characters array
        }
        printf("\n"); // Prints a new line for the next row
    }

    printf("Enjoy your pixel art, my dear Watson!\n");

    return 0;
}