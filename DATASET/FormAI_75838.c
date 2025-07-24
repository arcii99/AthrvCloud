//FormAI DATASET v1.0 Category: Arithmetic ; Style: careful
#include <stdio.h>

int main() {
    float firstNumber, secondNumber;
    int choice;

    printf("Enter the first number: ");
    scanf("%f", &firstNumber);
    printf("Enter the second number: ");
    scanf("%f", &secondNumber);

    printf("Press 1 for addition\n");
    printf("Press 2 for subtraction\n");
    printf("Press 3 for multiplication\n");
    printf("Press 4 for division\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("%.2f + %.2f = %.2f", firstNumber, secondNumber, firstNumber + secondNumber);
            break;
        case 2:
            printf("%.2f - %.2f = %.2f", firstNumber, secondNumber, firstNumber - secondNumber);
            break;
        case 3:
            printf("%.2f * %.2f = %.2f", firstNumber, secondNumber, firstNumber * secondNumber);
            break;
        case 4:
            if(secondNumber == 0) {
                printf("Cannot divide by zero");
            } else {
                printf("%.2f / %.2f = %.2f", firstNumber, secondNumber, firstNumber / secondNumber);
            }
            break;
        default:
            printf("Invalid choice");
    }

    return 0;
}