//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: safe
#include<stdio.h>
#include<math.h>

double add(double a, double b)
{
    return a+b;
}

double sub(double a, double b) 
{
    return a-b;
}

double mul(double a, double b) 
{
    return a*b;
}

double div(double a, double b)
{
    if(b != 0)
        return a/b;
    else {
        printf("Error: division by zero \n");
        return NAN;
    }
}

double power(double a, double b)
{
    return pow(a,b);
}

double factorial(double a)
{
    if(a < 0)
        return NAN;
    else if(a==0)
        return 1;
    else
        return a * factorial(a-1);
}

int main()
{
    int choice;
    double num1,num2,result;
    printf("Enter 1.Addition\n2.Substraction\n3.Multiplication\n4.Division\n5.Power\n6.Factorial\nEnter your choice:");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
            printf("Enter two numbers to add: ");
            scanf("%lf %lf",&num1,&num2);
            result=add(num1,num2);
            printf("%.2lf + %.2lf = %.2lf",num1,num2,result);
            break;
        case 2:
            printf("Enter two numbers to subtract: ");
            scanf("%lf %lf",&num1,&num2);
            result=sub(num1,num2);
            printf("%.2lf - %.2lf = %.2lf",num1,num2,result);
            break;
        case 3:
            printf("Enter two numbers to multiply: ");
            scanf("%lf %lf",&num1,&num2);
            result=mul(num1,num2);
            printf("%.2lf * %.2lf = %.2lf",num1,num2,result);
            break;
        case 4:
            printf("Enter two numbers to divide: ");
            scanf("%lf %lf",&num1,&num2);
            result=div(num1,num2);
            if(result != NAN)
                printf("%.2lf / %.2lf = %.2lf",num1,num2,result);                
            break;
        case 5:
            printf("Enter base and exponent: ");
            scanf("%lf %lf",&num1,&num2);
            result=power(num1,num2);
            printf("%.2lf ^ %.2lf = %.2lf",num1,num2,result);
            break;
        case 6:
            printf("Enter a number: ");
            scanf("%lf",&num1);
            result=factorial(num1);
            if(result != NAN)
                printf("%.2lf! = %.2lf",num1,result);                
            break;
        default:
            printf("Invalid choice");
    }    
    return 0;
}