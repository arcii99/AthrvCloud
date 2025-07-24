//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// A mind-bending implementation of a scientific calculator in C.

int main()
{
    printf("Welcome to the Mind-bending Scientific Calculator!\n\n");

    int choice=0;
    float num1,num2,result;

    while(choice!=6){
        printf("**********MENU************\n");
        printf("1. Add\n");
        printf("2. Subtract\n");
        printf("3. Multiply\n");
        printf("4. Divide\n");
        printf("5. Power\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1: printf("Enter first number: ");
                    scanf("%f",&num1);
                    printf("Enter second number: ");
                    scanf("%f",&num2);
                    result=num1+num2;
                    printf("Result: %f\n\n",result);
                    break;

            case 2: printf("Enter first number: ");
                    scanf("%f",&num1);
                    printf("Enter second number: ");
                    scanf("%f",&num2);
                    result=num1-num2;
                    printf("Result: %f\n\n",result);
                    break;

            case 3: printf("Enter first number: ");
                    scanf("%f",&num1);
                    printf("Enter second number: ");
                    scanf("%f",&num2);
                    result=num1*num2;
                    printf("Result: %f\n\n",result);
                    break;

            case 4: printf("Enter first number: ");
                    scanf("%f",&num1);
                    printf("Enter second number: ");
                    scanf("%f",&num2);
                    if(num2!=0){
                        result=num1/num2;
                        printf("Result: %f\n\n",result);
                    }
                    else{
                        printf("Division by zero not possible!\n\n");
                    }
                    break;

            case 5: printf("Enter the number: ");
                    scanf("%f",&num1);
                    printf("Enter the power: ");
                    scanf("%f",&num2);
                    result=pow(num1,num2);
                    printf("Result: %f\n\n",result);
                    break;

            case 6: printf("Thank you for using the Mind-bending Calculator!");
                    break;

            default: printf("Invalid Choice!\n\n");
        }
    }
    return 0;
}