//FormAI DATASET v1.0 Category: Calculator ; Style: creative
#include<stdio.h>
#include<math.h>

int main(){
    int choice;
    float num1,num2,result;
    printf("Welcome to my Unique Calculator Program!\n");

    do{
        printf("\nPlease select an operation:\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n5.Sine\n6.Cosine\n7.Tangent\n8.Power\n9.Square Root\n10.Exit\n");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("You chose Addition. Please enter two numbers: ");
                scanf("%f %f",&num1,&num2);
                result = num1 + num2;
                printf("The sum of %.2f and %.2f is: %.2f \n",num1, num2,result);
                break;

            case 2:
                printf("You chose Subtraction. Please enter two numbers: ");
                scanf("%f %f",&num1,&num2);
                result = num1 - num2;
                printf("The difference of %.2f and %.2f is: %.2f \n",num1, num2,result);
                break;

            case 3:
                printf("You chose Multiplication. Please enter two numbers: ");
                scanf("%f %f",&num1,&num2);
                result = num1 * num2;
                printf("The product of %.2f and %.2f is: %.2f \n",num1, num2,result);
                break;

            case 4:
                printf("You chose Division. Please enter two numbers: ");
                scanf("%f %f",&num1,&num2);
                if(num2==0){
                    printf("Cannot divide by zero.\n");
                }
                else{
                    result = num1 / num2;
                    printf("%.2f divided by %.2f is : %.2f \n",num1, num2,result);
                }
                break;

            case 5:
                printf("You chose Sine. Please enter a number in radians: ");
                scanf("%f",&num1);
                result = sin(num1);
                printf("The sine of %.2f is: %.2f \n",num1,result);
                break;

            case 6:
                printf("You chose Cosine. Please enter a number in radians: ");
                scanf("%f",&num1);
                result = cos(num1);
                printf("The cosine of %.2f is: %.2f \n",num1,result);
                break;

            case 7:
                printf("You chose Tangent. Please enter a number in radians: ");
                scanf("%f",&num1);
                result = tan(num1);
                printf("The tangent of %.2f is: %.2f \n",num1,result);
                break;

            case 8:
                printf("You chose Power. Please enter two numbers: ");
                scanf("%f %f",&num1,&num2);
                result = pow(num1,num2);
                printf("%.2f raised to the power of %.2f is: %.2f \n",num1, num2,result);
                break;

            case 9:
                printf("You chose Square Root. Please enter a positive number: ");
                scanf("%f",&num1);
                if(num1<0){
                    printf("Cannot take square root of negative number.\n");
                }
                else{
                    result = sqrt(num1);
                    printf("The square root of %.2f is: %.2f \n",num1,result);
                }
                break;

            case 10:
                printf("Exiting Calculator Program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }while(choice!=10);

    return 0;
}