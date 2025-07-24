//FormAI DATASET v1.0 Category: Arithmetic ; Style: imaginative
#include<stdio.h>

int main(){
    int num1, num2, result;
    char operator;

    printf("Welcome to the Magic Calculator\n\n");

    printf("Please enter the first number: ");
    scanf("%d", &num1);

    printf("Please enter the operator (+,-,*,/): ");
    scanf(" %c", &operator);

    printf("Please enter the second number: ");
    scanf("%d", &num2);

    switch(operator) {
        case '+':
            result = num1 + num2;
            printf("\n\nThe result is: %d\n", result);
            break;
        case '-':
            result = num1 - num2;
            printf("\n\nThe result is: %d\n", result);
            break;
        case '*':
            result = num1 * num2;
            printf("\n\nThe result is: %d\n", result);
            break;
        case '/':
            if(num2 == 0){
                printf("Error: Divide by zero.");
            }
            else{
                result = num1 / num2;
                printf("\n\nThe result is: %d\n", result);
            }
            break;
        default:
            printf("\n\nInvalid operator selected.\n");
            break;
    }

    printf("\nThank you for using the Magic Calculator!\n");

    return 0;
}