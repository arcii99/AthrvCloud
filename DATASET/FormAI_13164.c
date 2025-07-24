//FormAI DATASET v1.0 Category: Bitwise operations ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int num = rand() % 256; // Generates a random number between 0 and 255.
    int num2 = rand() % 256;

    printf("Number 1: %d\nNumber 2: %d\n\n", num, num2);

    int bitwise_and = num & num2;
    int bitwise_or = num | num2;
    int bitwise_xor = num ^ num2;
    int bitwise_left = num << 2;
    int bitwise_right = num >> 2;
    int bitwise_not = ~num;

    printf("Bitwise AND: %d & %d = %d\n", num, num2, bitwise_and);
    printf("Bitwise OR: %d | %d = %d\n", num, num2, bitwise_or);
    printf("Bitwise XOR: %d ^ %d = %d\n", num, num2, bitwise_xor);
    printf("Bitwise Left shift: %d << 2 = %d\n", num, bitwise_left);
    printf("Bitwise Right shift: %d >> 2 = %d\n", num, bitwise_right);
    printf("Bitwise Not: ~%d = %d\n",num,  bitwise_not);

    return 0;
}