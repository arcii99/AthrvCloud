//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: curious
#include <stdio.h>
#include <math.h>

double heron(double a, double b, double c) {
    double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main() {
    double a, b, c;

    printf("Enter the length of the first side (a): ");
    scanf("%lf", &a);

    printf("Enter the length of the second side (b): ");
    scanf("%lf", &b);

    printf("Enter the length of the third side (c): ");
    scanf("%lf", &c);

    if (a + b <= c || a + c <= b || b + c <= a) {
        printf("Invalid triangle!\n");
        return 1;
    }

    double area = heron(a, b, c);
    printf("The area of the triangle is: %.2lf\n", area);

    return 0;
}