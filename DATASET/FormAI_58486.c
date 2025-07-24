//FormAI DATASET v1.0 Category: Bitwise operations ; Style: standalone
#include <stdio.h>

int count_set_bits(unsigned int num) {
    int count = 0;

    while(num) {
        num &= (num-1);
        count++;
    }

    return count;
}

int main() {
    unsigned int num1, num2;

    printf("Enter two numbers: ");
    scanf("%u %u", &num1, &num2);

    printf("Num1: %u\n", num1);
    printf("Num2: %u\n", num2);
    printf("Bitwise OR: %u\n", num1 | num2);
    printf("Bitwise AND: %u\n", num1 & num2);
    printf("Bitwise XOR: %u\n", num1 ^ num2);
    printf("One's Complement of Num1: %u\n", ~num1);
    printf("One's Complement of Num2: %u\n", ~num2);
    printf("Left Shift of Num1 by 1: %u\n", num1 << 1);
    printf("Right Shift of Num2 by 1: %u\n", num2 >> 1);
    printf("Number of Set Bits in Num1: %d\n", count_set_bits(num1));
    printf("Number of Set Bits in Num2: %d\n", count_set_bits(num2));

    return 0;
}