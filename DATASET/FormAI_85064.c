//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: energetic
#include <stdio.h>

int main() {
    printf("Welcome to the C Pixel Art Generator!\n");

    printf("How many rows of pixels do you want to generate? (max 20)\n");
    int rows;
    scanf("%d", &rows);

    printf("And how many columns of pixels do you want to generate? (max 20)\n");
    int columns;
    scanf("%d", &columns);

    printf("Great! Generating your pixel art now...\n\n");

    // Define a 2D array to hold the pixel data
    int pixels[20][20];

    // Generate random pixel data and print out the art
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            pixels[i][j] = rand() % 2; // Randomly choose between 0 and 1
            printf("%d ", pixels[i][j]);
        }
        printf("\n");
    }

    printf("\nThanks for using the C Pixel Art Generator!");

    return 0;
}