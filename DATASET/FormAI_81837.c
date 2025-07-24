//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void drawPixel(char color) {
    printf("%c", color);
}

void drawArt(char pixels[8][8]) {
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            drawPixel(pixels[i][j]);
        }
        printf("\n");
    }
}

void generateArt(char pixels[8][8]) {
    char colors[4] = {' ', '.', '+', '*'};
    srand(time(NULL));
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            int random_int = rand() % 4;
            pixels[i][j] = colors[random_int];
        }
    }
}

int main() {
    char pixelsArray[8][8];
    printf("Welcome to Pixel Art Generator!\n\n");
    
    generateArt(pixelsArray);
    printf("Your generated Pixel Art:\n");
    printf("==========================\n");
    drawArt(pixelsArray);
    printf("==========================\n\n");
    
    generateArt(pixelsArray);
    printf("Your new generated Pixel Art:\n");
    printf("==============================\n");
    drawArt(pixelsArray);
    printf("==============================\n");
    
    return 0;
}