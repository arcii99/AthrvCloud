//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: thoughtful
#include<stdio.h>
#include<math.h>

int main(){
    char operator;
    float num1, num2, result;

    printf("Enter an operator (+, -, *, /, ^, %%) : ");
    scanf("%c", &operator);

    switch(operator){
        case '+':
            printf("Enter the first number: ");
            scanf("%f", &num1);
            printf("Enter the second number: ");
            scanf("%f", &num2);
            result = num1 + num2;
            printf("%.2f + %.2f = %.2f", num1, num2, result);
            break;

        case '-':
            printf("Enter the first number: ");
            scanf("%f", &num1);
            printf("Enter the second number: ");
            scanf("%f", &num2);
            result = num1 - num2;
            printf("%.2f - %.2f = %.2f", num1, num2, result);
            break;

        case '*':
            printf("Enter the first number: ");
            scanf("%f", &num1);
            printf("Enter the second number: ");
            scanf("%f", &num2);
            result = num1 * num2;
            printf("%.2f * %.2f = %.2f", num1, num2, result);
            break;

        case '/':
            printf("Enter the first number: ");
            scanf("%f", &num1);
            printf("Enter the second number: ");
            scanf("%f", &num2);

            if(num2 == 0){
                printf("Error! Division by zero is not allowed.");
                break;
            }

            result = num1 / num2;
            printf("%.2f / %.2f = %.2f", num1, num2, result);
            break;

        case '^':
            printf("Enter the number: ");
            scanf("%f", &num1);
            printf("Enter the power: ");
            scanf("%f", &num2);
            result = pow(num1, num2);
            printf("%.2f^%.2f = %.2f", num1, num2, result);
            break;

        case '%':
            printf("Enter the first number: ");
            scanf("%f", &num1);
            printf("Enter the second number: ");
            scanf("%f", &num2);

            if(num2 == 0){
                printf("Error! Modulus by zero is not allowed.");
                break;
            }

            result = fmod(num1, num2);
            printf("%.2f % %.2f = %.2f", num1, num2, result);
            break;

        default:
            printf("Error! Operator not recognized.");
            break;
    }

    return 0;
}