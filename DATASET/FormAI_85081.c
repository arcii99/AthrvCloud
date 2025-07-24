//FormAI DATASET v1.0 Category: Temperature Converter ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice;
    double celsius, fahrenheit;

    printf("\nWelcome to the Temperature Converter Program\n");

    do {
        printf("\nPlease choose from the following options:\n");
        printf("\n1. Celsius to Fahrenheit\n2. Fahrenheit to Celsius\n3. Quit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter temperature in Celsius: ");
                scanf("%lf", &celsius);
                fahrenheit = (celsius * 9/5) + 32;
                printf("\n%.2lf degree Celsius is equal to %.2lf degree Fahrenheit.\n", celsius, fahrenheit);
                break;

            case 2:
                printf("\nEnter temperature in Fahrenheit: ");
                scanf("%lf", &fahrenheit);
                celsius = (fahrenheit - 32) * 5/9;
                printf("\n%.2lf degree Fahrenheit is equal to %.2lf degree Celsius.\n", fahrenheit, celsius);
                break;

            case 3:
                printf("\nThank you for using the Temperature Converter Program.\n");
                exit(EXIT_SUCCESS);
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while(choice != 3);

    return 0;
}