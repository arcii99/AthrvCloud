//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: enthusiastic
#include<stdio.h>
#include<math.h>

/* This is a Scientific Calculator implementation program which can perform various scientific calculations */

int main()
{
    printf("\n\t\tWelcome to my Scientific Calculator\n");
    printf("\t\t******************************************\n");
    float num1, num2, result;
    int option;
    
    do{
        printf("\n\t\tChoose an operation to perform");
        printf("\n\t\t1. Addition");
        printf("\n\t\t2. Subtraction");
        printf("\n\t\t3. Multiplication");
        printf("\n\t\t4. Division");
        printf("\n\t\t5. Power of a number");
        printf("\n\t\t6. Square root of a number");
        printf("\n\t\t7. Sine of an angle");
        printf("\n\t\t8. Cosine of an angle");
        printf("\n\t\t9. Tangent of an angle");
        printf("\n\t\t10. Exit");
        printf("\n\t\t____________________________________\n");
        printf("\n\t\tEnter your choice: ");
        scanf("%d", &option);
        
        switch(option)
        {
            case 1:
                printf("\n\t\tEnter two numbers to add: ");
                scanf("%f %f", &num1, &num2);
                result = num1 + num2;
                printf("\n\t\tThe result is: %.2f", result);
                break;
            case 2:
                printf("\n\t\tEnter two numbers to subtract: ");
                scanf("%f %f", &num1, &num2);
                result = num1 - num2;
                printf("\n\t\tThe result is: %.2f", result);
                break;
            case 3:
                printf("\n\t\tEnter two numbers to multiply: ");
                scanf("%f %f", &num1, &num2);
                result = num1 * num2;
                printf("\n\t\tThe result is: %.2f", result);
                break;
            case 4:
                printf("\n\t\tEnter two numbers to divide: ");
                scanf("%f %f", &num1, &num2);
                if(num2 == 0){
                    printf("\n\t\tMath Error: Division by zero");
                }
                else{
                    result = num1 / num2;
                    printf("\n\t\tThe result is: %.2f", result);
                }
                break;
            case 5:
                printf("\n\t\tEnter base and exponent: ");
                scanf("%f %f", &num1, &num2);
                result = pow(num1, num2);
                printf("\n\t\t%.2f to the power of %.2f is: %.2f", num1, num2, result);
                break;
            case 6:
                printf("\n\t\tEnter a number to find it's square root: ");
                scanf("%f", &num1);
                if(num1 < 0){
                    printf("\n\t\tMath Error: Squre root of negative number is not real");
                }
                else{
                    result = sqrt(num1);
                    printf("\n\t\tThe square root of %.2f is: %.2f", num1, result);
                }
                break;
            case 7:
                printf("\n\t\tEnter an angle in degrees to find it's sine value: ");
                scanf("%f", &num1);
                result = sin(num1 * 3.14159265 / 180.0);
                printf("\n\t\tThe sin(%.2f) is: %.2f", num1, result);
                break;
            case 8:
                printf("\n\t\tEnter an angle in degrees to find it's cosine value: ");
                scanf("%f", &num1);
                result = cos(num1 * 3.14159265 / 180.0);
                printf("\n\t\tThe cos(%.2f) is: %.2f", num1, result);
                break;
            case 9:
                printf("\n\t\tEnter an angle in degrees to find it's tangent value: ");
                scanf("%f", &num1);
                if(num1 == 90 || num1 == 270){
                    printf("\n\t\tMath Error: Tan(90) and Tan(270) are not defined");
                }
                else{
                    result = tan(num1 * 3.14159265 / 180.0);
                    printf("\n\t\tThe tan(%.2f) is: %.2f", num1, result);
                }
                break;
            case 10:
                printf("\n\t\t*******************************");
                printf("\n\t\tThanks for using this calculator");
                printf("\n\t\t*******************************");
                break;
            default:
                printf("\n\t\tInvalid choice, please enter a valid option");
        }
        
    }while(option != 10);
    
    return 0;
}