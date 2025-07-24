//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: ephemeral
#include<stdio.h>
#include<math.h>

//Defining Calculator Functions
double addition(double x, double y)
{
    return x+y;
}

double subtraction(double x, double y)
{
    return x-y;
}

double multiplication(double x, double y)
{
    return x*y;
}

double division(double x, double y)
{
    return x/y;
}

double power(double x, double y)
{
    return pow(x,y);
}

double square_root(double x)
{
    return sqrt(x);
}

double absolute_value(double x)
{
    return fabs(x);
}

//Defining Main Function
int main()
{
    //Displaying Menu to User
    printf("\n\n**************************************");
    printf("\n    Scientific Calculator");
    printf("\n**************************************");
    printf("\n\nPlease Select an Operation from Below:");
    printf("\n\n1. Addition");
    printf("\n2. Subtraction");
    printf("\n3. Multiplication");
    printf("\n4. Division");
    printf("\n5. Power");
    printf("\n6. Square Root");
    printf("\n7. Absolute Value");
    printf("\n8. Exit");
    
    //Initializing Variables
    int option;
    double x,y,result;
    
    //Getting User Input and Performing Operation
    do {
        printf("\n\nOption: ");
        scanf("%d",&option);
        
        if(option==8)
        {
            printf("\nThank You for Using the Program!\n");
            return 0;
        }
        
        if(option==6 || option==7)
        {
            printf("\nEnter a Number: ");
            scanf("%lf",&x);
        }   
        else
        {
            printf("\nEnter Two Numbers: ");
            scanf("%lf %lf",&x,&y);
        }
        
        switch(option)
        {
            case 1:
                result = addition(x,y);
                printf("\nResult: %.3lf",result);
                break;
            case 2:
                result = subtraction(x,y);
                printf("\nResult: %.3lf",result);
                break;
            case 3:
                result = multiplication(x,y);
                printf("\nResult: %.3lf",result);
                break;
            case 4:
                if(y==0) printf("\nError: Division by Zero!");
                else
                {
                    result = division(x,y);
                    printf("\nResult: %.3lf",result);
                }
                break;
            case 5:
                result = power(x,y);
                printf("\nResult: %.3lf",result);
                break;
            case 6:
                if(x<0) printf("\nError: Square Root of Negative Number!");
                else
                {
                    result = square_root(x);
                    printf("\nResult: %.3lf",result);
                }
                break;
            case 7:
                result = absolute_value(x);
                printf("\nResult: %.3lf",result);
                break;
            default:
                printf("\nInvalid Option! Please Select Again.");
        }
    } while(1); //Continue Looping Until User Chooses to Exit
    
    return 0;
}