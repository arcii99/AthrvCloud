//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Romeo and Juliet
/* Romeo and Juliet - A Calculus Tragedy */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double num1, num2, result;
    char operator, decision;

    printf("Enter your first number, my fair Juliet: ");
    scanf("%lf", &num1);
    printf("\nOh! My dearest Romeo, please enter your operator (+, -, *, /, ^): ");
    scanf(" %c", &operator);
    printf("\nAnd now, my love, a second number: ");
    scanf("%lf", &num2);

    switch (operator)
    {
        case '+':
            result = num1 + num2;
            printf("\nThe sum of thy numbers is: %lf\n", result);
            break;
        case '-':
            result = num1 - num2;
            printf("\nAh me! A subtraction has occurred and the result is: %lf\n", result);
            break;
        case '*':
            result = num1 * num2;
            printf("\nThou art an excellent multiplier, sweet Romeo. The product is: %lf\n", result);
            break;
        case '/':
            if (num2 == 0)
            {
                printf("\nO wretched villain that attempts to divide by zero! Alas, an error has occurred.\n");
                exit(0);
            }
            else
            {
                result = num1 / num2;
                printf("\nThou hast divided successfully! The quotient is: %lf\n", result);
            }
            break;
        case '^':
            result = pow(num1, num2);
            printf("\nBy my troth, thou art a powerful exponent! The answer is: %lf\n", result);
            break;
        default:
            printf("\nOh no! Error has occurred. The operator is invalid. Please try again.\n");
            exit(0);
    }

    printf("\nWould thou liketh doth another calculation, my love? (y/n)\n");
    scanf(" %c", &decision);

    if (decision == 'y' || decision == 'Y')
    {
        main();
    }
    else
    {
        printf("\nFarewell, my dear Romeo. We shall meet again.\n");
        exit(0);
    }

    return 0;
}