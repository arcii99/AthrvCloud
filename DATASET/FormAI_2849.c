//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 16
#define HEIGHT 16

void fillPixel(int x, int y, char pixels[HEIGHT][WIDTH], char color){
    if(x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT){
        pixels[y][x] = color;
    }
}

void printPixels(char pixels[HEIGHT][WIDTH]){
    for(int i=0; i<HEIGHT; i++){
        for(int j=0; j<WIDTH; j++){
            printf("%c", pixels[i][j]);
        }
        printf("\n");
    }
}

int main(){
    char pixels[HEIGHT][WIDTH];

    //Initialize pixels to spaces
    for(int i=0; i<HEIGHT; i++){
        for(int j=0; j<WIDTH; j++){
            pixels[i][j] = ' ';
        }
    }

    srand(time(NULL)); //Seed the random number generator

    //Generate random pixel art
    for(int i=0; i<HEIGHT; i++){
        for(int j=0; j<WIDTH; j++){
            int randNum = rand() % 10;
            if(randNum < 5){
                fillPixel(j, i, pixels, '@');
            } else {
                fillPixel(j, i, pixels, '#');
            }
        }
    }

    //Print the pixel art
    printPixels(pixels);

    return 0;
}