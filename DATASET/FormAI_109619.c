//FormAI DATASET v1.0 Category: Bitwise operations ; Style: retro
#include <stdio.h>

int main() {
    // Print header
    printf("********************************************\n");
    printf("*                                          *\n");
    printf("*         RETRO C BITWISE OPERATIONS        *\n");
    printf("*                                          *\n");
    printf("********************************************\n\n");

    // Declare variables
    unsigned int num1 = 0x26;
    unsigned int num2 = 0x5b;
    unsigned int result;

    // Perform bitwise AND operation
    printf("Performing bitwise AND operation:\n\n");
    result = num1 & num2;
    printf("Number 1:    0x%02x\n", num1);
    printf("Number 2:    0x%02x\n", num2);
    printf("Result:      0x%02x\n", result);

    // Perform bitwise OR operation
    printf("\nPerforming bitwise OR operation:\n\n");
    result = num1 | num2;
    printf("Number 1:    0x%02x\n", num1);
    printf("Number 2:    0x%02x\n", num2);
    printf("Result:      0x%02x\n", result);

    // Perform bitwise XOR operation
    printf("\nPerforming bitwise XOR operation:\n\n");
    result = num1 ^ num2;
    printf("Number 1:    0x%02x\n", num1);
    printf("Number 2:    0x%02x\n", num2);
    printf("Result:      0x%02x\n", result);

    // Perform bitwise complement operation
    printf("\nPerforming bitwise complement operation:\n\n");
    result = ~num1;
    printf("Number:      0x%02x\n", num1);
    printf("Result:      0x%02x\n", result);

    // Print footer
    printf("\n********************************************\n");
    printf("*                                          *\n");
    printf("*       END RETRO C BITWISE OPERATIONS      *\n");
    printf("*                                          *\n");
    printf("********************************************\n");

    return 0;
}