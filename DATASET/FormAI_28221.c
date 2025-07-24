//FormAI DATASET v1.0 Category: Scientific ; Style: creative
#include <stdio.h>

// Function to calculate factorial recursively
int factorial(int n) {
    if(n == 0) {
        return 1;
    }
    else {
        return n * factorial(n-1);
    }
}

// Function to calculate fibonacci sequence recursively
int fibonacci(int n) {
    if(n <= 1) {
        return n;
    }
    else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

// Main function
int main() {

    printf("Welcome to the scientific C program!\n\n");

    // Factorial calculation
    int fact_num = 5;
    int fact_res = factorial(fact_num);
    printf("The factorial of %d is %d\n\n", fact_num, fact_res);

    // Fibonacci sequence calculation
    int fibo_num = 8;
    int fibo_res = fibonacci(fibo_num);
    printf("The %dth number in the fibonacci sequence is %d\n\n", fibo_num, fibo_res);

    // Trigonometric functions
    double angle = 30.0;
    double radian = angle * (3.141592653589793 / 180.0);
    double sin_res = sin(radian);
    double cos_res = cos(radian);
    double tan_res = tan(radian);
    printf("The sin, cos and tan of %f degrees are %f, %f and %f respectively\n\n", angle, sin_res, cos_res, tan_res);

    // Natural log and exponent function
    double log_arg = 2.718281828459045; // e
    double log_res = log(log_arg);
    double exp_arg = 1.0;
    double exp_res = exp(exp_arg);
    printf("The natural log of %f is %f\n", log_arg, log_res);
    printf("The exponent of %f is %f\n\n", exp_arg, exp_res);

    printf("Thanks for using the scientific C program!\n");

    return 0;
}