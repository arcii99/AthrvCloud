//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {
    char op;
    double num1, num2, result;

    printf("Welcome to the Scientific Calculator\n\n");

    while(1) {
        printf("Enter the operator (+,-,*,/,^,s,r,c,t) or press 'q' to quit: ");
        scanf("%c",&op);
        fflush(stdin);

        if(op=='q')
            break;

        switch(op) {
            case '+':
                printf("Enter num1: ");
                scanf("%lf",&num1);
                printf("Enter num2: ");
                scanf("%lf",&num2);
                result = num1 + num2;
                printf("Result = %.2lf\n",result);
                break;
            case '-':
                printf("Enter num1: ");
                scanf("%lf",&num1);
                printf("Enter num2: ");
                scanf("%lf",&num2);
                result = num1 - num2;
                printf("Result = %.2lf\n",result);
                break;
            case '*':
                printf("Enter num1: ");
                scanf("%lf",&num1);
                printf("Enter num2: ");
                scanf("%lf",&num2);
                result = num1 * num2;
                printf("Result = %.2lf\n",result);
                break;
            case '/':
                printf("Enter num1: ");
                scanf("%lf",&num1);
                printf("Enter num2: ");
                scanf("%lf",&num2);

                if(num2==0) {
                    printf("Error: Division by zero!\n");
                    break;
                }

                result = num1 / num2;
                printf("Result = %.2lf\n",result);
                break;
            case 's':
                printf("Enter num: ");
                scanf("%lf",&num1);
                result = sin(num1);
                printf("Result = %.2lf\n",result);
                break;
            case 'r':
                printf("Enter num: ");
                scanf("%lf",&num1);

                if(num1<0) {
                    printf("Error: Cannot find square root of a negative number!\n");
                    break;
                }

                result = sqrt(num1);
                printf("Result = %.2lf\n",result);
                break;
            case 'c':
                printf("Enter num: ");
                scanf("%lf",&num1);
                result = cos(num1);
                printf("Result = %.2lf\n",result);
                break;
            case 't':
                printf("Enter num: ");
                scanf("%lf",&num1);
                result = tan(num1);
                printf("Result = %.2lf\n",result);
                break;
            case '^':
                printf("Enter base: ");
                scanf("%lf",&num1);
                printf("Enter exponent: ");
                scanf("%lf",&num2);
                result = pow(num1,num2);
                printf("Result = %.2lf\n",result);
                break;
            default:
                printf("Error: Invalid operator!\n");
        }

        fflush(stdin); //clear input buffer
    }

    printf("Thank you for using the Scientific Calculator!\n");
    return 0;
}