//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: excited
#include <stdio.h>
#include <math.h>

int main()
{
    printf("Welcome to the exciting world of geometric algorithms!\n\n");

    printf("Today, we will be finding the area of a triangle using the Pythagorean theorem and the cross product formula.\n\n");

    double x1, y1, x2, y2, x3, y3;

    printf("Enter the coordinates of the first point (x1, y1): ");
    scanf("%lf %lf", &x1, &y1);

    printf("Enter the coordinates of the second point (x2, y2): ");
    scanf("%lf %lf", &x2, &y2);

    printf("Enter the coordinates of the third point (x3, y3): ");
    scanf("%lf %lf", &x3, &y3);

    double a = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
    double b = sqrt(pow(x3-x2, 2) + pow(y3-y2, 2));
    double c = sqrt(pow(x1-x3, 2) + pow(y1-y3, 2));

    double s = (a + b + c) / 2; // Semiperimeter

    double area_pythagorean = sqrt(s * (s-a) * (s-b) * (s-c));

    printf("The area of the triangle using the Pythagorean theorem is %.2f.\n\n", area_pythagorean);

    double x12 = x2-x1, y12 = y2-y1;
    double x23 = x3-x2, y23 = y3-y2;
    double x31 = x1-x3, y31 = y1-y3;

    double cross_product = fabs(x12 * y23 - y12 * x23); // Magnitude of cross product

    double area_cross_product = cross_product / 2;

    printf("The area of the triangle using the cross product formula is %.2f.\n\n", area_cross_product);

    if (area_pythagorean == area_cross_product) {
        printf("The two methods produced the same result. How exciting!\n");
    } else {
        printf("Oh no, the results didn't match. We must have made a mistake somewhere. Let's try again!\n");
    }

    return 0;
}