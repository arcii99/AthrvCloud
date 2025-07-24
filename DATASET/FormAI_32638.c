//FormAI DATASET v1.0 Category: Error handling ; Style: active
#include<stdio.h>
#include<stdlib.h>

void divide(int num1, int num2) {
    if (num2 == 0) {
        // Throw an error and exit
        fprintf(stderr, "Error! Cannot divide by zero.\n");
        exit(1);
    } else {
        printf("%d / %d = %d\n", num1, num2, num1/num2);
    }
}

void subtract(int num1, int num2) {
    if (num2 > num1) {
        // Throw an error and exit
        fprintf(stderr, "Error! Cannot subtract a larger number from a smaller one.\n");
        exit(1);
    } else {
        printf("%d - %d = %d\n", num1, num2, num1-num2);
    }
}

int main() {
    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    // Division
    printf("Division:\n");
    divide(num1, num2);

    // Subtraction
    printf("Subtraction:\n");
    subtract(num1, num2);

    return 0;
}