//FormAI DATASET v1.0 Category: Error handling ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    int num1, num2;

    printf("Enter two integers: ");

    if(scanf("%d %d", &num1, &num2) != 2) {
        fprintf(stderr, "Oops! Something went wrong while scanning the input. Please try again.\n");
        exit(1);
    }

    if(num1 == 0 && num2 == 0) {
        fprintf(stderr, "Invalid input! Both integers cannot be zero.\n");
        exit(1);
    }

    int result = num1 / num2;

    if(num2 == 0) {
        fprintf(stderr, "Oops! Division by zero is not defined.\n");
        exit(1);
    }

    printf("The quotient of %d and %d is %d.\n", num1, num2, result);

    return 0;
}