//FormAI DATASET v1.0 Category: Bitwise operations ; Style: complete
#include<stdio.h>

int main(){
    int num1 = 19; //0001 0011
    int num2 = 13; //0000 1101
    int result;

    // Bitwise AND
    result = num1 & num2; // 0000 0001
    printf("Bitwise AND: %d & %d = %d\n", num1, num2, result);

    // Bitwise OR
    result = num1 | num2; // 0001 1111
    printf("Bitwise OR: %d | %d = %d\n", num1, num2, result);

    // Bitwise XOR
    result = num1 ^ num2; // 0001 1110
    printf("Bitwise XOR: %d ^ %d = %d\n", num1, num2, result);

    // Bitwise NOT
    result = ~num1; // 1110 1100
    printf("Bitwise NOT: ~%d = %d\n", num1, result);

    // Left Shift
    result = num1 << 2; // 0100 1100
    printf("Left Shift: %d << 2 = %d\n", num1, result);

    // Right Shift
    result = num2 >> 2; // 0000 0011
    printf("Right Shift: %d >> 2 = %d\n", num2, result);

    return 0;
}