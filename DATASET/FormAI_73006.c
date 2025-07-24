//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Sherlock Holmes
#include <stdio.h>
#include <math.h>

int main()
{
    int x1, y1, x2, y2, x3, y3;
    double a, b, c, s, perimeter, area;

    printf("Enter the coordinates of the first point:\n");
    scanf("%d %d", &x1, &y1);

    printf("Enter the coordinates of the second point:\n");
    scanf("%d %d", &x2, &y2);

    printf("Enter the coordinates of the third point:\n");
    scanf("%d %d", &x3, &y3);

    a = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    b = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
    c = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));

    perimeter = a + b + c;
    s = perimeter / 2;
    area = sqrt(s * (s - a) * (s - b) * (s - c));

    printf("Perimeter of the triangle is: %lf\n", perimeter);
    printf("Area of the triangle is: %lf\n", area);

    return 0;
}