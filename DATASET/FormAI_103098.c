//FormAI DATASET v1.0 Category: Math exercise ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Function to calculate factorial of a number
int factorial(int n) {
    int fact = 1;
    for(int i=1; i<=n; i++) {
        fact *= i;
    }
    return fact;
}

// Function to calculate exponential
double exp(double x) {
    double exp_val = 1;
    for(int i=1; i<=10; i++) {
        exp_val += pow(x, i) / factorial(i);
    }
    return exp_val;
}

// Function to calculate square root of a number
double sqrt(double num) {
    double x = num;
    double y = 1;
    double e = 0.000001;
    while(x - y > e) {
        x = (x + y) / 2;
        y = num / x;
    }
    return x;
}

// Function to calculate sine value of an angle
double sin(double angle) {
    double sin_val = 0;
    for(int i=0; i<=10; i++) {
        sin_val += (pow(-1, i) * pow(angle, 2*i+1)) / factorial(2*i+1);
    }
    return sin_val;
}

// Function to calculate cosine value of an angle
double cos(double angle) {
    double cos_val = 0;
    for(int i=0; i<=10; i++) {
        cos_val += (pow(-1, i) * pow(angle, 2*i)) / factorial(2*i);
    }
    return cos_val;
}

// Asynchronous function to generate random numbers
int async_random(int n) {
    srand(time(NULL));
    return rand() % n;
}

// Asynchronous function to calculate square of a number
double async_square(int num) {
    return pow(num, 2);
}

int main() {
    // Example usage of asynchronous functions
    int rand_num = async_random(100);
    double square_num = async_square(rand_num);
    
    // Print the results
    printf("Random number: %d\n", rand_num);
    printf("Square of random number: %f\n", square_num);
    
    // Example usage of synchronous Math functions
    double x = 0.5;
    double exp_val = exp(x);
    double sqrt_val = sqrt(25);
    double sin_val = sin(30 * M_PI / 180);
    double cos_val = cos(45 * M_PI / 180);
    
    // Print the results
    printf("Exponential value of %f: %f\n", x, exp_val);
    printf("Square root of 25: %f\n", sqrt_val);
    printf("Sine value of 30 degrees: %f\n", sin_val);
    printf("Cosine value of 45 degrees: %f\n", cos_val);

    return 0;
}