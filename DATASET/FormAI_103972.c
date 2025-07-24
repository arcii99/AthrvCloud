//FormAI DATASET v1.0 Category: Bitwise operations ; Style: random
#include <stdio.h>

/*
This program demonstrates various bitwise operations in C.
It allows the user to enter two integers and performs the following operations on them:
1. Bitwise AND
2. Bitwise OR
3. Bitwise XOR
4. Bitwise Complement
5. Bitwise Left Shift
6. Bitwise Right Shift
*/

int main() {

    int num1, num2;

    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    printf("\nBitwise AND: %d & %d = %d", num1, num2, num1 & num2);
    printf("\nBitwise OR: %d | %d = %d", num1, num2, num1 | num2);
    printf("\nBitwise XOR: %d ^ %d = %d", num1, num2, num1 ^ num2);
    printf("\nBitwise Complement: ~%d = %d, ~%d = %d", num1, ~num1, num2, ~num2);
    printf("\nBitwise Left Shift: %d << 1 = %d, %d << 2 = %d", num1, num1 << 1, num2, num2 << 2);
    printf("\nBitwise Right Shift: %d >> 1 = %d, %d >> 2 = %d", num1, num1 >> 1, num2, num2 >> 2);

    return 0;
}