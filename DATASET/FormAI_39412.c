//FormAI DATASET v1.0 Category: Calculator ; Style: bold
#include <stdio.h>

int main() {
    int num1, num2, choice;

    printf("Enter two numbers:\n");
    scanf("%d %d", &num1, &num2);

    printf("Choose an operation to perform:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Result: %d\n", num1 + num2);
            break;
        case 2:
            printf("Result: %d\n", num1 - num2);
            break;
        case 3:
            printf("Result: %d\n", num1 * num2);
            break;
        case 4:
            if(num2 == 0) {
                printf("Error: Cannot divide by 0.\n");
            }
            else {
                printf("Result: %d\n", num1 / num2);
            }
            break;
        default:
            printf("Invalid operation.\n");
    }

    return 0;
}