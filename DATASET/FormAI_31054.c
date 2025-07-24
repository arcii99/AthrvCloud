//FormAI DATASET v1.0 Category: Educational ; Style: Claude Shannon
#include <stdio.h>
#include <math.h>

// Function prototypes
int binaryToDecimal(long long n);
int decimalToBinary(int n);
int bitwiseAnd(int x, int y);
int bitwiseOr(int x, int y);
int bitwiseXor(int x, int y);
int bitwiseNot(int x);

int main()
{
    // Binary to Decimal conversion
    long long binaryNum = 1010101;
    printf("Binary number %lld = Decimal number %d\n", binaryNum, binaryToDecimal(binaryNum));

    // Decimal to Binary conversion
    int decimalNum = 23;
    printf("Decimal number %d = Binary number %d\n", decimalNum, decimalToBinary(decimalNum));

    // Bitwise Operators
    int x = 82;
    int y = 98;
    printf("x = %d, y = %d\n", x, y);
    printf("Bitwise AND: %d\n", bitwiseAnd(x, y));
    printf("Bitwise OR: %d\n", bitwiseOr(x, y));
    printf("Bitwise XOR: %d\n", bitwiseXor(x, y));
    printf("Bitwise NOT x: %d\n", bitwiseNot(x));
    printf("Bitwise NOT y: %d\n", bitwiseNot(y));

    return 0;
}

// Function to convert binary to decimal
int binaryToDecimal(long long n)
{
    int decimalNum = 0, i = 0, remainder;
    while (n != 0)
    {
        remainder = n % 10;
        n /= 10;
        decimalNum += remainder * pow(2, i);
        ++i;
    }
    return decimalNum;
}

// Function to convert decimal to binary
int decimalToBinary(int n)
{
    int binaryNum = 0, i = 1, remainder;
    while (n != 0)
    {
        remainder = n % 2;
        n /= 2;
        binaryNum += remainder * i;
        i *= 10;
    }
    return binaryNum;
}

// Function for bitwise AND operation
int bitwiseAnd(int x, int y)
{
    return x & y;
}

// Function for bitwise OR operation
int bitwiseOr(int x, int y)
{
    return x | y;
}

// Function for bitwise XOR operation
int bitwiseXor(int x, int y)
{
    return x ^ y;
}

// Function for bitwise NOT operation
int bitwiseNot(int x)
{
    return ~x;
}