//FormAI DATASET v1.0 Category: Graph representation ; Style: artistic
#include<stdio.h>

//Function to draw a line
void drawLine(int x1, int y1, int x2, int y2)
{
    printf("(%d,%d)--(%d,%d)\n", x1, y1, x2, y2);
}

int main()
{
    int n = 8;
    int x[n], y[n];
    int i;

    //Coordinates of the vertices of the graph
    x[0] = 0, y[0] = 0;
    x[1] = 1, y[1] = 1;
    x[2] = 2, y[2] = 0;
    x[3] = 3, y[3] = 1;
    x[4] = 4, y[4] = 0;
    x[5] = 5, y[5] = 1;
    x[6] = 6, y[6] = 0;
    x[7] = 7, y[7] = 1;

    //Drawing the edges of the graph
    for(i=0; i<n-1; i++)
    {
        drawLine(x[i], y[i], x[i+1], y[i+1]);
    }

    //Drawing the first loop
    drawLine(x[0], y[0], x[2], y[2]);
    drawLine(x[1], y[1], x[3], y[3]);
    drawLine(x[2], y[2], x[4], y[4]);
    drawLine(x[3], y[3], x[5], y[5]);
    drawLine(x[4], y[4], x[6], y[6]);
    drawLine(x[5], y[5], x[7], y[7]);
    drawLine(x[6], y[6], x[0], y[0]);
    drawLine(x[7], y[7], x[1], y[1]);

    //Drawing the second loop
    drawLine(x[0], y[0], x[4], y[4]);
    drawLine(x[1], y[1], x[5], y[5]);
    drawLine(x[2], y[2], x[6], y[6]);
    drawLine(x[3], y[3], x[7], y[7]);
    drawLine(x[4], y[4], x[0], y[0]);
    drawLine(x[5], y[5], x[1], y[1]);
    drawLine(x[6], y[6], x[2], y[2]);
    drawLine(x[7], y[7], x[3], y[3]);

    return 0;
}