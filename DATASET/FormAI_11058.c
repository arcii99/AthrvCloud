//FormAI DATASET v1.0 Category: Error handling ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num1, num2;
    printf("Enter two integers: ");
    if (scanf("%d %d", &num1, &num2) != 2) {
        printf("Invalid input format.\n");
        exit(EXIT_FAILURE);
    }

    if (num2 == 0) {
        printf("Error: Division by zero.\n");
        exit(EXIT_FAILURE);
    }

    int result = num1 / num2;
    printf("%d / %d = %d\n", num1, num2, result);

    char input[10];
    printf("Enter a character: ");
    if (scanf("%9s", input) != 1) {
        printf("Invalid input format.\n");
        exit(EXIT_FAILURE);
    }
    
    if (input[0] < 65 || input[0] > 90) {
        printf("Error: Input character is not capitalized.\n");
        exit(EXIT_FAILURE);
    }

    printf("Input character: %c\n", input[0]);

    return 0;
}