//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: futuristic
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int main() {
    float x1, y1, x2, y2, x3, y3; 
    float AB, BC, AC;
    float perimeter, s, area;
 
    // Ask user for input
    printf("Enter the coordinates of point A: ");
    scanf("%f%f", &x1, &y1);

    printf("Enter the coordinates of point B: ");
    scanf("%f%f", &x2, &y2);

    printf("Enter the coordinates of point C: ");
    scanf("%f%f", &x3, &y3);

    // Calculate side lengths
    AB = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    BC = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
    AC = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));

    // Calculate perimeter and semi-perimeter
    perimeter = AB + BC + AC;
    s = perimeter / 2;

    // Calculate area using Heron's formula
    area = sqrt(s * (s - AB) * (s - BC) * (s - AC));

    // Display results
    printf("\nSide lengths:\nAB = %.2f\nBC = %.2f\nAC = %.2f\n", AB, BC, AC);
    printf("Perimeter of triangle = %.2f\n", perimeter);
    printf("Area of triangle = %.2f\n", area);

    return 0;
}