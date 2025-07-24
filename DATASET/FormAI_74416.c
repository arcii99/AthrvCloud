//FormAI DATASET v1.0 Category: Error handling ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num1, num2;

    // prompt user to input two numbers
    printf("Enter two numbers to divide: ");
    scanf("%d %d", &num1, &num2);

    // check if the second number is zero
    if (num2 == 0) {
        // if the second number is zero, exit the program with error code 1
        printf("Error: division by zero\n");
        exit(1);
    }

    // calculate the result of division
    float result = (float) num1 / num2;

    // print the result
    printf("%d divided by %d is %.2f\n", num1, num2, result);

    return 0;
}