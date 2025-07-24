//FormAI DATASET v1.0 Category: Calculator ; Style: grateful
#include <stdio.h>

int main() {
    printf("Hello there, welcome to my calculator!\n");
    printf("I am thankful that you chose to use my program.\n");
    
    float num1, num2, result;
    char op;
    
    printf("Please enter the first number: ");
    scanf("%f", &num1);
    printf("Please enter the operation (+, -, *, /): ");
    scanf(" %c", &op);
    printf("Please enter the second number: ");
    scanf("%f", &num2);
    
    switch(op) {
        case '+':
            result = num1 + num2;
            printf("The result of %f + %f is %f\n", num1, num2, result);
            break;
        case '-':
            result = num1 - num2;
            printf("The result of %f - %f is %f\n", num1, num2, result);
            break;
        case '*':
            result = num1 * num2;
            printf("The result of %f * %f is %f\n", num1, num2, result);
            break;
        case '/':
            if(num2 == 0) {
                printf("Cannot divide by zero. Please enter a non-zero second number.\n");
                scanf("%f", &num2);
                result = num1 / num2;
                printf("The result of %f / %f is %f\n", num1, num2, result);
            } else {
                result = num1 / num2;
                printf("The result of %f / %f is %f\n", num1, num2, result);
            }
            break;
        default:
            printf("Invalid operation. Please enter a valid operation (+, -, *, /)\n");
            main();
    }
    
    printf("Thank you for using my calculator! Have a great day!\n");
    return 0;
}