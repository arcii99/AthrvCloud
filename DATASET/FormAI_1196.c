//FormAI DATASET v1.0 Category: Error handling ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void errorHandler(int errorCode);

int main(void) {
    int num1, num2;
    
    printf("Enter two numbers to divide:\n");
    scanf("%d %d", &num1, &num2);
    
    if (num2 == 0) {
        errorHandler(1); // divide by zero error code
        return 1;
    }
    
    int result = num1 / num2;
    printf("%d / %d = %d\n", num1, num2, result);
    
    return 0;
}

void errorHandler(int errorCode) {
    char errorMessage[50];
    
    if (errorCode == 1) {
        strcpy(errorMessage, "ERROR: Cannot divide by zero.\n");
    } else {
        strcpy(errorMessage, "ERROR: Unknown error occurred.\n");
    }
    
    printf("%s", errorMessage);
}