//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // setting up the seed to get a random sequence
    srand(time(NULL));
    
    char pixels[8][8]; // 8x8 pixel art canvas
    
    // fill the canvas with black pixels
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            pixels[i][j] = ' ';
        }
    }
    
    // generate a random pattern of pixels
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            int random = rand() % 2;
            if(random == 0) {
                pixels[i][j] = ' ';
            } else {
                pixels[i][j] = '#';
            }
        }
    }
    
    // print out the generated pixel art
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            printf("%c ", pixels[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}