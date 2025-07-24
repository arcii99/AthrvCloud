//FormAI DATASET v1.0 Category: Bitwise operations ; Style: active
#include<stdio.h>

int main(){
    int num1, num2, result;
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    printf("\nInitial values \nnum1 = %d\nnum2 = %d\n\n", num1, num2);

    // Bitwise AND
    result = num1 & num2;
    printf("Bitwise AND operator (&): %d & %d = %d\n", num1, num2, result);

    // Bitwise OR
    result = num1 | num2;
    printf("Bitwise OR operator (|): %d | %d = %d\n", num1, num2, result);

    // Bitwise XOR
    result = num1 ^ num2;
    printf("Bitwise XOR operator (^): %d ^ %d = %d\n", num1, num2, result);

    // Bitwise NOT (Complement)
    result = ~num1;
    printf("Bitwise NOT operator (~): ~%d = %d\n", num1, result);

    result = ~num2;
    printf("Bitwise NOT operator (~): ~%d = %d\n", num2, result);

    // Left shift operator
    result = num1 << 2;
    printf("Left shift operator (<<): %d << 2 = %d\n", num1, result);

    // Right shift operator
    result = num2 >> 2;
    printf("Right shift operator (>>): %d >> 2 = %d\n", num2, result);

    return 0;
}