//FormAI DATASET v1.0 Category: Error handling ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// function to handle divide by zero error
void handle_divide_by_zero() {
    printf("Oopsie, you divided by zero! But don't worry, I've got your back.\n");
    exit(EXIT_FAILURE);
}

int main() {
    int dividend, divisor, quotient;

    printf("Let's divide some numbers!\n");

    // ask user for input
    printf("Enter your dividend: ");
    scanf("%d", &dividend);

    printf("Enter your divisor: ");
    scanf("%d", &divisor);

    // check for divide by zero error
    if (divisor == 0) {
        handle_divide_by_zero();
    }

    // calculate quotient
    quotient = dividend / divisor;

    // celebrate successful calculation
    printf("Hooray, we successfully divided %d by %d and got %d!\n", dividend, divisor, quotient);

    return 0;
}