//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void drawPixel(int x, int y, int color){
    printf("\033[38;5;%dm@\033[0m", color);
    fflush(stdout);
}

int main(){
    int width = 40;
    int height = 20;
    int colors[] = {0, 15, 16, 17, 18, 19, 20, 21, 57, 58, 59, 60, 61, 62, 63, 64};
    int numColors = sizeof(colors)/sizeof(colors[0]);
    int color;
    srand(time(NULL));

    for(int y=0; y<height; y++){
        for(int x=0; x<width; x++){
            color = colors[rand() % numColors];
            drawPixel(x, y, color);
        }
        printf("\n");
    }

    return 0;
}