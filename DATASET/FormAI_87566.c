//FormAI DATASET v1.0 Category: Bitwise operations ; Style: statistical
#include <stdio.h>

// Function to perform bitwise and between two numbers
int bitwiseAnd(int num1, int num2){
    return num1 & num2;
}

// Function to perform bitwise or between two numbers
int bitwiseOr(int num1, int num2){
    return num1 | num2;
}

// Function to perform bitwise exclusive or between two numbers
int bitwiseXor(int num1, int num2){
    return num1 ^ num2;
}

// Function to perform bitwise complement of a number
int bitwiseComplement(int num){
    return ~num;
}

// Main function to test bitwise operations
int main(){
    int num1, num2;

    // Take input from user
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    // Perform bitwise operations and display the output
    printf("Bitwise AND of %d and %d is %d\n", num1, num2, bitwiseAnd(num1, num2));
    printf("Bitwise OR of %d and %d is %d\n", num1, num2, bitwiseOr(num1, num2));
    printf("Bitwise XOR of %d and %d is %d\n", num1, num2, bitwiseXor(num1, num2));
    printf("Bitwise complement of %d is %d\n", num1, bitwiseComplement(num1));

    return 0;
}