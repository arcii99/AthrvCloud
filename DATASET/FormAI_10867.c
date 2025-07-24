//FormAI DATASET v1.0 Category: Arithmetic ; Style: Claude Shannon
#include <stdio.h>

// Define variables A and B
int A = 12;
int B = 5;

// Define function for calculating greatest common divisor using Euclidean Algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Define function for calculating least common multiple
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

// Define function for calculating the power of a number
int power(int base, int exponent) {
    int result = 1;
    while (exponent != 0) {
        result *= base;
        --exponent;
    }
    return result;
}

// Define function for calculating the factorial of a number
int factorial(int n) {
    int result = 1;
    while (n != 0) {
        result *= n;
        --n;
    }
    return result;
}

// Define main function
int main() {
    // Calculate the greatest common divisor of A and B
    int greatest_common_divisor = gcd(A, B);
    printf("The greatest common divisor of %d and %d is %d\n", A, B, greatest_common_divisor);
    
    // Calculate the least common multiple of A and B
    int least_common_multiple = lcm(A, B);
    printf("The least common multiple of %d and %d is %d\n", A, B, least_common_multiple);
    
    // Calculate the power of A to the Bth power
    int power_of_A = power(A, B);
    printf("%d to the power of %d is %d\n", A, B, power_of_A);
    
    // Calculate the factorial of A
    int A_factorial = factorial(A);
    printf("%d factorial is %d\n", A, A_factorial);
    
    // Print a fun message
    printf("I hope you enjoyed these calculations!\n");
    
    return 0;
}