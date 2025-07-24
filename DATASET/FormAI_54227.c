//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 50
#define HEIGHT 50

void createArt(int pixel[WIDTH][HEIGHT]) {
    int i, j, r;
    for(i = 0; i < WIDTH; i++) {
        for(j = 0; j < HEIGHT; j++) {
            r = rand() % 4;
            if(r == 0) {
                pixel[i][j] = 0;
            } else if(r == 1) {
                pixel[i][j] = 1;
            } else if(r == 2) {
                pixel[i][j] = 2;
            } else {
                pixel[i][j] = 3;
            }
        }
    }
}

void displayArt(int pixel[WIDTH][HEIGHT]) {
    int i, j;
    for(i = 0; i < WIDTH; i++) {
        for(j = 0; j < HEIGHT; j++) {
            if(pixel[i][j] == 0) {
                printf(".");
            } else if(pixel[i][j] == 1) {
                printf("%c", 219);
            } else if(pixel[i][j] == 2) {
                printf("%c", 43);
            } else {
                printf("%c", 97);
            }
        }
        printf("\n");
    }
}

int main() {
    int pixel[WIDTH][HEIGHT];
    srand(time(NULL));
    createArt(pixel);
    displayArt(pixel);
    return 0;
}