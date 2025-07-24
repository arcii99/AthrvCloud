//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int width, height, colors;
    printf("Enter the width and height of the pixel art: ");
    scanf("%d %d", &width, &height);
    printf("Enter the number of available colors (maximum 16): ");
    scanf("%d", &colors);

    if (colors > 16) {
        printf("Error: Maximum number of colors is 16.\n");
        return 1;
    }

    char* color_codes = "0123456789ABCDEF";

    int pixels[height][width];
    int x, y;

    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            pixels[y][x] = rand() % colors;
        }
    }

    printf("Here is your pixel art:\n");

    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            printf("\e[48;5;%dm  \e[0m", pixels[y][x]);
        }
        printf("\n");
    }

    return 0;
}