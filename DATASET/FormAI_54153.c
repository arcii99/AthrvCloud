//FormAI DATASET v1.0 Category: Arithmetic ; Style: shocked
#include<stdio.h>
#include<math.h>

int main(){
    int a = 10, b = 5;
    float c = 2.5, d = 7.8, result;
    printf("The value of a is %d\n", a);
    printf("The value of b is %d\n", b);
    printf("The value of c is %f\n", c);
    printf("The value of d is %f\n", d);
    printf("Let's perform some arithmetic operations!\n\n");

    // Addition operation
    result = a + b + c + d;
    printf("The result of addition operation is %f\n", result);

    // Subtraction operation
    result = d - a;
    printf("The result of subtraction operation is %f\n", result);

    // Multiplication operation
    result = b * c;
    printf("The result of multiplication operation is %f\n", result);

    // Division operation
    result = c / b;
    printf("The result of division operation is %f\n", result);

    // Modulus operation
    result = b % a;
    printf("The result of modulus operation is %f\n", result);

    // Power operation
    result = pow(a, b);
    printf("The result of power operation is %f\n", result);

    printf("\nWow! These arithmetic operations are amazing. I'm just shocked at how the computer can perform these complex calculations so smoothly.\n");

    return 0;
}