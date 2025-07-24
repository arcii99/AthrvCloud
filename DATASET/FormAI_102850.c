//FormAI DATASET v1.0 Category: Bitwise operations ; Style: standalone
#include <stdio.h>

// function to convert decimal to binary
void decimalToBinary(int num)
{
    int binaryNum[32];
    int i = 0;
    while (num > 0) {
        binaryNum[i] = num % 2;
        num = num / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binaryNum[j]);
}

int main()
{
    int num1 = 20;
    int num2 = 15;
    
    printf("Binary equivalent of %d: ", num1);
    decimalToBinary(num1);

    printf("\nBinary equivalent of %d: ", num2);
    decimalToBinary(num2);

    printf("\nBitwise AND of %d and %d is %d\n", num1, num2, num1 & num2);
    printf("Bitwise OR of %d and %d is %d\n", num1, num2, num1 | num2);
    printf("Bitwise XOR of %d and %d is %d\n", num1, num2, num1 ^ num2);
    printf("Bitwise NOT of %d is %d\n", num1, ~num1);
    printf("Left shift of %d by 2 is %d\n", num1, num1 << 2);
    printf("Right shift of %d by 2 is %d\n", num1, num1 >> 2);

    return 0;
}