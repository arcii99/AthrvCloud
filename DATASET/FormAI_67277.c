//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: scientific
#include <stdlib.h>
#include <stdio.h>

int main() {
    char pixelArt[10][10];

    //Fill the array with random characters from A to Z
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            pixelArt[i][j] = rand()%26 + 'A';
        }
    }

    //Print the array as a pixel art
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            printf("%c ", pixelArt[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}