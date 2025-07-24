//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); //Seed the random number generator
    
    char pixel[8][8]; //8x8 pixel art array
    
    //Fill in the pixel array randomly with either a space or an asterisk
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            int random = rand() % 2;
            if (random == 0) {
                pixel[i][j] = ' ';
            } else {
                pixel[i][j] = '*';
            }
        }
    }
    
    //Print out the pixel art array
    printf("Pixel Art:\n\n");
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%c ", pixel[i][j]);
        }
        printf("\n");
    }

    //Count the number of asterisks in the pixel art
    int asteriskCount = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (pixel[i][j] == '*') {
                asteriskCount++;
            }
        }
    }

    //Print out the number of asterisks in the pixel art
    printf("\nNumber of asterisks: %d\n", asteriskCount);

    return 0;
}