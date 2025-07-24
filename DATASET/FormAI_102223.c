//FormAI DATASET v1.0 Category: Bitwise operations ; Style: content
#include <stdio.h>

// function to convert decimal to binary
void decToBin(int num)
{
    int binaryNum[32];
    int i = 0;
    // converting decimal to binary
    while (num > 0) {
        binaryNum[i] = num % 2;
        num = num / 2;
        i++;
    }
    // printing binary number in reverse order
    printf("Binary Number: ");
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binaryNum[j]);
}

int main()
{
    int num1 = 6, num2 = 3;
    // bitwise AND operator
    int andResult = num1 & num2;
    printf("Bitwise AND Result: %d\n", andResult);

    // bitwise OR operator
    int orResult = num1 | num2;
    printf("Bitwise OR Result: %d\n", orResult);

    // bitwise NOT operator
    int notResult = ~num1;
    printf("Bitwise NOT Result: %d\n", notResult);

    // bitwise XOR operator
    int xorResult = num1 ^ num2;
    printf("Bitwise XOR Result: %d\n", xorResult);

    // left shift operator
    int leftShiftResult = num1 << 2;
    printf("Left Shift Result: %d\n", leftShiftResult);

    // right shift operator
    int rightShiftResult = num1 >> 1;
    printf("Right Shift Result: %d\n", rightShiftResult);

    // calling the function to convert decimal to binary
    decToBin(num1);

    return 0;
}