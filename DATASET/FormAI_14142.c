//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: romantic
#include <stdio.h>
#include <math.h>

int main() {
    float x1, y1, x2, y2, x3, y3;
    float a, b, c, s, area;
    float radius, circum;

    printf("My love,\n");
    printf("Please enter the coordinates of the first point: ");
    scanf("%f %f", &x1, &y1);
    printf("Please enter the coordinates of the second point: ");
    scanf("%f %f", &x2, &y2);
    printf("Please enter the coordinates of the third point: ");
    scanf("%f %f", &x3, &y3);

    a = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
    b = sqrt(pow(x3-x2, 2) + pow(y3-y2, 2));
    c = sqrt(pow(x1-x3, 2) + pow(y1-y3, 2));
    s = (a + b + c) / 2;
    area = sqrt(s * (s-a) * (s-b) * (s-c));
    radius = a * b * c / (4 * area);
    circum = 2 * M_PI * radius;

    printf("\nMy dear, did you know?\n");
    printf("The area of the triangle made by our love is: %f\n", area);
    printf("The circumradius of our love triangle is: %f\n", radius);
    printf("The circumference of our love circle is: %f\n", circum);

    return 0;
}