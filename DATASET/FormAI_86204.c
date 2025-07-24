//FormAI DATASET v1.0 Category: Bitwise operations ; Style: intelligent
#include <stdio.h>

int main() {
    int num1 = 623;
    int num2 = 336;

    printf("num1 before bitwise complement: %d\n", num1);
    num1 = ~num1;
    printf("num1 after bitwise complement: %d\n", num1);
    printf("num2 before bitwise complement: %d\n", num2);
    num2 = ~num2;
    printf("num2 after bitwise complement: %d\n", num2);

    printf("num1 before left shift: %d\n", num1);
    num1 = num1 << 4;
    printf("num1 after left shift: %d\n", num1);
    printf("num2 before right shift: %d\n", num2);
    num2 = num2 >> 3;
    printf("num2 after right shift: %d\n", num2);

    int num3 = 239;
    int num4 = 932;
    int result_and = num3 & num4;
    int result_or = num3 | num4;
    int result_xor = num3 ^ num4;

    printf("num3: %d\n", num3);
    printf("num4: %d\n", num4);
    printf("result of bitwise AND: %d\n", result_and);
    printf("result of bitwise OR: %d\n", result_or);
    printf("result of bitwise XOR: %d\n", result_xor);

    return 0;
}