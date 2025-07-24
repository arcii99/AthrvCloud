//FormAI DATASET v1.0 Category: Math exercise ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// function to calculate the root of a quadratic equation
void quadratic_solver(double a, double b, double c) {
    // calculate the discriminant
    double d = (b * b) - (4.0 * a * c);
    double x1, x2;
    
    // check the value of the discriminant
    if (d > 0.0) {
        // calculate the two roots
        x1 = (-b + sqrt(d)) / (2.0 * a);
        x2 = (-b - sqrt(d)) / (2.0 * a);
        
        printf("The roots are real and distinct:\n");
        printf("x1 = %.2lf\n", x1);
        printf("x2 = %.2lf\n", x2);
    } else if (d == 0.0) {
        // calculate the single root
        x1 = -b / (2.0 * a);
        
        printf("The root is real and equal:\n");
        printf("x1 = %.2lf\n", x1);
    } else {
        // calculate the real and imaginary parts of the complex roots
        double real_part = -b / (2.0 * a);
        double imag_part = sqrt(fabs(d)) / (2.0 * a);
        
        printf("The roots are complex and conjugate:\n");
        printf("x1 = %.2lf + %.2lfi\n", real_part, imag_part);
        printf("x2 = %.2lf - %.2lfi\n", real_part, imag_part);
    }
}

// function to calculate the factorial of a number
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    
    // calculate the factorial recursively
    return n * factorial(n - 1);
}

int main() {
    // test the quadratic_solver function
    printf("Solve the quadratic equation: 4x^2 + 5x - 1 = 0\n");
    quadratic_solver(4.0, 5.0, -1.0);
    
    // test the factorial function
    printf("Calculate the factorial of 6:\n");
    printf("6! = %d\n", factorial(6));
    
    return 0;
}