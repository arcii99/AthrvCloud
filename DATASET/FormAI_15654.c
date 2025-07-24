//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

char canvas[HEIGHT][WIDTH];

void initCanvas(){
    for(int i=0; i<HEIGHT; i++){
        for(int j=0; j<WIDTH; j++){
            canvas[i][j] = ' ';
        }
    }
}

void printCanvas(){
    for(int i=0; i<HEIGHT; i++){
        for(int j=0; j<WIDTH; j++){
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }
}

void drawPixel(int x, int y){
    canvas[y][x] = '*';
}

void drawLine(int x1, int y1, int x2, int y2){
    int dx = abs(x2-x1);
    int dy = abs(y2-y1);
    int sx = (x1<x2)?1:-1;
    int sy = (y1<y2)?1:-1;
    int err = dx-dy;
    while(1){
        drawPixel(x1, y1);
        if(x1==x2 && y1==y2) break;
        int e2 = 2*err;
        if(e2 > -dy){
            err -= dy;
            x1 += sx;
        }
        if(e2 < dx){
            err += dx;
            y1 += sy;
        }
    }
}

void generateArt(){
    srand(time(NULL));
    for(int i=0; i<10; i++){
        int x1 = rand()%WIDTH;
        int y1 = rand()%HEIGHT;
        int x2 = rand()%WIDTH;
        int y2 = rand()%HEIGHT;
        drawLine(x1, y1, x2, y2);
    }
}

int main(){
    initCanvas();
    generateArt();
    printCanvas();
    return 0;
}