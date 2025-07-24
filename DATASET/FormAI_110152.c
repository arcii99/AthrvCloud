//FormAI DATASET v1.0 Category: Error handling ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

int divide(int a, int b) {
    if (b == 0) {
        // Divide by zero error
        printf("ERROR: Division by zero\n");
        exit(1);
    }
    return a/b;
}

int main() {
    int num1, num2, result;
    
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    
    result = divide(num1, num2);
    
    printf("%d/%d = %d\n", num1, num2, result);
    
    return 0;
}