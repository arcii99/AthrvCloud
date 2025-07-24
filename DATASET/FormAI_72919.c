//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Sherlock Holmes
#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c, s, area;

    printf("Enter the three sides of the triangle: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    // checking if the triangle is valid
    if (a + b > c && b + c > a && c + a > b) {
        // calculating the semi-perimeter of the triangle
        s = (a + b + c) / 2;
        // calculate the area of the triangle using Heron's formula
        area = sqrt(s * (s - a) * (s - b) * (s - c));
        printf("The area of the triangle is: %lf\n", area);
    } else {
        printf("Invalid triangle!\n");
    }
    return 0;
}