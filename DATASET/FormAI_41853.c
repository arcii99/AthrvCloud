//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: excited
#include <stdio.h>
#include <math.h>

double calculate_area(double a, double b, double c);

int main() {
    double a, b, c;
    printf("Enter the length of side a: ");
    scanf("%lf", &a);
    printf("Enter the length of side b: ");
    scanf("%lf", &b);
    printf("Enter the length of side c: ");
    scanf("%lf", &c);
    double area = calculate_area(a, b, c);
    printf("The area of the triangle is: %lf\n", area);
    return 0;
}

double calculate_area(double a, double b, double c) {
    double s = (a + b + c) / 2;
    double area = sqrt(s * (s - a) * (s - b) * (s - c));
    return area;
}