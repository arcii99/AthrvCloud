//FormAI DATASET v1.0 Category: Math exercise ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double x = 0.5, y = 1.5;

    // calculate the sine of x and y
    double sin_x = sin(x);
    double sin_y = sin(y);

    // calculate the cosine of x and y
    double cos_x = cos(x);
    double cos_y = cos(y);

    // calculate the tangent of x and y
    double tan_x = tan(x);
    double tan_y = tan(y);

    // calculate the square root of x and y
    double sqrt_x = sqrt(x);
    double sqrt_y = sqrt(y);

    // calculate the natural logarithm of x and y
    double log_x = log(x);
    double log_y = log(y);

    // calculate the exponential of x and y
    double exp_x = exp(x);
    double exp_y = exp(y);

    // calculate the absolute value of x and y
    double abs_x = fabs(x);
    double abs_y = fabs(y);

    // calculate the power of x and y
    double pow_x_y = pow(x, y);

    // print the results
    printf("The sine of %.2f is %.2f\n", x, sin_x);
    printf("The cosine of %.2f is %.2f\n", x, cos_x);
    printf("The tangent of %.2f is %.2f\n", x, tan_x);
    printf("The square root of %.2f is %.2f\n", x, sqrt_x);
    printf("The natural logarithm of %.2f is %.2f\n", x, log_x);
    printf("The exponential of %.2f is %.2f\n", x, exp_x);
    printf("The absolute value of %.2f is %.2f\n", x, abs_x);

    printf("\n");

    printf("The sine of %.2f is %.2f\n", y, sin_y);
    printf("The cosine of %.2f is %.2f\n", y, cos_y);
    printf("The tangent of %.2f is %.2f\n", y, tan_y);
    printf("The square root of %.2f is %.2f\n", y, sqrt_y);
    printf("The natural logarithm of %.2f is %.2f\n", y, log_y);
    printf("The exponential of %.2f is %.2f\n", y, exp_y);
    printf("The absolute value of %.2f is %.2f\n", y, abs_y);

    printf("\n");

    printf("%.2f raised to the power of %.2f is %.2f.\n", x, y, pow_x_y);

    return 0;
}