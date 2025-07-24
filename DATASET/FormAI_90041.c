//FormAI DATASET v1.0 Category: Bitwise operations ; Style: rigorous
#include <stdio.h>

int main() {
    unsigned int num1, num2;
    printf("Enter two unsigned integers: ");
    scanf("%u %u", &num1, &num2);

    printf("\nBitwise OR: %u | %u = %u\n", num1, num2, num1|num2);
    printf("Bitwise AND: %u & %u = %u\n", num1, num2, num1&num2);
    printf("Bitwise XOR: %u ^ %u = %u\n", num1, num2, num1^num2);
    printf("Bitwise Complement: ~%u = %u\n", num1, ~num1);
    printf("Left Shift: %u << 1 = %u\n", num1, num1<<1);
    printf("Right Shift: %u >> 1 = %u\n", num1, num1>>1);

    return 0;
}