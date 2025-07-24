//FormAI DATASET v1.0 Category: Scientific ; Style: complex
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
   double real;
   double imag;
} complex;

complex add(complex c1, complex c2);
complex subtract(complex c1, complex c2);
complex multiply(complex c1, complex c2);
complex divide(complex c1, complex c2);
complex power(complex c, int n);
double magnitude(complex c);
double phase(complex c);
void print_complex(complex c);

int main() {
    complex c1 = {7.0, 3.0};
    complex c2 = {4.0, -2.0};
    complex sum, diff, prod, quot, pow;
    double mag, phs;

    sum = add(c1, c2);
    diff = subtract(c1, c2);
    prod = multiply(c1, c2);
    quot = divide(c1, c2);
    pow = power(c1, 3);

    mag = magnitude(c1);
    phs = phase(c1);

    printf("Complex Numbers:\n");
    printf("c1 = ");
    print_complex(c1);
    printf("c2 = ");
    print_complex(c2);

    printf("\nOperations:\n");
    printf("c1 + c2 = ");
    print_complex(sum);
    printf("c1 - c2 = ");
    print_complex(diff);
    printf("c1 * c2 = ");
    print_complex(prod);
    printf("c1 / c2 = ");
    print_complex(quot);
    printf("c1^3 = ");
    print_complex(pow);

    printf("\nMagnitude and Phase:\n");
    printf("|c1| = %f\n", mag);
    printf("arg(c1) = %f degrees\n", phs*180/PI);

    return 0;
}

complex add(complex c1, complex c2) {
    complex sum = {c1.real + c2.real, c1.imag + c2.imag};
    return sum;
}

complex subtract(complex c1, complex c2) {
    complex diff = {c1.real - c2.real, c1.imag - c2.imag};
    return diff;
}

complex multiply(complex c1, complex c2) {
    complex prod = {c1.real*c2.real - c1.imag*c2.imag, c1.real*c2.imag + c1.imag*c2.real};
    return prod;
}

complex divide(complex c1, complex c2) {
    double denom = pow(c2.real, 2) + pow(c2.imag, 2);
    complex quot = {(c1.real*c2.real + c1.imag*c2.imag)/denom, (c1.imag*c2.real - c1.real*c2.imag)/denom};
    return quot;
}

complex power(complex c, int n) {
    double r = pow(magnitude(c), n);
    double theta = phase(c)*n;
    complex pow = {r*cos(theta), r*sin(theta)};
    return pow;
}

double magnitude(complex c) {
    return sqrt(pow(c.real, 2) + pow(c.imag, 2));
}

double phase(complex c) {
    return atan2(c.imag, c.real);
}

void print_complex(complex c) {
    if (c.imag < 0) {
        printf("%.2f - %.2fi\n", c.real, fabs(c.imag));
    } else {
        printf("%.2f + %.2fi\n", c.real, c.imag);
    }
}