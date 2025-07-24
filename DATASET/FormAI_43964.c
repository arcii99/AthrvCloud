//FormAI DATASET v1.0 Category: Bitwise operations ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

#define PARANOID 1

int main() {
    
    int num1, num2, result;
    
    /* Prompt user to enter two integers */
    printf("Enter two integers:\n");
    scanf("%d %d", &num1, &num2);
    
    if(PARANOID) {
        printf("Performing paranoid bitwise operations...\n");
            
        /* Check if integers are negative */
        if(num1 < 0 || num2 < 0) {
            printf("Error: Negative integers not allowed\n");
            exit(0);
        }
            
        /* Check if integers are within range */
        if(num1 > 65535 || num2 > 65535) {
            printf("Error: Integers out of range\n");
            exit(0);
        }
    }
    
    /* Perform bitwise AND operation */
    result = num1 & num2;
    printf("Bitwise AND result: %d\n", result);
    
    /* Perform bitwise OR operation */
    result = num1 | num2;
    printf("Bitwise OR result: %d\n", result);
    
    /* Perform bitwise XOR operation */
    result = num1 ^ num2;
    printf("Bitwise XOR result: %d\n", result);
    
    /* Perform bitwise NOT operation */
    result = ~num1;
    printf("Bitwise NOT result of num1: %d\n", result);
    
    return 0;
}