//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

void generatePixelArt(){
    srand(time(NULL));
    char characters[3] = {'0', '1', '2'};
    char pixelArt[HEIGHT][WIDTH];
  
    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
            int index = rand() % 3;
            pixelArt[i][j] = characters[index];
        }
    }

    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
            printf("%c ", pixelArt[i][j]);
        }
        printf("\n");
    }
}

int main(){
    generatePixelArt();
    return 0;
}