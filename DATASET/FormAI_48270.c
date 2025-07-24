//FormAI DATASET v1.0 Category: Fractal Generation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void draw_fractal(int n);

int main(void)
{
    int n;

    printf("Enter the number of iterations: ");
    scanf("%d", &n);

    draw_fractal(n);

    return 0;
}

void draw_fractal(int n)
{
    double x1, y1, x2, y2, angle;
    int i;

    x1 = 0.5;
    y1 = 0.5;
    x2 = 0.5;
    y2 = 0.6;

    for (i = 0; i < n; i++) {
        angle = atan2(y2 - y1, x2 - x1) - M_PI_2;
        x1 = x2;
        y1 = y2;
        x2 = x1 + 0.4 * cos(angle);
        y2 = y1 + 0.4 * sin(angle);
        printf("%f %f\n", x2, y2);
    }
}