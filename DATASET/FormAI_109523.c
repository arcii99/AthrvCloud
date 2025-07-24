//FormAI DATASET v1.0 Category: Error handling ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num1, num2;
    float result;

    printf("Enter two numbers: ");
    if(scanf("%d %d", &num1, &num2) != 2) {
        printf("Error: Invalid input!\n");
        exit(1);
    }

    if(num2 == 0) {
        printf("Error: Division by zero is not allowed!\n");
        exit(1);
    }

    result = (float)num1 / num2;
    printf("The result is %.2f\n", result);

    return 0;
}