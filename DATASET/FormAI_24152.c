//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <math.h>

int main()
{
    char operator;
    double num1, num2, result;
    
    printf("Enter an operator (+, -, *, /, ^): ");
    scanf("%c", &operator);
    
    printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);
    
    switch(operator)
    {
        case '+':
            result = num1 + num2;
            printf("%.2lf + %.2lf = %.2lf\n", num1, num2, result);
            break;
        
        case '-':
            result = num1 - num2;
            printf("%.2lf - %.2lf = %.2lf\n", num1, num2, result);
            break;
            
        case '*':
            result = num1 * num2;
            printf("%.2lf * %.2lf = %.2lf\n", num1, num2, result);
            break;
            
        case '/':
            if(num2 == 0)
            {
                printf("Error: Divide by zero");
                break;
            }
            else
            {
                result = num1 / num2;
                printf("%.2lf / %.2lf = %.2lf\n", num1, num2, result);
                break;
            }
        
        case '^':
            result = pow(num1, num2);
            printf("%.2lf ^ %.2lf = %.2lf\n", num1, num2, result);
            break;
        
        default:
            printf("Invalid operator");
            break;
    }
    
    return 0;
}