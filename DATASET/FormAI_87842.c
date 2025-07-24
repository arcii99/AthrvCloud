//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void drawPixel(int color) {
    printf("\033[48;5;%dm ", color);
}

int main() {
    int width, height, numColors, i, j;

    printf("Enter width: ");
    scanf("%d", &width);
    printf("Enter height: ");
    scanf("%d", &height);
    printf("Enter number of colors (0 - 255): ");
    scanf("%d", &numColors);

    if (numColors > 255) {
        printf("Invalid number of colors. Maximum is 255.\n");
        return 1;
    }

    // Seed the random number generator
    srand(time(NULL));

    // Generate random pixels
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            // Generate random color
            int color = rand() % numColors;

            // Draw pixel with color
            drawPixel(color);
        }

        // Move to next line
        printf("\n");
    }

    return 0;
}