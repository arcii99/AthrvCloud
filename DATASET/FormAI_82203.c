//FormAI DATASET v1.0 Category: Error handling ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num1, num2, remainder;
    printf("Enter two numbers: ");
    if(scanf("%d %d", &num1, &num2) != 2) {
        printf("Error: Invalid input");
        exit(EXIT_FAILURE);
    }
    if(num2 == 0) {
        printf("Error: Division by zero");
        exit(EXIT_FAILURE);
    }
    remainder = num1 % num2;
    printf("The remainder of %d/%d is %d", num1, num2, remainder);
    return 0;
}