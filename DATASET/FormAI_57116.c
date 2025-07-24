//FormAI DATASET v1.0 Category: Error handling ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

jmp_buf env;

/* Function to handle errors */
void errorHandling() {
    longjmp(env, 1);
}

/* Divide function */
int divide(int a, int b) {
    if (b == 0) {
        errorHandling();    // handling zero division error
    }
    return a / b;
}

/* Main function */
int main() {
    int num1, num2, result;
    
    if (setjmp(env) == 0) {
        printf("Enter the first number: ");
        scanf("%d", &num1);
        
        printf("Enter the second number: ");
        scanf("%d", &num2);
        
        result = divide(num1, num2);
        printf("The result of %d divided by %d is %d.", num1, num2, result);
    } 
    else {
        printf("Error: division by zero.\n");
        exit(EXIT_FAILURE);
    }
    
    return 0;
}