//FormAI DATASET v1.0 Category: Arithmetic ; Style: future-proof
#include<stdio.h>

int main(){
    printf("Enter two numbers:\n");
    int num1, num2;
    scanf("%d%d",&num1,&num2);

    printf("Select an Arithmetic operation:\n");
    printf("1. Addition (+)\n");
    printf("2. Subtraction (-)\n");
    printf("3. Multiplication (*)\n");
    printf("4. Division (/)\n");
    int choice;
    scanf("%d",&choice);

    switch(choice){
        case 1:
            printf("Sum of %d and %d is %d\n",num1,num2,num1+num2);
            break;
        case 2:
            printf("Difference of %d and %d is %d\n",num1,num2,num1-num2);
            break;
        case 3:
            printf("Product of %d and %d is %d\n",num1,num2,num1*num2);
            break;
        case 4:
            if(num2 != 0) printf("Quotient of %d and %d is %d with a remainder of %d\n",num1,num2,num1/num2,num1%num2);
            else printf("Division by zero not possible!\n");
            break;
        default:
            printf("Invalid option!\n");
    }

    return 0;
}