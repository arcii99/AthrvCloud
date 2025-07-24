//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20 // width of the pixel art
#define HEIGHT 20 // height of the pixel art

void generatePixelArt(char pixelArt[][HEIGHT]) {
    int x, y;
    srand(time(NULL));
    
    for(x = 0; x < WIDTH; x++) {
        for(y = 0; y < HEIGHT; y++) {
            int randomValue = rand() % 10;
            if(randomValue == 9) {
                pixelArt[x][y] = 'C';
            } else if(randomValue == 8) {
                pixelArt[x][y] = 'A';
            } else if(randomValue == 7) {
                pixelArt[x][y] = 'T';
            } else if(randomValue == 6) {
                pixelArt[x][y] = 'D';
            } else if(randomValue == 5) {
                pixelArt[x][y] = 'O';
            } else if(randomValue == 4) {
                pixelArt[x][y] = 'G';
            } else if(randomValue == 3) {
                pixelArt[x][y] = 'E';
            } else if(randomValue == 2) {
                pixelArt[x][y] = 'R';
            } else if(randomValue == 1) {
                pixelArt[x][y] = 'S';
            } else {
                pixelArt[x][y] = ' ';
            }
        }
    }
}

void displayPixelArt(char pixelArt[][HEIGHT]) {
    int x, y;
    
    printf("   ");
    for(x = 0; x < WIDTH; x++) {
        printf("%d ", x % 10);
    }
    printf("\n");
    
    for(y = 0; y < HEIGHT; y++) {
        printf("%2d ", y);
        for(x = 0; x < WIDTH; x++) {
            printf("%c ", pixelArt[x][y]);
        }
        printf("\n");
    }
}

int main(void) {
    char pixelArt[WIDTH][HEIGHT];
    
    generatePixelArt(pixelArt);
    displayPixelArt(pixelArt);
    
    return 0;
}