//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 25

void printPixel(char c) {
    printf("%c",c);
}

char getRandomPixel() {
    char pixels[10] = {'*', '+', '-', '#', '.', ',', ':', ';', 'O', ' '};
    int randomIndex = rand() % 10;
    return pixels[randomIndex];
}

void generatePixelImage(char pixelArr[HEIGHT][WIDTH]) {
    int x, y;
    for (y=0; y<HEIGHT; y++) {
        for (x=0; x<WIDTH; x++) {
            pixelArr[y][x] = getRandomPixel();
        }
    }
}

void printPixelImage(char pixelArr[HEIGHT][WIDTH]) {
    int x, y;
    for (y=0; y<HEIGHT; y++) {
        for (x=0; x<WIDTH; x++) {
            printPixel(pixelArr[y][x]);
        }
        printf("\n");
    }
}

int main() {
    char pixelArr[HEIGHT][WIDTH];
    srand(time(0)); // seed the random number generator with the current time

    generatePixelImage(pixelArr);
    printPixelImage(pixelArr);

    return 0;
}