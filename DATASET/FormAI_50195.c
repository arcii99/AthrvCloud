//FormAI DATASET v1.0 Category: Fractal Generation ; Style: Ken Thompson
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void drawFractal(int x1, int y1, int x2, int y2, int n){
    if(n == 0){
        return;
    }
    int deltaX = x2 - x1;
    int deltaY = y2 - y1;
    int x3 = x2 - deltaY;
    int y3 = y2 + deltaX;
    int x4 = x1 - deltaY;
    int y4 = y1 + deltaX;

    drawFractal(x1, y1, x4, y4, n-1);
    drawFractal(x4, y4, x3, y3, n-1);
    drawFractal(x3, y3, x2, y2, n-1);
    drawFractal(x2, y2, x1, y1, n-1);
}

int main(){
    int x1 = 0;
    int y1 = 0;
    int x2 = 300;
    int y2 = 300;
    int n = 4;

    drawFractal(x1, y1, x2, y2, n);

    return 0;
}