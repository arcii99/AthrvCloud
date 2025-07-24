//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: funny
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 10
#define HEIGHT 10

void printPixelArt(int pixelArt[HEIGHT][WIDTH]) {
    printf("Pixel Art:\n");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (pixelArt[i][j] == 1) {
                printf("#");
            } else {
                printf("_");
            }
        }
        printf("\n");
    }
}

int main() {
    int pixelArt[HEIGHT][WIDTH];
    srand(time(NULL));
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            pixelArt[i][j] = rand() % 2;
        }
    }
    printPixelArt(pixelArt);
    return 0;
}