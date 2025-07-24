//FormAI DATASET v1.0 Category: Temperature Converter ; Style: imaginative
#include <stdio.h>

// Function to convert Celsius to Fahrenheit
float CelsiusToFahrenheit(float celsius)
{
    float fahrenheit;
    fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
    return fahrenheit;
}

// Function to convert Fahrenheit to Celsius
float FahrenheitToCelsius(float fahrenheit)
{
    float celsius;
    celsius = (fahrenheit - 32.0) * 5.0 / 9.0;
    return celsius;
}

int main()
{
    float temperature; // temperature to be converted
    char unit; // unit of the input temperature
    printf("Enter the temperature and the unit (C/F): ");
    scanf("%f %c", &temperature, &unit);

    // checking for invalid units
    if (unit != 'C' && unit != 'F') {
        printf("Invalid unit!\n");
        return 0;
    }

    if (unit == 'C') {
        float fahrenheit = CelsiusToFahrenheit(temperature);
        printf("%.2fC is equivalent to %.2fF.\n", temperature, fahrenheit);
    }
    else {
        float celsius = FahrenheitToCelsius(temperature);
        printf("%.2fF is equivalent to %.2fC.\n", temperature, celsius);
    }

    return 0;
}