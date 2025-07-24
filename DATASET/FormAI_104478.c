//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    char operator;
    double num1, num2, result;
    
    printf("Welcome to the Curious Scientific Calculator!\n");

    while (1) {

        printf("Please enter an operator (+, -, *, /, ^, s, c, t, q): ");
        scanf("%c", &operator);

        if (operator == 'q') {
            printf("Goodbye! Thank you for using the Curious Scientific Calculator.\n");
            break;
        }

        else if (operator == 's' || operator == 'c' || operator == 't') {
            printf("Please enter an angle in radians: ");
            scanf("%lf", &num1);

            if (operator == 's') {
                result = sin(num1);
                printf("The sine of %lf radians is %lf\n", num1, result);
            }

            else if (operator == 'c') {
                result = cos(num1);
                printf("The cosine of %lf radians is %lf\n", num1, result);
            }

            else if (operator == 't') {
                result = tan(num1);
                printf("The tangent of %lf radians is %lf\n", num1, result);
            }
        }

        else {
            printf("Please enter the first number: ");
            scanf("%lf", &num1);

            printf("Please enter the second number: ");
            scanf("%lf", &num2);

            if (operator == '+') {
                result = num1 + num2;
                printf("The sum of %lf and %lf is %lf\n", num1, num2, result);
            }

            else if (operator == '-') {
                result = num1 - num2;
                printf("The difference of %lf and %lf is %lf\n", num1, num2, result);
            }

            else if (operator == '*') {
                result = num1 * num2;
                printf("The product of %lf and %lf is %lf\n", num1, num2, result);
            }

            else if (operator == '/') {
                if (num2 == 0) {
                    printf("Invalid denominator. Please try again.\n");
                    continue;
                }
                result = num1 / num2;
                printf("The quotient of %lf and %lf is %lf\n", num1, num2, result);
            }

            else if (operator == '^') {
                result = pow(num1, num2);
                printf("%lf raised to the power of %lf is %lf\n", num1, num2, result); 
            }

            else {
                printf("Invalid operator. Please try again.\n");
                continue;
            }
        }
    } 

    return 0;
}