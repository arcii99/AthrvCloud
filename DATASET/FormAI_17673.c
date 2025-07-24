//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10
#define PIXEL_SIZE 2

void generatePixelArt(char pixelArt[HEIGHT][WIDTH][PIXEL_SIZE], int row, int col)
{
    if(row == HEIGHT)
        return;
    if(col == WIDTH){
        printf("\n");
        generatePixelArt(pixelArt, row+1, 0);
        return;
    }
    int randomValue = rand() % 2;
    if(randomValue == 0){
        pixelArt[row][col][0] = ' ';
        pixelArt[row][col][1] = ' ';
    }
    else if(randomValue == 1){
        pixelArt[row][col][0] = '#';
        pixelArt[row][col][1] = '#';
    }
    printf("%c%c", pixelArt[row][col][0], pixelArt[row][col][1]);
    generatePixelArt(pixelArt, row, col+1);
}

int main()
{
    srand(time(NULL));
    char pixelArt[HEIGHT][WIDTH][PIXEL_SIZE];
    generatePixelArt(pixelArt, 0, 0);
    return 0;
}