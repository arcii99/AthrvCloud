//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: funny
#include<stdio.h>
#include<math.h>

int main() {
    printf("**************************************************\n");
    printf("* Welcome to the Awesome Scientific Calculator! *\n");
    printf("**************************************************\n");
    printf("Are you ready to crunch some numbers?\n");
    printf("Enter 'Y' for YES, 'N' for NO: ");

    char response;
    scanf("%c", &response);

    if (response == 'N') {
        printf("Well, then what are you waiting for? Go do something else!\n");
        return 0;
    }

    double num1, num2;
    char operator;

    printf("Please enter your first number: ");
    scanf("%lf", &num1);

    printf("Please choose an operator (+, -, *, /, ^, %%): ");
    scanf(" %c", &operator);

    if (operator == '^') {
        printf("Please enter your second number (exponent): ");
        scanf("%lf", &num2);
        double result = pow(num1, num2);
        printf("%lf ^ %lf = %lf\n", num1, num2, result);
    } else {
        printf("Please enter your second number: ");
        scanf("%lf", &num2);
        double result;
        switch (operator) {
            case '+':
                result = num1 + num2;
                printf("%lf + %lf = %lf\n", num1, num2, result);
                break;
            case '-':
                result = num1 - num2;
                printf("%lf - %lf = %lf\n", num1, num2, result);
                break;
            case '*':
                result = num1 * num2;
                printf("%lf * %lf = %lf\n", num1, num2, result);
                break;
            case '/':
                if (num2 == 0) {
                    printf("Oops! You can't divide by zero...try again.\n");
                    return 1;
                }
                result = num1 / num2;
                printf("%lf / %lf = %lf\n", num1, num2, result);
                break;
            case '%':
                if (num2 == 0) {
                    printf("Oops! You can't mod by zero...try again.\n");
                    return 1;
                }
                result = fmod(num1, num2);
                printf("%lf mod %lf = %lf\n", num1, num2, result);
                break;
            default:
                printf("Oops! That's not a valid operator...\n");
                return 1;
        }
    }

    printf("Thanks for using the Awesome Scientific Calculator! Until next time!\n");

    return 0;
}