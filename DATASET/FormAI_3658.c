//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Ken Thompson
#include<stdio.h>
#include<math.h>

double factorial(double x){
    if (x == 0) return 1;
    return x * factorial(x-1);
}

int main(){
    char operator;
    double num1,num2,result;

    printf("Enter an operator (+,-,*,/,^,%%): ");
    scanf("%c",&operator);

    printf("Enter first operand: ");
    scanf("%lf",&num1);

    if(operator == '^'){
        printf("Enter second operand: ");
        scanf("%lf",&num2);
    }

    switch(operator){
        case '+':
            printf("%.2lf + ",num1);
            printf("Enter second operand: ");
            scanf("%lf",&num2);
            result = num1 + num2;
            break;

        case '-':
            printf("%.2lf - ",num1);
            printf("Enter second operand: ");
            scanf("%lf",&num2);
            result = num1 - num2;
            break;

        case '*':
            printf("%.2lf * ",num1);
            printf("Enter second operand: ");
            scanf("%lf",&num2);
            result = num1 * num2;
            break;

        case '/':
            printf("%.2lf / ",num1);
            printf("Enter second operand: ");
            scanf("%lf",&num2);
            if(num2 == 0){
                printf("Error: Cannot divide by zero.\n");
                return 0;
            }
            result = num1 / num2;
            break;

        case '^':
            printf("%.2lf ^ %.2lf = ",num1,num2);
            result = pow(num1,num2);
            break;

        case '%':
            printf("%.2lf %% ",num1);
            printf("Enter second operand: ");
            scanf("%lf",&num2);
            if(num2 <= 0 || num2 > num1){
                printf("Error: Invalid modulo operand.\n");
                return 0;
            }
            result = fmod(num1,num2);
            break;

        default:
            printf("Error: Invalid operator.\n");
            return 0;
    }
    printf("%.2lf\n",num2);
    printf("Result: %.2f\n",result);

    return 0;
}