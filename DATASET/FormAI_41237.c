//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

void drawPixel(int r, int g, int b){
    printf("\033[38;2;%d;%d;%dm█\033[0m", r, g, b);
}

void drawArt(int art[HEIGHT][WIDTH][3], int width, int height){
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            drawPixel(art[i][j][0], art[i][j][1], art[i][j][2]);
        }
        printf("\n");
    }
}

void generateArt(int art[HEIGHT][WIDTH][3], int width, int height){
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            art[i][j][0] = rand() % 256;
            art[i][j][1] = rand() % 256;
            art[i][j][2] = rand() % 256;
        }
    }
}

int main(){
    srand(time(NULL));

    int art[HEIGHT][WIDTH][3];

    generateArt(art, WIDTH, HEIGHT);

    drawArt(art, WIDTH, HEIGHT);

    return 0;
}