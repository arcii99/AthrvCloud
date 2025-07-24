//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generatePixel(char canvas[20][20]) {
    int i, j;

    for (i = 0; i < 20; i++) {
        for (j = 0; j < 20; j++) {
            canvas[i][j] = rand() % 2;
        }
    }
}

void displayCanvas(char canvas[20][20]) {
    int i, j;

    for (i = 0; i < 20; i++) {
        for (j = 0; j < 20; j++) {
            if (canvas[i][j] == 0) {
                printf(" ");
            }
            else {
                printf("*");
            }
        }
        printf("\n");
    }
}

int main() {
    char canvas[20][20];
    srand(time(NULL));

    printf("Welcome to the Pixel Art Generator!\n\n");
    printf("Generating new pixel art...\n");
    generatePixel(canvas);
    displayCanvas(canvas);

    return 0;
}