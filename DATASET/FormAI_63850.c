//FormAI DATASET v1.0 Category: Scientific ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

double find_sum(int n) {
    double sum = 0.0;
    int i;
    for(i = 1; i <= n; i++) {
        double x = i * PI / n;
        sum += sin(x);
    }
    return sum;
}

double trapezoidal_rule(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = (sin(a) + sin(b)) / 2.0;
    int i;
    for(i = 1; i < n; i++) {
        double x = a + i * h;
        sum += sin(x);
    }
    return h * sum;
}

int main() {
    int n = 1000000;
    double sum = find_sum(n);
    printf("The sum of sin(x) for x = 0 to pi is: %lf\n", sum);

    double a = 0.0, b = PI / 2.0;
    double integral = trapezoidal_rule(a, b, n);
    printf("The integral of sin(x) from 0 to pi/2 using the trapezoidal rule with %d intervals is: %lf\n", n, integral);

    return 0;
}