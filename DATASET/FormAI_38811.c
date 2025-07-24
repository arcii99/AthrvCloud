//FormAI DATASET v1.0 Category: Temperature Converter ; Style: automated
#include <stdio.h>

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    float fahrenheit = (celsius * 9 / 5) + 32;
    return fahrenheit;
}

// Function to convert Celsius to Kelvin
float celsiusToKelvin(float celsius) {
    float kelvin = celsius + 273.15;
    return kelvin;
}

int main() {
    float temperature, convertedTemperature;
    int choice;

    // Display the menu to the user
    printf("TEMPERATURE CONVERTER\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Celsius to Kelvin\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Get the temperature from the user
    printf("Enter the temperature in Celsius: ");
    scanf("%f", &temperature);

    switch (choice) {
        case 1:
            convertedTemperature = celsiusToFahrenheit(temperature);
            printf("%.2f degrees Celsius = %.2f degrees Fahrenheit\n", temperature, convertedTemperature);
            break;
        case 2:
            convertedTemperature = celsiusToKelvin(temperature);
            printf("%.2f degrees Celsius = %.2f degrees Kelvin\n", temperature, convertedTemperature);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}