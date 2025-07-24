//FormAI DATASET v1.0 Category: Bitwise operations ; Style: standalone
#include <stdio.h>

// Function to convert decimal to binary
void decimalToBinary(int decimalNumber)
{
    int binaryNum[20];
    int i = 0;
    
    while(decimalNumber > 0)
    {
        binaryNum[i] = decimalNumber % 2;
        decimalNumber /= 2;
        i++;
    }
    
    // Printing the binary array in reverse order
    printf("Binary Number: ");
    for(int j = i - 1; j >= 0; j--)
    {
        printf("%d", binaryNum[j]);
    }    
}

// Function to convert binary to decimal
void binaryToDecimal(int binaryNumber)
{
    int decimal = 0;
    int base = 1;
    
    while(binaryNumber > 0)
    {
        int lastDigit = binaryNumber % 10;
        binaryNumber = binaryNumber / 10;
        decimal += lastDigit * base;
        base = base * 2;
    }
    
    printf("Decimal Number: %d", decimal);
}

int main()
{
    int a = 5;  // Binary: 00000101
    int b = 9;  // Binary: 00001001
    
    // Bitwise AND Operation
    int result1 = a & b;  // Binary: 00000001
    printf("Bitwise AND Operation: %d\n", result1);
    
    // Bitwise OR Operation
    int result2 = a | b;  // Binary: 00001101
    printf("Bitwise OR Operation: %d\n", result2);
    
    // Bitwise XOR Operation
    int result3 = a ^ b;  // Binary: 00001100
    printf("Bitwise XOR Operation: %d\n", result3);
    
    // Bitwise Complement (~) Operation
    int result4 = ~a;  // Binary: 11111010
    printf("Bitwise Complement (~) Operation: %d\n", result4);
    
    // Bitwise Left Shift Operation
    int result5 = a << 2;  // Binary: 00010100
    printf("Bitwise Left Shift Operation: %d\n", result5);
    
    // Bitwise Right Shift Operation
    int result6 = a >> 2;  // Binary: 00000001
    printf("Bitwise Right Shift Operation: %d\n", result6);
    
    // Converting Decimal to Binary
    int decimalNumber = 85;
    decimalToBinary(decimalNumber);
    printf("\n");
    
    // Converting Binary to Decimal
    int binaryNumber = 1010101;
    binaryToDecimal(binaryNumber);
    printf("\n");
    
    return 0;
}