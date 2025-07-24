//FormAI DATASET v1.0 Category: Temperature Converter ; Style: shocked
#include <stdio.h>

int main()
{
    char choice;
    float temperature, convertedTemperature;

    printf("Welcome to the Temperature Converter!\n");

    printf("Do you want to convert from Fahrenheit to Celsius? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y')
    {
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &temperature);

        convertedTemperature = (temperature - 32) * 5 / 9;

        printf("%.2f Fahrenheit = %.2f Celsius\n", temperature, convertedTemperature);
    }
    else
    {
        printf("Enter temperature in Celsius: ");
        scanf("%f", &temperature);

        convertedTemperature = (temperature * 9 / 5) + 32;

        printf("%.2f Celsius = %.2f Fahrenheit\n", temperature, convertedTemperature);
    }

    printf("Thank you for using the Temperature Converter!\n");

    return 0;
}