//FormAI DATASET v1.0 Category: Math exercise ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    int a, b;
    double result;

    srand(time(0)); // Seeding the random number generator

    printf("Welcome to the Math Exercise Program!\n");
    printf("You will be given two random numbers and asked to perform a mathematical operation.\n");

    while (1) { // Infinite loop until user chooses to quit
        a = rand() % 101; // Generate random number between 0 and 100
        b = rand() % 101;

        printf("Your numbers are %d and %d.\n", a, b);
        printf("What operation would you like to perform on the numbers?\n");
        printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division (with decimal)\n5. Division (without decimal)\n6. Exponentiation\n7. Square root\n");
        printf("Enter the number corresponding to your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                result = a + b;
                printf("%d + %d = %.2lf\n", a, b, result);
                break;
            case 2:
                result = a - b;
                printf("%d - %d = %.2lf\n", a, b, result);
                break;
            case 3:
                result = a * b;
                printf("%d * %d = %.2lf\n", a, b, result);
                break;
            case 4:
                result = (double) a / b;
                printf("%d / %d = %.2lf\n", a, b, result);
                break;
            case 5:
                result = a / b;
                printf("%d / %d = %d\n", a, b, (int) result);
                break;
            case 6:
                result = pow(a, b);
                printf("%d ^ %d = %.2lf\n", a, b, result);
                break;
            case 7:
                result = sqrt(a);
                printf("sqrt(%d) = %.2lf\n", a, result);
                result = sqrt(b);
                printf("sqrt(%d) = %.2lf\n", b, result);
                break;
            default:
                printf("Invalid choice! Please choose a number between 1 and 7.\n");
        }

        printf("Press 1 to continue or 0 to quit: ");
        int exit;
        scanf("%d", &exit);
        if (exit == 0) {
            printf("Thank you for using the Math Exercise Program!\n");
            break; // Exit the while loop and end the program
        }
    }

    return 0;
}