//FormAI DATASET v1.0 Category: Fractal Generation ; Style: shocked
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

void koch_curve(double x1, double y1, double x2, double y2, int n)
{
    if (n == 0)
    {
        printf("%.2f %.2f\n", x1, y1);
        printf("%.2f %.2f\n", x2, y2);
        return;
    }

    double x3 = (2*x1 + x2)/3;
    double y3 = (2*y1 + y2)/3;

    double x4 = (x1 + 2*x2)/3;
    double y4 = (y1 + 2*y2)/3;

    double x5 = x3 + (x4 - x3)*cos(PI/3) - (y4 - y3)*sin(PI/3);
    double y5 = y3 + (x4 - x3)*sin(PI/3) + (y4 - y3)*cos(PI/3);

    koch_curve(x1, y1, x3, y3, n-1);
    koch_curve(x3, y3, x5, y5, n-1);
    koch_curve(x5, y5, x4, y4, n-1);
    koch_curve(x4, y4, x2, y2, n-1);
}

int main()
{
    double x1 = 0.0;
    double y1 = 0.0;

    double x2 = 100.0;
    double y2 = 0.0;

    int n = 3;

    koch_curve(x1, y1, x2, y2, n);

    return 0;
}