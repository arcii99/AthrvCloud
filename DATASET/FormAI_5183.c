//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: real-life
#include<stdio.h>
#include<math.h>

int main()
{
    int choice, num1, num2, result;
    float num3, num4, result_float;
    printf("\tWelcome to Scientific Calculator\n");
    printf("\t--------------------------------\n");
    printf("\tPlease Select One from the Following Options:\n");
    printf("\t1: Addition\n");
    printf("\t2: Subtraction\n");
    printf("\t3: Multiplication\n");
    printf("\t4: Division\n");
    printf("\t5: Square\n");
    printf("\t6: Square Root\n");
    printf("\t7: Power\n");
    printf("\t8: Exponential\n");
    printf("\t9: Logarithm\n");
    printf("\t10: Sine\n");
    printf("\t11: Cosine\n");
    printf("\t12: Tangent\n");
    scanf("%d",&choice);
 
    switch(choice)
    {
        case 1:
            printf("Enter First Number: ");
            scanf("%d",&num1);
            printf("Enter Second Number: ");
            scanf("%d",&num2);
            result = num1 + num2;
            printf("Result of %d + %d = %d\n",num1,num2,result);
            break;
 
        case 2:
            printf("Enter First Number: ");
            scanf("%d",&num1);
            printf("Enter Second Number: ");
            scanf("%d",&num2);
            result = num1 - num2;
            printf("Result of %d - %d = %d\n",num1,num2,result);
            break;
 
        case 3:
            printf("Enter First Number: ");
            scanf("%d",&num1);
            printf("Enter Second Number: ");
            scanf("%d",&num2);
            result = num1 * num2;
            printf("Result of %d * %d = %d\n",num1,num2,result);
            break;
 
        case 4:
            printf("Enter First Number: ");
            scanf("%d",&num1);
            printf("Enter Second Number: ");
            scanf("%d",&num2);
            if(num2 == 0){
                printf("Error! Division by zero.\n");
            }
            else{
                result_float = (float)num1 / (float)num2;
                printf("Result of %d / %d = %.2f\n",num1,num2,result_float);
            }
            break;
 
        case 5:
            printf("Enter a Number: ");
            scanf("%d",&num1);
            result = pow(num1, 2);
            printf("Result of %d^2 = %d\n",num1,result);
            break;
 
        case 6:
            printf("Enter a Number: ");
            scanf("%d",&num1);
            result_float = sqrt(num1);
            printf("Result of √%d = %.2f\n",num1,result_float);
            break;
 
        case 7:
            printf("Enter First Number: ");
            scanf("%d",&num1);
            printf("Enter Second Number: ");
            scanf("%d",&num2);
            result = pow(num1, num2);
            printf("Result of %d^%d = %d\n",num1,num2,result);
            break;
 
        case 8:
            printf("Enter a Number: ");
            scanf("%f",&num3);
            result_float = exp(num3);
            printf("Result of e^%.1f = %.2f\n",num3,result_float);
            break;

        case 9:
            printf("Enter a Number: ");
            scanf("%f",&num3);
            result_float = log10(num3);
            printf("Result of log(%.1f) = %.2f\n",num3,result_float);
            break;

        case 10:
            printf("Enter a Number (in radians): ");
            scanf("%f",&num3);
            result_float = sin(num3);
            printf("Result of sin(%.1f) = %.2f\n",num3,result_float);
            break;

        case 11:
            printf("Enter a Number (in radians): ");
            scanf("%f",&num3);
            result_float = cos(num3);
            printf("Result of cos(%.1f) = %.2f\n",num3,result_float);
            break;

        case 12:
            printf("Enter a Number (in radians): ");
            scanf("%f",&num3);
            result_float = tan(num3);
            printf("Result of tan(%.1f) = %.2f\n",num3,result_float);
            break;

        default:
            printf("Invalid Input! Please Try Again.");
            break;
    }
 
    return 0;
}