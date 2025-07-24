//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to clear the console
void clearConsole()
{
    system("cls || clear");
}

// Function to get user input
void getUserInput(int *a, int *b)
{
    printf("Please enter two integers to perform calculations:\n");
    printf("a = ");
    scanf("%d", a);
    printf("b = ");
    scanf("%d", b);
}

// Function to display result
void displayResult(int result)
{
    printf("Result: %d\n", result);
}

int main()
{
    int a, b, choice, result;

    // Title Text
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("      Welcome to Medieval Scientific Calculator      \n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    do {
        // Options Text
        printf("\nPlease select an option:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Square Root\n");
        printf("6. Exponentiation\n");
        printf("7. Logarithm\n");
        printf("8. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        clearConsole();

        switch (choice) {
            case 1:
                getUserInput(&a, &b);
                result = a + b;
                displayResult(result);
                break;
            case 2:
                getUserInput(&a, &b);
                result = a - b;
                displayResult(result);
                break;
            case 3:
                getUserInput(&a, &b);
                result = a * b;
                displayResult(result);
                break;
            case 4:
                getUserInput(&a, &b);

                if (b != 0) {
                    result = a / b;
                    displayResult(result);
                } else {
                    printf("Error: Division by zero\n");
                }
                break;
            case 5:
                getUserInput(&a, &b);
                
                if (a >= 0) {
                    result = sqrt(a);
                    displayResult(result);
                } else {
                    printf("Error: Invalid input\n");
                }
                break;
            case 6:
                getUserInput(&a, &b);
                result = pow(a, b);
                displayResult(result);
                break;
            case 7:
                getUserInput(&a, &b);

                if (a >= 0 && b >= 0) {
                    result = log(a) / log(b);
                    displayResult(result);
                } else {
                    printf("Error: Invalid input\n");
                }
                break;
            case 8:
                printf("Thank you for using Medieval Scientific Calculator!\n");
                break;
            default:
                printf("Error: Invalid choice\n");
        }

    } while (choice != 8);

    return 0;
}