//FormAI DATASET v1.0 Category: Math exercise ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.141592653589793
#define MAX_ITER 100000 // Maximum number of iterations for the numerical integration method

// The function to be integrated
double func(double x, double y) {
    return exp(-(x*x + y*y)/2) / (2 * PI);
}

// Function to generate a random number between min and max
double randDouble(double min, double max) {
    double r = (double)rand() / RAND_MAX;
    return min + r * (max - min);
}

// The numerical integration method (Monte Carlo Method)
double integrate(double a, double b, double c, double d) {
    double sum = 0;
    srand(time(NULL)); // Seed the random number generator
    for (int i = 0; i < MAX_ITER; i++) {
        double x = randDouble(a, b);
        double y = randDouble(c, d);
        sum += func(x, y);
    }
    return (b - a) * (d - c) * sum / MAX_ITER;
}

int main(void) {
    double a, b, c, d;
    printf("Enter the limits of integration (a, b, c, d): ");
    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
    double result = integrate(a, b, c, d);
    printf("The result of the integration is: %lf\n", result);
    return 0;
}