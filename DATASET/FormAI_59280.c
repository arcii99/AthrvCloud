//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct {
    int x;
    int y;
} Pixel;

void drawPixel(Pixel pixel) {
    printf("%c[38;5;%dm%c[48;5;%dm%c[%d;%dH%c", 27, rand()%255+1, 27, rand()%255+1, 27, pixel.x, pixel.y, 219);
}

void clearScreen() {
    printf("%c[2J", 27);
}

int main() {
    srand(time(NULL));
    int rows = 30;
    int cols = 80;
    Pixel pixelArr[rows*cols];
    for(int i = 0; i < rows*cols; i++) {
        pixelArr[i].x = rand()%rows+1;
        pixelArr[i].y = rand()%cols+1;
    }
    clearScreen();
    while(1) {
        for(int i = 0; i < rows*cols; i++) {
            drawPixel(pixelArr[i]);
        }
        usleep(50000);
    }
    return 0;
}