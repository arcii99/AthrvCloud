//FormAI DATASET v1.0 Category: Arithmetic ; Style: Dennis Ritchie
#include<stdio.h>

// This program performs arithmetic calculations with multiple operators
// and displays the final result to the user

#define OPERATOR_1 +
#define OPERATOR_2 -
#define OPERATOR_3 *
#define OPERATOR_4 /

int main() {
    int operand_1, operand_2, operand_3, operand_4, result;
    
    printf("Enter four operands: ");
    scanf("%d %d %d %d", &operand_1, &operand_2, &operand_3, &operand_4);
    
    // Perform arithmetic operations
    result = operand_1 OPERATOR_1 operand_2;
    result = result OPERATOR_2 operand_3;
    result = result OPERATOR_3 operand_4;
    result = result OPERATOR_4 (operand_1 % operand_4); // Bonus operation
    
    // Display result
    printf("Result: %d\n", result);
    
    return 0;
}