//FormAI DATASET v1.0 Category: Bitwise operations ; Style: surprised
#include <stdio.h>

int main() {
    printf("Welcome to the Bitwise operations program!\n");
    printf("Enter two numbers to perform bitwise operations:\n");

    int num1, num2;
    scanf("%d%d", &num1, &num2);

    printf("Surprise!! We will now perform bitwise AND, OR, XOR, and NOT operations on %d and %d\n", num1, num2);

    int and = num1 & num2;
    printf("Bitwise AND of %d and %d is %d\n", num1, num2, and);

    int or = num1 | num2;
    printf("Bitwise OR of %d and %d is %d\n", num1, num2, or);

    int xor = num1 ^ num2;
    printf("Bitwise XOR of %d and %d is %d\n", num1, num2, xor);

    int not1 = ~num1;
    printf("Bitwise NOT of %d is %d\n", num1, not1);

    int not2 = ~num2;
    printf("Bitwise NOT of %d is %d\n", num2, not2);

    printf("\nWow! That was some exciting Bitwise operations!\n");
    return 0;
}