//FormAI DATASET v1.0 Category: Error handling ; Style: calm
#include <stdio.h>

int main() {
    int num1, num2, result;

    printf("Enter the first number: ");
    if(scanf("%d", &num1) != 1) {
        printf("Error: Invalid input\n");
        return 1;
    }

    printf("Enter the second number: ");
    if(scanf("%d", &num2) != 1) {
        printf("Error: Invalid input\n");
        return 1;
    }

    if(num2 == 0) {
        printf("Error: Division by zero\n");
        return 1;
    }

    result = num1 / num2;

    printf("%d divided by %d is %d\n", num1, num2, result);

    return 0;
}