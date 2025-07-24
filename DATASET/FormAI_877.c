//FormAI DATASET v1.0 Category: Bitwise operations ; Style: scientific
#include <stdio.h>

int main() {
    int num1 = 10;
    int num2 = 6;
    int result;
    
    // Bitwise AND operation 
    result = num1 & num2; 
    printf("%d & %d = %d\n", num1, num2, result); 
    
    // Bitwise OR operator
    result = num1 | num2;
    printf("%d | %d = %d\n", num1, num2, result);

    // Bitwise XOR operator
    result = num1 ^ num2;
    printf("%d ^ %d = %d\n", num1, num2, result);

    // Bitwise complement operator
    result = ~num1;
    printf("~%d = %d\n", num1, result);

    // Bitwise left shift operator
    result = num1 << 1;
    printf("%d << 1 = %d\n", num1, result);

    // Bitwise right shift operator
    result = num1 >> 1;
    printf("%d >> 1 = %d\n", num1, result);

    return 0;
}