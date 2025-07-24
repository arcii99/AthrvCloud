//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: satisfied
#include<stdio.h>
#include<math.h>

int main()
{
    int choice;
    float a,b,result;

    printf("Welcome to My Scientific Calculator\n");

    while(1) // Infinite loop for continuous use
    {
        printf("\nPlease Select the Operation:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Square root\n");
        printf("6. Power\n");
        printf("7. Sin Value\n");
        printf("8. Cos Value\n");
        printf("9. Tan Value\n");
        printf("10. Logarithmic Value\n");
        printf("11. Exit\n\n");

        printf("Enter Your Choice : ");
        scanf("%d",&choice);

        if(choice==11) // Exit Choice
        {
            printf("Thanks for using the calculator!\n");
            break;
        }

        switch(choice)
        {
            case 1: // Addition
                printf("Please Enter Two Numbers: ");
                scanf("%f%f",&a,&b);
                result = a + b;
                printf("Addition of %.2f and %.2f is : %.2f\n",a,b,result);
                break;

            case 2: // Subtraction
                printf("Please Enter Two Numbers: ");
                scanf("%f%f",&a,&b);
                result = a - b;
                printf("Subtraction of %.2f and %.2f is: %.2f\n",a,b,result);
                break;

            case 3: // Multiplication
                printf("Please Enter Two Numbers: ");
                scanf("%f%f",&a,&b);
                result = a * b;
                printf("Multiplication of %.2f and %.2f is : %.2f\n",a,b,result);
                break;

            case 4: // Division
                printf("Please Enter Two Numbers: ");
                scanf("%f%f",&a,&b);
                if(b==0)
                {
                    printf("The Second Number Can Not be Zero!\n");
                }
                else
                {
                    result = a / b;
                    printf("Division of %.2f and %.2f is : %.2f\n",a,b,result);
                }
                break;

            case 5: // Square root
                printf("Please Enter a Number: ");
                scanf("%f",&a);
                result = sqrt(a);
                printf("Square Root of %.2f is : %.2f\n",a,result);
                break;

            case 6: // Power
                printf("Please Enter the Base Number: ");
                scanf("%f",&a);
                printf("Please Enter the Exponent Number : ");
                scanf("%f",&b);
                result = pow(a,b);
                printf("Power of %.2f to %.2f is : %.2f\n",a,b,result);
                break;

            case 7: // Sin Value
                printf("Please Enter the Angle in Degree: ");
                scanf("%f",&a);
                result = sin(a*3.14159265/180);
                printf("Sin Value of %f in Degree is : %f\n",a,result);
                break;

            case 8: // Cos Value
                printf("Please Enter the Angle in Degree: ");
                scanf("%f",&a);
                result = cos(a*3.14159265/180);
                printf("Cos Value of %f in Degree is : %f\n",a,result);
                break;

            case 9: // Tan Value
                printf("Please Enter the Angle in Degree: ");
                scanf("%f",&a);
                result = tan(a*3.14159265/180);
                printf("Tan Value of %f in Degree is : %f\n",a,result);
                break;

            case 10: // Logarithmic Value
                printf("Please Enter a Number: ");
                scanf("%f",&a);
                result = log10(a);
                printf("Logarithmic Value of %f is : %f\n",a,result);
                break;

            default: // Wrong Choice
                printf("Wrong Choice! Please Try Again\n");
                break;
        }
    }

    return 0;
}