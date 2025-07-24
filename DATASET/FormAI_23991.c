//FormAI DATASET v1.0 Category: Unit converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Conversion Functions
float celsius_to_fahrenheit(float celsius);
float fahrenheit_to_celsius(float fahrenheit);
float meters_to_feet(float meters);
float feet_to_meters(float feet);

int main()
{
    int option;
    float value, result;

    printf("Welcome to the Cyberpunk Unit Converter!\n");
    printf("Please select an option from the menu below:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Meters to Feet\n");
    printf("4. Feet to Meters\n");
    scanf("%d", &option);

    switch(option)
    {
        case 1:
            printf("Enter the temperature in Celsius: ");
            scanf("%f", &value);
            result = celsius_to_fahrenheit(value);
            printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", value, result);
            break;

        case 2:
            printf("Enter the temperature in Fahrenheit: ");
            scanf("%f", &value);
            result = fahrenheit_to_celsius(value);
            printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", value, result);
            break;

        case 3:
            printf("Enter the distance in meters: ");
            scanf("%f", &value);
            result = meters_to_feet(value);
            printf("%.2f meters is equal to %.2f feet.\n", value, result);
            break;

        case 4:
            printf("Enter the distance in feet: ");
            scanf("%f", &value);
            result = feet_to_meters(value);
            printf("%.2f feet is equal to %.2f meters.\n", value, result);
            break;

        default:
            printf("Invalid option selected.");
    }

    return 0;
}

float celsius_to_fahrenheit(float celsius)
{
    return (celsius * 9/5) + 32;
}

float fahrenheit_to_celsius(float fahrenheit)
{
    return (fahrenheit - 32) * 5/9;
}

float meters_to_feet(float meters)
{
    return meters * 3.281;
}

float feet_to_meters(float feet)
{
    return feet / 3.281;
}