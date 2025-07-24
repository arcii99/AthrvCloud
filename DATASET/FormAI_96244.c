//FormAI DATASET v1.0 Category: Scientific ; Style: curious
#include <stdio.h>

int main() {
    printf("Welcome to the scientific program!\n");
    printf("Enter a value for X: ");
    float x;
    scanf("%f", &x);
    printf("Enter a value for Y: ");
    float y;
    scanf("%f", &y);

    printf("Calculating...\n\n");

    float numerator = (x*x) + (y*y);
    float denominator = (x*y) - (x+y);
    float result = numerator/denominator;

    printf("The value of (X^2 + Y^2)/(XY - X - Y) is: %f\n", result);

    printf("Now, let's explore some more!\n");
    printf("Enter a value for Z: ");
    float z;
    scanf("%f", &z);

    printf("Calculating...\n\n");

    float a = (2*x) - y/z;
    float b = 3*z + y/x;
    float c = (x + y + z) / (x*y*z);

    printf("The value of (2X - Y/Z) + (3Z + Y/X) + (X + Y + Z)/(XYZ) is: %f\n", a+b+c);

    printf("Thanks for exploring with me today! Goodbye!\n");

    return 0;
}