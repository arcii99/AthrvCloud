//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generatePixelArt(int size) {
    //initialize the random seed
    srand(time(NULL));

    int pixelMap[size][size];

    //fill the pixel map with random numbers between 0 and 1
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            pixelMap[i][j] = rand() % 2;
        }
    }

    //output the pixel art
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            if(pixelMap[i][j] == 0) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

int main() {
    int size;

    printf("Enter the size of the pixel art: ");
    scanf("%d", &size);

    generatePixelArt(size);

    return 0;
}