//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITERATIONS 1000000
#define TOLERANCE 0.000001

double calculate_sin(double x);

int main(int argc, char *argv[]) {
    double x;
    if (argc < 2) {
        printf("Please enter a value for x: ");
        scanf("%lf", &x);
    } else {
        x = atof(argv[1]);
    }
    printf("sin(%lf) = %lf\n", x, calculate_sin(x));
    return 0;
}

double calculate_sin(double x) {
    double sin_x = 0.0;
    double term = x;
    double denominator = 1.0;
    int iteration = 1;
    while (fabs(term) > TOLERANCE && iteration < MAX_ITERATIONS) {
        sin_x += term;
        denominator = denominator * (2 * iteration) * (2 * iteration + 1);
        term = -term * x * x / denominator;
        iteration++;
    }
    return sin_x;
}