//FormAI DATASET v1.0 Category: Error handling ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num1, num2;
    float result;

    // prompt user for input
    printf("Enter two numbers: ");
    scanf("%d%d", &num1, &num2);

    // divide num1 by num2
    if (num2 == 0) {
        printf("Cannot divide by zero\n");
        exit(EXIT_FAILURE);  // exit program with failure status
    }
    result = (float)num1 / num2;

    // print result
    printf("%d / %d = %.2f\n", num1, num2, result);

    return 0;
}