//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int width, height;

    printf("Enter width and height of the canvas: ");
    scanf("%d %d", &width, &height);

    if (width <= 0 || height <= 0) {
        printf("Invalid input. Both width and height must be positive integers.\n");
        return 1;
    }

    srand(time(NULL));

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int r = rand() % 256;
            int g = rand() % 256;
            int b = rand() % 256;

            printf("\033[48;2;%d;%d;%dm  \033[0m", r, g, b);
        }
        printf("\n");
    }

    return 0;
}