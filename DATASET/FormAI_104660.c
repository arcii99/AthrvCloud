//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void generatePixelArt(int pixels[SIZE][SIZE]);

int main(){
    int pixelArt[SIZE][SIZE];

    // Seed random number generator
    srand(time(NULL));

    // Generate pixel art
    generatePixelArt(pixelArt);

    // Print pixel art
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(pixelArt[i][j]){
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}

void generatePixelArt(int pixels[SIZE][SIZE]){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            pixels[i][j] = rand() % 2;
        }
    }
}