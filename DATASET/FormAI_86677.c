//FormAI DATASET v1.0 Category: Temperature Converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float celsius, fahrenheit;
    int choice;

    printf("Welcome to the Celsius to Fahrenheit converter!\n");

    while (1)
    {
        printf("\nEnter your choice:\n1. Convert Celsius to Fahrenheit\n2. Convert Fahrenheit to Celsius\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &celsius);

                fahrenheit = (celsius * 9/5) + 32;

                printf("\n%f degrees Celsius is %f degrees Fahrenheit.\n", celsius, fahrenheit);

                break;

            case 2:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &fahrenheit);

                celsius = (fahrenheit - 32) * 5/9;

                printf("\n%f degrees Fahrenheit is %f degrees Celsius.\n", fahrenheit, celsius);

                break;

            case 3:
                printf("\nThank you for using our converter! Goodbye!\n");
                exit(0); // exit the program

            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}