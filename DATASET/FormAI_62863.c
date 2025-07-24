//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: unmistakable
#include <stdio.h>
#include <math.h>

int main()
{
    double x1, y1, x2, y2, x3, y3;

    printf("Enter coordinates of point 1: ");
    scanf("%lf %lf", &x1, &y1);

    printf("Enter coordinates of point 2: ");
    scanf("%lf %lf", &x2, &y2);

    printf("Enter coordinates of point 3: ");
    scanf("%lf %lf", &x3, &y3);

    double a = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    double b = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
    double c = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));

    double s = (a + b + c) / 2;

    double area = sqrt(s * (s - a) * (s - b) * (s - c));

    double perimeter = a + b + c;

    printf("Side a = %.2lf\n", a);
    printf("Side b = %.2lf\n", b);
    printf("Side c = %.2lf\n", c);
    printf("Area = %.2lf\n", area);
    printf("Perimeter = %.2lf\n", perimeter);

    return 0;
}