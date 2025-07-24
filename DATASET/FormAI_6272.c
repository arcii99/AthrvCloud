//FormAI DATASET v1.0 Category: Math exercise ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    int a, b, c;
    double discriminant, x1, x2;

    // Generate random values for a, b, and c
    srand(time(NULL));
    a = rand() % 10;
    b = rand() % 10;
    c = rand() % 10;

    printf("Solve the following quadratic equation:\n");
    printf("%dx^2 + %dx + %d = 0\n", a, b, c);

    // Calculate the discriminant
    discriminant = pow(b, 2) - 4*a*c;

    if (discriminant < 0) {
        printf("The equation has no real roots.\n");
    } else if (discriminant == 0) {
        x1 = -b / (2*a);
        printf("The equation has one real root:\n");
        printf("x = %0.2lf\n", x1);
    } else {
        x1 = (-b + sqrt(discriminant)) / (2*a);
        x2 = (-b - sqrt(discriminant)) / (2*a);
        printf("The equation has two real roots:\n");
        printf("x1 = %0.2lf\n", x1);
        printf("x2 = %0.2lf\n", x2);
    }

    return 0;
}