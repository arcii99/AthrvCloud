//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: shape shifting
#include <stdio.h>
#include <math.h>

int main() {
    char op;
    double num1, num2, ans=0;

    printf("Welcome to the Scientific calculator!\n");

    do {
        printf("\nEnter an operator (+, -, *, /, ^, s): ");
        scanf(" %c", &op);

        if(op == 's') {
            printf("Enter the number: ");
            scanf("%lf", &num1);
            ans = sqrt(num1);
        } else {
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);

            switch(op) {
                case '+':
                    ans = num1 + num2;
                    break;
                case '-':
                    ans = num1 - num2;
                    break;
                case '*':
                    ans = num1 * num2;
                    break;
                case '/':
                    if(num2 != 0)
                        ans = num1 / num2;
                    else
                        printf("Cannot divide by zero!\n");
                    break;
                case '^':
                    ans = pow(num1, num2);
                    break;
                default:
                    printf("Invalid operator!\n");
                    break;
            }
        }
        printf("= %.2lf\n", ans);
        fflush(stdin);
    } while(op !='q');

    printf("\nThank you for using the Scientific Calculator!\n");
    return 0;
}