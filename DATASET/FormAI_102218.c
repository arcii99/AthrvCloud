//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: futuristic
#include <stdio.h>
#include <math.h>

int main()
{
    int choice;
    double num1, num2;
    printf("Welcome to the futuristic scientific calculator!\n");
    printf("Please choose an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power\n");
    printf("6. Square Root\n");
    printf("7. Logarithm\n");
    printf("8. Exit\n");

    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter two numbers to add: ");
                scanf("%lf %lf", &num1, &num2);
                printf("%.2lf + %.2lf = %.2lf\n", num1, num2, num1 + num2);
                break;
            case 2:
                printf("Enter two numbers to subtract: ");
                scanf("%lf %lf", &num1, &num2);
                printf("%.2lf - %.2lf = %.2lf\n", num1, num2, num1 - num2);
                break;
            case 3:
                printf("Enter two numbers to multiply: ");
                scanf("%lf %lf", &num1, &num2);
                printf("%.2lf * %.2lf = %.2lf\n", num1, num2, num1 * num2);
                break;
            case 4:
                printf("Enter two numbers to divide: ");
                scanf("%lf %lf", &num1, &num2);
                if(num2 == 0) {
                    printf("Error: Division by 0\n");
                }
                else {
                    printf("%.2lf / %.2lf = %.2lf\n", num1, num2, num1 / num2);
                }
                break;
            case 5:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                printf("%.2lf raised to the power of %.2lf is %.2lf\n", num1, num2, pow(num1, num2));
                break;
            case 6:
                printf("Enter a number: ");
                scanf("%lf", &num1);
                printf("The square root of %.2lf is %.2lf\n", num1, sqrt(num1));
                break;
            case 7:
                printf("Enter a number: ");
                scanf("%lf", &num1);
                printf("The natural logarithm of %.2lf is %.2lf\n", num1, log(num1));
                break;
            case 8:
                printf("Thank you for using the futuristic scientific calculator!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 8);

    return 0;
}