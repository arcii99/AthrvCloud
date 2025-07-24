//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int width, height;

    // Taking input from the user for the dimensions of the pixel art
    printf("Enter the width of the pixel art: ");
    scanf("%d", &width);
    printf("Enter the height of the pixel art: ");
    scanf("%d", &height);

    // Initializing the random number generator
    srand(time(0));

    // Generating pixel art
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            int pixel = rand() % 10; // Generating a random number between 0 and 9
            printf("%d ", pixel); // Printing the pixel value to the console
        }
        printf("\n"); // Moving to the next line
    }

    return 0;
}