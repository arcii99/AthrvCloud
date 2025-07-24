//FormAI DATASET v1.0 Category: Fractal Generation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

void drawFractal(int x, int y, int size, int level, int maxLevel);
void fill(int x1, int y1, int x2, int y2);

int main()
{
    int maxLevel, x, y, size;
    printf("Enter level for fractal shape: ");
    scanf("%d", &maxLevel);
    printf("Enter the x and y coordinates for the top left corner: ");
    scanf("%d %d", &x, &y);
    printf("Enter the initial size of the fractal: ");
    scanf("%d", &size);
  
    drawFractal(x, y, size, 0, maxLevel);

    return 0;
}

void drawFractal(int x, int y, int size, int level, int maxLevel)
{
    int x1, y1, x2, y2;

    if (level == maxLevel)
        return;

    drawFractal(x, y, size/3, level+1, maxLevel);
    drawFractal(x+2*size/3, y, size/3, level+1, maxLevel);
    drawFractal(x+size/3, y+size/3, size/3, level+1, maxLevel);
    drawFractal(x, y+2*size/3, size/3, level+1, maxLevel);
    drawFractal(x+2*size/3, y+2*size/3, size/3, level+1, maxLevel);

    x1 = x+size/3;
    y1 = y+size/3;
    x2 = x+2*size/3;
    y2 = y+2*size/3;
    fill(x1, y1,x2, y2);
}

void fill(int x1, int y1, int x2, int y2)
{
    int i, j;
    for(i = x1; i<x2; i++)
        for(j = y1;j<y2;j++)
            printf("* ");
        printf("\n");
}