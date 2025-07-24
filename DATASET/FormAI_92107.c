//FormAI DATASET v1.0 Category: Error handling ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

/* Function prototypes */
int divide(int num1, int num2);

int main(void) {
    int num1, num2, result;
    
    printf("Enter the first number: ");
    if(scanf("%d", &num1) != 1) {
        printf("Error: Invalid input\n");
        exit(EXIT_FAILURE);
    }
    
    printf("Enter the second number: ");
    if(scanf("%d", &num2) != 1) {
        printf("Error: Invalid input\n");
        exit(EXIT_FAILURE);
    }
    
    result = divide(num1, num2);
    
    printf("%d / %d = %d\n", num1, num2, result);
    
    return 0;
}

int divide(int num1, int num2) {
    if(num2 == 0) {
        fprintf(stderr, "Error: Divide by zero\n");
        exit(EXIT_FAILURE);
    }
    
    return num1 / num2;
}