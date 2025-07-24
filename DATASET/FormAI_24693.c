//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: immersive
/*
Scientific Calculator Implementation
Developed By: [Your Name]

This program is a scientific calculator that is capable of performing various mathematical calculations 
such as addition, subtraction, multiplication, division, square root, trigonometric functions, power function, etc.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

int main() {
    char ch;
    double num1, num2;

    do {
        system("clear"); // Clear the terminal screen

        printf("\t\t** Scientific Calculator **\n\n");
        printf("Operations Available:\n");
        printf("1. Add (+)\n2. Subtract (-)\n3. Multiply (*)\n4. Divide (/)\n5. Square Root (sqrt)\n6. Power (x^y)\n7. Sin (sin)\n8. Cos (cos)\n9. Tan (tan)\n10. Quit (q)\n\n");

        printf("Enter Your Choice: ");
        scanf(" %c", &ch);

        switch (ch) {
            case '+': {
                printf("Enter Two Numbers to Add:\n");
                printf("Number 1: ");
                scanf("%lf", &num1);
                printf("Number 2: ");
                scanf("%lf", &num2);

                printf("%.2lf + %.2lf = %.2lf\n\n", num1, num2, num1 + num2);
                break;
            }
            case '-': {
                printf("Enter Two Numbers to Subtract:\n");
                printf("Number 1: ");
                scanf("%lf", &num1);
                printf("Number 2: ");
                scanf("%lf", &num2);

                printf("%.2lf - %.2lf = %.2lf\n\n", num1, num2, num1 - num2);
                break;
            }
            case '*': {
                printf("Enter Two Numbers to Multiply:\n");
                printf("Number 1: ");
                scanf("%lf", &num1);
                printf("Number 2: ");
                scanf("%lf", &num2);

                printf("%.2lf * %.2lf = %.2lf\n\n", num1, num2, num1 * num2);
                break;
            }
            case '/': {
                printf("Enter Two Numbers to Divide:\n");
                printf("Number 1: ");
                scanf("%lf", &num1);
                printf("Number 2: ");
                scanf("%lf", &num2);

                printf("%.2lf / %.2lf = %.2lf\n\n", num1, num2, num1 / num2);
                break;
            }
            case 's': {
                printf("Enter a Number to Find Square Root:\n");
                printf("Number: ");
                scanf("%lf", &num1);

                printf("sqrt(%.2lf) = %.2lf\n\n", num1, sqrt(num1));
                break;
            }
            case 'x': {
                printf("Enter Two Numbers to Find Power (x^y):\n");
                printf("Number (x): ");
                scanf("%lf", &num1);
                printf("Power (y): ");
                scanf("%lf", &num2);

                printf("%.2lf ^ %.2lf = %.2lf\n\n", num1, num2, pow(num1, num2));
                break;
            }
            case 'S': {
                printf("Enter a Number to Find Sin (in degree):\n");
                printf("Number: ");
                scanf("%lf", &num1);

                printf("sin(%.2lf) = %.2lf\n\n", num1, sin(num1*PI/180));
                break;
            }
            case 'C': {
                printf("Enter a Number to Find Cos (in degree):\n");
                printf("Number: ");
                scanf("%lf", &num1);

                printf("cos(%.2lf) = %.2lf\n\n", num1, cos(num1*PI/180));
                break;
            }
            case 'T': {
                printf("Enter a Number to Find Tan (in degree):\n");
                printf("Number: ");
                scanf("%lf", &num1);

                printf("tan(%.2lf) = %.2lf\n\n", num1, tan(num1*PI/180));
                break;
            }
            case 'q': {
                printf("Thank You for Using Scientific Calculator!\n");
                return 0;
            }
            default: {
                printf("Invalid Choice! Try Again.\n\n");
                break;
            }
        }

        printf("Press Enter Key to Continue...\n");
        getchar();
        getchar();
    } while (1);

    return 0;
}