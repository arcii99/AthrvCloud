//FormAI DATASET v1.0 Category: System administration ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice, num1, num2, result;

    printf("Welcome to the mathematical system administration program!\n\n");

    do{
        printf("Here are your options: \n");
        printf("1. Add two numbers\n");
        printf("2. Subtract two numbers\n");
        printf("3. Multiply two numbers\n");
        printf("4. Divide two numbers\n");
        printf("5. Find the remainder of two numbers\n");
        printf("6. Exit program\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter two numbers to add: ");
                scanf("%d %d", &num1, &num2);
                result = num1 + num2;
                printf("The sum of %d and %d is %d\n", num1, num2, result);
                break;
            case 2:
                printf("Enter two numbers to subtract (in the form num1 - num2): ");
                scanf("%d %d", &num1, &num2);
                result = num1 - num2;
                printf("The difference of %d and %d is %d\n", num1, num2, result);
                break;
            case 3:
                printf("Enter two numbers to multiply: ");
                scanf("%d %d", &num1, &num2);
                result = num1 * num2;
                printf("The product of %d and %d is %d\n", num1, num2, result);
                break;
            case 4:
                printf("Enter two numbers to divide (in the form num1 / num2): ");
                scanf("%d %d", &num1, &num2);
                result = num1 / num2;
                printf("The quotient of %d and %d is %d\n", num1, num2, result);
                break;
            case 5:
                printf("Enter two numbers to find the remainder (in the form num1 %% num2): ");
                scanf("%d %d", &num1, &num2);
                result = num1 % num2;
                printf("The remainder of %d divided by %d is %d\n", num1, num2, result);
                break;
            case 6:
                printf("Exiting program. Thank you for using the mathematical system administration program!\n");
                exit(0);
            default:
                printf("Invalid choice. Please choose again.\n");
                break;
        }
    } while(choice != 6);

    return 0;
}