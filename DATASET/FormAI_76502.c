//FormAI DATASET v1.0 Category: Error handling ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

int divide(int num1, int num2) {
    if (num2 == 0) {
        printf("Error: Division by zero\n");
        return -1; // returning error code -1
    } else {
        return num1 / num2;
    }
}

int main() {
    int num1, num2, result;
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);

    result = divide(num1, num2);

    if (result == -1) {
        printf("Error occurred in calculating division\n");
        return 1; // returning error code 1
    } else {
        printf("%d / %d = %d\n", num1, num2, result);
        return 0; // returning success code 0
    }
}