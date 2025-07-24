//FormAI DATASET v1.0 Category: Bitwise operations ; Style: detailed
#include <stdio.h>

/* Function to convert decimal number to binary */
void decimalToBinary(int n)
{
    int binaryNum[128];
    int i = 0;
    while (n > 0) {

        /* Storing remainder in binary array */
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    /* Printing binary array in reverse order */
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binaryNum[j]);
}

int main()
{
    int num1, num2, result;
    
    /* Bitwise AND example */
    num1 = 5;
    num2 = 6;
    result = num1 & num2;
    printf("The result of bitwise AND of %d and %d is: %d\n", num1, num2, result);
    printf("Binary representation of %d: ", num1);
    decimalToBinary(num1);
    printf("\nBinary representation of %d: ", num2);
    decimalToBinary(num2);
    printf("\nBinary representation of bitwise AND result: ");
    decimalToBinary(result);
    printf("\n\n");

    /* Bitwise OR example */
    num1 = 10;
    num2 = 15;
    result = num1 | num2;
    printf("The result of bitwise OR of %d and %d is: %d\n", num1, num2, result);
    printf("Binary representation of %d: ", num1);
    decimalToBinary(num1);
    printf("\nBinary representation of %d: ", num2);
    decimalToBinary(num2);
    printf("\nBinary representation of bitwise OR result: ");
    decimalToBinary(result);
    printf("\n\n");

    /* Bitwise XOR example */
    num1 = 23;
    num2 = 45;
    result = num1 ^ num2;
    printf("The result of bitwise XOR of %d and %d is: %d\n", num1, num2, result);
    printf("Binary representation of %d: ", num1);
    decimalToBinary(num1);
    printf("\nBinary representation of %d: ", num2);
    decimalToBinary(num2);
    printf("\nBinary representation of bitwise XOR result: ");
    decimalToBinary(result);
    printf("\n\n");

    /* Bitwise NOT example */
    num1 = 55;
    result = ~num1;
    printf("The result of bitwise NOT of %d is: %d\n", num1, result);
    printf("Binary representation of %d: ", num1);
    decimalToBinary(num1);
    printf("\nBinary representation of bitwise NOT result: ");
    decimalToBinary(result);
    printf("\n\n");

    return 0;
}