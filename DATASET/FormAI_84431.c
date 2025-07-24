//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: complex
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main(){

    int choice;
    double a, b, result;

    //Displaying the Calculator Menu
    printf("***************************************\n");
    printf("\tC Scientific Calculator\n");
    printf("***************************************\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Square Root\n");
    printf("6. Exponentiation\n");
    printf("7. Logarithm\n");
    printf("8. Trigonometric Functions\n");
    printf("9. Exit\n");

    //Getting user choice
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice){

        case 1:
            //Addition
            printf("\nEnter two numbers: ");
            scanf("%lf %lf", &a, &b);
            result = a + b;
            printf("Result: %lf", result);
            break;

        case 2:
            //Subtraction
            printf("\nEnter two numbers: ");
            scanf("%lf %lf", &a, &b);
            result = a - b;
            printf("Result: %lf", result);
            break;

        case 3:
            //Multiplication
            printf("\nEnter two numbers: ");
            scanf("%lf %lf", &a, &b);
            result = a * b;
            printf("Result: %lf", result);
            break;

        case 4:
            //Division
            printf("\nEnter two numbers: ");
            scanf("%lf %lf", &a, &b);
            if(b == 0){
                printf("Error! Division by zero\n");
                exit(0);
            }
            result = a / b;
            printf("Result: %lf", result);
            break;

        case 5:
            //Square Root
            printf("\nEnter a number: ");
            scanf("%lf", &a);
            if(a < 0){
                printf("Error! Negative number\n");
                exit(0);
            }
            result = sqrt(a);
            printf("Result: %lf", result);
            break;

        case 6:
            //Exponentiation
            printf("\nEnter two numbers: ");
            scanf("%lf %lf", &a, &b);
            result = pow(a, b);
            printf("Result: %lf", result);
            break;

        case 7:
            //Logarithm
            printf("\nEnter a number: ");
            scanf("%lf", &a);
            if(a <= 0){
                printf("Error! Invalid input\n");
                exit(0);
            }
            result = log10(a);
            printf("Result: %lf", result);
            break;

        case 8:
            //Trigonometric Functions
            printf("\nEnter a number in radians: ");
            scanf("%lf", &a);
            printf("sin(%lf) = %lf\n", a, sin(a));
            printf("cos(%lf) = %lf\n", a, cos(a));
            printf("tan(%lf) = %lf\n", a, tan(a));
            break;

        case 9:
            //Exiting from the Program
            printf("\nExiting from the program...\n");
            exit(0);

        default:
            printf("Invalid choice!\n");

    }

    return 0;
}