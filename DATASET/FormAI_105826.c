//FormAI DATASET v1.0 Category: Bitwise operations ; Style: complex
#include<stdio.h>

int main(){
    int num1, num2;
    printf("Enter two numbers:\n");
    scanf("%d %d", &num1, &num2);

    int and = num1 & num2;
    int or = num1 | num2;
    int xor = num1 ^ num2;
    int not = ~num1;
    int left_shift = num1 << num2;
    int right_shift = num1 >> num2;

    printf("\nBitwise AND: %d & %d = %d\n", num1, num2, and);
    printf("Bitwise OR: %d | %d = %d\n", num1, num2, or);
    printf("Bitwise XOR: %d ^ %d = %d\n", num1, num2, xor);
    printf("Bitwise NOT: ~%d = %d\n", num1, not);
    printf("Left shift: %d << %d = %d\n", num1, num2, left_shift);
    printf("Right shift: %d >> %d = %d\n", num1, num2, right_shift);

    int b1 = 0b11001010; // Binary literal starting with 0b
    int b2 = 0b00110101; // Binary literal starting with 0b

    printf("\nBitwise AND: %d & %d = %d\n", b1, b2, b1 & b2);
    printf("Bitwise OR: %d | %d = %d\n", b1, b2, b1 | b2);
    printf("Bitwise XOR: %d ^ %d = %d\n", b1, b2, b1 ^ b2);
    printf("Bitwise NOT: ~%d = %d\n", b1, ~b1);
    printf("Left shift: %d << %d = %d\n", b1, 3, b1 << 3);
    printf("Right shift: %d >> %d = %d\n", b1, 2, b1 >> 2);

    return 0;
}