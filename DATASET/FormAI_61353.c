//FormAI DATASET v1.0 Category: Fractal Generation ; Style: irregular
#include <stdio.h>
#include <math.h>

void fractal(int level, int x1, int y1, int x2, int y2)
{
    if (level == 0)
    {
        return;
    }
    else
    {
        int x3 = (2 * x1 + x2) / 3;
        int y3 = (2 * y1 + y2) / 3;
        int x4 = (x1 + 2 * x2) / 3;
        int y4 = (y1 + 2 * y2) / 3;
        int dist = sqrt((x4 - x3) * (x4 - x3) + (y4 - y3) * (y4 - y3));
        double angle = M_PI / 3;
        int x5 = x3 + dist * cos(angle);
        int y5 = y3 + dist * sin(angle);
        fractal(level - 1, x1, y1, x3, y3);
        fractal(level - 1, x3, y3, x5, y5);
        fractal(level - 1, x5, y5, x4, y4);
        fractal(level - 1, x4, y4, x2, y2);
        printf("Pen up\n");
    }
}

int main()
{
    printf("Pen down\n");
    fractal(3, 50, 50, 450, 50);
    fractal(3, 450, 50, 450, 450);
    fractal(3, 450, 450, 50, 450);
    fractal(3, 50, 450, 50, 50);
    return 0;
}