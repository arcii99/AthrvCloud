//FormAI DATASET v1.0 Category: Fractal Generation ; Style: innovative
#include <stdio.h>

void drawFractal(int x1, int y1, int x2, int y2, int depth)
{
    if(depth == 0)
    {
        printf("Draw line from (%d, %d) to (%d, %d)\n", x1, y1, x2, y2);
    }
    else
    {
        int dx = x2 - x1;
        int dy = y2 - y1;
        int newX = x1 + dx / 3;
        int newY = y1 + dy / 3;
        int newXX = x2 - dx / 3;
        int newYY = y2 - dy / 3;
        int deltaX = newX - newXX;
        int deltaY = newY - newYY;
        int x3 = newXX + deltaY;
        int y3 = newYY - deltaX;
        drawFractal(x1, y1, newX, newY, depth - 1);
        drawFractal(newX, newY, x3, y3, depth - 1);
        drawFractal(x3, y3, newXX, newYY, depth - 1);
        drawFractal(newXX, newYY, x2, y2, depth - 1);
    }
}

int main()
{
    int x1 = 0;
    int y1 = 0;
    int x2 = 300;
    int y2 = 0;
    int depth = 4;
    drawFractal(x1, y1, x2, y2, depth);
    return 0;
}