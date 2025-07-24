//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: happy
#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;
    double s, area;

    printf("Let's calculate the area of a triangle using the Heron's formula!\n");
    printf("Enter the length of side a: ");
    scanf("%lf", &a);
    printf("Enter the length of side b: ");
    scanf("%lf", &b);
    printf("Enter the length of side c: ");
    scanf("%lf", &c);

    s = (a + b + c) / 2;
    area = sqrt(s * (s-a) * (s-b) * (s-c));

    printf("The area of the triangle is %lf\n", area);

    return 0;
}