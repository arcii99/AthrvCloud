//FormAI DATASET v1.0 Category: Math exercise ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    double num1, num2, result;
    int operation;

    printf("Welcome to the Math Exercise Program!\n");
    printf("Enter the first number: ");
    scanf("%lf", &num1);

    printf("Enter the second number: ");
    scanf("%lf", &num2);

    printf("Select an operation:\n");
    printf("1- Addition\n");
    printf("2- Subtraction\n");
    printf("3- Multiplication\n");
    printf("4- Division\n");

    scanf("%d", &operation);

    switch(operation){
        case 1:
            result = num1 + num2;
            printf("%.2lf + %.2lf = %.2lf\n", num1, num2, result);
            break;

        case 2:
            result = num1 - num2;
            printf("%.2lf - %.2lf = %.2lf\n", num1, num2, result);
            break;

        case 3:
            result = num1 * num2;
            printf("%.2lf * %.2lf = %.2lf\n", num1, num2, result);
            break;

        case 4:
            if(num2 == 0){
                printf("Error: Division by 0 is not allowed.\n");
            }else{
                result = num1 / num2;
                printf("%.2lf / %.2lf = %.2lf\n", num1, num2, result);
            }
            break;

        default:
            printf("Error: Invalid operation selected.\n");
            break;
    }

    double square1 = pow(num1, 2);
    double square2 = pow(num2, 2);
    printf("The square of %.2lf is %.2lf\n", num1, square1);
    printf("The square of %.2lf is %.2lf\n", num2, square2);

    printf("The absolute value of %.2lf is %.2lf\n", num1, fabs(num1));
    printf("The absolute value of %.2lf is %.2lf\n", num2, fabs(num2));

    printf("The cosine of %.2lf is %.2lf\n", num1, cos(num1));
    printf("The cosine of %.2lf is %.2lf\n", num2, cos(num2));

    printf("The sine of %.2lf is %.2lf\n", num1, sin(num1));
    printf("The sine of %.2lf is %.2lf\n", num2, sin(num2));

    printf("The hypotenuse of a right triangle with legs %.2lf and %.2lf is %.2lf\n", num1, num2, hypot(num1, num2));

    return 0;
}