//FormAI DATASET v1.0 Category: Bitwise operations ; Style: active
#include <stdio.h>

int main() {
    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    
    printf("Left shift operation: %d << %d = %d\n", num1, num2, num1 << num2);
    printf("Right shift operation: %d >> %d = %d\n", num1, num2, num1 >> num2);
    printf("Bitwise AND operation: %d & %d = %d\n", num1, num2, num1 & num2);
    printf("Bitwise OR operation: %d | %d = %d\n", num1, num2, num1 | num2);
    printf("Bitwise XOR operation: %d ^ %d = %d\n", num1, num2, num1 ^ num2);
    printf("Bitwise Ones Complement operation: ~ %d = %d, ~ %d = %d", num1, ~num1, num2, ~num2);
    
    return 0;
}