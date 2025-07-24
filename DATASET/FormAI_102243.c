//FormAI DATASET v1.0 Category: Temperature Converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice;
    float temperature, convertedTemp;

    printf("Welcome to the Temperature Converter!\n\n");

    printf("Select an option:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Exit\n\n");

    while(1)
    {
        printf("Enter your choice (1, 2, or 3): ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\nEnter temperature in Celsius: ");
                scanf("%f", &temperature);
                convertedTemp = (temperature * 9/5) + 32;
                printf("\n%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n\n", temperature, convertedTemp);
                break;

            case 2:
                printf("\nEnter temperature in Fahrenheit: ");
                scanf("%f", &temperature);
                convertedTemp = (temperature - 32) * 5/9;
                printf("\n%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n\n", temperature, convertedTemp);
                break;

            case 3:
                printf("\nExiting Temperature Converter. Stay safe and keep warm!\n");
                exit(0);
                break;

            default:
                printf("\nInvalid choice. Please enter 1, 2, or 3.\n\n");
                break;
        }
    }

    return 0;
}