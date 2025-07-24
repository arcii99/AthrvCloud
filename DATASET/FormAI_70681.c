//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed random number generator with current time

    int width, height, color_depth;
    printf("Enter width of pixel art: ");
    scanf("%d", &width);
    printf("Enter height of pixel art: ");
    scanf("%d", &height);
    printf("Enter color depth of pixel art (1-255): ");
    scanf("%d", &color_depth);

    // allocate memory for pixel art array
    int **pix = malloc(height * sizeof(int*));
    for (int i = 0; i < height; i++) {
        pix[i] = malloc(width * sizeof(int));
    }

    // generate random pixel art
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            pix[i][j] = rand() % color_depth + 1; // random color value
        }
    }

    // print pixel art
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", pix[i][j]); // print color value
        }
        printf("\n"); // move to next row
    }

    // free allocated memory
    for (int i = 0; i < height; i++) {
        free(pix[i]);
    }
    free(pix);

    return 0;
}