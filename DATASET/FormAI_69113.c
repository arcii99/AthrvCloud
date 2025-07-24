//FormAI DATASET v1.0 Category: Unit converter ; Style: excited
#include <stdio.h>

int main()
{
    int choice;
    float temp, result;

    printf("Welcome to the unit converter!\n\n");

    printf("Which conversion would you like to perform?\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    scanf("%d", &choice);

    if (choice == 1)
    {
        // Celsius to Fahrenheit conversion
        printf("Enter the temperature in Celsius: ");
        scanf("%f", &temp);
        result = (temp * 9 / 5) + 32;
        printf("%f degrees Celsius is equal to %f degrees Fahrenheit.\n", temp, result);
    }
    else if (choice == 2)
    {
        // Fahrenheit to Celsius conversion
        printf("Enter the temperature in Fahrenheit: ");
        scanf("%f", &temp);
        result = (temp - 32) * 5 / 9;
        printf("%f degrees Fahrenheit is equal to %f degrees Celsius.\n", temp, result);
    }
    else
    {
        printf("Invalid choice. Please select 1 or 2.\n");
    }

    return 0;
}