//FormAI DATASET v1.0 Category: Bitwise operations ; Style: calm
#include<stdio.h>

int main()
{
    int num1 = 16, num2 = 8;

    printf("Bitwise AND operator:\n");
    printf("%d & %d = %d\n", num1, num2, num1&num2);

    printf("Bitwise OR operator:\n");
    printf("%d | %d = %d\n", num1, num2, num1|num2);

    printf("Bitwise XOR operator:\n");
    printf("%d ^ %d = %d\n", num1, num2, num1^num2);

    printf("Bitwise complement operator:\n");
    printf("~%d = %d\n", num1, ~num1);

    printf("Left Shift Operator:\n");
    printf("%d << 2 = %d\n", num1, num1<<2);

    printf("Right Shift Operator:\n");
    printf("%d >> 2 = %d\n", num1, num1>>2);

    return 0;
}