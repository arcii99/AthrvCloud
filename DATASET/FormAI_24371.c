//FormAI DATASET v1.0 Category: Bitwise operations ; Style: light-weight
#include <stdio.h>

int main() {
    int num1, num2;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    printf("Bitwise AND: %d\n", num1 & num2);
    printf("Bitwise OR: %d\n", num1 | num2);
    printf("Bitwise XOR: %d\n", num1 ^ num2);
    printf("Bitwise NOT of %d: %d\n", num1, ~num1);
    printf("Bitwise NOT of %d: %d\n", num2, ~num2);

    printf("Left shift of %d by 2: %d\n", num1, num1 << 2);
    printf("Right shift of %d by 2: %d\n", num1, num1 >> 2);

    printf("Left shift of %d by 3: %d\n", num2, num2 << 3);
    printf("Right shift of %d by 3: %d\n", num2, num2 >> 3);

    return 0;
}