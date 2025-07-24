//FormAI DATASET v1.0 Category: Unit converter ; Style: automated
#include<stdio.h>

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) 
{
    float fahrenheit = (celsius * 1.8) + 32;
    return fahrenheit;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit)
{
    float celsius = (fahrenheit - 32) * 5/9;
    return celsius;
}

int main()
{
    int choice;
    float temperature;

    // Display menu to the user
    printf("Select the option to convert:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1: // Convert Celsius to Fahrenheit
            printf("Enter the temperature in Celsius: ");
            scanf("%f", &temperature);
            printf("%.2f degree Celsius is equal to %.2f degree Fahrenheit\n", temperature, celsiusToFahrenheit(temperature));
            break;

        case 2: // Convert Fahrenheit to Celsius
            printf("Enter the temperature in Fahrenheit: ");
            scanf("%f", &temperature);
            printf("%.2f degree Fahrenheit is equal to %.2f degree Celsius\n", temperature, fahrenheitToCelsius(temperature));
            break;

        default: // Invalid option selected
            printf("Invalid input! Please select 1 or 2\n");
            break;
    }

    return 0;
}