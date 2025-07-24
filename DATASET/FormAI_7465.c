//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int height, width;

    printf("Enter the height of the pixel art: ");
    scanf("%d", &height);

    printf("Enter the width of the pixel art: ");
    scanf("%d", &width);

    int pixels[height][width];

    // Generating random pixel values
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            pixels[i][j] = rand() % 10;
        }
    }

    // Printing the pixel art
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            printf("%d ", pixels[i][j]);
        }
        printf("\n");
    }

    return 0;
}