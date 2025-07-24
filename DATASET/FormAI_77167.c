//FormAI DATASET v1.0 Category: Error handling ; Style: lively
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num1, num2, result;

    printf("Enter two numbers to divide:\n");
    scanf("%d %d", &num1, &num2);

    if(num2 == 0) {
        printf("Oops! You cannot divide by 0.\n");

        // Let's handle the error gracefully by exiting the program with an error code:
        exit(1);
    }
    else {
        // If the second number is not 0, we can safely divide the two numbers:
        result = num1 / num2;

        printf("%d / %d = %d\n", num1, num2, result);

        // Let's return a success code to indicate that the program ran without any errors:
        return 0;
    }
}