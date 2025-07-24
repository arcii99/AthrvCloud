//FormAI DATASET v1.0 Category: Error handling ; Style: active
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num1, num2;
    printf("Enter two numbers to divide:\n");
    scanf("%d %d", &num1, &num2);
    if (num2 == 0) {
        fprintf(stderr, "Error: Division by zero\n");
        exit(EXIT_FAILURE);
    }
    float result = (float) num1 / num2;
    printf("%d / %d = %.2f", num1, num2, result);
    return 0;
}