//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: high level of detail
#include<stdio.h>
#include<math.h>

int main()
{
    int choice;
    float num1,num2,result;
    printf("\nWelcome to the Scientific Calculator\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Square Root\n6. Exponential\n7. Logarithm\n8. Trigonometric Functions\n");
    printf("Enter your choice:");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            printf("Enter two numbers:");
            scanf("%f%f",&num1,&num2);
            result=num1+num2;
            printf("Result=%.2f",result);
            break;
        case 2:
            printf("Enter two numbers:");
            scanf("%f%f",&num1,&num2);
            result=num1-num2;
            printf("Result=%.2f",result);
            break;
        case 3:
            printf("Enter two numbers:");
            scanf("%f%f",&num1,&num2);
            result=num1*num2;
            printf("Result=%.2f",result);
            break;
        case 4:
            printf("Enter two numbers:");
            scanf("%f%f",&num1,&num2);
            result=num1/num2;
            printf("Result=%.2f",result);
            break;
        case 5:
            printf("Enter a number:");
            scanf("%f",&num1);
            result=sqrt(num1);
            printf("Result=%.2f",result);
            break;
        case 6:
            printf("Enter a number:");
            scanf("%f",&num1);
            result=exp(num1);
            printf("Result=%.2f",result);
            break;
        case 7:
            printf("Enter a number:");
            scanf("%f",&num1);
            result=log(num1);
            printf("Result=%.2f",result);
            break;
        case 8:
            printf("1. Sin\n2. Cos\n3. Tan\n4. Cosec\n5. Sec\n6. Cot\n");
            printf("Enter your choice:");
            scanf("%d",&choice);
            printf("Enter a number:");
            scanf("%f",&num1);
            switch(choice)
            {
                case 1:
                    result=sin(num1*M_PI/180);
                    printf("Result=%.2f",result);
                    break;
                case 2:
                    result=cos(num1*M_PI/180);
                    printf("Result=%.2f",result);
                    break;
                case 3:
                    result=tan(num1*M_PI/180);
                    printf("Result=%.2f",result);
                    break;
                case 4:
                    result=1/sin(num1*M_PI/180);
                    printf("Result=%.2f",result);
                    break;
                case 5:
                    result=1/cos(num1*M_PI/180);
                    printf("Result=%.2f",result);
                    break;
                case 6:
                    result=1/tan(num1*M_PI/180);
                    printf("Result=%.2f",result);
                    break;
                default:
                    printf("Invalid choice");
            }
            break;
        default:
            printf("Invalid choice");
    }
    return 0;
}