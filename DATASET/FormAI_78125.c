//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: surprised
#include<stdio.h>
#include<math.h>

int main(){
    printf("Welcome to the Scientific Calculator!\n");

    int choice;
    double number, number2, result;

    do{
        printf("\nPlease select an operation:\n\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Square root\n");
        printf("6. Power\n");
        printf("7. Sin\n");
        printf("8. Cos\n");
        printf("9. Tan\n");
        printf("10. Exit\n");

        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter two numbers to add: \n");
                scanf("%lf %lf", &number, &number2);
                result = number + number2;
                printf("%.2lf + %.2lf = %.2lf\n", number, number2, result);
                break;

            case 2:
                printf("Enter two numbers to subtract: \n");
                scanf("%lf %lf", &number, &number2);
                result = number - number2;
                printf("%.2lf - %.2lf = %.2lf\n", number, number2, result);
                break;

            case 3:
                printf("Enter two numbers to multiply: \n");
                scanf("%lf %lf", &number, &number2);
                result = number * number2;
                printf("%.2lf * %.2lf = %.2lf\n", number, number2, result);
                break;

            case 4:
                printf("Enter two numbers to divide: \n");
                scanf("%lf %lf", &number, &number2);
                if(number2 == 0){
                    printf("Cannot divide by zero!\n");
                }
                else{
                    result = number / number2;
                    printf("%.2lf / %.2lf = %.2lf\n", number, number2, result);
                }
                break;

            case 5:
                printf("Enter a number to find the square root: \n");
                scanf("%lf", &number);
                result = sqrt(number);
                printf("The square root of %.2lf is %.2lf\n", number, result);
                break;

            case 6:
                printf("Enter a number to find the power: \n");
                scanf("%lf", &number);
                printf("Enter the power: \n");
                scanf("%lf", &number2);
                result = pow(number, number2);
                printf("%.2lf raised to the power of %.2lf is %.2lf\n", number, number2, result);
                break;

            case 7:
                printf("Enter a number to find the sine: \n");
                scanf("%lf", &number);
                result = sin(number);
                printf("The sine of %.2lf is %.2lf\n", number, result);
                break;

            case 8:
                printf("Enter a number to find the cosine: \n");
                scanf("%lf", &number);
                result = cos(number);
                printf("The cosine of %.2lf is %.2lf\n", number, result);
                break;

            case 9:
                printf("Enter a number to find the tangent: \n");
                scanf("%lf", &number);
                result = tan(number);
                printf("The tangent of %.2lf is %.2lf\n", number, result);
                break;

            case 10:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid input!\n");
        }

    } while(choice != 10);

    return 0;
}