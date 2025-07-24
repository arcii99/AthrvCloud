//FormAI DATASET v1.0 Category: Error handling ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b;

    printf("Enter two numbers:\n");
    if(scanf("%d%d", &a, &b) != 2) {
        printf("Error: Invalid input!\n");
        exit(1); // Terminate the program with an error code
    }

    if(b == 0) { // Division by zero error handling
        printf("Error: Cannot divide by zero!\n");
        exit(1); // Terminate the program with an error code
    }

    int result = a / b;

    printf("%d divided by %d is %d\n", a, b, result);

    return 0;
}