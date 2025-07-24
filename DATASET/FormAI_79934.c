//FormAI DATASET v1.0 Category: Error handling ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num1, num2, result;
    printf("Enter two numbers to divide: ");
    scanf("%d %d", &num1, &num2);

    if (num2 == 0) {
        printf("Error: Cannot divide by zero\n");
        exit(EXIT_FAILURE);
    } else {
        result = num1 / num2;
        printf("%d divided by %d is %d\n", num1, num2, result);
    }
    return EXIT_SUCCESS;
}