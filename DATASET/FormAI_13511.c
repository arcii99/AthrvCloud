//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//function to perform addition
double add(double a, double b){
    return a + b;
}

//function to perform subtraction
double subtract(double a, double b){
    return a - b;
}

//function to perform multiplication
double multiply(double a, double b){
    return a * b;
}

//function to perform division
double divide(double a, double b){
    return a / b;
}

//function to perform square root
double squareRoot(double a){
    return sqrt(a);
}

//function to perform power
double power(double a, double b){
    return pow(a,b);
}

//Driver function
int main()
{
    int choice;
    double num1, num2;

    printf("Welcome to Scientific Calculator!\n");

    do{
        printf("\nPlease select an option:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Square Root\n");
        printf("6. Power\n");
        printf("7. Exit\n");

        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter two numbers to add separated by space: ");
                scanf("%lf %lf", &num1, &num2);
                printf("Result: %.2lf\n", add(num1, num2));
                break;
            case 2:
                printf("Enter two numbers to subtract separated by space: ");
                scanf("%lf %lf", &num1, &num2);
                printf("Result: %.2lf\n", subtract(num1, num2));
                break;
            case 3:
                printf("Enter two numbers to multiply separated by space: ");
                scanf("%lf %lf", &num1, &num2);
                printf("Result: %.2lf\n", multiply(num1, num2));
                break;
            case 4:
                printf("Enter two numbers to divide separated by space: ");
                scanf("%lf %lf", &num1, &num2);
                if(num2 == 0){
                    printf("Division by zero not possible!\n");
                    break;
                }
                printf("Result: %.2lf\n", divide(num1, num2));
                break;
            case 5:
                printf("Enter number to find square root: ");
                scanf("%lf", &num1);
                if(num1 < 0){
                    printf("Square root of negative number not possible!\n");
                    break;
                }
                printf("Result: %.2lf\n", squareRoot(num1));
                break;
            case 6:
                printf("Enter number and its power separated by space: ");
                scanf("%lf %lf", &num1, &num2);
                printf("Result: %.2lf\n", power(num1, num2));
                break;
            case 7: 
                printf("Thank you, bye!");
                exit(0);
            default:
                printf("Invalid option selected!\n");
        }
    }while(choice != 7);

    return 0;
}