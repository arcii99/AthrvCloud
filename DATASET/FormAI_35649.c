//FormAI DATASET v1.0 Category: Error handling ; Style: excited
#include <stdio.h>
#include <stdlib.h>

/* This is an exciting error handling example program! */

int main() {
    int num1, num2;
    
    printf("Enter two numbers to divide:\n");
    scanf("%d %d", &num1, &num2);
    
    if (num2 == 0) {
        fprintf(stderr, "Error: Division by zero is not possible!\n");
        exit(EXIT_FAILURE); // termination of program with non-zero status
    }
    else {
        printf("The result is: %d\n", num1/num2);
    }
    
    return 0;
}