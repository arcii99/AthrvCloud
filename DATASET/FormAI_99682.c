//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//Calculator functions
double addition(double x, double y);
double substraction(double x, double y);
double multiplication(double x, double y);
double division(double x, double y);
double power(double x, double y);
double square_root(double x);
double absolute_value(double x);

//Menu function
void menu();

int main()
{
    int choice;
    double x,y,result;

    do
    {
        //Displaying the calculator menu
        menu();
        
        //Taking user choice
        printf("\n\nEnter your choice: ");
        scanf("%d",&choice);
        
        //Switch case statement to perform the chosen operation
        switch(choice)
        {
            case 1: //Addition
                printf("\nEnter two numbers to add: ");
                scanf("%lf %lf",&x,&y);
                result = addition(x,y);
                printf("\nResult: %.2lf\n",result);
                break;
            case 2: //Substraction
                printf("\nEnter two numbers to subtract: ");
                scanf("%lf %lf",&x,&y);
                result = substraction(x,y);
                printf("\nResult: %.2lf\n",result);
                break;
            case 3: //Multiplication
                printf("\nEnter two numbers to multiply: ");
                scanf("%lf %lf",&x,&y);
                result = multiplication(x,y);
                printf("\nResult: %.2lf\n",result);
                break;
            case 4: //Division
                printf("\nEnter two numbers to divide: ");
                scanf("%lf %lf",&x,&y);
                result = division(x,y);
                printf("\nResult: %.2lf\n",result);
                break;
            case 5: //Power
                printf("\nEnter base and exponent: ");
                scanf("%lf %lf",&x,&y);
                result = power(x,y);
                printf("\nResult: %.2lf\n",result);
                break;
            case 6: //Square root
                printf("\nEnter a number: ");
                scanf("%lf",&x);
                result = square_root(x);
                printf("\nResult: %.2lf\n",result);
                break;
            case 7: //Absolute value
                printf("\nEnter a number: ");
                scanf("%lf",&x);
                result = absolute_value(x);
                printf("\nResult: %.2lf\n",result);
                break;
            case 8: //Exit
                printf("\nThank you for using the calculator\n");
                exit(0);
            default:
                printf("\nInvalid choice, please try again!\n");
        }
    } while(choice);
    return 0;
}

//Function to display the calculator menu
void menu()
{
    printf("\n================ MENU ================\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power\n");
    printf("6. Square Root\n");
    printf("7. Absolute Value\n");
    printf("8. Exit\n");
}

//Function to perform addition
double addition(double x, double y)
{
    return x+y;
}

//Function to perform substraction
double substraction(double x, double y)
{
    return x-y;
}

//Function to perform multiplication
double multiplication(double x, double y)
{
    return x*y;
}

//Function to perform division
double division(double x, double y)
{
    if(y==0)
    {
        printf("\nError: Division by zero!\n");
        return 0;
    }
    else
    {
        return x/y;
    }
}

//Function to calculate power
double power(double x, double y)
{
    return pow(x,y);
}

//Function to calculate square root
double square_root(double x)
{
    return sqrt(x);
}

//Function to calculate absolute value
double absolute_value(double x)
{
    return fabs(x);
}