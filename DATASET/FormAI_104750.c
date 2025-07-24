//FormAI DATASET v1.0 Category: Fractal Generation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void midpoint(double x1, double y1, double x2, double y2, int n) {
    double xNew, yNew, slope, distance, angle;
    if (n == 0) {
        printf("%lf %lf\n", x1, y1);
        printf("%lf %lf\n", x2, y2);
    }
    else {
        distance = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
        angle = atan((y2 - y1)/(x2 - x1));
        slope = tan(angle + M_PI/4);
        xNew = x1 + distance/2 * cos(angle);
        yNew = y1 + distance/2 * sin(angle);
        midpoint(x1, y1, xNew, yNew, n-1);
        midpoint(xNew, yNew, x2, y2, n-1);
    }
}

int main() {
    int iter;
    double x1, y1, x2, y2;
    printf("Enter the number of iterations: ");
    scanf("%d", &iter);
    x1 = 0;
    y1 = 0;
    x2 = 1;
    y2 = 1;
    midpoint(x1, y1, x2, y2, iter);
    return 0;
}