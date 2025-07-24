//FormAI DATASET v1.0 Category: Math exercise ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double customFunction(double x, double y) {
    // You can change the function to anything you want
    double result = y * sin(x) + x * cos(y);
    return result;
}

double numericalIntegral(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0;
    for (int i = 0; i <= n; i++) {
        double x_i = a + (i * h);
        sum += customFunction(x_i, x_i + h);
    }
    return (h / 2) * sum;
}

double numericalDerivative(double x, double h) {
    double firstTerm = customFunction(x + h, x + h) - customFunction(x - h, x - h);
    double secondTerm = 2 * h;
    return firstTerm / secondTerm;
}

int main() {
    // Choose your own parameters here
    double a = 0, b = 2 * M_PI;
    int n = 100;
    double h = 0.01;
    double x = M_PI;

    // Numerical integral calculation and output
    double integral = numericalIntegral(a, b, n);
    printf("Numerical integral of function = %lf\n", integral);

    // Numerical derivative calculation and output
    double derivative = numericalDerivative(x, h);
    printf("Numerical derivative of function at x = %lf, h = %lf = %lf\n", x, h, derivative);

    return 0;
}