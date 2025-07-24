//FormAI DATASET v1.0 Category: Error handling ; Style: complex
#include <stdio.h>
#include <stdlib.h>

void errorHandler(int errorNum);

int main() {
    int num1, num2;
    printf("Enter two numbers: ");
    if (scanf("%d %d", &num1, &num2) != 2) {
        errorHandler(1);
        exit(1);
    }
    if (num2 == 0) {
        errorHandler(2);
        exit(1);
    }
    float quotient = (float)num1 / num2;
    printf("The quotient is: %f", quotient);
    return 0;
}

void errorHandler(int errorNum) {
    switch (errorNum) {
        case 1:
            printf("Error: Invalid input format\n");
            break;
        case 2:
            printf("Error: Division by zero\n");
            break;
        default:
            printf("Unknown error occurred\n");
            break;
    }
}