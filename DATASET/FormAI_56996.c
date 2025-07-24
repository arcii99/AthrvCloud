//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Romeo and Juliet
#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c;
    float s, area;

    printf("Enter the length of side a: ");
    scanf("%f", &a);

    printf("Enter the length of side b: ");
    scanf("%f", &b);

    printf("Enter the length of side c: ");
    scanf("%f", &c);

    s = (a + b + c) / 2;
    area = sqrt(s * (s - a) * (s - b) * (s - c));

    printf("The area of the triangle is: %.2f\n", area);

    return 0;
}