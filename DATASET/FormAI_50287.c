//FormAI DATASET v1.0 Category: Arithmetic ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()
{
    // Initialize variables
    int a, b, c;
    float d, e, f;
    double g, h, i;
    long long j, k, l;

    // Get user input
    printf("Enter an integer: ");
    scanf("%d", &a);
    printf("Enter another integer: ");
    scanf("%d", &b);

    // Perform arithmetic operations
    c = a + b;
    printf("%d + %d = %d\n", a, b, c);

    c = a - b;
    printf("%d - %d = %d\n", a, b, c);

    c = a * b;
    printf("%d * %d = %d\n", a, b, c);

    if (b != 0) {
        d = (float)a / (float)b;
        printf("%d / %d = %f\n", a, b, d);
    } else {
        printf("Cannot divide by 0.\n");
        d = NAN;
    }

    // Compute trigonometric functions
    e = sinf(d);
    printf("Sine of %f = %f\n", d, e);

    f = cosf(d);
    printf("Cosine of %f = %f\n", d, f);

    g = tan((double)d);
    printf("Tangent of %f = %lf\n", d, g);

    // Compute exponential function
    h = exp(g);
    printf("Exponential of %lf = %lf\n", g, h);

    // Generate a random number
    srand(time(NULL));
    j = rand() % 100;
    printf("Random integer between 0 to 100: %lld\n", j);

    // Compute power and square root
    k = pow(j, 2);
    printf("%lld squared = %lld\n", j, k);

    if (j >= 0) {
        l = sqrt(j);
        printf("Square root of %lld = %lld\n", j, l);
    } else {
        printf("Cannot take square root of a negative number.\n");
        l = -1;
    }

    return 0;
}