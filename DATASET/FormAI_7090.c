//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

void generatePixelArt(char pixels[][WIDTH], char chars[], int numChars) {
    srand(time(NULL));
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            int randIndex = rand() % numChars;
            pixels[i][j] = chars[randIndex];
        }
    }
}

void printPixelArt(char pixels[][WIDTH]) {
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            printf("%c", pixels[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char pixelArt[HEIGHT][WIDTH];
    char characters[] = {'*', '+', '-', '=', '/', '\\'};
    int numChars = sizeof(characters) / sizeof(characters[0]);
    generatePixelArt(pixelArt, characters, numChars);
    printPixelArt(pixelArt);
    return 0;
}