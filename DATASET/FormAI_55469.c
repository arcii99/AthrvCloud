//FormAI DATASET v1.0 Category: Error handling ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num1, num2, result;
    printf("Enter two numbers separated by a space: ");
    if(scanf("%d %d", &num1, &num2) != 2) { // error handling
        printf("Invalid input. Please enter two numbers separated by a space.\n");
        exit(1);
    }
    if(num2 == 0) { // divide by zero error handling
        printf("Error: Division by zero.\n");
        exit(1);
    }
    result = num1 / num2;
    printf("%d / %d = %d\n", num1, num2, result);
    return 0;
}