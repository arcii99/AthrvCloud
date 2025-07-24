//FormAI DATASET v1.0 Category: Bitwise operations ; Style: inquisitive
#include <stdio.h>

int main() {
    int num1, num2;

    printf("Enter two numbers: ");
    scanf("%d%d", &num1, &num2);

    printf("\nPerforming bitwise operations on %d and %d...\n", num1, num2);
    
    // bitwise AND
    int andResult = num1 & num2;
    printf("\nThe result of bitwise AND between %d and %d is: %d\n", num1, num2, andResult);

    // bitwise OR
    int orResult = num1 | num2;
    printf("\nThe result of bitwise OR between %d and %d is: %d\n", num1, num2, orResult);

    // bitwise XOR
    int xorResult = num1 ^ num2;
    printf("\nThe result of bitwise XOR between %d and %d is: %d\n", num1, num2, xorResult);

    // bitwise NOT
    int notResult1 = ~num1;
    int notResult2 = ~num2;
    printf("\nThe result of bitwise NOT for %d is: %d\n", num1, notResult1);
    printf("The result of bitwise NOT for %d is: %d\n", num2, notResult2);

    // left shift
    int numShifted1 = num1 << 2;
    int numShifted2 = num2 << 3;
    printf("\n%d shifted left by 2 is: %d\n", num1, numShifted1);
    printf("%d shifted left by 3 is: %d\n", num2, numShifted2);

    // right shift
    int numShifted3 = num1 >> 1;
    int numShifted4 = num2 >> 2;
    printf("\n%d shifted right by 1 is: %d\n", num1, numShifted3);
    printf("%d shifted right by 2 is: %d\n", num2, numShifted4);

    return 0;
}