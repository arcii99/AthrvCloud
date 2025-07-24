//FormAI DATASET v1.0 Category: Bitwise operations ; Style: thoughtful
#include <stdio.h>

// Function to convert decimal to binary
void decimalToBinary(int n)
{
    // array to store binary number
    int binaryNum[32];
 
    // counter for binary array
    int i = 0;
    while (n > 0) {
 
        // storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
 
    // printing binary array in reverse order
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binaryNum[j]);
}

int main()
{
    // example usage: perform a left shift operation
    int x = 10;  // decimal value
    printf("Decimal value of x: %d\n", x);
    printf("Binary value of x: ");
    decimalToBinary(x);
    printf("\n");

    // perform a left shift operation by 1 bit
    int y = x << 1;
    printf("Decimal value of x after left shift by 1 bit: %d\n", y);
    printf("Binary value of x after left shift by 1 bit: ");
    decimalToBinary(y);
    printf("\n");

    return 0;
}