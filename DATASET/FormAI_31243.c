//FormAI DATASET v1.0 Category: Benchmarking ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int calculate_factorial(int num) {
    int factorial = 1;
    for(int i = 1; i<=num; i++) {
        factorial *= i;
    }
    return factorial;
}

double calculate_power(double base, int exponent) {
    if(exponent == 0) {
        return 1;
    } else if(exponent == 1) {
        return base;
    } else if(exponent % 2 == 0) {
        double power = calculate_power(base, exponent/2);
        return power * power;
    } else {
        double power = calculate_power(base, (exponent-1)/2);
        return base * power * power;
    }
}

int main() {
    
    clock_t start = clock();
    int factorial = calculate_factorial(10);
    printf("Factorial of 10: %d\n", factorial);
    clock_t end = clock();
    double time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to calculate factorial: %f seconds\n", time_taken);
    
    printf("\n");
    
    start = clock();
    double power = calculate_power(2, 10);
    printf("Power of 2 raised to 10: %f\n", power);
    end = clock();
    time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to calculate power: %f seconds\n", time_taken);
    
    return 0;
}