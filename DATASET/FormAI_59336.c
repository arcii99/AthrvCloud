//FormAI DATASET v1.0 Category: Bitwise operations ; Style: standalone
//A unique C program demonstrating use of bitwise operations

#include <stdio.h>

//helper function to convert decimal numbers to binary
void dec_to_bin(int num)
{
    if(num > 1)
        dec_to_bin(num/2);
    printf("%d",num%2);
}

int main()
{
    int num1 = 15; // 1111 in binary
    int num2 = 8; // 1000 in binary

    printf("Using bitwise AND operator:\n");
    printf("%d AND %d = %d\n\n", num1, num2, num1&num2);

    printf("Using bitwise OR operator:\n");
    printf("%d OR %d = %d\n\n", num1, num2, num1|num2);

    printf("Using bitwise XOR operator:\n");
    printf("%d XOR %d = %d\n\n", num1, num2, num1^num2);

    printf("Using bitwise NOT operator on %d:\n", num1);
    printf("NOT %d = %d\n\n", num1, ~num1);

    printf("Using left shift operator on %d:\n", num1);
    printf("%d left shift by 2 = ", num1);
    dec_to_bin(num1 << 2);
    printf("\n\n");

    printf("Using right shift operator on %d:\n", num1);
    printf("%d right shift by 2 = ", num1);
    dec_to_bin(num1 >> 2);
    printf("\n\n");

    return 0;
}