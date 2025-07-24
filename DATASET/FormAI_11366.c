//FormAI DATASET v1.0 Category: Error handling ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double divide(double a, double b){
    if(b == 0){
        fprintf(stderr, "[ERROR]: Division by zero is not allowed.\n");
        exit(EXIT_FAILURE);
    }
    return a/b;
}

double square_root(double a){
    if(a < 0){
        fprintf(stderr, "[ERROR]: Square root of a negative number is not defined.\n");
        exit(EXIT_FAILURE);
    }
    return sqrt(a);
}

int main(){
    double a, b;

    printf("Enter two numbers to divide:\n");
    scanf("%lf%lf", &a, &b);

    double result = divide(a, b);
    printf("The result of the division is: %lf\n", result);

    printf("Enter a number to find the square root of:\n");
    scanf("%lf", &a);

    double sqrt_result = square_root(a);
    printf("The square root of %lf is: %lf\n", a, sqrt_result);

    return 0;
}