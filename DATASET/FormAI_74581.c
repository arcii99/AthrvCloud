//FormAI DATASET v1.0 Category: Arithmetic ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>

int main()
{
    // Welcome message
    printf("Welcome to the math wizard program!\n");

    // Getting user input
    int num1, num2, choice;
    printf("Please enter the first number: ");
    scanf("%d", &num1);
    printf("Please enter the second number: ");
    scanf("%d", &num2);

    // Displaying the menu
    printf("\nWhat would you like to do with these numbers?\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. Find the remainder\n");
    printf("6. Find the power\n");
    printf("7. Swap the values\n");
    printf("Please enter your choice: ");
    scanf("%d", &choice);

    // Performing the selected operation 
    switch(choice)
    {
        case 1:
            printf("%d + %d = %d\n", num1, num2, num1+num2);
            break;
        case 2:
            printf("%d - %d = %d\n", num1, num2, num1-num2);
            break;
        case 3:
            printf("%d * %d = %d\n", num1, num2, num1*num2);
            break;
        case 4:
            printf("%d / %d = %d\n", num1, num2, num1/num2);
            break;
        case 5:
            printf("%d %% %d = %d\n", num1, num2, num1%num2);
            break;
        case 6:
            printf("%d raised to the power of %d = %f\n", num1, num2, pow(num1, num2));
            break;
        case 7:
            num1 = num1 + num2;
            num2 = num1 - num2;
            num1 = num1 - num2;
            printf("After swapping, num1 = %d and num2 = %d\n", num1, num2);
            break;
        default:
            printf("Invalid choice!\n");
    }

    printf("\nThank you for using math wizard program!\n");

    return 0;
}