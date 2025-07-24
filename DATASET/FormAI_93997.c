//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: statistical
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//Function declarations
double add(double x, double y);
double subtract(double x, double y);
double multiply(double x, double y);
double divide(double x, double y);
double power(double x, double y);
double absolute(double x);
double logarithm(double x);
double root(double x);

int main()
{
    int choice;
    double x, y, ans;
    
    printf("*********Scientific Calculator*********\n\n");
    printf("Choose an operation to perform:\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Power\n6. Absolute\n7. Logarithm\n8. Square Root\n");
    scanf("%d", &choice); //Take input from user for desired operation
    
    switch(choice)
    {
        case 1: //Addition
            printf("Enter two numbers: ");
            scanf("%lf %lf", &x, &y); //Taking two inputs from user
            ans = add(x, y); //Calling add function
            printf("%.2lf  +  %.2lf  =  %.2lf", x, y, ans);
            break;
        
        case 2: //Subtraction
            printf("Enter two numbers: ");
            scanf("%lf %lf", &x, &y); //Taking two inputs from user
            ans = subtract(x, y); //Calling subtract function
            printf("%.2lf  -  %.2lf  =  %.2lf", x, y, ans);
            break;
            
        case 3: //Multiplication
            printf("Enter two numbers: ");
            scanf("%lf %lf", &x, &y); //Taking two inputs from user
            ans = multiply(x, y); //Calling multiply function
            printf("%.2lf  *  %.2lf  =  %.2lf", x, y, ans);
            break;
            
        case 4: //Division
            printf("Enter two numbers: ");
            scanf("%lf %lf", &x, &y); //Taking two inputs from user
            ans = divide(x, y); //Calling divide function
            printf("%.2lf  /  %.2lf  =  %.2lf", x, y, ans);
            break;
            
        case 5: //Power
            printf("Enter two numbers (x^y): ");
            scanf("%lf %lf", &x, &y); //Taking two inputs from user
            ans = power(x, y); //Calling power function
            printf("%.2lf  ^  %.2lf  =  %.2lf", x, y, ans);
            break;
            
        case 6: //Absolute
            printf("Enter a number: ");
            scanf("%lf", &x); //Taking input from user
            ans = absolute(x); //Calling absolute function
            printf("|%.2lf|  =  %.2lf", x, ans);
            break;
            
        case 7: //Logarithm
            printf("Enter a number (ln(x)): ");
            scanf("%lf", &x); //Taking input from user
            ans = logarithm(x); //Calling logarithm function
            printf("ln(%.2lf)  =  %.2lf", x, ans);
            break;
            
        case 8: //Root
            printf("Enter a number (sqrt(x)): ");
            scanf("%lf", &x); //Taking input from user
            ans = root(x); //Calling root function
            printf("sqrt(%.2lf)  =  %.2lf", x, ans);
            break;
            
        default:
            printf("Invalid Choice!!!");
    }
    
    return 0;
}

//Add function
double add(double x, double y)
{
    double result = x + y;
    return result;
}

//Subtract function
double subtract(double x, double y)
{
    double result = x - y;
    return result;
}

//Multiply function
double multiply(double x, double y)
{
    double result = x * y;
    return result;
}

//Divide function
double divide(double x, double y)
{
    if(y==0) //Checking division by 0
    {
        printf("Error: Division by zero");
        exit(0);
    }
    else
    {
        double result = x / y;
        return result;
    }
}

//Power function
double power(double x, double y)
{
    double result = pow(x, y);
    return result;
}

//Absolute function
double absolute(double x)
{
    double result = abs(x);
    return result;
}

//Logarithm function
double logarithm(double x)
{
    double result = log(x);
    return result;
}

//Root function
double root(double x)
{
    double result = sqrt(x);
    return result;
}