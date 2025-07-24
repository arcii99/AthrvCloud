//FormAI DATASET v1.0 Category: Math exercise ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()
{
    // Declare variables
    int a, b, c;
    float x1, x2;

    // Generate random numbers for a, b, and c
    srand(time(NULL));
    a = (rand() % 10) + 1;
    b = (rand() % 10) + 1;
    c = (rand() % 10) + 1;

    // Calculate the discriminant
    float discriminant = (b * b) - (4 * a * c);

    // Calculate the roots of the quadratic equation
    if (discriminant > 0) {
        x1 = (-b + sqrt(discriminant)) / (2 * a);
        x2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("The roots are %.2f and %.2f\n", x1, x2);
    }
    else if (discriminant == 0) {
        x1 = -b / (2 * a);
        printf("The root is %.2f\n", x1);
    }
    else {
        printf("The roots are imaginary\n");
    }

    // Calculate the area of a circle with random radius
    float radius = (rand() % 10) + 1;
    float area = M_PI * pow(radius, 2);
    printf("The area of the circle with radius %.2f is %.2f\n", radius, area);

    // Calculate the factorial of a random number
    int num = (rand() % 10) + 1;
    int fact = 1;
    for (int i = 1; i <= num; i++) {
        fact *= i;
    }
    printf("The factorial of %d is %d\n", num, fact);

    return 0;
}