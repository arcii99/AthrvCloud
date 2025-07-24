//FormAI DATASET v1.0 Category: Educational ; Style: mathematical
/*
A program to calculate the LCM of two integers using the Euclidean Algorithm
Author: Chatbot AI
*/

#include <stdio.h>

int gcd(int a, int b) {
    // computes the greatest common divisor of two integers a and b using the Euclidean algorithm
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a%b);
    }
}

int lcm(int a, int b) {
    // computes the least common multiple of two integers a and b
    return (a * b) / gcd(a, b);
}

int main() {
    int num1, num2, lcm_result;

    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);

    lcm_result = lcm(num1, num2);

    printf("The LCM of %d and %d is %d", num1, num2, lcm_result);

    return 0;
}