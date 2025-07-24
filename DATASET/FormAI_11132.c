//FormAI DATASET v1.0 Category: Bitwise operations ; Style: statistical
#include <stdio.h>

int main() {
    int num1, num2, num3;
    num1 = 23;
    num2 = 43;
    num3 = 66;

    printf("Num1 is %d\n", num1);
    printf("Num2 is %d\n", num2);
    printf("Num3 is %d\n", num3);
  
    // Left shift operator example
    printf("After shifting left by 1 bit, Num1 is %d\n", num1 << 1);

    // Right shift operator example
    printf("After shifting right by 2 bits, Num2 is %d\n", num2 >> 2);

    // Bitwise AND operator example
    printf("Bitwise AND of Num1 and Num2 is %d\n", num1 & num2);

    // Bitwise OR operator example
    printf("Bitwise OR of Num1 and Num3 is %d\n", num1 | num3);

    // Bitwise XOR operator example
    printf("Bitwise XOR of Num2 and Num3 is %d\n", num2 ^ num3);

    // Bitwise complement operator example
    printf("Bitwise complement of Num1 is %d\n", ~num1);

    return 0;
}