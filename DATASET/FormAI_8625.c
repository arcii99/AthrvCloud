//FormAI DATASET v1.0 Category: Unit converter ; Style: visionary
#include <stdio.h>

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

// Funion to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

// Function to convert Celsius to Kelvin
float celsiusToKelvin(float celsius) {
    return celsius + 273.15;
}

// Function to convert Kelvin to Celsius
float kelvinToCelsius(float kelvin) {
    return kelvin - 273.15;
}

// Function to convert Fahrenheit to Kelvin
float fahrenheitToKelvin(float fahrenheit) {
    return (fahrenheit + 459.67) * 5 / 9;
}

// Function to convert Kelvin to Fahrenheit
float kelvinToFahrenheit(float kelvin) {
    return (kelvin * 9 / 5) - 459.67;
}

int main() {
    float temperature;
    int choice;

    printf("Enter temperature to convert: ");
    scanf("%f", &temperature);

    printf("\n1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    printf("5. Fahrenheit to Kelvin\n");
    printf("6. Kelvin to Fahrenheit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("%.2f C = %.2f F\n", temperature, celsiusToFahrenheit(temperature));
            break;
        case 2:
            printf("%.2f F = %.2f C\n", temperature, fahrenheitToCelsius(temperature));
            break;
        case 3:
            printf("%.2f C = %.2f K\n", temperature, celsiusToKelvin(temperature));
            break;
        case 4:
            printf("%.2f K = %.2f C\n", temperature, kelvinToCelsius(temperature));
            break;
        case 5:
            printf("%.2f F = %.2f K\n", temperature, fahrenheitToKelvin(temperature));
            break;
        case 6:
            printf("%.2f K = %.2f F\n", temperature, kelvinToFahrenheit(temperature));
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}