//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: artistic
/*
------------------------------------
-  C Scientific Calculator         -
------------------------------------
-  Author: Your Name Here          -
-  Date:   Today's Date Here       -
------------------------------------
-  This program is a simple yet    -
-  powerful scientific calculator  -
-  that can perform various        -
-  mathematical operations.        -
------------------------------------
*/

#include <stdio.h>
#include <math.h>

int main() {
    printf("---------------\n");
    printf("| CALCULATOR  |\n");
    printf("---------------\n");
    printf("Enter 'q' to quit.\n\n");

    char op;
    double num1, num2, result;

    do {
        printf("Enter operation (+, -, *, /, ^, sin, cos, tan, sqrt): ");
        scanf(" %c", &op);

        if (op != 'q') {
            printf("Enter first number: ");
            scanf("%lf", &num1);

            if (op != 'sqrt') {
                printf("Enter second number: ");
                scanf("%lf", &num2);
            }

            switch(op) {
                case '+':
                    result = num1 + num2;
                    printf("%.2lf + %.2lf = %.2lf\n\n", num1, num2, result);
                    break;
                case '-':
                    result = num1 - num2;
                    printf("%.2lf - %.2lf = %.2lf\n\n", num1, num2, result);
                    break;
                case '*':
                    result = num1 * num2;
                    printf("%.2lf * %.2lf = %.2lf\n\n", num1, num2, result);
                    break;
                case '/':
                    result = num1 / num2;
                    printf("%.2lf / %.2lf = %.2lf\n\n", num1, num2, result);
                    break;
                case '^':
                    result = pow(num1, num2);
                    printf("%.2lf ^ %.2lf = %.2lf\n\n", num1, num2, result);
                    break;
                case 's':
                    result = sin(num1);
                    printf("sin(%.2lf) = %.2lf\n\n", num1, result);
                    break;
                case 'c':
                    result = cos(num1);
                    printf("cos(%.2lf) = %.2lf\n\n", num1, result);
                    break;
                case 't':
                    result = tan(num1);
                    printf("tan(%.2lf) = %.2lf\n\n", num1, result);
                    break;
                case 'q':
                    printf("Exiting calculator...\n");
                    break;
                default:
                    printf("Invalid operator. Please try again.\n");
            }
        }
    } while (op != 'q');

    return 0;
}